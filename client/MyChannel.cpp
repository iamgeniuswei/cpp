#include "MyChannel.h"



MyChannel::MyChannel()
{
}


MyChannel::~MyChannel()
{
}

void Myserver::dispatch_msg(const std::string & service_name, const std::string & method_name, const std::string & serialized_data, const boost::shared_ptr<boost::asio::ip::tcp::socket>& sock)
{
	auto service = _services[service_name].service;
	auto md = _services[service_name].mds[method_name];

	std::cout << "recv service_name:" << service_name << std::endl;
	std::cout << "recv method_name:" << method_name << std::endl;
	std::cout << "recv type:" << md->input_type()->name() << std::endl;
	std::cout << "resp type:" << md->output_type()->name() << std::endl;

	auto recv_msg = service->GetRequestPrototype(md).New();
	recv_msg->ParseFromString(serialized_data);
	auto resp_msg = service->GetResponsePrototype(md).New();

	MyController controller;
	//auto done = NewCallback(
	//	this,
	//	&Myserver::on_resp_msg_filled,
	//	recv_msg,
	//	resp_msg,
	//	sock);

	
	service->CallMethod(md, &controller, recv_msg, resp_msg, NULL);
}

void Myserver::on_resp_msg_filled(::google::protobuf::Message * recv_msg, ::google::protobuf::Message * resp_msg, const boost::shared_ptr<boost::asio::ip::tcp::socket> sock)
{
	boost::scoped_ptr<::google::protobuf::Message> recv_msg_guard(recv_msg);
	boost::scoped_ptr<::google::protobuf::Message> resp_msg_guard(resp_msg);

	std::string resp_str;
	pack_message(resp_msg, &resp_str);

	sock->send(boost::asio::buffer(resp_str));
}
