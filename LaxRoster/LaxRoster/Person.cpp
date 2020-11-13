#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Person.h"

//Default Constructor
Person::Person() {
	name = "Not Entered";
}

//Constructor
Person::Person(string n) {
	name = n;
}

//Set name of person
void Person::setName(string n) {
	name = n;
}

//Return name
string Person::getName() {
	return name;
}