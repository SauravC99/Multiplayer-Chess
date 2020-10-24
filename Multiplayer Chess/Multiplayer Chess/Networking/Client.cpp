#include "Client.h"

Client::Client(const sf::IpAddress& ipAddress, unsigned short port, sf::Time timeout) {
	if (socket.connect(ipAddress, port, timeout) != sf::Socket::Done) {
		throw "Could not connect to server, possibly timed out";
	}
	socket.setBlocking(false);
}

void Client::send(const char* data, std::size_t bytes) {
	if (socket.send(data, bytes) != sf::Socket::Done) {
		throw "Data could not be sent";
	}
}

bool Client::receive(std::string& output) {
	sf::Socket::Status status;
	do {
		status = socket.receive(buffer, sizeof(buffer), received);
		if (status == sf::Socket::NotReady)
			break;
		if (status != sf::Socket::Done)
			throw "Error while receiving data";
	} while (received == 0);

	if (status == sf::Socket::Done) {
		std::string temp(buffer, received);
		output = temp;
	}

	return status == sf::Socket::Done;
}