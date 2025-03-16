#include "QueueManager.h"

QueueManager* QueueManager::P_SHARED_INSTANCE = NULL;
QueueManager::QueueManager() {}
QueueManager::QueueManager(const QueueManager&) {}

QueueManager* QueueManager::getInstance() 
{
    if (P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new QueueManager();

    return P_SHARED_INSTANCE;
}

/*

    Party-creation-related

*/
// Create as many full parties as possible
void QueueManager::createParties()
{
    unsigned int numTanks = TANK_PLAYERS;
    unsigned int numHealers = HEALER_PLAYERS;
    unsigned int numDPS = DPS_PLAYERS;

    // How many parties can be formed
    int partyCount = std::min({ numTanks, numHealers, numDPS / 3 });

    // Add parties to the queue
    for (int i = 0; i < partyCount; i++) {
        this->partiesInQueue++;
    }

    // Reduce the available players
    numTanks -= partyCount;
    numHealers -= partyCount;
    numDPS -= partyCount * 3;

    // Handle leftover players
    this->leftoverTanks = numTanks;
    this->leftoverHealers = numHealers;
    this->leftoverDPS = numDPS;
}

/*

    Getters

*/
unsigned int QueueManager::getPartiesInQueue()
{
    return this->partiesInQueue;
}

unsigned int QueueManager::getLeftoverTanks()
{
    return this->leftoverTanks;
}

unsigned int QueueManager::getLeftoverHealers()
{
    return this->leftoverHealers;
}

unsigned int QueueManager::getLeftoverDPS()
{
    return this->leftoverDPS;
}

/*

    Other

*/
void QueueManager::decrementPartiesInQueue()
{
    this->partiesInQueue--;
}

