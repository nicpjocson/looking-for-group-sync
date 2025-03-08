#pragma once
#include <iostream>
#include <string>

// For reading config.txt
#include <fstream>
#include <sstream>

#include <thread>

#include "Dungeon.h"
#include "Player.h"

class Driver
{
public:
	typedef std::string String;

	void initialize();
	void run();

private:
	std::vector<Dungeon> dungeons;

	int maxDungeons;
	int minTime;
	int maxTime;

	bool readConfig();
};

