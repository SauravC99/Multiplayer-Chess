#pragma once
#include <SFML/Network.hpp>
#include <string>

#ifndef BUFFER_LENGTH
#define BUFFER_LENGTH 127
#endif

class Client
{
private:
	sf::TcpSocket socket;
	std::size_t received;
	char buffer[BUFFER_LENGTH];

public:
	Client(const sf::IpAddress& ipAddress = "localhost", 
		   unsigned short       port      = 27015, 
		   sf::Time             timeout   = sf::Time::Zero);

	void send(const char* data, std::size_t bytes);
	std::string receive();
};

