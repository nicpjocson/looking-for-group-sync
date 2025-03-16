#include "Driver.h"

void Driver::initialize()
{
    //QueueManager::getInstance()->initialize();
    QueueManager::getInstance()->createParties();
    this->createDungeons();
}

void Driver::createDungeons()
{
    // Create dungeons/threads
    for (int i = 0; i < MAX_DUNGEONS; i++) {
        Dungeon* newDungeon = new Dungeon(i);
        this->dungeons.push_back(newDungeon);
    }
}

void Driver::run()
{
    this->isRunning = true;

    while (isRunning)
    {
        //// For each dungeon, search for parties
        //for (Dungeon* dungeon : this->dungeons) {

        //    // At least one party looking for dungeon
        //    if (QueueManager::getInstance()->getPartyQueue().size() > 0) {
        //        dungeon->startDungeon();
        //    }
        //}
    }

    this->waitForThreadsToFinish();
    this->displaySummary();
}

// DOUBLE CHECK
void Driver::waitForThreadsToFinish()
{
    //bool standby = true;

    //while (standby) {
    //    standby = false;
    //    for (Dungeon* dungeon : this->dungeons) {
    //        if (dungeon->getIsRunning()) {
    //            standby = true;
    //            break;
    //        }
    //    }
    //}
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
    unsigned int leftoverTanks = QueueManager::getInstance()->getLeftoverTanks();
    unsigned int leftoverHealers = QueueManager::getInstance()->getLeftoverHealers();
    unsigned int leftoverDPS = QueueManager::getInstance()->getLeftoverDPS();

    std::cout << "Leftover Tanks: " << leftoverTanks << std::endl;
    std::cout << "Leftover Healers: " << leftoverHealers << std::endl;
    std::cout << "Leftover DPS: " << leftoverDPS << std::endl;
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

