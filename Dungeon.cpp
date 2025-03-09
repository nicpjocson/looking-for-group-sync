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
	return 0;
}

int Dungeon::getTotalTimeServed()
{
	return 0;
}

