#include "Dungeon.h"
#include <chrono>
#include <random>
#include <thread>
#include "PartyManager.h"

Dungeon::Dungeon(std::mutex* guard, unsigned int id, unsigned int minTime, unsigned int maxTime)
{
	this->guard = guard;
	this->id = id;
	this->minTime = minTime;
	this->maxTime = maxTime;
}

void Dungeon::startDungeon()
{
	this->isRunning = true;
	std::thread thread(&Dungeon::clearDungeon, this);
	thread.detach();
}

void Dungeon::assignParty()
{
	if (this->isActive) this->isActive = false;
	this->isActive = true;
}

void Dungeon::clearDungeon()
{
	while (this->isRunning) {
		if (this->isActive) {
			std::lock_guard<std::mutex> lock(*this->guard);

			std::cout << "Clearing Dungeon " << this->id << "... ";

			// Simulate clear
			int clearTime = this->randomClearTime();
			std::this_thread::sleep_for(std::chrono::seconds(clearTime));

			this->partiesServed += 1;
			this->totalTimeServed += clearTime;
			this->isActive = false;

			std::cout << "Cleared!" << std::endl;
		}
		else {
			if (PartyManager::getInstance()->getPartiesInQueue() == 0) {
				this->isRunning = false;
			}
		}
	}
}

void Dungeon::updateDungeonStats(int clearTime)
{
	this->partiesServed += 1;
	this->totalTimeServed += clearTime;
}

/*
	Returns a random unsigned integer between t1 and t2
*/
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
	* ACTIVE: Returns true if there is a party in the dungeon.
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

