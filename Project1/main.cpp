//Written by Aleksander Spikkerud Furnes

#include <iostream> 
#include <vector>
#include <string>
#include <conio.h> //For _getch()
#include <stdlib.h> //for random number
#include <time.h> //for seed for random number
#include <stdio.h> //For NULL for random number

//Declare all functions beforehand
void task1();
void task2();
void task3();
void diceTasks();
void rollDice(std::vector <int>& diceVec, std::vector <int>& hold);
void holdDice(std::vector <int>& diceVec, std::vector <int>& hold, int MaxDi);
void checkForSixesAndPairs(std::vector <int>& diceVec);


int main() {
	
	bool programFinished = false; 
	while (!programFinished) {
		system("cls");
		std::cout << "Welcome to my weeklies! You can select which task you would like to see.\n1. Make a function that converts lower case letters to capitals. Use data type Char.\n";
		std::cout << "2. Make a 10x10 game of chasing the G.\n3. Make a program that can hold names and phone numbers. etc.\n4. Dice tasks.\n5 or Escape. Exit the program.\nPlease enter your selection:\n";
		//This is just a menu.
		switch (_getch()) {
		case '1':
			task1();
			break;
		case '2':
			task2();
			break;
		case '3':
			task3();
			break;
		case '4':
			diceTasks();
			break;
		case '5':
			programFinished = true;
			break;
		case 27:
			programFinished = true;
			break;
		default:
			break;
		}
	}
}

void task1() {
	system("cls");
	std::string userInput = "";
	std::vector <char> output;
	std::cout << "Please enter what you want, and everything will be converted to a capital letter.\n";
	std::cin.clear();
	//Get user input
	if (userInput.size() < 1) {
		std::getline(std::cin, userInput);
	}
	//Convert to char vector and print at the same time
	for (int i = 0; i < userInput.size(); i++) {
		output.push_back(userInput.at(i));
		output[i] = toupper(output[i]);
		std::cout << output[i];
	}
	std::cout << "\n";
	system("pause");
}

void task2() {
	//Make sure the seed for the random number generator is set.
	srand(time(NULL));

	//Set all the pieces at random locations. 
	int peiceRow = rand() % 10;
	int peiceCol = rand() % 10;
	int targetRow = rand() % 10;
	int targetCol = rand() % 10;
	struct ladders
	{
		int Row = rand() % 10;
		int Col = rand() % 10;
	};
	ladders ladderUp;
	ladders ladderDown;
	const int boardSize = 10;

	//Make a 2d array that will hold all the characters
	std::vector <std::vector <char>> board(boardSize, std::vector<char>(boardSize, ' '));

	//These make sure the board only updates if something changed, and also just keeps it running until the player wins.
	bool changed = true;
	bool finished = false;

	while (!finished) {
		if (changed) {
			system("cls");

			//Print the top part manually
			std::cout << "-------------------------------------------\n";

			//Make sure the vector has updated values, then print it out
			for (int r = 0; r < board.size(); r++) {
				for (int c = 0; c < board[r].size(); c++) {
					if (r == peiceRow && c == peiceCol) {
						board[r][c] = '*';
					}
					else if (r == targetRow && c == targetCol) {
						board[r][c] = 'G';
					}
					else if (r == ladderUp.Row && c == ladderUp.Col) {
						board[r][c] = '\\';
					}
					else if (r == ladderDown.Row && c == ladderDown.Col) {
						board[r][c] = '/';
					}
					else {
						board[r][c] = ' ';
					}

					//All of the above update the board, this is where it gets printed. 
					std::cout << " | " << board[r][c];
				}

				//After every row, add a line on the end and start a new one. Also print the lines between the rows.
				std::cout << " |\n";
				std::cout << "-------------------------------------------\n";
			}
			srand(time(NULL));

			//There is a 50 percent chance of the G moving in the X direction, and 50 percent chance of moving in the Y direction.
			//Whichever it selects, it either moves +1, -1 or 0. So there is always a 33 percent chance of not moving at all. 
			//This is so the player can actually catch it.
			if ((rand() % 100) > 50) {
				targetRow = targetRow + (rand() % 3) - 1;
				if (targetRow == -1) {
					targetRow = 9;
				}
				else if (targetRow == 10) {
					targetRow = 0;
				}
			}
			else {
				targetCol = targetCol + (rand() % 3) - 1;
				if (targetCol == -1) {
					targetCol = 9;
				}
				else if (targetCol == 10) {
					targetCol = 0;
				}
			}
		}

		//Reset changed so it won't re-print the board until the user presses a new key.
		changed = false;

		//If the player has won, don't bother waiting for the next input.
		if (finished) {
			break;
		}

		//Get next input and move the piece accordingly.
		switch (_getch())
		{
		case 'w':
			if (peiceRow == 0) {
				peiceRow = 9;
			}
			else peiceRow--;
			changed = true;
			break;
		case 's':
			if (peiceRow == 9) {
				peiceRow = 0;
			}
			else peiceRow++;
			changed = true;
			break;
		case 'a':
			if (peiceCol == 0) {
				peiceCol = 9;
			}
			else peiceCol--;
			changed = true;
			break;
		case 'd':
			if (peiceCol == 9) {
				peiceCol = 0;
			}
			else peiceCol++;
			changed = true;
			break;
		default:
			changed = false;
			break;
		}

		//If the player is on top of the G, the game is finished.
		if (peiceRow == targetRow && peiceCol == targetCol) {
			finished = true;
		}

		//If the player hits one of the ladders, move either up or down.
		else if (peiceRow == ladderUp.Row && peiceCol == ladderUp.Col) {
			if (peiceRow == 0) {
				peiceRow = 9;
			}
			else peiceRow--;
			ladderUp.Row = rand() % 10;
			ladderUp.Col = rand() % 10;
		}
		else if (peiceRow == ladderDown.Row && peiceCol == ladderDown.Col) {
			if (peiceRow == 9) {
				peiceRow = 0;
			}
			else peiceRow++;
			ladderDown.Row = rand() % 10;
			ladderDown.Col = rand() % 10;
		}
	}

	//After the player wins, clear the screen and give a hopeful message.
	system("cls");
	std::cout << "Congratulations, you beat the ominous G! You are the real G!\n";
	system("pause");
}

