#include "Dungeon.h"

// DOUBLE CHECK
Dungeon::Dungeon(int id)
{
	this->id = id;
	this->dungeonParties = {};
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
	while (this->dungeonParties.size() < MAX_PARTIES) // FIX???
	{
		// Add a party
		Party* newParty = QueueManager::getInstance()->getParty();
		this->dungeonParties.push_back(newParty);
	}

	// When full
	if (this->dungeonParties.size() == MAX_PARTIES) {
		this->clearDungeon();
	}
}

// DOUBLE CHECK
void Dungeon::clearDungeon()
{
	int clearTime = randomClearTime();
	std::cout << "parties in dungeon: " << this->dungeonParties.size() << std::endl;
	// Simulate clear
	std::this_thread::sleep_for(std::chrono::seconds(2/*clearTime*/));
	std::cout << "clearing dungeon..." << this->id << std::endl;
	this->dungeonCleared(clearTime);
}

// DOUBLE CHECK
void Dungeon::dungeonCleared(int clearTime)
{
	this->isActive = false;
	this->partiesServed += this->dungeonParties.size();
	this->totalTimeServed += clearTime;

	// "Empty" dungeon
	this->dungeonParties = {};
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

