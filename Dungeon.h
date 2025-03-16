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
	//bool getIsRunning();
	bool getIsActive();
	int getPartiesServed();
	int getTotalTimeServed();

private:
	std::mutex guard;

	int id;
	bool isRunning = false;
	int dungeonParties = 0;

	// To be displayed after execution
	bool isActive = false;
	int partiesServed = 0;
	int totalTimeServed = 0;

	int randomClearTime();
};

