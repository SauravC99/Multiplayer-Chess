#include "Client.h"

Client::Client(const sf::IpAddress& ipAddress, unsigned short port, sf::Time timeout) {
	if (socket.connect(ipAddress, port, timeout) != sf::Socket::Done) {
		throw "Could not connect to server, possibly timed out";
	}
}

void Client::send(const char* data, std::size_t bytes) {
	if (socket.send(data, bytes) != sf::Socket::Done) {
		throw "Data could not be sent";
	}
}

std::string Client::receive() {
	do {
		if (socket.receive(buffer, sizeof(buffer), received) != sf::Socket::Done)
			throw "Error while receiving data";
	} while (received == 0);

	return std::string(buffer, received);
}