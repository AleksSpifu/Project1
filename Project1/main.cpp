#include <iostream>
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
/*		Random number:
 
		srand(time(NULL));
		rand() % MAX;
*/

int main() {
	
	bool programFinished = false;
	while (!programFinished) {
		system("cls");

		std::cout << "Welcome to my weeklies! You can select which task you would like to see.\n1. Make a function that converts lower case letters to capitals. Use data type Char.\n";
		std::cout << "2. Make a 10x10 game of chasing the G.\n3. Make a program that can hold names and phone numbers. etc.\n4. Dice tasks.\n5 or Space. Exit the program.\nPlease enter your selection:\n";
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
			//diceTasks();
			break;
		case '5':
			programFinished = true;
			break;
		case ' ':
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
		int number;
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
		std::cout << "Either select a number to view/edit, or hit space to exit.\n";
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
			case ' ':
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
			std::cout << "Press P to edit phone number, N to edit name, or Space to go back\n";
			switch (tolower(_getch()))
			{
			case 'p':
				std::cout << "Please write the new number: ";
				std::cin >> person[selection].number;
				std::cin.clear();
				break;
			case 'n':
				std::cout << "Please write the new name: ";
				std::cin.clear();
				std::cin.ignore(100, '\n');
				std::getline(std::cin, person[selection].name);
				break;
			case ' ':
				selection = 10;
				break;
			default:
				break;
			}
		}
	}

}
