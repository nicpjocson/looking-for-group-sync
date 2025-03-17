#include "Dungeon.h"
#include "QueueManager.h"

Dungeon::Dungeon(int id)
{
	this->id = id;
}

void Dungeon::startDungeon()
{
	std::thread thread(&Dungeon::run, this);
	thread.detach();
}

void Dungeon::run(int numParties)
{
	//while(QueueManager::getInstance()->getPartiesInQueue() > 0) {}
	//this->dungeonParties = numParties;
	//this->isActive = true;

	////int clearTime = randomClearTime();
	//int clearTime = 2;

	//std::cout << "parties in dungeon " << this->dungeonParties << std::endl;

	//// Simulate dungeon clearing with sleep
	//std::this_thread::sleep_for(std::chrono::seconds(clearTime));

	//std::cout << "dungeon cleared in " << clearTime << std::endl;

	//this->isActive = false;
	//this->partiesServed += this->dungeonParties;
	//this->totalTimeServed += clearTime;
}

int Dungeon::randomClearTime()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(MIN_TIME, MAX_TIME);
	
	return distr(gen);
}

/*

	Getters

*/
int Dungeon::getId()
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

int Dungeon::getPartiesServed()
{
	return this->partiesServed;
}

int Dungeon::getTotalTimeServed()
{
	return this->totalTimeServed;
}

