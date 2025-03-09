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

	//void addParty(Party party);
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
	void setIsFull(bool isFull);
	void setIsAvailable(bool isAvailable);
	void setIsActive(bool isActive);

private:
	int id;

	bool isRunning = false;

	int dungeonParties;

	bool isFull;

	// To display
	bool isAvailable;
	bool isActive;
	int partiesServed;
	float totalTimeServed;
};

