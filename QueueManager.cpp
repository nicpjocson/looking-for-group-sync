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

void QueueManager::initialize()
{
    // Initialize Tank queue
    for (int i = 0; i < TANK_PLAYERS; i++) {
        this->tankQueue.push(new Tank);
    }

    // Initialize Healer queue
    for (int i = 0; i < HEALER_PLAYERS; i++) {
        this->healerQueue.push(new Healer);
    }

    // Initialize DPS queue
    for (int i = 0; i < DPS_PLAYERS; i++) {
        this->dpsQueue.push(new DPS);
    }
}

/*

    Party-creation-related

*/
// Create as many full parties as possible
void QueueManager::createParties()
{
    while (this->canCreateParty())
    {
        Party* newParty = this->createParty();
        this->partyQueue.push(newParty);
    }

    this->handleLeftoverPlayers();
}

bool QueueManager::canCreateParty()
{
    // Less players in queue than players required for full party
    if (this->tankQueue.size() < 1 ||
        this->healerQueue.size() < 1 ||
        this->dpsQueue.size() < 3) {
        return false;
    }

    // There are enough players for full party
    return true;
}

Party* QueueManager::createParty()
{
    // Assign 1 Tank to Party
    Tank* newTank = this->tankQueue.front();
    this->tankQueue.pop();

    // Assign 1 Healer to Party
    Healer* newHealer = this->healerQueue.front();
    this->healerQueue.pop();

    // Assign 3 DPS to Party
    DPS* newDPS1 = this->dpsQueue.front();
    this->dpsQueue.pop();
    DPS* newDPS2 = this->dpsQueue.front();
    this->dpsQueue.pop();
    DPS* newDPS3 = this->dpsQueue.front();
    this->dpsQueue.pop();

    // DEBUG
    std::cout << "created new party " << this->partyQueue.size() - 1 << std::endl;

    Party* newParty = new Party(newTank, newHealer, newDPS1, newDPS2, newDPS3);
    
    return newParty;
}

void QueueManager::handleLeftoverPlayers()
{
    this->leftoverTanks = this->tankQueue.size();
    this->leftoverHealers = this->healerQueue.size();
    this->leftoverDPS = this->dpsQueue.size();
}

/*

    Getters

*/
std::queue<Party*> QueueManager::getPartyQueue()
{
    return this->partyQueue;
}

std::queue<Tank*> QueueManager::getTankQueue()
{
    return this->tankQueue;
}

std::queue<Healer*> QueueManager::getHealerQueue()
{
    return this->healerQueue;
}

std::queue<DPS*> QueueManager::getDPSQueue()
{
    return this->dpsQueue;
}

/*

    Other

*/
Party* QueueManager::getParty()
{
    this->guard.lock();
    Party* party = this->getFrontPartyQueue();
    this->guard.unlock();

    return party;
}

Party* QueueManager::getFrontPartyQueue()
{
    Party* party = this->partyQueue.front();
    this->partyQueue.pop();

    return party;
}

