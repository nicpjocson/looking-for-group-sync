#pragma once
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

#include "config.h"
//#include "Party.h"

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

	// To use for displaying after execution
	bool getIsActive();
	int getPartiesServed();
	int getTotalTimeServed();

private:
	std::mutex guard;

	int id;
	bool isRunning = false;
	//std::vector<Party*> dungeonParties;
	int dungeonParties;

	// To be displayed after execution
	bool isActive;
	int partiesServed;
	int totalTimeServed;
};

