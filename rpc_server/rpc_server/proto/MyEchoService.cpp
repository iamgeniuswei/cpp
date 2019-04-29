//#include "stdafx.h"
#include "MyEchoService.h"
#include <iostream>
using namespace std;

MyEchoService::MyEchoService()
{
}


MyEchoService::~MyEchoService()
{
}

void MyEchoService::Echo(::google::protobuf::RpcController * controller, const::echo::EchoRequest * request, ::echo::EchoResponse * response, ::google::protobuf::Closure * done)
{
	std::cout << request->msg() << endl;
	response->set_id(100);
	response->set_msg(std::string("I have received '") + request->msg() + std::string("'"));
	if (done != nullptr)
		done->Run();
}
