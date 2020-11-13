#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Person.h"

//Default Constructor
Person::Person() { 
	name = "Not Entered";
	position = "UN";
}

///// Mutators /////

//Set name of person
void Person::setName(string n) { name = n; }

//Sets players position
void Person::setPosition(string pos) { position = pos; }

///// Accessors /////

//Return name
string Person::getName() { return name; }

//Returns position
string Person::getPosition() { return position; }