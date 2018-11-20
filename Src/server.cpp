#include "server.h"



Server::Server(io_serv& io) :accept(io, tcp::endpoint(tcp::v4(), 13)) {
	waitForConnection();
}


void Server::waitForConnection() {
	User* ptr = User::getPointer(accept.get_io_service());
	accept.async_accept(ptr->getSocket(), boost::bind(&Server::acceptHandler, this, boost::asio::placeholders::error, ptr));
}

void Server::acceptHandler(const boost::system::error_code& ec, User* ptr) {
	ptr->writeMsg("hello");
	ptr->readMsg();


	waitForConnection();
}