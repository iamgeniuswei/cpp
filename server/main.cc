#include "Person.pb.h"
#include <iostream>
using namespace std;
#include "MyChannel.h"
#include "echo.pb.h"

class MyEchoService : public echo::EchoService
{
public:
	virtual void Echo(::google::protobuf::RpcController* controller,
		const ::echo::EchoRequest* request,
		::echo::EchoResponse* response,
		::google::protobuf::Closure* done)
	{
		std::cout << request->msg() << std::endl;
		response->set_msg(std::string("I have received '") + request->msg() + std::string("'"));
		done->Run();
	}
};



int main()
{
    Person person;
    person.set_id(100);
    cout << person.id() << endl;

	Myserver server;
	MyEchoService service;

	const ServiceDescriptor *des = service.GetDescriptor();

	server.add(&service);
	server.start("127.0.0.1", 5678);
    return 0;
}