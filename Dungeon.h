#pragma once
#include <iostream>
#include <chrono>
#include <random>
#include <thread>
#include <mutex>

#include "config.h"

class Dungeon
{
public:
	Dungeon(int id);

	void startDungeon();
	void run(int numParties);

	// Getters
	int getId();
	bool getIsRunning();
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

