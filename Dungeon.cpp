#include "Dungeon.h"

//Dungeon::Dungeon() 
//{
//}

void Dungeon::addParty(Party party)
{
	this->parties.push_back(party);
}

void Dungeon::dungeonTask() 
{
	//std::this_thread::sleep_for(std::chrono::seconds(2));
}

/*
	
	Getters

*/
bool Dungeon::getIsFull()
{
	return this->isFull;
}

bool Dungeon::getIsAvailable()
{
	return this->isAvailable;
}

bool Dungeon::getIsActive()
{
	return this->isActive;
}

int Dungeon::getPartiesServed()
{
	return partiesServed;
}

float Dungeon::getTotalTimeServed()
{
	return totalTimeServed;
}

/*

	Setters

*/
bool Dungeon::setIsFull()
{
	return this->isFull;
}

bool Dungeon::setIsAvailable()
{
	return isAvailable;
}

/*
	Dungeon Status
	* ACTIVE: Returns true if dungeon has at least one party. 
	* EMPTY: Returns false, otherwise.
*/
bool Dungeon::setIsActive()
{
	return isActive;
}
