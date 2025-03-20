#pragma once
#include <iostream>

#include "Dungeon.h"

class DungeonManager
{
public:
	static DungeonManager* getInstance();
	void initialize(unsigned int maxInstances, unsigned int minTime, unsigned int maxTime);
	void createDungeons();
	void run();

	// Getters
	std::vector<Dungeon*> getDungeons();

private:
	static DungeonManager* P_SHARED_INSTANCE;

private:
	DungeonManager();
	DungeonManager(const DungeonManager&);
	DungeonManager& operator = (const DungeonManager&);
	
	bool isRunning = false;
	std::mutex guard;
	std::vector<Dungeon*> dungeons;

	unsigned int maxInstances;
	unsigned int minTime;
	unsigned int maxTime;

	void waitForDungeonsToFinish();
};

