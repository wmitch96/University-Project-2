// Author: William Mitchell
// SID: 1610113
// Module: Object Oriented C++

#pragma once
#include "InterfaceManager.h"

using namespace std;

Maze* InterfaceManager::MainMenu()
{
	string mazeName;
	bool selected = false;
	bool firstLoad = true;

	while (selected == false)
	{
		system("CLS");
		cout << "Welcome to Maze Game!" << endl << endl;

		cout << "Modes:" << endl;
		cout << "1) Basic Maze" << endl;
		cout << "2) Random Maze" << endl;
		cout << "3) Load Maze from .txt File" << endl;
		cout << "4) Load Maze from .xml File" << endl;
		cout << "5) Close the game" << endl << endl;

		if (!firstLoad)
		{
			cout << "That is not a valid input, please try again." << endl;
		}
		firstLoad = false;

		cout << "Which mode do you wish to play?: ";
		char input;
		cin >> input;
		
		
		/*-----Supporting Documentation (if else vs switch)-----*/
		if (input == '1') //Fixed Maze
		{
			selected = true;
			return InputFixedMaze();
		}
		else if (input == '2') //Random Maze
		{
			selected = true;
			return InputRandomMaze();
		}
		else if (input == '3') //.txt File Maze
		{
			selected = true;
			return InputFileMaze(false);
		}
		else if (input == '4') //.xml File Maze
		{
			selected = true;
			return InputFileMaze(true);
		}
		else if (input == '5') //Quit
		{
			selected = true;
			exit(0); // Close the application
		}
	}
}

void InterfaceManager::DisplayRoomExits(bool simpleMode, Room* r, Maze* maze)
{
	system("CLS");
	vector<Room*> exits;
	if (simpleMode) //If using north, south, east, west
	{
		cout << "(N)orth exit" << endl;
		cout << "(S)outh exit" << endl;
		cout << "(E)ast exit" << endl;
		cout << "(W)est exit" << endl;
	}
	else
	{
		cout << "You have entered " << r->getName() << " The following exits are avaliable" << endl << endl;
		bool exitChosen = false;
		while (exitChosen == false)
		{
			exits = r->getExits();
			if (exits.size() > 0) //If the Room has exits to display (should be all the time in a fully functional maze, the check is here mainly for user generated maze files)
			{
				for (int i = 0; i < exits.size(); i++)
				{
					cout << i+1 << ") Exit to " << exits[i]->getName() << endl;
				}

				//Choose exit
				int exit;
				cout << endl << "Which exit do you wish to take?: ";
				while (!(cin >> exit) || exit > exits.size()) //If the given value is not an intager or is greater than the number of exits, ask again for a valid input
				{
					system("CLS");
					cout << "You have entered " << r->getName() << " The following exits are avaliable" << endl << endl;
					for (int i = 0; i < exits.size(); i++)
					{
						cout << i + 1 << ") Exit to " << exits[i]->getName() << endl;
					}
					cout << endl << "Invalid Input, please try again! Which exit do you wish to take?: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				exitChosen = true;
				Room* exitRoom = &*exits[exit - 1];				
				maze->setCurrentRoom(exitRoom); //Moves the user to the selected room
			}
			else //If the room has no exits: display an error message and close the application
			{
				cout << "An error has occured and this room has no exits!" << endl;
				cout << "If the maze was loaded with a file, please check the file for errors!" << endl;
				cout << "The game will now exit." << endl;
				exit(0);
			}
		}
	}
}

Maze* InterfaceManager::InputFixedMaze()
{
	string mazeName;
	system("CLS");
	cout << "What do you wish to call this maze ?" << endl;
	cin >> mazeName;
	return new MazeFixed(mazeName);
}

Maze* InterfaceManager::InputRandomMaze()
{
	string mazeName;
	int min, max, dif;

	//Name
	system("CLS");
	cout << "What do you wish to call this maze ?" << endl;
	cin >> mazeName;

	//Minimum Rooms
	system("CLS");
	cout << "What is the minimum number of rooms you would like the maze to contain? (recommended to be over 15, can go as low as 10)" << endl;
	while (!(cin >> min) || min < 10)  //Makes sure the input is an int that is larger than very minimum number of 2.
	{
		system("CLS");
		cout << "Invalid input please try again!" << endl << "What is the minimum number of rooms you would like the maze to contain? (recommended to be over 15 but can be as low as 10)" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	//Maximum Rooms
	system("CLS");
	cout << "What is the maximum number of rooms you would like the maze to contain? (recommended to be under 50 but can go up to 100) (minimum = " << min << ")" << endl;
	while (!(cin >> max) || max < min || max > 100)  //Makes sure the input is an int that is larger than very minimum number of 2.
	{
		system("CLS");
		cout << "Invalid input please try again!" << endl << "What is the maximum number of rooms you would like the maze to contain? (recommended to be under 50 but can go up to 100) (minimum = " << min << ")" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	//Difficulty
	system("CLS");
	cout << "How difficult do you want the maze to be? (1 = Easiest | 7 = Hardest)" << endl;
	while (!(cin >> dif) || dif < 1 || dif > 7)  //Makes sure the input between 1-7
	{
		system("CLS");
		cout << "Invalid input please try again!" << endl << "How difficult do you want the maze to be? (1 = Easiest | 7 = Hardest)" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return new MazeRandom(mazeName, dif, min, max);
}

Maze* InterfaceManager::InputFileMaze(bool xml)
{
	string mazeName;
	system("CLS");
	cout << "What do you wish to call this maze ?" << endl;
	cin >> mazeName;
	if (xml)
	{
		return new MazeFile(mazeName, "Maze1.xml", xml);
	}
	else
	{
		return new MazeFile(mazeName, "Maze1.txt", xml);
	}
}