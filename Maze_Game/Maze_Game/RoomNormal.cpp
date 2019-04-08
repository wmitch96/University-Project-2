// Author: William Mitchell
// SID: 1610113
// Module: Object Oriented C++

#pragma once
#include "RoomNormal.h"

RoomNormal::RoomNormal(string n): Room(n)
{

}

void RoomNormal::AddExit(Room* exit)
{
	exits.push_back(exit);
}

int RoomNormal::NumberOfExits() const
{
	return exits.size();
}

vector<Room*> RoomNormal::getExits()
{
	return exits;
}
