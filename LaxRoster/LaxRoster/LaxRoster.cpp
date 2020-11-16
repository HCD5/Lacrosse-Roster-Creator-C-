#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Header files
#include "Person.h"
#include "Player.h"
#include "Coach.h"

//Function prototypes
void playerOrCoach(vector<Player>&, vector<Coach>&);
void addPlayer(vector<Player>&);
void addCoach(vector<Coach>&);
void printRoster();

//Main Meathod 
int main()
{
	//Declare variables
	vector<Player> Players;
	vector<Coach> Coaches;

	//Print main menu
	playerOrCoach(Players, Coaches);


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

	cout << endl;


/////////////////////////////////// TESTING ///////////////////////////////////

}

//Prints menu asking to add player or coach
void playerOrCoach(vector<Player>& p, vector<Coach>& c) {
	//Number inputted by user and data validation flag
	int num;
	bool valid;

	//Data validation loop
	do {
		valid = true;

		//Menu
		cout << "Would you like to add a player or a coach to the roster?" << endl;
		cout << "--------------------------------------------------------" << endl;
		cout << "1: Player" << endl;
		cout << "2: Coach" << endl;
		cout << "3: Finished/Print Roster" << endl;

		//Input
		cin >> num;

		//Check input
		switch (num) {
		case 1: 
			addPlayer(p);
			break;
		case 2: 
			addCoach(c);
			break;
		case 3:
			break;
		default :
			cout << "The number you entered was incorrect, please try again." << endl;
			cout << endl;
			valid = false;
		}

	} while (valid == false);

}

//Adds player to the roster
void addPlayer(vector<Player>&) {

}

//Adds coach to the roster
void addCoach(vector<Coach>&) {

}

//Prints roster 
void printRoster() {

}