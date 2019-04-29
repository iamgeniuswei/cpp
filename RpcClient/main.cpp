#include <iostream>

using namespace std;
#include "proto/echo.pb.h"


int main()
{
    cout << "Hello World!" << endl;
    //Test Protocol Buffers
    echo::EchoRequest request;
    cout << &request << endl;
    request.set_id(10);
    cout << request.id() << endl;
    cout << request.msg() << endl;

    return 0;
}
