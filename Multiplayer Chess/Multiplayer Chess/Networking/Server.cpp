#include "Server.h"

Server::Server(unsigned short port) {
	if (listener.listen(port) != sf::Socket::Done) {
		throw "Listener socket failed";
	}
	if (listener.accept(client) != sf::Socket::Done) {
		throw "Client socket failed";
	}
}

void Server::send(const char* data, std::size_t bytes) {
	if (client.send(data, bytes) != sf::Socket::Done) {
		throw "Data could not be sent";
	}
}

std::string Server::receive() {
	do {
		if (client.receive(buffer, sizeof(buffer), received) != sf::Socket::Done)
			throw "Error while receiving data";
	} while (received == 0);

	return std::string(buffer, received);
}