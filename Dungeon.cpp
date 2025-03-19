#include "Dungeon.h"

Dungeon::Dungeon(unsigned int id, unsigned int minTime, unsigned int maxTime)
{
	this->id = id;
	this->minTime = minTime;
	this->maxTime = maxTime;
}

void Dungeon::startDungeon()
{
	std::lock_guard<std::mutex> lock(this->guard);
	//std::cout << "dungeon " << this->id << std::endl;
	this->isRunning = true;
	std::thread thread(&Dungeon::clearDungeon, this);
	thread.detach();
}

void Dungeon::addParties(unsigned int assignedParties)
{
	this->dungeonParties = assignedParties;
	this->isActive = true;
}

void Dungeon::clearDungeon()
{	
	// There is at least one party in the dungeon
	while (this->isRunning && this->isActive)
	{	
		std::cout << "dungeon " << this->id << " clearing " << this->dungeonParties << " parties" << std::endl;
		std::lock_guard<std::mutex> lock(this->guard);

		/*int clearTime = randomClearTime();*/ int clearTime = 2;

		// Simulate dungeon clearing with sleep
		std::this_thread::sleep_for(std::chrono::seconds(clearTime));

		this->updateDungeonStats(clearTime);
		this->resetDungeon();
	}
}

void Dungeon::updateDungeonStats(int clearTime)
{
	this->partiesServed += this->dungeonParties;
	this->totalTimeServed += clearTime;
}

void Dungeon::resetDungeon()
{
	this->isActive = false;
	this->dungeonParties = 0;
}

unsigned int Dungeon::randomClearTime()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(this->minTime, this->maxTime);

	return distr(gen);
}

/*

	Getters

*/
unsigned int Dungeon::getId()
{
	return this->id;
}

bool Dungeon::getIsRunning()
{
	return this->isRunning;
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

unsigned int Dungeon::getPartiesServed()
{
	return this->partiesServed;
}

unsigned int Dungeon::getTotalTimeServed()
{
	return this->totalTimeServed;
}

