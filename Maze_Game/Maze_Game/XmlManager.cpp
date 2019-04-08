// Author: William Mitchell
// SID: 1610113
// Module: Object Oriented C++

#pragma once
#include "XmlManager.h"

void XmlManager::CreateRooms(Maze* maze, string filePath)
{
	//Create Vector
	vector<Room*> roomList; //Temp list used to create the maze layout

	//Root XML Nodes
	pugi::xml_document doc; 
	doc.load_file(filePath.c_str(), pugi::parse_default | pugi::parse_declaration); //Loads the file from the given filepath


	pugi::xml_node root = doc.document_element();
	pugi::xml_node room = root.child("Room");

	pugi::xml_attribute attr; //Assign memory

	bool nextRoom = true;
	while (nextRoom == true) //loop untill all rooms have been created
	{
		if (attr = room.attribute("Name")) // If the name attribute exists on this node
		{
			Room* r = new RoomNormal(attr.as_string()); //Create room and pass its name with a string to char* converison
			roomList.push_back(r);
		}
		if (room.next_sibling()) //If another room is found in the file
		{
			room = room.next_sibling(); //activate the next room and continue
		}
		else //File contains no more rooms
		{
			nextRoom = false; //Stops the loop
		}
	}
	LinkRooms(roomList, root.child("Room"), maze); //Pass the roomList and the first roomNode
}

Room* XmlManager::FindRoomInVector(vector<Room*> rooms, string name)
{
	for (Room* room : rooms)
	{
		if (room->getName() == name)
		{
			return room;
		}
	}
	return NULL;
}

void XmlManager::LinkRooms(vector<Room*> rooms, pugi::xml_node firstRoomNode, Maze* maze)
{
	pugi::xml_node roomNode = firstRoomNode;
	for (int i = 0; i < (signed)rooms.size(); i++) //Loop For each room in the rooms list
	{
		pugi::xml_node exitNode = roomNode.first_child();
		pugi::xml_attribute exit; //Assign memory

		bool nextExit = true;
		while (nextExit == true) //Repeat untill all exits have been created
		{
			if (exit = exitNode.attribute("Name")) // If the name attribute exists on this node
			{
				Room* target = FindRoomInVector(rooms, exitNode.attribute("Target").as_string());
				rooms[i]->AddExit(target);
			}

			if (exitNode.next_sibling())
			{
				exitNode = exitNode.next_sibling();
			}
			else
			{
				nextExit = false;
			}
		}

		roomNode = roomNode.next_sibling();
	}

	maze->setStart(rooms[0]);
	maze->setEnd(rooms[rooms.size() - 1]);
	maze->setCurrentRoom(rooms[0]);
}