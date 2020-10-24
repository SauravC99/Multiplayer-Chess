#pragma once
#include "Socket.h"
#include <SFML/Network.hpp>
#include <string>

#ifndef BUFFER_LENGTH
#define BUFFER_LENGTH 128
#endif

class Server : public Socket
{
private:
	sf::TcpListener listener;
	sf::TcpSocket   client;
	std::size_t received;
	char buffer[BUFFER_LENGTH];

public:
	Server(unsigned short port = 27015);

	void send(const char* data, std::size_t bytes);
	bool receive(std::string&);
};

