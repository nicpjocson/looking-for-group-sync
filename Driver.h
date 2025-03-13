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

typedef std::string String;

class Driver
{
public:
	void initialize();
	void run();
	void waitForThreadsToFinish();

	void createParties();
	Party* createParty();
	bool canCreateParty();
	void handleLeftoverPlayers();

	void displaySummary();
	void displayAllInstances();
	void const displayLeftoverPlayers();
	String getStatus(bool status);

private:
	bool isRunning = false;

	std::vector<Dungeon*> dungeons;
	std::queue<Party*> partyQueue;

	std::queue<Tank*> tankQueue;
	std::queue<Healer*> healerQueue;
	std::queue<DPS*> dpsQueue;

	int leftoverTanks = 0;
	int leftoverHealers = 0;
	int leftoverDPS = 0;
};

