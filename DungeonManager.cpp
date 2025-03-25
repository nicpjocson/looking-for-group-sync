#include "DungeonManager.h"
#include "PartyManager.h"

DungeonManager* DungeonManager::P_SHARED_INSTANCE = NULL;
DungeonManager::DungeonManager() {}
DungeonManager::DungeonManager(const DungeonManager&) {}

DungeonManager* DungeonManager::getInstance()
{
    if (P_SHARED_INSTANCE == NULL)
        P_SHARED_INSTANCE = new DungeonManager();

    return P_SHARED_INSTANCE;
}

void DungeonManager::initialize(unsigned int maxInstances, unsigned int minTime, unsigned int maxTime)
{
    this->maxInstances = maxInstances;
    this->minTime = minTime;
    this->maxTime = maxTime;
}

void DungeonManager::createDungeons()
{
    for (int i = 0; i < this->maxInstances; i++) {
        Dungeon* newDungeon = new Dungeon(&this->guard, i, this->minTime, this->maxTime);
        this->dungeons.push_back(newDungeon);
        newDungeon->startDungeon();
    }
}

void DungeonManager::run()
{
    this->isRunning = true;
    while (this->isRunning) {
        for (Dungeon* dungeon : this->dungeons) {
            // There is at least one party in queue
            if (PartyManager::getInstance()->getPartiesInQueue() > 0) {
                if (!dungeon->getIsActive()) {
                    dungeon->assignParty();
                    PartyManager::getInstance()->decreasePartiesInQueue();
                }
            }

            // Stop program when all parties are assigned (i.e., no more parties in queue)
            if (PartyManager::getInstance()->getPartiesInQueue() == 0) {
                this->isRunning = false;
                break;
            }
        }
    }

    this->waitForDungeonsToFinish();
}

void DungeonManager::waitForDungeonsToFinish()
{
    bool standby = true;

    while (standby) {
        standby = false;
        for (Dungeon* dungeon : this->dungeons) {
            if (dungeon->getIsRunning()) {  
                standby = true;
                break;
            }
        }
    }
}

/*

    Getters

*/
std::vector<Dungeon*> DungeonManager::getDungeons()
{
    return this->dungeons;
}

