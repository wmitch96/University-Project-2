// Author: William Mitchell
// SID: 1610113
// Module: Object Oriented C++

#pragma once
#include <vector>
#include "Room.h" //Includes Room, RoomNormal, RoomLocked, string

using namespace std;

//Maze Abstract Base Class
class Maze
{
	protected:
		string name;

		Room* start;
		Room* currentRoom;
		Room* end;

		vector<Room*> history;

	public:
		Maze(string n);

		void setName(string n);
		string getName() const;

		void setStart(Room* r);
		Room* getStart();

		void setCurrentRoom(Room* r);
		Room* getCurrentRoom();

		void setEnd(Room* r);
		Room* getEnd();

		void AddToHistory(Room* r);
		vector<Room*> getHistory();

		virtual vector<Room*> CreateRooms() = 0;
};