// Author: William Mitchell
// SID: 1610113
// Module: Object Oriented C++

#pragma once
#include "RoomLocked.h"

RoomLocked::RoomLocked(string n, string q, int a) : Room(n)
{
	question = n;
	answer = a;
}

void RoomLocked::setQuestion(string q)
{
	question = q;
}

string RoomLocked::getQuestion() const
{
	return question;
}

void RoomLocked::setAnswer(int a)
{
	answer = a;
}

int RoomLocked::getAnswer() const
{
	return answer;
}

void RoomLocked::setNorth(Room * r)
{
	north = r;
}

Room* RoomLocked::getNorth()
{
	return north;
}

void RoomLocked::setSouth(Room * r)
{
	south = r;
}

Room* RoomLocked::getSouth()
{
	return south;
}

void RoomLocked::setEast(Room * r)
{
	east = r;
}

Room* RoomLocked::getEast()
{
	return east;
}

void RoomLocked::setWest(Room * r)
{
	west = r;
}

Room* RoomLocked::getWest()
{
	return west;
}

int RoomLocked::NumberOfExits() const
{
	int exits = 0;
	if (north != NULL)
		exits++;
	if (south != NULL)
		exits++;
	if (east != NULL)
		exits++;
	if (west != NULL)
		exits++;

		return exits;
}

vector<Room*> RoomLocked::getExits()
{
	vector<Room*> rooms;
	rooms.push_back(north);
	rooms.push_back(south);
	rooms.push_back(east);
	rooms.push_back(west);

	return rooms;
}