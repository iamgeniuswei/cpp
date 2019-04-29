#include "MyController.h"



MyController::MyController()
{
}


MyController::~MyController()
{
}

void MyController::Reset()
{
}

bool MyController::Failed() const
{
	return false;
}

std::string MyController::ErrorText() const
{
	return std::string();
}

void MyController::StartCancel()
{
}

void MyController::SetFailed(const std::string & reason)
{
}

bool MyController::IsCanceled() const
{
	return false;
}

void MyController::NotifyOnCancel(Closure * callback)
{
}
