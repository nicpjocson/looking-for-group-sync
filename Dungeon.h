#pragma once
#include <iostream>
#include <vector>
#include <thread>

#include "config.h"
#include "Party.h"

class Dungeon
{
public:
	Dungeon();

	void addParty(Party party);
	void startDungeon();
	void dungeonTask();
	void clearDungeon();
	int randomClearTime();

	// Getters
	bool getIsRunning();
	bool getIsFull();
	bool getIsAvailable();
	bool getIsActive();
	int getPartiesServed();
	float getTotalTimeServed();

	// Setters
	bool setIsFull();
	bool setIsAvailable();
	bool setIsActive();

private:
	bool isRunning = false;

	std::vector<Party> parties;

	bool isFull;
	// To display
	bool isAvailable;
	bool isActive;
	int partiesServed;
	float totalTimeServed;
};

