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

void QueueManager::initialize(unsigned int tankPlayers, unsigned int healerPlayers, unsigned int dpsPlayers)
{
    this->tanksInQueue = tankPlayers;
    this->healersInQueue = healerPlayers;
    this->dpsInQueue = dpsPlayers;
}

/*

    Party-creation-related

*/
// Create as many full parties as possible
void QueueManager::createParties()
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

    std::cout << this->partiesInQueue << " parties created" << std::endl;
}

/*

    Getters

*/
unsigned int QueueManager::getPartiesInQueue()
{
    std::lock_guard<std::mutex> lock(this->guard);
    return this->partiesInQueue;
}

unsigned int QueueManager::getTanksInQueue()
{
    return this->tanksInQueue;
}

unsigned int QueueManager::getHealersInQueue()
{
    return this->healersInQueue;
}

unsigned int QueueManager::getDPSInQueue()
{
    return this->dpsInQueue;
}

/*

    Other

*/
void QueueManager::decreasePartiesInQueue()
{
    std::lock_guard<std::mutex> lock(this->guard);
    this->partiesInQueue -= 1;
}

