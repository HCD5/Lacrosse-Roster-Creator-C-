#pragma once
#ifndef Person_H
#define Person_H

using namespace std;

class Person {

public:
	Person();
	void setName(string);
	void setPosition(string);
	string getName();
	string getPosition();

protected:
	string name;
	string position;
};

#endif

