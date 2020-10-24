#include "Server.h"

Server::Server(unsigned short port) {
	if (listener.listen(port) != sf::Socket::Done) {
		throw "Listener socket failed";
	}
	if (listener.accept(client) != sf::Socket::Done) {
		throw "Client socket failed";
	}
	client.setBlocking(false);
}

void Server::send(const char* data, std::size_t bytes) {
	if (client.send(data, bytes) != sf::Socket::Done) {
		throw "Data could not be sent";
	}
}

bool Server::receive(std::string& output) {
	sf::Socket::Status status;
	do {
		status = client.receive(buffer, sizeof(buffer), received);
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