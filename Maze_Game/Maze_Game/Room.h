// Author: William Mitchell
// SID: 1610113
// Module: Object Oriented C++

#pragma once
#include <string>
#include <vector>

using namespace std;

//Room Abstract Base Class
class Room
{
	protected:
		string name;

	public:
		//Constructor
		Room(string n);

		//Get & Set
		void setName(string n);
		string getName() const;

		virtual void AddExit(Room* r) = 0;

		virtual int NumberOfExits() const = 0; //Returns the number of exits a room contains
		virtual vector<Room*> getExits() = 0;
};