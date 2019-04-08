// Author: William Mitchell
// SID: 1610113
// Module: Object Oriented C++

#pragma once
#include "MazeFile.h"

MazeFile::MazeFile(string n, string f, bool xml) : Maze(n)
{
	file = f;

	if (xml) //if file is a .xml
	{
		XmlManager::CreateRooms(this, f);
	}
	else
	{
		vector<Room*> r = CreateRooms();
		setStart(r[0]);
		setEnd(r[r.size()-1]);
		setCurrentRoom(r[0]);
	}
}

vector<Room*> MazeFile::CreateRooms()
{
	ifstream txtFile;
	txtFile.open(file);

	vector<string> lines; //A vector used to contain each line from the given file
	string line;
	while (getline(txtFile, line)) //For each line in .txt file
	{
		lines.push_back(line); //Add line to file vector
	}

	vector<Room*> rooms; //A vector used to store all of the room objects
	for (int i = 0; i < lines.size(); i++) //For each line taken from the file
	{
		rooms.push_back(new RoomNormal("Room " + to_string(i + 1))); //Add room to the room list vector
	}


	for (int i = 0; i < rooms.size(); i++) //For each string in the vector
	{
		string cutMarker = ","; //identifier of where to cut the string
		size_t posInString = 0; //Position in the string
		string token; //Holds the value split from the string

		vector<string> exits;

		while ((posInString = lines[i].find(cutMarker)) != string::npos) //While the string can still be split
		{
			token = lines[i].substr(0, posInString); //Assigns the contents of the string 
			exits.push_back(token); //Adds exit to the exits vector
			lines[i].erase(0, posInString + cutMarker.length()); //Remove token value from original string
		}
		for (int x = 0; x < exits.size(); x++) //For each exit in the given room
		{
			int roomPos = stoi(exits[x]) - 1; //cast exit target to int (-1 for index refernecing)
			rooms[i]->AddExit(rooms[roomPos]); //Assign the given exit to the target room
		}
	}
	return rooms;
}