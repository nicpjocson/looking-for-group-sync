#include "Dungeon.h"

// DOUBLE CHECK
Dungeon::Dungeon() 
{
	this->parties = {};
	this->isFull = false;
	this->isAvailable = true;
	this->isActive = false;
	this->partiesServed = 0;
	this->totalTimeServed = 0;
}

void Dungeon::addParty(Party party)
{
	this->parties.push_back(party);
}

void Dungeon::clearDungeon()
{
	this->isRunning = false;
	this->parties.clear();
}

void Dungeon::startDungeon() 
{
	this->isRunning = true;
	std::thread thread(&Dungeon::dungeonTask, this);
	thread.detach();

	std::cout << "started thread" << std::endl;
}

void Dungeon::dungeonTask() 
{
	while (this->parties.size() < MAX_PARTIES) {}

	std::cout << this->parties.size() << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(2/*randomClearTime()*/));
	std::cout << "closing thread" << std::endl;
	clearDungeon();
}

int Dungeon::randomClearTime()
{
	return rand() % MAX_TIME - MIN_TIME; // IDK brb ill pee n get food
}

/*
	
	Getters

*/
bool Dungeon::getIsRunning()
{
	return this->isRunning;
}

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
