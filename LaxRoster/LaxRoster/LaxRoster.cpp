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
int findPlayer(vector<Player>, int, int, int);\
bool searchForPlayer(vector<Player>);


//Main function
int main()
{
	//Declare variables
	vector<Player> Players;
	vector<Coach> Coaches;
	bool print = false;
	bool repeat = false;

	//Loop for adding players and coaches
	do {
		print = playerOrCoach(Players, Coaches);

	} while (print == false);

	//Print roster whn user is done adding players and coaches
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
	bool valid;
	bool print = false;

	//Data validation loop
	do {
		valid = true;

		//Menu
		cout << "Would you like to add a player or a coach to the roster?" << endl;
		cout << "--------------------------------------------------------" << endl;
		cout << "1: Player" << endl;
		cout << "2: Coach" << endl;
		cout << "3: Finished/Print Roster" << endl;
		cout << "Enter Number: " << endl;

		//Input
		cin >> num;
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
		default :
			cout << "The number you entered was incorrect, please try again." << endl;
			cout << endl;
			valid = false;
		}

	} while (valid == false);

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
	cin >> number;
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
	cin >> input;
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
	cin >> input;
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
	cin >> input;
	temp.setPosition(input);
	cout << endl;

	//Add temp to Coaches vector
	c.push_back(temp);

}

//Prints roster 
void printRoster(vector<Player>& p, vector<Coach> c) {
	//Sort players
	sortRoster(p);

	//Print players
	cout << "Players" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << left << setw(20) << "Name" << setw(8) << "Number" << setw(8) << "Year" << setw(10) << "Position" <<endl;
	cout << "-----------------------------------------------------" << endl;
	for (int i = 0; i < p.size(); i++) {
		p.at(i).printPlayer();
	}

	cout << endl;

	//Print coaches
	cout << "Coaches" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << left << setw(20) << "Name" << "Position" << endl;
	cout << "-----------------------------------------------------" << endl;
	for (int i = 0; i < c.size(); i++) {
		c.at(i).printCoach();
	}
	cout << endl;
	cout << endl;
	cout << endl;

}

//Sort roster by number from least to greatest
void sortRoster(vector<Player>& p) {
	//Declare variables
	int minIndex;

	for (int i = 0; i < p.size(); i++) { 
		minIndex = i;
		for (int x = 0; x < p.size(); x++) {
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

//Allows user to enter players number and find there name
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
	cin >> input;
	cout << endl;

	//Check user decision
	switch (input)
	{
	case 1:
		cout << "Please enter a players number to get there name: " << endl;
		cin >> playerNum;
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
	default:
		cout << "Invalid entry, please try again" << endl;
		cout << endl;
		repeat = true;
		break;
	}

	return repeat;
}