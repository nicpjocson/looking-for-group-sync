#pragma once
#include <iostream>
#include <vector>
#include <thread>

#include "config.h"
#include "Party.h"

class Dungeon
{
public:
	Dungeon(int id);

	void startDungeon();
	void searchForParties();
	void clearDungeon();
	void dungeonCleared(int clearTime);
	int randomClearTime();

	// Getters
	int getId();
	bool getIsRunning();

	bool getIsActive();
	int getPartiesServed();
	int getTotalTimeServed();

private:
	int id;
	bool isRunning = false;
	int dungeonParties;

	// To display
	bool isActive;
	int partiesServed;
	int totalTimeServed;
};

