#include "DungeonManager.h"
#include "PartyManager.h"
#include "Dungeon.h"

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
    unsigned int dungeonIndex = 0;

    while (this->isRunning) {
        if (PartyManager::getInstance()->getPartiesInQueue() > 0) {
            Dungeon* dungeon = this->dungeons[dungeonIndex];

            // Dungeon is empty
            if (!dungeon->getIsActive()) {
                // Assign party
                dungeon->assignParty();
                // Decrement parties in queue
                PartyManager::getInstance()->decreasePartiesInQueue();
            }

            // Cycle through dungeons
            dungeonIndex = (dungeonIndex + 1) % this->dungeons.size();
        }

        if (PartyManager::getInstance()->getPartiesInQueue() == 0) {
            this->isRunning = false;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
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

