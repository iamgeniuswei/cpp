// rpc_server.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "proto\MyServer.h"

int main()
{
	MyServer server;
	server.start("127.0.0.1", 12345);
    return 0;
}

