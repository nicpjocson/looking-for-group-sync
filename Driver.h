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

	void createDungeons();
};

