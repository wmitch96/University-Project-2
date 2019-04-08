// Author: William Mitchell
// SID: 1610113
// Module: Object Oriented C++

#pragma once
#include "Maze.h"
#include "InterfaceManager.h"

Maze::Maze(string n)
{
	name = n;
}

void Maze::setName(string n)
{
	name = n;
}

string Maze::getName() const
{
	return name;
}

void Maze::setStart(Room* r)
{
	start = r;
}

Room* Maze::getStart()
{
	return start;
}

void Maze::setCurrentRoom(Room* r)
{
	if (r != end)
	{
		currentRoom = r;
		AddToHistory(r);
		InterfaceManager::DisplayRoomExits(false, currentRoom, this);
	}
	else
	{
		system("CLS");
		cout << "Congradulations, you have reached the end!" << endl << endl;;
		cout << "It took you the following (" << getHistory().size() << ") Moves:" << endl;
		for (Room* step : getHistory())
		{
			cout << step->getName() << endl;
		}

		cout << endl << "You will now be returned to the main menu" << endl << endl;
		system("pause");
		InterfaceManager::MainMenu();
	}

}

Room* Maze::getCurrentRoom()
{
	return currentRoom;
}

void Maze::setEnd(Room* r)
{
	end = r;
}

Room* Maze::getEnd()
{
	return end;
}

void Maze::AddToHistory(Room* r)
{
	history.push_back(r);
}

vector<Room*> Maze::getHistory()
{
	return history;
}
