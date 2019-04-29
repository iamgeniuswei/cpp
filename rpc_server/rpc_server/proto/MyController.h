#pragma once
#include <google\protobuf\service.h>
using namespace ::google::protobuf;


class MyController : public RpcController
{
public:
	MyController();
	~MyController();



	// Í¨¹ý RpcController ¼Ì³Ð
	virtual void Reset() override;

	virtual bool Failed() const override;

	virtual std::string ErrorText() const override;

	virtual void StartCancel() override;

	virtual void SetFailed(const std::string & reason) override;

	virtual bool IsCanceled() const override;

	virtual void NotifyOnCancel(Closure * callback) override;

};