void task3() {
	//Make a struct with the information
	struct people {
		std::string name;
		int number = 0;
	};
	
	//Then make a vector with that struct for the 10 people
	std::vector <people> person(10);
	std::cout << "List of all people: \n";

	//Populate the first 5 spots to see what it looks like.
	for (int i = 0; i < 5; i++) {
		switch (i)
		{
		case 0:
			person[i].name = "Tony Stark";
			person[i].number = 92058395;
			break;
		case 1:
			person[i].name = "Steve Rodgers";
			person[i].number = 29543483;
			break;
		case 2:
			person[i].name = "Bruce Banner";
			person[i].number = 34958732;
			break;
		case 3:
			person[i].name = "Peter Parker";
			person[i].number = 85838959;
			break;
		case 4:
			person[i].name = "Clint Barton";
			person[i].number = 39958399;
			break;

		default:
			break;
		}

	}

	//Run until the user exits
	bool finishedWithTask = false;
	while (!finishedWithTask) {
		system("cls");

		//Check for the longest name, in order to still leave some space for the phone numbers, and have them line up.
		int longestName = 0;
		for (int i = 0; i < person.size(); i++) {
			std::string temp = person[i].name;
			if (temp.size() > longestName) {
				longestName = temp.size();
			}
		}

		//Print out the names, and their number
		for (int i = 0; i < person.size(); i++) {
			std::cout << i << ". ";
			if (person[i].name.size() > 0) {
				std::string temp = person[i].name;
				std::cout << person[i].name;

				//Leave enough space so even the longest name fits, and the numbers line up.
				for (int i = (longestName + 4); i > temp.size(); i--) {
					std::cout << " ";
				}

				//Then print the numbers on the same line.
				std::cout << person[i].number << "\n";
			}

			//If there is no name, print empty
			else {
				std::cout << "Empty.\n";
			}
		}
		std::cout << "Either select a number to view/edit, or hit escape to exit.\n";

		//Set a bool to make sure the user enters a valid input, 
		//and also set selection outside the range of where it can be, in order to not get a warning but not give any false positive choices.
		bool acceptedInput = false;
		int selection = 10;

		while (!acceptedInput) {
			switch (_getch()) {
			case '0':
				selection = 0;
				acceptedInput = true;
				break;
			case '1':
				selection = 1;
				acceptedInput = true;
				break;
			case '2':
				selection = 2;
				acceptedInput = true;
				break;
			case '3':
				selection = 3;
				acceptedInput = true;
				break;
			case '4':
				selection = 4;
				acceptedInput = true;
				break;
			case '5':
				selection = 5;
				acceptedInput = true;
				break;
			case '6':
				selection = 6;
				acceptedInput = true;
				break;
			case '7':
				selection = 7;
				acceptedInput = true;
				break;
			case '8':
				selection = 8;
				acceptedInput = true;
				break;
			case '9':
				selection = 9;
				acceptedInput = true;
				break;
			case 27:
				acceptedInput = true;
				finishedWithTask = true;
				break;
			default:
				acceptedInput = false;
				break;
			}
		}

		//This is a failsafe to make sure the initialization of "selection = 10" doesn't screw with any vectors.
		//Also it's a way to make sure it runs until the user is done changing the name and number. When the user is done, i change it back to 10.
		while (selection >= 0 && selection <= 9) {
			system("cls");
			std::cout << "Name: " << person[selection].name << "\nNumber: " << person[selection].number << "\n";
			std::cout << "Press P to edit phone number, N to edit name, or Escape to go back\n";

			//This is pretty straight forward. I got some bugs unless i used cin.ignore(32767, '\n'); but i don't really know what 32767 is for. 
			//It works now, though.
			switch (tolower(_getch()))
			{
			case 'p':
				std::cout << "Please write the new number: ";
				std::cin >> person[selection].number;
				std::cin.ignore(32767, '\n');
				std::cin.clear();
				break;
			case 'n':
				std::cout << "Please write the new name: ";
				
				std::getline(std::cin, person[selection].name);
				break;
			case 27:
				selection = 10;
				break;
			default:
				break;
			}
		}
	}

}

