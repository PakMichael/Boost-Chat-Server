#ifndef USER_H
#define USER_H

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
using boost::asio::ip::tcp ;

class User  {
	tcp::socket socket_;
	//buffer read 
	std::string writeBuffer;
	boost::asio::streambuf readBuffer;
public:

	static User* getPointer(boost::asio::io_service& io) { return new User(io); };
	void writeMsg(std::string msg);
	void readMsg();

	User(boost::asio::io_service& io) :socket_(io) {}
	void handle_write(const boost::system::error_code& /*error*/,
		size_t /*bytes_transferred*/);
	void handle_read(const boost::system::error_code& /*error*/,
		size_t /*bytes_transferred*/);
	tcp::socket& getSocket() {
		return socket_;
	}
 };


#endif // !USER_H
