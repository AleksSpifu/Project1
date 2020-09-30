#include <iostream> //You know, for input and output.
#include <vector>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string>

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
	while (userInput.size() < 1) {
		std::getline(std::cin, userInput);
	}
	
	for (int i = 0; i < userInput.size(); i++) {
		output.push_back(userInput.at(i));
		output[i] = toupper(output[i]);
		std::cout << output[i];
	}
	std::cout << "\n";
	system("pause");
}

void task2() {
	srand(time(NULL));
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
	std::vector <std::vector <char>> board(boardSize, std::vector<char>(boardSize, ' '));
	bool changed = true;
	bool finished = false;
	while (!finished) {
		if (changed) {
			system("cls");
			std::cout << "-------------------------------------------\n";
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
					std::cout << " | " << board[r][c];
				}
				std::cout << " |\n";
				std::cout << "-------------------------------------------\n";
			}
			srand(time(NULL));
			if ((rand() % 100) > 50) {
				targetRow = targetRow + (rand() % 2) - 1;
				if (targetRow == -1) {
					targetRow = 9;
				}
				else if (targetRow == 10) {
					targetRow = 0;
				}
			}
			else {
				targetCol = targetCol + (rand() % 2) - 1;
				if (targetCol == -1) {
					targetCol = 9;
				}
				else if (targetCol == 10) {
					targetCol = 0;
				}
			}
		}
		changed = false;
		if (finished) {
			break;
		}
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
		if (peiceRow == targetRow && peiceCol == targetCol) {
			finished = true;
		}
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
	system("cls");
	std::cout << "Congratulations, you beat the ominous G! You are the real G!\n";
	system("pause");
}

void task3() {
	struct people {
		std::string name;
		int number = 0;
	};
	std::vector <people> person(10);
	std::cout << "List of all people: \n";
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
	bool finishedWithTask = false;
	while (!finishedWithTask) {
		system("cls");
		int longestName = 0;
		for (int i = 0; i < person.size(); i++) {
			std::string temp = person[i].name;
			if (temp.size() > longestName) {
				longestName = temp.size();
			}
		}
		for (int i = 0; i < person.size(); i++) {
			std::cout << i << ". ";
			if (person[i].name.size() > 0) {
				std::string temp = person[i].name;
				std::cout << person[i].name;
				for (int i = (longestName + 4); i > temp.size(); i--) {
					std::cout << " ";
				}
				std::cout << person[i].number << "\n";
			}
			else {
				std::cout << "Empty.\n";
			}
		}
		std::cout << "Either select a number to view/edit, or hit escape to exit.\n";
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
		while (selection >= 0 && selection <= 9) {
			system("cls");
			std::cout << "Name: " << person[selection].name << "\nNumber: " << person[selection].number << "\n";
			std::cout << "Press P to edit phone number, N to edit name, or Escape to go back\n";
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
	int MaxDi = 5;
	std::string spacer = "   ";
	std::vector <int> dice(MaxDi, 0);
	std::vector <int> heldDice(MaxDi, 0);
	bool holdingDice = false;
	bool rolled = false;
	
	bool doneWithTask = false;
	while (!doneWithTask) {
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
		if (rolled) {
			std::cout << "Press H to hold dice.\n";
			checkForSixesAndPairs(dice);
		}
		if (!doneWithTask && dice[0] != 0) {
			if (rolled) {
				std::cout << "\n";
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
	while (!finished) {
		system("cls");
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
	srand(time(NULL));
	for (int i = 0; i < diceVec.size(); i++) {
		if (hold[i] == 0) {
			diceVec[i] = (rand() % 6) + 1;
		}
	}
}

void checkForSixesAndPairs(std::vector <int>& diceVec) {
	std::vector <int> diceChecks(7, 0);
	for (int i = 0; i < diceVec.size(); i++) {
		diceChecks[diceVec[i]]++;
	}
	std::cout << "You have " << diceChecks[6] << " six";
	if (diceChecks[6] > 1 || diceChecks[6] == 0) {
		std::cout << "es.\n";
	}
	else {
		std::cout << ".\n";
	}
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
