#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

//Header files
#include "Person.h"
#include "Player.h"
#include "Coach.h"

//Function prototypes
bool playerOrCoach(vector<Player>&, vector<Coach>&);
void addPlayer(vector<Player>&);
void addCoach(vector<Coach>&);
void printRoster(vector<Player>&, vector<Coach>);
void sortRoster(vector<Player>&);
void switchSpot(Player&, Player&);
int findPlayer(vector<Player>, int, int, int);
bool searchForPlayer(vector<Player>);
int validNumber(int);
int validMenuNumber(int, int);


//Main function
int main()
{
	//Declare variables
	vector<Player> Players;
	vector<Coach> Coaches;
	bool print = false;
	bool repeat = false;

	//Greet user and breifly explain program
	cout << "Welcome to the lacrosse roster creator" << endl;
	cout << "This program allow you to enter in as many players and coaches as you want " << endl;
	cout << "Once your done adding players you can print the roster and then search for a players name by entering their number" << endl;
	cout << endl;

	//Loop for adding players and coaches
	do {
		print = playerOrCoach(Players, Coaches);

	} while (print == false);

	//Print sorted roster when user is done adding players and coaches
	printRoster(Players, Coaches);

	//Loop for searching for players
	do {
		repeat = searchForPlayer(Players);

	} while (repeat == true);

}

//Prints menu asking to add player or coach
bool playerOrCoach(vector<Player>& p, vector<Coach>& c) {
	//Number inputted by user and data validation flag
	int num;
	bool print = false;


		//Menu
		cout << "Would you like to add a player or a coach to the roster?" << endl;
		cout << "--------------------------------------------------------" << endl;
		cout << "1: Player" << endl;
		cout << "2: Coach" << endl;
		cout << "3: Finished/Print Roster" << endl;
		cout << "Enter Number: " << endl;

		//Input
		num = validNumber(3);
		cout << endl;

		//Check input
		switch (num) {
		case 1: 
			addPlayer(p);
			break;
		case 2: 
			addCoach(c);
			break;
		case 3:
			print = true;
			break;
		}

	return print;

}

//Adds player to the roster
void addPlayer(vector<Player>& p) {
	// Create temporary player to add to players vector, and variables
	Player temp;
	string name;
	int number;
	int input;

	//Player name
	cout << "Please enter the players full name: " << endl;
	cin.ignore();
	getline(cin, name);
	temp.setName(name);
	cout << endl;

	//Player number
	cout << "Please enter the players number: " << endl;
	number = validNumber(-1);
	temp.setNum(number);
	cout << endl;

	//Player position
	cout << "Please enter the number corresponding with the players position:" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "1: Attack" << endl;
	cout << "2: Mid-Field" << endl;
	cout << "3: Faceoff" << endl;
	cout << "4: Defense" << endl;
	cout << "5: Goalie" << endl;
	cout << "Enter Number: " << endl;
	input = validNumber(5);
	temp.setPosition(input);
	cout << endl;
	
	//Player year
	cout << "Please enter the number corresponding with the players year:" << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "1: Freshmen" << endl;
	cout << "2: Sophmore" << endl;
	cout << "3: Junior" << endl;
	cout << "4: Senior" << endl;
	cout << "5: Graduate" << endl;
	cout << "Enter Number: " << endl;
	input = validNumber(5);
	temp.setYear(input);
	cout << endl;

	//Add temp to Players vector
	p.push_back(temp);

}

//Adds coach to the roster
void addCoach(vector<Coach>& c) {
	//Create temporary Coach to ass To Coaches vector, and other variables
	Coach temp;
	string name;
	int input;

	//Coach Name
	cout << "Please enter the coaches full name: " << endl;
	cin.ignore();
	getline(cin, name);
	temp.setName(name);
	cout << endl;

	//Coach position
	cout << "Please enter the number corresponding with the Coaches position:" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "1: Head" << endl;
	cout << "2: Assistant" << endl;
	cout << "3: Graduate" << endl;
	cout << "Enter Number: " << endl;
	input = validNumber(3);
	temp.setPosition(input);
	cout << endl;

	//Add temp to Coaches vector
	c.push_back(temp);

}

