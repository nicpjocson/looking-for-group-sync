#include "Dungeon.h"
//#include "QueueManager.h"

Dungeon::Dungeon(int id)
{
	this->id = id;
	this->dungeonParties = 0;
	this->isActive = false;
	this->partiesServed = 0;
	this->totalTimeServed = 0;
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

//// !! used to be in Driver class
//// !! verify if should keep here
//void Dungeon::searchForParties()
//{
//	// Dungeon is not full
//	// FIX: INFINITE LOOPING
//	while (this->dungeonParties.size() < MAX_PARTIES)
//	{
//		// Add a party
//		Party* newParty = QueueManager::getInstance()->getParty();
//		this->dungeonParties.push_back(newParty);
//		std::cout << "3333333333" << std::endl;
//	}
//	std::cout << "4444444444" << std::endl;
//	// When full
//	if (this->dungeonParties.size() == MAX_PARTIES) {
//		std::cout << "5555555555" << std::endl;
//		this->clearDungeon();
//	}
//	std::cout << "7777777777" << std::endl;
//}
//
//// DOUBLE CHECK
//void Dungeon::clearDungeon()
//{
//	int clearTime = randomClearTime();
//	std::cout << "parties in dungeon: " << this->dungeonParties.size() << std::endl;
//	// Simulate clear
//	std::this_thread::sleep_for(std::chrono::seconds(2/*clearTime*/));
//	std::cout << "clearing dungeon..." << this->id << std::endl;
//	this->dungeonCleared(clearTime);
//}
//
//// DOUBLE CHECK
//void Dungeon::dungeonCleared(int clearTime)
//{
//	this->isActive = false;
//	this->partiesServed += this->dungeonParties.size();
//	this->totalTimeServed += clearTime;
//
//	// "Empty" dungeon
//	this->dungeonParties = {};
//	this->isRunning = false;
//	// CHECKPOINT: NEVER PRINTS
//	std::cout << "cleared dungeon" << this->id << std::endl;
//}
//
//// DOUBLE CHECK
//int Dungeon::randomClearTime()
//{
//	return rand() % MAX_TIME - MIN_TIME;
//}
//

//bool Dungeon::getIsRunning()
//{
//	return this->isRunning;
//}
//

