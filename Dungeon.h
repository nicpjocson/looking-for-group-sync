#pragma once
#include <iostream>
#include <chrono>
#include <random>
#include <thread>
#include <mutex>

class Dungeon
{
public:
	Dungeon(unsigned int id, unsigned int minTime, unsigned int maxTime);

	void startDungeon();
	void addParties(unsigned int assignedParties);
	void clearDungeon();

	// Getters
	unsigned int getId();
	bool getIsRunning();
	bool getIsActive();
	unsigned int getPartiesServed();
	unsigned int getTotalTimeServed();

private:
	std::mutex guard;

	int id;
	bool isRunning = false;
	unsigned int dungeonParties = 0;
	unsigned int minTime;
	unsigned int maxTime;

	// To be displayed after execution
	bool isActive = false;
	unsigned int partiesServed = 0;
	unsigned int totalTimeServed = 0;

	unsigned int randomClearTime();

	void updateDungeonStats(int clearTime);
	void resetDungeon();
};

