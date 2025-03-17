#pragma once
#include <iostream>
#include <chrono>
#include <random>
#include <thread>

#include "config.h"

class Dungeon
{
public:
	Dungeon(int id);

	void startDungeon(int assignedParties);
	void run();

	// Getters
	int getId();
	bool getIsRunning();
	bool getIsActive();
	int getPartiesServed();
	int getTotalTimeServed();

private:
	int id;
	bool isRunning = false;
	int dungeonParties = 0;

	// To be displayed after execution
	bool isActive = false;
	int partiesServed = 0;
	int totalTimeServed = 0;

	int randomClearTime();
};

