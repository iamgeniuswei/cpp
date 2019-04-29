// rpc_client.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "proto\echo.pb.h"
#include <iostream>
using namespace std;
#include "proto\echo.pb.h"
#include "proto\MyChannel.h"
#include "proto\MyController.h"
int main()
{
	//Test Protocol Buffers
	echo::EchoRequest req;
	req.set_id(10);
	req.set_msg("EchoRequest");
	cout << req.id() << ": " << req.msg() << endl;

	MyChannel channel("127.0.0.1", 12345);
	echo::EchoResponse response;
	echo::EchoService_Stub stub(&channel);
	MyController cntl;
	stub.Echo(&cntl, &req, &response, NULL);
	std::cout << response.id() << ":" << response.msg() << std::endl;
    return 0;
}

