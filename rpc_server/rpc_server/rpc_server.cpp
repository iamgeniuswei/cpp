// rpc_server.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "proto\MyServer.h"

int main()
{
	MyServer server;
	server.start("127.0.0.1", 12345);
    return 0;
}

