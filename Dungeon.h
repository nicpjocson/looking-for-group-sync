#pragma once
#include <iostream>
#include <chrono>
#include <random>
#include <thread>
#include <mutex>

class Dungeon
{
public:
	Dungeon(std::mutex* guard, unsigned int id, unsigned int minTime, unsigned int maxTime);

	void startDungeon();
	void assignParty();
	void clearDungeon();

	// Getters
	bool getIsRunning();
	unsigned int getId();
	bool getIsActive();
	unsigned int getPartiesServed();
	unsigned int getTotalTimeServed();

private:
	std::mutex* guard;
	
	bool isRunning = false;

	unsigned int id;
	unsigned int minTime;
	unsigned int maxTime;

	// To be displayed after execution
	bool isActive = false;
	unsigned int partiesServed = 0;
	unsigned int totalTimeServed = 0;

	void updateDungeonStats(int clearTime);
	unsigned int randomClearTime();
};

