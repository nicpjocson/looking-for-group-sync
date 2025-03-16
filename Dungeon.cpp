#include "Dungeon.h"
#include "QueueManager.h"

// DOUBLE CHECK
Dungeon::Dungeon(int id)
{
	this->id = id;
	this->dungeonParties = 0;
	this->isActive = false;
	this->partiesServed = 0;
	this->totalTimeServed = 0;
}

//void Dungeon::startDungeon() 
//{
//	this->isRunning = true;
//	std::thread thread(&Dungeon::searchForParties, this);
//	thread.detach();
//
//	// DEBUG
//	std::cout << "started dungeon/thread " << this->id << std::endl;
//}
//
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
///*
//	
//	Getters
//
//*/
//int Dungeon::getId()
//{
//	return this->id;
//}
//
//bool Dungeon::getIsRunning()
//{
//	return this->isRunning;
//}
//
///*
//	Dungeon Status
//	* ACTIVE: Returns true if dungeon has at least one party.
//	* EMPTY: Returns false, otherwise.
//*/
//bool Dungeon::getIsActive()
//{
//	return this->isActive;
//}
//
//int Dungeon::getPartiesServed()
//{
//	return this->partiesServed;
//}
//
//int Dungeon::getTotalTimeServed()
//{
//	return this->totalTimeServed;
//}

