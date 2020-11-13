#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "Player.h"

//Construtor
Player::Player() {
	name = "Weenie man";
	num = -1;
	year = "UN";
	position = "UN";
}

///// Mutators /////

//Sets players number
void Player::setNum(int nmbr) { num = nmbr; }

//Sets players year
void Player::setYear(string yr) { year = yr; }

//Sets players position
void Player::setPosition(string pos) { position = pos }

///// Accessors /////

//Returns player Number
int Player::getNum() { return num; }
//Returns player year
string Player::getYear() { return year; }

//Returns position
string Player::getPosition() { return position; }