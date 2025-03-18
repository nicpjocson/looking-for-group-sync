#include "Dungeon.h"
#include "QueueManager.h"

Dungeon::Dungeon(int id)
{
	this->id = id;
}

void Dungeon::startDungeon(int assignedParties)
{
	std::lock_guard<std::mutex> lock(this->guard);

	this->dungeonParties = assignedParties;

	this->isRunning = true;
	std::thread thread(&Dungeon::run, this);
	thread.detach();
}

void Dungeon::run()
{
	std::lock_guard<std::mutex> lock(this->guard);

	int clearTime = randomClearTime();

	this->isActive = true; // idk how this 
	//std::cout << "dungeon" << this->id << "with parties " << this->dungeonParties << std::endl;
	// Simulate dungeon clearing with sleep
	std::this_thread::sleep_for(std::chrono::seconds(clearTime));

	this->isActive = false; // idk how this works
	this->partiesServed += this->dungeonParties;
	this->totalTimeServed += clearTime;
	this->dungeonParties = 0;
	this->isRunning = false;
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

