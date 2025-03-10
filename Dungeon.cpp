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

void Dungeon::startDungeon() 
{
	this->isRunning = true;
	std::thread thread(&Dungeon::searchForParties, this);
	thread.detach();

	// DEBUG
	std::cout << "started dungeon/thread " << this->id << std::endl;
}

// !! used to be in Driver class
// !! verify if should keep here
void Dungeon::searchForParties()
{
	// Dungeon is not full
	// REFACTOR??
	while (/*!this->isFull*/this->dungeonParties < MAX_PARTIES)
	{
		this->dungeonParties++;
		//this->partyQueue.pop();
	}

	// When full
	if (/*this->isFull*/this->dungeonParties == MAX_PARTIES) {
		this->clearDungeon();
	}
}

// DOUBLE CHECK
void Dungeon::clearDungeon()
{
	//while (this->dungeonParties < MAX_PARTIES) {}
	std::cout << this->dungeonParties << "lalalala" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(2/*randomClearTime()*/));
	std::cout << "clearing dungeon" << this->id << std::endl;
	this->dungeonCleared();
}

// DOUBLE CHECK
void Dungeon::dungeonCleared()
{
	this->isRunning = false;
	this->partiesServed += this->dungeonParties;
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

int Dungeon::getTotalTimeServed()
{
	return this->totalTimeServed;
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

//void Dungeon::incrementDungeonParties()
//{
//	this->dungeonParties++;
//}

