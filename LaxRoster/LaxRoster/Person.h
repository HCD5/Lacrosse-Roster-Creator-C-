#pragma once
#ifndef Person_H
#define Person_H

using namespace std;

class Person {

public:
	Person();
	Person(string);
	void setName(string);
	string getName();

private:
	string name;
};

#endif

