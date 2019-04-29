#pragma once
#include <google\protobuf\service.h>
using namespace ::google::protobuf;
#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

class MyChannel : public RpcChannel
{
public:
	MyChannel(const std::string& ip, const int port);
	~MyChannel();

	// Í¨¹ý RpcChannel ¼Ì³Ð
	virtual void CallMethod(const MethodDescriptor * method, RpcController * controller, const Message * request, Message * response, Closure * done) override;

private:
	SOCKET client;
};

