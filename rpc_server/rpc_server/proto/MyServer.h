#pragma once
#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#include <string>
#include <google\protobuf\service.h>
class MyEchoService;
class MyServer
{
public:
	MyServer();
	~MyServer();
	void start(const std::string& ip, const int port);
private:
	void on_resp_msg_filled(::google::protobuf::Message* resp_msg,
		SOCKET socket);
	
private:
	SOCKET server;
	MyEchoService *echoService = nullptr;
};

