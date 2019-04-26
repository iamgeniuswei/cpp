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

	MyChannel channel;
	channel.init("127.0.0.1", 5678);
	echo::EchoRequest request;
	echo::EchoResponse response;
	request.set_msg("hello, server");
	echo::EchoService_Stub stub(&channel);
	MyController cntl;
	stub.Echo(&cntl, &request, &response, NULL);
	std::cout << "resp:" << response.msg() << std::endl;
    return 0;
}