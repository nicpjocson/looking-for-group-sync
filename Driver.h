#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "DungeonManager.h"
#include "PartyManager.h"

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
	// Program parameters
	unsigned int maxInstances = 0;  // 0 to max
	unsigned int tankPlayers = 0;   // 0 to max
	unsigned int healerPlayers = 0; // 0 to max
	unsigned int dpsPlayers = 0;	// 0 to max
	unsigned int minTime = 0;		// 0 to maxTime
	unsigned int maxTime = 0;		// 0 to 15

	// Reading and validating config
	strList readConfig(String filename);
	bool validateConfig(strList parameters);
	bool isValid(String param, String value);
	void setParams(uintList parameters);

	// Printing functions
	void displaySummary();
	void displayAllInstances();
	void displayLeftoverPlayers();
	String getStatus(bool status);
};

