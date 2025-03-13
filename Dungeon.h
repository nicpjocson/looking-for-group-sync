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

	//void incrementDungeonParties();

	// Getters
	int getId();
	bool getIsRunning();
	//bool getIsFull();
	bool getIsActive();
	int getPartiesServed();
	int getTotalTimeServed();

	// Setters
	//void setIsFull(bool isFull);
	void setIsActive(bool isActive);

private:
	int id;

	bool isRunning = false;

	int dungeonParties;

	//bool isFull;

	// To display
	bool isActive;
	int partiesServed;
	int totalTimeServed;
};

