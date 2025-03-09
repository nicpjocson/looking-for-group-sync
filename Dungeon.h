#pragma once
#include <vector>
#include "Party.h"

class Dungeon
{
public:
	//Dungeon();

	void addParty(Party party);

	bool getIsFull();
	bool getIsAvailable();
	int getPartiesServed();
	int getTotalTimeServed();


private:
	int currParties;

	std::vector<Party> parties;

	bool isFull;

	bool isAvailable;
	bool isActive;
	int partiesServed;
	float totalTimeServed;
};

