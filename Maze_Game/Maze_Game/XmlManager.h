// Author: William Mitchell
// SID: 1610113
// Module: Object Oriented C++

#pragma once
#include "Maze.h"
#include "pugixml.hpp"
#include "RoomNormal.h"
#include "RoomLocked.h"

class XmlManager
{
	private:
		XmlManager() {} //Stops this class from being created as an object
		static Room* FindRoomInVector(vector<Room*> rooms, string name);
		static void LinkRooms(vector<Room*> rooms, pugi::xml_node node, Maze* maze);

	public:
		static void CreateRooms(Maze* m, string filePath);
};