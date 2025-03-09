#pragma once
#include <iostream>
#include <string>

// For reading config.txt
#include <fstream>
#include <sstream>

//#include <thread>
#include <queue>

#include "config.h"
#include "Dungeon.h"
#include "Party.h"
#include "Player.h"
#include "Tank.h"
#include "Healer.h"
#include "DPS.h"

class Driver
{
public:
	typedef std::string String;

	void initialize();
	void run();
	void waitForThreadsToFinish();

	Party createParty();

	bool canCreateParty();

	void displayAllInstances(int maxDungeons);
	void displayStatus(bool status);

private:
	bool isRunning = false;

	std::vector<Dungeon*> dungeons;

	std::queue<Tank*> tankQueue;
	std::queue<Healer*> healerQueue;
	std::queue<DPS*> dpsQueue;
};

