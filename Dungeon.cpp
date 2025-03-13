#include "Dungeon.h"

// DOUBLE CHECK
Dungeon::Dungeon(int id)
{
	this->id = id;
	this->dungeonParties = 0;
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
	int clearTime = randomClearTime();
	std::cout << "parties in dungeon: " << this->dungeonParties << std::endl;
	// Simulate clear
	std::this_thread::sleep_for(std::chrono::seconds(10/*clearTime*/));
	// !! CHECKPOINT: STUCK HERE????
	// ???? CHECKPOINT: NEVER PRINTS
	std::cout << "clearing dungeon..." << this->id << std::endl;
	// !! DOUBLE CHECK: verify if should call here
	this->dungeonCleared(clearTime);
}

// DOUBLE CHECK
void Dungeon::dungeonCleared(int clearTime)
{
	this->isActive = false;
	this->partiesServed += this->dungeonParties;
	this->totalTimeServed += clearTime;

	// "Empty" dungeon
	this->dungeonParties = 0;
	this->isRunning = false;
	// CHECKPOINT: NEVER PRINTS
	std::cout << "cleared dungeon" << this->id << std::endl;
}

// DOUBLE CHECK
int Dungeon::randomClearTime()
{
	return rand() % MAX_TIME - MIN_TIME;
}

/*
	
	Getters

*/
bool Dungeon::getIsRunning()
int Dungeon::getId()
{
	return this->isRunning;
	return this->id;
}

//bool Dungeon::getIsFull()
//{
//	return this->isFull;
//}

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
	return this->partiesServed;
}

int Dungeon::getTotalTimeServed()
{
	return this->totalTimeServed;
}

/*

	Setters

*/
//void Dungeon::setIsFull(bool isFull)
//{
//	this->isFull = isFull;
//}

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

