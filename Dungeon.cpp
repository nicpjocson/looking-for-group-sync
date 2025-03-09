#include "Dungeon.h"

//Dungeon::Dungeon() 
//{
//}

void Dungeon::addParty(Party party)
{
	this->parties.push_back(party);
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
