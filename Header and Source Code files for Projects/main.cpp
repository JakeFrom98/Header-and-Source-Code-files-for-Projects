#include "pch.h"
#include <string>
#include <iostream>
#include "story1.h"
#include <cstdlib>

using namespace std;

// Global Variables
int sanity = 3;
int amount_of_sanity_potion = 0;
int win = 0;

// Declared Functions
void story3(); 
void story2(); 
void story1(); 

int main() // Main function
{
	string player_name; // Stores player name into a string
	cout << "Hello! What is your name? ";
	cin >> player_name;
rerun:
	system("cls");
	cout << "Welcome " << player_name << " to Insanity!" << endl;
	system("pause");
	system("cls");
	cout << "Insanity is a text based horror game.\n";
	system("cls");
	cout << "In this game you will have something called sanity if your sanity reaches 0 you will die. \n";
	cout << "You will lose sanity throughout the game.\n";
	system("pause");
	system("cls");
	cout << "Good luck and don't die!\n";
	system("pause");
	story1(); // Call story1 function

	if (sanity > 0) // Check to make sure player has sanity before continuing to story function 2
	{
		story2(); // Go to story function 2
	}

	if (sanity > 0) // Check to make sure player has sanity before continuing to story function 3
	{
		story3(); // Go to story function 2
	}

	if (sanity <= 0) // if sanity is less than or equal to 0 tell user they died
	{
		string answer; // Stores player name in a string
		system("cls");
		cout << "Your sanity reached 0" << " you died!\n";
		cout << "Would you like to try again? y/n\n";
		cin >> answer;

		if (answer == "y" || answer == "Y") // If user input y rerun code
		{
			system("cls");
			++sanity; // Add one to sanity 
			++sanity; // Add one to sanity 
			++sanity; // Add one to sanity 
			goto rerun; // Go to rerun
		}
		else if (answer == "n" || answer == "N") // if user inputs n quite game
		{
			system("cls");
			cout << "Thank you for playing " << player_name << endl;
			cout << "\nPress enter to quit the game.\n";
			exit(0); // closes application
		}
	}

	if (win == 1) // if win variable = 1 congratulate the user on winning the game
	{
		system("cls");
		cout << "Congratulations " << player_name << " you won the game!";
		cout << "\nPress enter to quit the game.\n";
		system("pause");
		exit(0); // closes application
	}
}



void story2() // Second story function
{
	// Variables
	int items = 2;
	int map = 0;
	int leave_room = 1;

	cout << "Now that your sanity is back to normal you look around the room and see a few things.\n";

	while (items != 0) // while times doesn't equal 0
	{
		cout << "You see another vile that says sanity potion, what looks like to be a map, and a door.\n";
		cout << "What would you like to do? \n";

		string answer; // String variable
		getline(cin, answer); // Gets whole line

		if ((answer == "grab sanity potion" || answer == "Grab sanity potion") && (amount_of_sanity_potion < 1)) // Checks if user input equals string and if the variable amount_of_sanity_potion is < 1
		{
			cout << "You grabbed some sanity potion!\n";
			++amount_of_sanity_potion; // adds one to amount_of_sanity_potion variable
			--items; // minuses one from items
			system("pause");
			system("cls");
		}

		else if ((answer == "grab sanity potion" || answer == "Grab sanity potion") && amount_of_sanity_potion == 1) // Checks if the user input equals string and if the variable amount_of_sanity_potion equals one
		{
			cout << "You already grabbed the sanity potion!\n";
			system("pause");
			system("cls");
		}

		else if ((answer == "grab the map" || answer == "Grab the map") && map < 1) // checks if the user input equals string and if the variable map < 1
		{
			cout << "You grabbed a map!\n";
			cout << "The map tells you that there is only one room left and an exit.\n";
			--items; // adds one to items variables
			++map; // ads one to map variable
			system("pause");
			system("cls");
		}

		else if ((answer == "grab the map" || answer == "Grab the map") && map == 1) // checks if the user input equals string and if the variable map equals 1
		{
			cout << "You already grabbed a map!\n";
			system("pause");
			system("cls");
		}

		else if ((answer == "leave the room" || answer == "Leave the room") && leave_room == 0) // checks if the user input equals string and if the variable leave_room equals 0
		{
			cout << "You cant leave yet!\n";
			cout << "hint something to tell directions might be nice.\n";
			system("pause");
			system("cls");
		}

		else if ((answer == "leave the room" || answer == "Leave the room") && leave_room == 1) // checks if the user input equals string and if the variable leave_room equals 1
		{
			cout << "You cant leave yet!\n";
			cout << "Hint something to tell directions and to help with your sanity might be useful.\n";
			system("pause");
			system("cls");
		}

		else // If the user inputs an unknown string
		{
			cout << ("I'm sorry I didn't understand that...\n");
			system("pause");
			system("cls");
		}
	}
}

void story3() { // Third Story Function

	int options = 0; // Variable for While loop

	while (options == 0) // While loop
	{
		cout << "Would you like to check the last room or go to the exit? ";

		string answer; // String variable

		getline(cin, answer); // Gets whole line
		if ((answer == "check the last room" || answer == "Check the last room")) // Checks users input and if user input equals string 
		{
			cout << "You got jumped and you lost your sanity causing you to die.\n";
			system("pause");
			--sanity; // minuses one from sanity
			--sanity; // minuses one from sanity
			--sanity; // minuses one from sanity
			++options; // adds one to sanity
		}

		else if ((answer == "Go to the exit" || answer == "go to the exit")) // Checks users input and if user input equals string
		{
			++options; // adds one to options
			++win; // adds one to win
		}

		else // if the user inputs anything else display this message
		{
			cout << ("I'm sorry I didn't understand that...\n");
			system("pause");
			system("cls");
		}
	}
}