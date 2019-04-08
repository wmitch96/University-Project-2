// Author: William Mitchell
// SID: 1610113
// Module: Object Oriented C++

#pragma once
#include "room.h"

using namespace std;

class RoomLocked : public Room
{
	private:
		bool locked; //Is the room locked
		string question; //The question asked to unlock the room
		int answer; //The requried answer to unlock the room 

		Room* north;
		Room* east;
		Room* south;
		Room* west;

	public:
		RoomLocked(string n, string q, int a);

		void setQuestion(string q);
		string getQuestion() const;

		void setAnswer(int a);
		int getAnswer() const;

		void setNorth(Room* r);
		Room* getNorth();

		void setSouth(Room* r);
		Room* getSouth();

		void setEast(Room* r);
		Room* getEast();

		void setWest(Room* r);
		Room* getWest();

		virtual int NumberOfExits() const;
		virtual vector<Room*> getExits();
};