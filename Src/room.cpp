#include <room.h>
#include <user.h>


std::vector<User*> usersInRoom;

void Room::addUser(User* user) {

	usersInRoom.push_back(user);
}

void Room::removeUser(User* user) {
	usersInRoom.erase(std::find(usersInRoom.begin(), usersInRoom.end(), user));
}

void Room::deliverMessage(std::string msg, User* sender) {
	for (User* recipient : usersInRoom) {
		if (recipient != sender) {
			recipient->writeMsg(msg);
		}
	}
}