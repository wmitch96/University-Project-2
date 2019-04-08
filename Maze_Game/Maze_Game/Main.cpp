// Author: William Mitchell
// SID: 1610113
// Module: Object Oriented C++
#pragma once

#include <iostream>
#include <ctime>
#include "InterfaceManager.h"

using namespace std;

int main()
{
	srand(time(NULL)); // Seed the random function with the current time

	InterfaceManager::MainMenu();

	system("pause");
	return 0;
}