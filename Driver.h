#pragma once
#include <iostream>
#include <string>
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

	void createParties();
	Party* createParty();
	bool canCreateParty();

	void displayAllInstances(int maxDungeons);
	void displayStatus(bool status);

private:
	bool isRunning = false;

	std::vector<Dungeon*> dungeons;
	std::queue<Party*> partyQueue;

	std::queue<Tank*> tankQueue;
	std::queue<Healer*> healerQueue;
	std::queue<DPS*> dpsQueue;
};

