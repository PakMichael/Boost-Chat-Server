#ifndef ROOM_H
#define ROOM_H

class User;
#include <vector>

class Room {
	
public:
	void addUser(User* user);
	void removeUser(User* user);
	void deliverMessage(std::string msg, User* sender);



}; 


#endif // !ROOM_H

