#pragma once
#include <vector>
#include "Player.h"
#include "Tank.h"
#include "Healer.h"
#include "DPS.h"

class Dungeon
{
public:
	bool getIsAvailable();
	int getPartiesServed();
	int getTotalTimeServed();

private:
	enum Status { ACTIVE, EMPTY };

	int currParties;
	int maxParties;

	std::vector<std::vector<Player>> parties;

	std::vector<Tank> tankQueue;
	std::vector<Healer> healerQueue;
	std::vector<DPS> dpsQueue;

	bool isAvailable;
	Status status;
	int partiesServed;
	float totalTimeServed;
};