void diceTasks() {
	//initialize some variables.
	int MaxDi = 5;
	std::string spacer = "   ";
	std::vector <int> dice(MaxDi, 0);
	std::vector <int> heldDice(MaxDi, 0);

	//The user hasn't rolled yet, and is not holding any dice.
	bool holdingDice = false;
	bool rolled = false;
	
	//Once again, run until the user exits.
	bool doneWithTask = false;
	while (!doneWithTask) {

		//Update if the program detects any variables that aren't default. This is to stop it printing stuff until it is relevant. 
		for (int i = 0; i < dice.size(); i++) {
			if (dice[i] != 0) {
				rolled = true;
			}
			if (heldDice[i] != 0) {
				holdingDice = true;
			}
		}
		system("cls");
		std::cout << "Welcome to the dice thing. \nPress enter to roll new dice, or Escape to go back.\n";

		//only print this if the user has rolled already.
		if (rolled) {
			std::cout << "Press H to hold dice.\n";
			checkForSixesAndPairs(dice);
		}
		//Make sure the user hasn't exited already, and check again if a roll has been made.
		if (!doneWithTask && dice[0] != 0) {
			if (rolled) {
				std::cout << "\n";

				//Print the numbers with some spaces, add an H if the dice is being held.
				for (int i = 0; i < dice.size(); i++) {
					std::cout << spacer;
					std::cout << dice[i];
					if (dice[i] == heldDice[i]) {
						std::cout << "H ";
					}
					else
					{
						std::cout << "  ";
					}
					std::cout << spacer;
				}

				//Then print the number of the dice.
				std::cout << "\n";
				for (int i = 0; i < MaxDi; i++) {
					std::cout << "Dice " << i;
					if ((i + 1) != MaxDi) {
						std::cout << ",  ";
					}
					else {
						std::cout << "\n";
					}
				}
				std::cout << "\n";
			}
		}

		//Ask the user what they want to do.
		switch (tolower(_getch()))
		{
		case '\r':
			rollDice(dice, heldDice);
			doneWithTask = false;
			break;
		case 27:
			doneWithTask = true;
			break;
		case 'h':
			holdDice(dice, heldDice, MaxDi);
			break;
		default:
			break;
		}
		
		
	}
	
}

