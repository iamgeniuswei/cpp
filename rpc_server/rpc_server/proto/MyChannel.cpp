#include "MyChannel.h"
#include <iostream>
using namespace std;
#include "echo.pb.h"

MyChannel::MyChannel(const std::string & ip, const int port)
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
	client = socket(AF_INET, SOCK_STREAM, 0);
	if (client == INVALID_SOCKET)
	{
		cerr << "socket faild: " << WSAGetLastError() << endl;
		return;
	}
	SOCKADDR_IN addrSrv;
	memset(&addrSrv, 0, sizeof(addrSrv));
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_addr.s_addr = inet_addr(ip.data());
	addrSrv.sin_port = htons(port);
	err = connect(client, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));
	if (err == INVALID_SOCKET)
	{
		cerr << "connect failed: " << WSAGetLastError() << endl;
		return;
	}
}

MyChannel::~MyChannel()
{
	closesocket(client);
	WSACleanup();
	cout << "clean OK!" << endl;
}

void MyChannel::CallMethod(const MethodDescriptor * method, RpcController * controller, const Message * request, Message * response, Closure * done)
{
	std::string serialized_data = request->SerializeAsString();
	int err = 0;
	char sendBuf[1024];
	memset(sendBuf, 0, 1024);
	strcpy_s(sendBuf, serialized_data.data());
	err = send(client, sendBuf, serialized_data.size(), 0);
	char recvBuf[1024];
	memset(recvBuf, 0, 1024);
	int iLen = recv(client, recvBuf, 1024, 0);
	response->ParseFromArray((const void*)recvBuf, iLen);
}
