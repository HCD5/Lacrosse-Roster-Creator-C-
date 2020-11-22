#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

#include "Player.h"

//Construtor
Player::Player() {
	name = "Not Entered";
	num = -1;
	year = "UN";
	position = "Not Entered";
}

///// Mutators /////

//Sets player number
void Player::setNum(int nmbr) { num = nmbr; }

//Sets player year
void Player::setYear(int input) { 
	switch (input) {
	case 1:
		year = "Freshmen";
		break;
	case 2:
		year = "Sophmore";
		break;
	case 3:
		year = "Junior";
		break;
	case 4:
		year = "Senior";
		break;
	case 5:
		year = "Graduate";
		break;
	default:
		year = "Not Entered";
	}
}

//Sets player position
void Player::setPosition(int input) {
	switch (input) {
	case 1:
		position = "Attack";
		break;
	case 2:
		position = "Mid-Field";
		break;
	case 3:
		position = "Faceoff";
		break;
	case 4:
		position = "Defense";
		break;
	case 5: 
		position = "Goalie";
		break;
	default: 
		position = "Not Entered";
	}
}

///// Accessors /////

//Returns player Number
int Player::getNum() { return num; }

//Returns player year
string Player::getYear() { return year; }

///// Output /////

//Prints players info
void Player::printPlayer() {
	cout << left << setw(20) << name << setw(8) << num << setw(11) << year << setw(10) << position << endl;
}

