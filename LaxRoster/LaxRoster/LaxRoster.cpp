#include <iostream>
#include <string>

using namespace std;

#include "Person.h"
#include "Player.h"
#include "Coach.h"

//Main Meathod 
int main()
{

/////////////////////////////////// TESTING ///////////////////////////////////

	Player joe;

	joe.setName("Joe");
	joe.setNum(52);
	joe.setYear(2);
	joe.setPosition(2);

	cout << joe.getName() << " " << joe.getNum() << " " << joe.getYear() << " " << joe.getPosition() << endl;


	Coach boe;

	boe.setName("Boe");
	boe.setPosition(2);

	cout << boe.getName() << " " << boe.getPosition() << endl;

/////////////////////////////////// TESTING ///////////////////////////////////

}