// Author: William Mitchell
// SID: 1610113
// Module: Object Oriented C++

#pragma once
#include "MazeFixed.h"

MazeFixed::MazeFixed(string n) : Maze(n)
{
	vector<Room*> r = CreateRooms();
	setStart(r[0]);
	setEnd(r[14]);
	setCurrentRoom(r[0]);
}

vector<Room*> MazeFixed::CreateRooms()
{
	vector<Room*> rooms;
	rooms.push_back(new RoomNormal("Room 1")); //Creates the first room to allow for backward linking
	
	for (int i = 1; i < 15; i++) //Creates rooms 2-15 and makes a link all the way through from 1-15
	{
		rooms.push_back(new RoomNormal("Room " + to_string(i+1))); //Creates a new room
		rooms[i]->AddExit(rooms[i-1]); //adds a link to the previous room
		rooms[i-1]->AddExit(rooms[i]); //adds a link back from the previous room
	}
	//Links for skipping
	rooms[2]->AddExit(rooms[4]);
	rooms[4]->AddExit(rooms[2]);

	rooms[3]->AddExit(rooms[7]);
	rooms[7]->AddExit(rooms[3]);

	rooms[7]->AddExit(rooms[9]);
	rooms[9]->AddExit(rooms[7]);

	rooms[10]->AddExit(rooms[13]);
	rooms[13]->AddExit(rooms[10]);

	return rooms;
}
