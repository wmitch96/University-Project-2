// Author: William Mitchell
// SID: 1610113
// Module: Object Oriented C++

#pragma once
#include <iostream>
#include "MazeFixed.h"
#include "MazeRandom.h"
#include "MazeFile.h"

using namespace std;

//Interface Manager Static Class
class InterfaceManager
{
	private:
		InterfaceManager() {} //Stops this class from being created as an object
		static Maze* InputFixedMaze();
		static Maze* InputRandomMaze();
		static Maze* InputFileMaze(bool xml);

	public:
		static Maze* MainMenu();
		static void DisplayRoomExits(bool simpleMode, Room* r, Maze* maze);
};