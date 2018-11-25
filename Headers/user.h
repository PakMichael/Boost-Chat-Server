#ifndef USER_H
#define USER_H


#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <deque>
#include <room.h>

using boost::asio::ip::tcp ;

 
class User  {
	tcp::socket socket_;
	std::deque<std::string> writeBuffer;
	boost::asio::streambuf readBuffer;
	Room* chatRoom;
public:
	bool nameSet = false;
	std::string name;

public:

	static User* getPointer(boost::asio::io_service& io, Room* room) { return new User(io, room); };
	void queueMsg(std::string msg);
	void readMsg();

	User(boost::asio::io_service& io, Room* room) :socket_(io), chatRoom(room){ chatRoom->addUser(this); }
	void handle_write(const boost::system::error_code&, size_t );
	void handle_read(const boost::system::error_code&, size_t);
	tcp::socket& getSocket() {
		return socket_;
	}

 };


#endif // !USER_H
