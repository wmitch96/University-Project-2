// Author: William Mitchell
// SID: 1610113
// Module: Object Oriented C++

#pragma once
#include "maze.h" //Includes Maze, Room, RoomNormal, RoomLocked, string
#include "XmlManager.h"
#include <fstream>

using namespace std;

class MazeFile : public Maze
{
	protected:
		string file;

	public:
		MazeFile(string n, string f, bool xml);
		virtual vector<Room*> CreateRooms();
};