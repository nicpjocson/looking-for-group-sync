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

//void QueueManager::initialize()
//{
//    // Initialize Tank queue
//    for (int i = 0; i < TANK_PLAYERS; i++) {
//        Tank* newTank = new Tank;
//        this->tankQueue.push(newTank);
//    }
//
//    // Initialize Healer queue
//    for (int i = 0; i < HEALER_PLAYERS; i++) {
//        Healer* newHealer = new Healer;
//        this->healerQueue.push(newHealer);
//    }
//
//    // Initialize DPS queue
//    for (int i = 0; i < DPS_PLAYERS; i++) {
//        DPS* newDPS = new DPS;
//        this->dpsQueue.push(newDPS);
//    }
//}

/*

    Party-creation-related

*/
// Create as many full parties as possible
void QueueManager::createParties()
{
    //while (this->canCreateParty())
    //{
    //    Party* newParty = this->createParty();
    //    this->partyQueue.push(newParty);
    //}

    //this->handleLeftoverPlayers();

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

//bool QueueManager::canCreateParty()
//{
//    // Less players in queue than players required for full party
//    if (this->tankQueue.size() < 1 ||
//        this->healerQueue.size() < 1 ||
//        this->dpsQueue.size() < 3) {
//        return false;
//    }
//
//    // There are enough players for full party
//    return true;
//}

//Party* QueueManager::createParty()
//{
//    // Assign 1 Tank to Party
//    Tank* newTank = this->tankQueue.front();
//    this->tankQueue.pop();
//
//    // Assign 1 Healer to Party
//    Healer* newHealer = this->healerQueue.front();
//    this->healerQueue.pop();
//
//    // Assign 3 DPS to Party
//    DPS* newDPS1 = this->dpsQueue.front();
//    this->dpsQueue.pop();
//    DPS* newDPS2 = this->dpsQueue.front();
//    this->dpsQueue.pop();
//    DPS* newDPS3 = this->dpsQueue.front();
//    this->dpsQueue.pop();
//
//    // DEBUG
//    std::cout << "created new party " << this->partyQueue.size() - 1 << std::endl;
//
//    Party* newParty = new Party(newTank, newHealer, newDPS1, newDPS2, newDPS3);
//    
//    return newParty;
//}

//void QueueManager::handleLeftoverPlayers()
//{
//    this->leftoverTanks = this->tankQueue.size();
//    this->leftoverHealers = this->healerQueue.size();
//    this->leftoverDPS = this->dpsQueue.size();
//}

/*

    Getters

*/
//std::queue<Party*> QueueManager::getPartyQueue()
//{
//    return this->partyQueue;
//}
//
//std::queue<Tank*> QueueManager::getTankQueue()
//{
//    return this->tankQueue;
//}
//
//std::queue<Healer*> QueueManager::getHealerQueue()
//{
//    return this->healerQueue;
//}
//
//std::queue<DPS*> QueueManager::getDPSQueue()
//{
//    return this->dpsQueue;
//}

/*

    Other

*/
//Party* QueueManager::getParty()
//{
//    this->guard.lock();
//    Party* party = this->getFrontPartyQueue();
//    this->guard.unlock();
//
//    return party;
//}
//
//Party* QueueManager::getFrontPartyQueue()
//{
//    Party* party = this->partyQueue.front();
//    this->partyQueue.pop();
//
//    return party;
//}

