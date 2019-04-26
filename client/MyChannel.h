#pragma once

#include <google\protobuf\service.h>
#include <boost\asio.hpp>
#include <boost\scoped_ptr.hpp>
#include <boost\shared_ptr.hpp>
#include <boost\make_shared.hpp>
#include <map>
#include <iostream>
#include "meta.pb.h"
using namespace ::google::protobuf;
using namespace boost::asio;

class MyController : public ::google::protobuf::RpcController
{
public:
	virtual void Reset() {}
	virtual bool Failed() const {
		return false;
	}
	virtual std::string ErrorText() const {
		return "";
	}
	virtual void StartCancel() {}
	virtual void SetFailed(const std::string& reason) {}
	virtual bool IsCanceled() const { return false; }
	virtual void NotifyOnCancel(::google::protobuf::Closure*){}
	
};




class MyChannel : public ::google::protobuf::RpcChannel
{
private:
	boost::shared_ptr<boost::asio::io_service> _io;
	boost::shared_ptr<boost::asio::ip::tcp::socket> _sock;

public:
	MyChannel();
	~MyChannel();
	void init(const std::string &ip, const int port)
	{
		_io = boost::make_shared<boost::asio::io_service>();
		_sock = boost::make_shared<boost::asio::ip::tcp::socket>(*_io);
		boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address::from_string(ip), port);
		_sock->connect(ep);
	}

	virtual void CallMethod(const MethodDescriptor *method,
		RpcController* controller,
		const Message *request,
		Message *response,
		Closure* done)
	{
		std::string serialized_data = request->SerializeAsString();

		echo::RpcMeta rpc_meta;
		rpc_meta.set_service_name(method->service()->name());
		rpc_meta.set_method_name(method->name());
		rpc_meta.set_data_size(serialized_data.size());

		std::string serialzied_str = rpc_meta.SerializeAsString();

		int serialzied_size = serialzied_str.size();
		serialzied_str.insert(0, std::string((const char*)&serialzied_size, sizeof(int)));
		serialzied_str += serialized_data;

		_sock->send(boost::asio::buffer(serialzied_str));

		char resp_data_size[sizeof(int)];
		_sock->receive(boost::asio::buffer(resp_data_size));

		int resp_data_len = *(int*)resp_data_size;
		std::vector<char> resp_data(resp_data_len, 0);
		_sock->receive(boost::asio::buffer(resp_data));

		response->ParseFromString(std::string(&resp_data[0], resp_data.size()));
	}

	
};


class Myserver
{

private:
	void dispatch_msg(const std::string& service_name,
		const std::string& method_name,
		const std::string& serialized_data,
		const boost::shared_ptr<boost::asio::ip::tcp::socket> &sock);
	void on_resp_msg_filled(
		::google::protobuf::Message* recv_msg,
		::google::protobuf::Message* resp_msg,
		const boost::shared_ptr<boost::asio::ip::tcp::socket> sock);
	void pack_message(const ::google::protobuf::Message *msg,
		std::string* serialized_data)
	{
		int serialized_size = msg->ByteSize();
		serialized_data->assign((const char*)& serialized_size, sizeof(serialized_size));
		msg->AppendToString(serialized_data);
	}


public:
	void add(Service *service)
	{
		ServiceInfo service_info;
		service_info.service = service;
		service_info.sd = service->GetDescriptor();
		for (int i = 0; i < service_info.sd->method_count(); ++i)
		{
			//service_info.mds[service_info.sd->method(i)->name] = service_info.sd->method(i);
		}
		_services[service_info.sd->name()] = service_info;
	}

	void start(const std::string& ip, const int port)
	{
		io_service io;
		ip::tcp::acceptor acceptor(io,
			ip::tcp::endpoint(ip::address::from_string(ip), port));
		while (true)
		{
			auto sock = boost::make_shared<ip::tcp::socket>(io);
			acceptor.accept(*sock);
			std::cout << "recv from client: "
				<< sock->remote_endpoint().address()
				<< std::endl;

			char meta_size[sizeof(int)];
			sock->receive(buffer(meta_size));
			int meta_len = *(int*)(meta_size);
			std::vector<char> meta_data(meta_len, 0);
			sock->receive(buffer(meta_data));

			echo::RpcMeta meta;
			meta.ParseFromString(std::string(&meta_data[0], meta_data.size()));
			std::vector<char> data(meta.data_size(), 0);
			sock->receive(boost::asio::buffer(data));
			dispatch_msg(
				meta.service_name(),
				meta.method_name(),
				std::string(&data[0], data.size()),
				sock);
		}
	}



private:
	struct ServiceInfo {
		Service *service;
		const ServiceDescriptor* sd;
		std::map<std::string, const MethodDescriptor*> mds;
	};
	std::map<std::string, ServiceInfo> _services;
};
