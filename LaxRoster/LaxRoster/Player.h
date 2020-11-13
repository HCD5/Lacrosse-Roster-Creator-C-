#pragma once
#ifndef Player_H
#define Player_H

using namespace std;

#include "Person.h"

class Player : public Person {

public:
	Player();
	void setNum(int);
	void setYear(string);
	void setPosition(string);
	int getNum();
	string getYear();
	string getPosition();
	
private:
	int num;
	string year;
	string position;
};

#endif
