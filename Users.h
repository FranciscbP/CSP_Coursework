//Made By Francisco Pedrosa (N0883131)
#pragma once
#include <../../Header.h>

class Users
{
public:
	Users();

	void setNum(int);
	void createUser(string, string);
	int logUser(string, string);
	int checkUsername(string);
	string createHash (string);
	string convertHashtoString(size_t);
	int getMoney();
	void updateMoney(int);

private:
	int userNum;

};
