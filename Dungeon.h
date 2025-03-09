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
	bool getIsActive();
	int getPartiesServed();
	float getTotalTimeServed();

	bool setIsFull();
	bool setIsAvailable();
	bool setIsActive();

private:
	int currParties;

	std::vector<Party> parties;

	bool isFull;

	bool isAvailable;
	bool isActive;
	int partiesServed;
	float totalTimeServed;
};