void holdDice(std::vector <int>& diceVec, std::vector <int>& hold, int MaxDi) {
	std::string spacer = "   ";
	bool finished = false;

	//Once again wait until the user exits.
	while (!finished) {
		system("cls");

		//Print out the currently active dice rolls
		std::cout << "Which dice would you like to hold? Or press Escape or Enter to finish holding.\n";
		std::cout << "\n";
		for (int i = 0; i < diceVec.size(); i++) {
			std::cout << spacer;
			std::cout << diceVec[i] << "  ";
			std::cout << spacer;
		}
		std::cout << "\n";
		for (int i = 0; i < MaxDi; i++) {
			std::cout << "Dice " << i;
			if ((i + 1) != MaxDi) {
				std::cout << ",  ";
			}
			else {
				std::cout << "\n";
			}
		}

		//And print out the dice that are currently being held.
		std::cout << "\n";
		std::cout << "Dice currently held: ";
		for (int i = 0; i < hold.size(); i++) {
			if (hold[i] != 0) {
				std::cout << "Dice #" << i << ", " << hold[i];
				if (i + 1 == hold.size()) {
					std::cout << "\n";
				}
				else 
				{
					std::cout << ". ";
				}
			}
		}

		//Get input from user. If they select a correct number, the dice roll will be saved. 
		//If they select the same number again, it will be un-held for lack of a better name for it. 
		//It will no longer be saved.
		int holdSelection = -1;
		switch (tolower(_getch()))
		{
		case '0':
			if (diceVec[0] == hold[0]) {
				hold[0] = 0;
			}
			else {
				hold[0] = diceVec[0];
			}
			break;
		case '1':
			if (diceVec[1] == hold[1]) {
				hold[1] = 0;
			}
			else {
				hold[1] = diceVec[1];
			}
			break;
		case '2':
			if (diceVec[2] == hold[2]) {
				hold[2] = 0;
			}
			else {
				hold[2] = diceVec[2];
			}
			break;
		case '3':
			if (diceVec[3] == hold[3]) {
				hold[3] = 0;
			}
			else {
				hold[3] = diceVec[3];
			}
			break;
		case '4':
			if (diceVec[4] == hold[4]) {
				hold[4] = 0;
			}
			else {
				hold[4] = diceVec[4];
			}
			break;
		case '\r':
			finished = true;
			break;
		case 27:
			finished = true;
			break;
		default:
			break;
		}	
	}
	
}

void rollDice(std::vector <int>& diceVec, std::vector <int>& hold) {

	//This just populates the dice vector with random numbers between 1 and 6.
	srand(time(NULL));
	for (int i = 0; i < diceVec.size(); i++) {
		if (hold[i] == 0) {
			diceVec[i] = (rand() % 6) + 1;
		}
	}
}

void checkForSixesAndPairs(std::vector <int>& diceVec) {
	//Make a vector where the index is the roll of the dice, and the value is the amount. So if you had 5 fours, it would look like this:
	//{0, 0, 0, 0, 5, 0, 0}. The size is 7 because the first one, 0, is still there. It is not being used, it's there to make it easier for me.
	//This is easier than remembering to do -1 all the time. It's lazy but i like to think of it as mentally efficient! :P
	std::vector <int> diceChecks(7, 0);

	//Whatever the current dice roll is (diceVec[i]) is the position in which this will add one. This is to count how many of each number there are.
	for (int i = 0; i < diceVec.size(); i++) {
		diceChecks[diceVec[i]]++;
	}

	//Step one, print how many sixes there are, easy peezy
	std::cout << "You have " << diceChecks[6] << " six";
	if (diceChecks[6] > 1 || diceChecks[6] == 0) {
		std::cout << "es.\n";
	}
	else {
		std::cout << ".\n";
	}

	//Then check if there is one two or (if you increase maximum dice) three pairs, then print this. 
	for (int i = 0; i <= diceVec.size(); i++) {
		if (diceChecks[i] >= 2 && diceChecks[i] < 4) {
			std::cout << "You have a pair of " << i << ".\n";
		}
		else if (diceChecks[i] >= 4 && diceChecks[i] < 6) {
			std::cout << "You have two pairs of " << i << ".\n";
		}
		else if (diceChecks[i] == 6) {
			std::cout << "You have three pairs of " << i << ".\n";
		}
	}
}
//That's it. Thank you for your time!