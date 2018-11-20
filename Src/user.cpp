#include <user.h>


void User::writeMsg(std::string msg) {
	writeBuffer = msg;
	boost::asio::async_write(socket_, boost::asio::buffer(writeBuffer), boost::bind(&User::handle_write, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));

}
void User::readMsg() {
	boost::asio::async_read_until(socket_, readBuffer,'\n', boost::bind(&User::handle_read, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}


void User::handle_write(const boost::system::error_code& /*error*/,
	size_t /*bytes_transferred*/)
{
}

void User::handle_read(const boost::system::error_code& /*error*/,
	size_t /*bytes_transferred*/)
{
	std::istream is(&readBuffer);
	std::string line;
	std::getline(is, line);
	std::cout << line << std::endl;

	readMsg();
}