//#include "stdafx.h"
#include "MyServer.h"
#include <iostream>
using namespace std;
#include "echo.pb.h"
#include "MyEchoService.h"
MyServer::MyServer()
{
	echoService = new MyEchoService();
}


MyServer::~MyServer()
{
	delete echoService;
}

void MyServer::start(const std::string & ip, const int port)
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err = 0;
	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersionRequested, &wsaData);
	if (err != 0)
	{
		cerr << "WSAStartup failed with error: %d\n" << err << endl;
		return;
	}
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
	{
		cerr << "Could not find a usable version of Winsock.dll\n" << endl;
		WSACleanup();
		return;
	}
	server = socket(AF_INET, SOCK_STREAM, 0);
	if (server == INVALID_SOCKET)
	{
		cerr << "socket() failed: " << WSAGetLastError() << endl;
		return;
	}
	SOCKADDR_IN addrSrv;
	memset(&addrSrv, 0, sizeof(addrSrv));
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_addr.s_addr = htonl(INADDR_ANY);
	addrSrv.sin_port = htons(port);
	err = ::bind(server, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
	if (err != 0)
	{
		cerr << "bind() failed: " << WSAGetLastError() << endl;
		return;
	}
	err = listen(server, 5);
	if (err != 0)
	{
		cerr << "listen() failed: " << WSAGetLastError() << endl;
		return;
	}
	cout << "RPC Server listening......" << endl;
	SOCKADDR_IN addrClt;
	int len = sizeof(SOCKADDR);
	memset(&addrClt, 0, len);
	while (true)
	{
		SOCKET sockConn = accept(server, (SOCKADDR*)&addrClt, &len);
		char recvBuf[1024] = "\0";
		int iLen = recv(sockConn, recvBuf, 1024, 0);
		echo::EchoRequest request;
		request.ParseFromArray((const void*)recvBuf, iLen);
		echo::EchoResponse *resp_msg = new echo::EchoResponse();
		//auto done = ::google::protobuf::NewCallback(this, &MyServer::on_resp_msg_filled,
		//	resp_msg, sockConn);
		auto sd = echoService->GetDescriptor();
		auto md = sd->method(0);
		echoService->CallMethod(md, nullptr, &request, resp_msg, nullptr);
		std::string serialized_data = resp_msg->SerializeAsString();
		int err = 0;
		char sendBuf[1024];
		memset(sendBuf, 0, 1024);
		strcpy_s(sendBuf, serialized_data.data());
		err = send(sockConn, sendBuf, serialized_data.size(), 0);
	}
}

void MyServer::on_resp_msg_filled(::google::protobuf::Message * resp_msg, SOCKET socket)
{
}
