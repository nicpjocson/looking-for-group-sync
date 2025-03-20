#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "QueueManager.h"
#include "Dungeon.h"

typedef std::string String;
typedef std::vector<String> strList;
typedef std::vector<unsigned int> uintList;

class Driver
{
public:
	bool getConfig();
	void initialize();
	void run();

private:
	bool isRunning = false;

	// Program parameters
	unsigned int maxInstances = 0;   // 0 to max
	unsigned int tankPlayers = 0;   // 0 to max
	unsigned int healerPlayers = 0; // 0 to max
	unsigned int dpsPlayers = 0;	// 0 to max
	unsigned int minTime = 0;		// 0 to maxTime
	unsigned int maxTime = 0;		// 0 to 15

	std::vector<Dungeon*> dungeons;
	void createDungeons();
	void waitForThreadsToFinish();

	// Reading and validating config
	strList readConfig(String filename);
	uintList validateConfig(strList parameters);
	bool isValid(String param, String value);
	void setParams(uintList parameters);

	// Printing functions
	void displaySummary();
	void displayAllInstances();
	void displayLeftoverPlayers();
	String getStatus(bool status);
};

