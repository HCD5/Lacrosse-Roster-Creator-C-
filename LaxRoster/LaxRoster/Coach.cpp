#include <iostream>
#include <vector>
#include <string>

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




