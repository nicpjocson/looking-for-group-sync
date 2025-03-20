#include "PartyManager.h"

PartyManager* PartyManager::P_SHARED_INSTANCE = NULL;
PartyManager::PartyManager() {}
PartyManager::PartyManager(const PartyManager&) {}

PartyManager* PartyManager::getInstance() 
{
    if (P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new PartyManager();

    return P_SHARED_INSTANCE;
}

void PartyManager::initialize(unsigned int tankPlayers, unsigned int healerPlayers, unsigned int dpsPlayers)
{
    this->tanksInQueue = tankPlayers;
    this->healersInQueue = healerPlayers;
    this->dpsInQueue = dpsPlayers;
}

/*

    Party-creation-related

*/
// Create as many full parties as possible
void PartyManager::createParties()
{
    // How many parties can be formed
    int partyCount = std::min({ this->tanksInQueue, this->healersInQueue, this->dpsInQueue / 3 });

    // Add parties to the queue
    for (int i = 0; i < partyCount; i++) {
        this->partiesInQueue++;
    }

    // Reduce the available players
    this->tanksInQueue -= partyCount;
    this->healersInQueue -= partyCount;
    this->dpsInQueue -= partyCount * 3;
}

/*

    Getters

*/
unsigned int PartyManager::getPartiesInQueue()
{
    std::lock_guard<std::mutex> lock(this->guard);
    return this->partiesInQueue;
}

unsigned int PartyManager::getTanksInQueue()
{
    return this->tanksInQueue;
}

unsigned int PartyManager::getHealersInQueue()
{
    return this->healersInQueue;
}

unsigned int PartyManager::getDPSInQueue()
{
    return this->dpsInQueue;
}

/*

    Other

*/
void PartyManager::decreasePartiesInQueue()
{
    std::lock_guard<std::mutex> lock(this->guard);
    this->partiesInQueue -= 1;
}

