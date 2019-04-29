#pragma once
#include <google\protobuf\service.h>
#include "echo.pb.h"
class MyEchoService : public echo::EchoService
{
public:
	MyEchoService();
	~MyEchoService();
	virtual void Echo(::google::protobuf::RpcController* controller,
		const ::echo::EchoRequest* request,
		::echo::EchoResponse* response,
		::google::protobuf::Closure* done);

};

