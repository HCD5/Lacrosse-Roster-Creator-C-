#pragma once
#ifndef Person_H
#define Person_H

using namespace std;

class Person {

public:
	Person();
	void setName(string);
	string getName();

protected:
	string name;
};

#endif

