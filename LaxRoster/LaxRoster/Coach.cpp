#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
#include "Coach.h"

//Constructor
Coach::Coach() {
	name = "Not Entered";
	position = "Not Entered";
}

//Sets Coach position
void Coach::setPosition(int input) {
	switch (input) {
	case 1:
		position = "Head";
		break;
	case 2:
		position = "Assistant";
		break;
	case 3:
		position = "Graduate";
		break;
	default:
		position = "Not Entered";
	}
}

//Prints Coaches info
void Coach::printCoach() {
	cout << left << setw(20) << name << position << endl;
}




