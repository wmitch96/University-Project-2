// Author: William Mitchell
// SID: 1610113
// Module: Object Oriented C++

#pragma once
#include "MazeRandom.h"
#include <iostream>
#include "RoomNormal.h"

MazeRandom::MazeRandom(string n, double dif, int min, int max) : Maze(n)
{
	numRooms = rand() % (max - min + 1) + min; //Generates a minimum number between the min and max values
	difficulty = (dif / 10) + 0.2;
	vector<Room*> rooms = CreateRooms(); //Creates the rooms
	JoinRooms(rooms); //Creates the paths between the rooms
}

vector<Room*> MazeRandom::CreateRooms()
{
	vector<Room*> r; //The vector used to store the rooms

	for (int i = 0; i < numRooms; i++) //Loop for room creation
	{
		RoomNormal* room = new RoomNormal("Room " + to_string(i + 1)); //Creates a new room
		r.push_back(room); //Adds the room to the vector
	}

	return r; //Outputs the populated vector
}

void MazeRandom::JoinRooms(vector<Room*> allRooms)
{
	vector<Room*> unrequiredRooms = allRooms;
	vector<Room*> requiredRooms;

	unrequiredRooms.erase(unrequiredRooms.begin());  //Removes the first room from the unrequired vector
	unrequiredRooms.erase(unrequiredRooms.end() - 1);  //Removes the final room from the unrequired vectr

	double numRequiredRooms = (unsigned)ceil((double)allRooms.size() * difficulty) - 2; //Calculates the minimum number of rooms required to complete the maze (-2 for start and final rooms)
	requiredRooms.push_back(allRooms[0]); //Adds the first room to the required vector
	setStart(allRooms[0]); //Sest the start point of the maze

	while (requiredRooms.size() < numRequiredRooms) //Loops until the required rooms vector has reached the correct number of rooms.
	{
		int roomToAdd = rand() % (unrequiredRooms.size() - 1) + 1; //Picks a random room number to add from the unrequired vector
		requiredRooms.push_back(unrequiredRooms[roomToAdd]); //Adds the randomly chosen room to the required vector
		unrequiredRooms.erase(unrequiredRooms.begin() + roomToAdd); //Removes it from the unrequired vector
	}

	requiredRooms.push_back(allRooms[allRooms.size() - 1]); //Adds the final room to the required rooms vector
	setEnd(allRooms[allRooms.size() - 1]); //Sets the end point of the maze

	for (int i = 0; i < requiredRooms.size() - 1; i++) //Foreach room in the requiredRooms vector
	{
		requiredRooms[i]->AddExit(requiredRooms[i + 1]); //Adds the next required room to the exits vector
		requiredRooms[i + 1]->AddExit(requiredRooms[i]); //Adds an exit back to this room from the next room
	}

	for (int i = 0; i < unrequiredRooms.size() - 1; i++) //For every room that currently has no exits
	{
		int totalExits = rand() % 4 + 1; //Pick a random number of exits to assign (1-5)
		for (int j = 0; j < totalExits; j++) //For each exit
		{
			int target = rand() % (requiredRooms.size() - 1) + 1; //Pick a random required room to connect to
			{
				bool alreadyConnected = false; // used as a check to see if a target room is already connecteed to the current room
				
				for (Room* room : unrequiredRooms[i]->getExits()) //Foreach exit this room already has
				{
					if (requiredRooms[target] == room) //If the target room is already connected to this room
					{
						alreadyConnected = true; 
					}
				}

				if (alreadyConnected == false) //If the two rooms are not already connected with another exit
				{
					unrequiredRooms[i]->AddExit(requiredRooms[target]); //Add an exit to the target room in this room
					requiredRooms[target]->AddExit(unrequiredRooms[i]); //Add an exit in the target room to this room
				}
			}
		}
		requiredRooms.push_back(unrequiredRooms[i]); //Add this room to required room lists so other rooms can target it for links
		unrequiredRooms.erase(unrequiredRooms.begin() + i); //Remove this room from the unrequired vector
	}
	setCurrentRoom(allRooms[0]); //Sets the user to the start of the maze
}