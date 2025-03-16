#pragma once
#include <iostream>
#include <string>

#include "config.h"
#include "QueueManager.h"
#include "Dungeon.h"

typedef std::string String;

class Driver
{
public:
	void initialize();
	void run();
	void waitForThreadsToFinish();

	void displaySummary();
	void displayAllInstances();
	void displayLeftoverPlayers();
	String getStatus(bool status);

private:
	bool isRunning = false;

	std::vector<Dungeon*> dungeons;

	int leftoverTanks = 0;
	int leftoverHealers = 0;
	int leftoverDPS = 0;

	void createDungeons();
};

