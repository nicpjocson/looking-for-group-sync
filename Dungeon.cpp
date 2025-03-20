#include "Dungeon.h"
#include "QueueManager.h"

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
	this->isActive = true;
}

void Dungeon::clearDungeon()
{
	while (this->isRunning)
	{
		if (this->isActive) {
			//std::cout << "Clearing dungeon " << this->id << std::endl;
			std::lock_guard<std::mutex> lock(*this->guard);
			this->isActive = true;

			// Simulate clear
			int clearTime = 2/*ranadomClearTime()*/;
			std::this_thread::sleep_for(std::chrono::seconds(clearTime));

			std::cout << "dungeon " << this->id << std::endl;
			std::cout << "parties before " << this->partiesServed << std::endl;
			this->partiesServed += 1;
			std::cout << "parties after " << this->partiesServed << std::endl;
			this->totalTimeServed += clearTime;
			this->isActive = false;

			//std::cout << "Cleared dungeon " << this->id << std::endl;
		}
		else 
		{
			if (QueueManager::getInstance()->getPartiesInQueue() == 0) {
				this->isRunning = false;
			}
		}
	}
	
}

void Dungeon::updateDungeonStats(int clearTime)
{
	this->partiesServed += 1;
	this->totalTimeServed += clearTime;
	//std::cout << "parties served " << this->partiesServed << std::endl;
	//std::cout << "total time served " << this->totalTimeServed << std::endl;
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

