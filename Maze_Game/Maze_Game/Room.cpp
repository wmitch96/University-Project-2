// Author: William Mitchell
// SID: 1610113
// Module: Object Oriented C++

#pragma once
#include "Room.h"
#include <iostream>

Room::Room(string n)
{
	name = n;
}

void Room::setName(string n)
{
	name = n;
}

string Room::getName() const
{
	return name;
}
