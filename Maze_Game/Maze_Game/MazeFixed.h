// Author: William Mitchell
// SID: 1610113
// Module: Object Oriented C++

#pragma once
#include "maze.h" //Includes Maze, Room, RoomNormal, RoomLocked, string
#include "RoomNormal.h"
#include "RoomLocked.h"

using namespace std;

class MazeFixed : public Maze
{
	public:
		MazeFixed(string n);
		virtual vector<Room*> CreateRooms();
};