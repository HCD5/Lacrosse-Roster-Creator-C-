#pragma once
#ifndef Player_H
#define Player_H

using namespace std;

#include "Person.h"

class Player : public Person {

public:
	Player();
	void setNum(int);
	void setYear(int);
	int getNum();
	string getYear();
	void setPosition(int);
	
private:
	int num;
	string year;
};

#endif
