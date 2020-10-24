#pragma once
#include <string>

class Socket
{
public:
	Socket() {}

	virtual void send(const char* data, std::size_t bytes) = 0;
	virtual bool receive(std::string&) = 0;
};

