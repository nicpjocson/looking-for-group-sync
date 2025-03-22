#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "DungeonManager.h"
#include "PartyManager.h"

typedef std::string String;
typedef std::vector<String> List;

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
	List readConfig(String filename);
	bool validateConfig(List parameters);
	bool isValid(String param, String value);

	// Printing functions
	void displaySummary();
	void displayAllInstances();
	void displayLeftoverPlayers();
	String getStatus(bool status);
};

