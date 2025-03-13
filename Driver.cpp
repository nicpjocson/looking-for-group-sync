#include "Driver.h"

void Driver::initialize()
{
    // Create dungeons/threads
    for (int i = 0; i < MAX_DUNGEONS; i++) {
        this->dungeons.push_back(new Dungeon(i));
    }

    QueueManager::getInstance()->initialize();
}

void Driver::run()
{
    this->isRunning = true;
    QueueManager::getInstance()->createParties();

    while (isRunning)
    {
        // For each dungeon, search for parties
        for (Dungeon* dungeon : this->dungeons) {

            // At least one party looking for dungeon
            if (QueueManager::getInstance()->getPartyQueue().size() > 0) {
                dungeon->startDungeon();
            }
        }
    }

    this->waitForThreadsToFinish();
    this->displaySummary();
}

// DOUBLE CHECK
void Driver::waitForThreadsToFinish()
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

    Printing functions

*/
void Driver::displaySummary()
{
    std::cout << "==================================================" << std::endl;
    std::cout << "SUMMARY" << std::endl;
    std::cout << "==================================================" << std::endl;
    this->displayAllInstances();
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "LEFTOVER PLAYERS" << std::endl;
    this->displayLeftoverPlayers();
}

void Driver::displayAllInstances() 
{
    // For all available dungeons
    for (Dungeon* dungeon : this->dungeons)
    {
        std::cout << "DUNGEON " << dungeon->getId() << std::endl;
        std::cout << "Status: " << this->getStatus(dungeon->getIsActive()) << std::endl;
        std::cout << "Parties served: " << dungeon->getPartiesServed() << std::endl;
        std::cout << "Total time served: " << dungeon->getTotalTimeServed() << std::endl;
    }
}

void Driver::displayLeftoverPlayers()
{
    std::cout << "Leftover Tanks: " << this->leftoverTanks << std::endl;
    std::cout << "Leftover Healers: " << this->leftoverHealers << std::endl;
    std::cout << "Leftover DPS: " << this->leftoverDPS << std::endl;
}

String Driver::getStatus(bool isActive) 
{
    String status;

    // At leats one party in instance
    if (isActive) {
        status = "Active";
    }
    /// Empty instance
    else {
       status = "Empty";
    }

    return status;
}

