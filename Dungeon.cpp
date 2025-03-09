#include "Dungeon.h"

//Dungeon::Dungeon() 
//{
//}

void Dungeon::addParty(Party party)
{
	this->parties.push_back(party);
}

bool Dungeon::getIsAvailable()
{
	return isAvailable;
}

int Dungeon::getPartiesServed()
{
	return 0;
}

int Dungeon::getTotalTimeServed()
{
	return 0;
}

