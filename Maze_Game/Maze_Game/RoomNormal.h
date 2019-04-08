// Author: William Mitchell
// SID: 1610113
// Module: Object Oriented C++

#pragma once
#include "room.h"

using namespace std;

class RoomNormal : public Room
{
	private:
		vector<Room*> exits;

	public:
		RoomNormal(string n);
		virtual void AddExit(Room* exit);

		virtual int NumberOfExits() const;
		vector<Room*> getExits();
};