//Prints roster 
void printRoster(vector<Player>& p, vector<Coach> c) {
	//Sort players
	sortRoster(p);

	cout << "*****************************************************" << endl;
	cout << "*****************************************************" << endl;

	//Print players
	cout << "Players" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << left << setw(20) << "Name" << setw(8) << "Number" << setw(11) << "Year" << setw(10) << "Position" <<endl;
	cout << "-----------------------------------------------------" << endl;
	for (unsigned int i = 0; i < p.size(); i++) {
		p.at(i).printPlayer();
	}

	cout << endl;

	//Print coaches
	cout << "Coaches" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << left << setw(20) << "Name" << "Position" << endl;
	cout << "-----------------------------------------------------" << endl;
	for (unsigned int i = 0; i < c.size(); i++) {
		c.at(i).printCoach();
	}
	cout << "*****************************************************" << endl;
	cout << "*****************************************************" << endl;
	cout << endl;
	cout << endl;
	cout << endl;

}

//Sort roster by number from least to greatest
void sortRoster(vector<Player>& p) {
	//Declare variables
	int minIndex;

	for (unsigned int i = 0; i < p.size(); i++) { 
		minIndex = i;
		for (unsigned int x = 0; x < p.size(); x++) {
			if (p.at(x).getNum() > p.at(minIndex).getNum()) {
				minIndex = x;
			}
			switchSpot(p.at(i), p.at(minIndex));
		}
	}

}

//Switches the place of 2 players on the roster.
void switchSpot(Player& a, Player& b) {
	Player temp;
	temp = a;
	a = b;
	b = temp;
}

//Searches for player by number using a binary serch and returns index
int findPlayer(vector<Player> p, int lower, int upper, int num) {
	while (lower <= upper) {
		//Midpoint 
		int mid = (lower + upper) / 2;

		//Check values
		if (p.at(mid).getNum() == num) {
			return mid;
		}
		if (p.at(mid).getNum() > num) {
			return findPlayer(p, lower, mid - 1, num);
		}
		if (p.at(mid).getNum() < num) {
			return findPlayer(p, mid + 1, upper, num);
		}
	}
	return -1;
}

//Allows user to enter players number and find their name
bool searchForPlayer(vector<Player> p) {
	//Delare variables
	int playerNum;
	int playerIndex;
	int input;
	bool repeat = false;



	cout << "Would you like to search for a player?" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "1: Yes" << endl;
	cout << "2: No" << endl;
	cout << "Enter Number :" << endl;
	input = validNumber(2);
	cout << endl;

	//Check user decision
	switch (input)
	{
	case 1:
		cout << "Please enter a players number to get there name: " << endl;
		playerNum = validNumber(-1);
		playerIndex = findPlayer(p, 0, p.size() - 1, playerNum);
		cout << endl;

		//See if the number entered corresponds to a player
		if (playerIndex == -1) {
			cout << "There is no player with the number " << playerNum << endl;
			cout << endl;
		}
		else {
			cout << playerNum << ":" << " " << p.at(playerIndex).getName() << endl;
			cout << endl;
		}
		repeat = true;

		break;
	case 2:
		cout << "Program will now close" << endl;
		repeat = false;
		break;
	}

	return repeat;
}

//Validates that a user has entered a number, not a char or string 
int validNumber(int max) {
	int x;
	cin >> x;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input, enter a NUMBER: " << endl;
		cin >> x;
	}
	return validMenuNumber(max, x);
}

//Validates if a inputed number for a menu option is to large or small
int validMenuNumber(int max, int num) {
	//If number is valid (A value of -1 for nax means any value is valid
	if (((num >= 1) && (num <= max)) || (max == -1)) {
		return num;
	}
	else
	{
		cout << "Please enter a valid number according to the menu above: " << endl;
		return validNumber(max);
	}
}