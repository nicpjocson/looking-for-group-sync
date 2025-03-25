#pragma once
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>

typedef std::string String;
typedef std::unordered_map<String, String> HashMap;

class Driver
{
public:
	Driver();
	~Driver();

	bool getConfig();
	const void initialize();
	void run();

private:
	// Program configuration
	HashMap configValues;
	unsigned int maxInstances = 0;  // 0 to max
	unsigned int tankPlayers = 0;   // 0 to max
	unsigned int healerPlayers = 0; // 0 to max
	unsigned int dpsPlayers = 0;	// 0 to max
	unsigned int minTime = 0;		// 0 to maxTime
	unsigned int maxTime = 0;		// 0 to 15

	// Reading and validating config
	HashMap readConfig(String filename);
	bool validateConfig();
	const bool isValid(String param, String value);

	// Printing functions
	void displaySummary();
	void displayAllInstances();
	void displayLeftoverPlayers();
	String getStatus(bool status);
};

