#include "Dungeon.h"

// DOUBLE CHECK
Dungeon::Dungeon(int id) 
{
	this->id = id;
	this->dungeonParties = 0;
	this->isFull = false;
	this->isAvailable = true; // UNCLEAR WHAT AVAILABLE MEANS !!
	this->isActive = false;
	this->partiesServed = 0;
	this->totalTimeServed = 0;
}

//void Dungeon::addParty(Party party)
//{
//	this->dungeonParties.push_back(party);
//}

void Dungeon::startDungeon() 
{
	this->isRunning = true;
	std::thread thread(&Dungeon::clearDungeon, this);
	thread.detach();

	// DEBUG
	std::cout << "started dungeon/thread " << this->id << std::endl;
}

void Dungeon::clearDungeon()
{
	//while (this->dungeonParties < MAX_PARTIES) {}
	std::cout << this->dungeonParties << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(2/*randomClearTime()*/));
	std::cout << "clearing dungeon" << this->id << std::endl;
	this->dungeonCleared();
}

void Dungeon::dungeonCleared()
{
	this->isRunning = false;
	this->dungeonParties = 0;
	std::cout << "cleared dungeon" << this->id << std::endl;
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

/*
	Dungeon Status
	* ACTIVE: Returns true if dungeon has at least one party.
	* EMPTY: Returns false, otherwise.
*/
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
void Dungeon::setIsFull(bool isFull)
{
	this->isFull = isFull;
}

void Dungeon::setIsAvailable(bool isAvailable)
{
	this->isAvailable = isAvailable;
}

void Dungeon::setIsActive(bool isActive)
{
	this->isActive = isActive;
}

