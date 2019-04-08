// Author: William Mitchell
// SID: 1610113
// Module: Object Oriented C++

#pragma once
#include "maze.h" //Includes Maze, Room, RoomNormal, RoomLocked, string

using namespace std;

class MazeRandom : public Maze
{
	private:
		int numRooms;
		double difficulty;
		vector<Room*> roomList;

	public:
		MazeRandom(string n, double dif, int min, int max);
		virtual vector<Room*> CreateRooms();
		void JoinRooms(vector<Room*> roomList);
};