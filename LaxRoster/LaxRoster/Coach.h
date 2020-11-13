#pragma once
#ifndef Coach_H
#define Coach_H

using namespace std;

#include "Person.h"

class Coach : public Person {

public:
	Coach();
	void setPosition(int);
};

#endif