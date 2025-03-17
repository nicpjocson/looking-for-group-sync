#include "Driver.h"

void Driver::initialize()
{
    QueueManager::getInstance()->createParties();
    this->createDungeons();
}

void Driver::createDungeons()
{
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
        for (Dungeon* dungeon : this->dungeons)
        {
            int numParties = QueueManager::getInstance()->getPartiesInQueue();

            if (numParties > 0)
            {
                std::cout << "enter lop" << std::endl;

                int assignedParties = std::min(numParties, MAX_PARTIES);

                dungeon->startDungeon(assignedParties);
                
                std::cout << "BEFORE decrement " << QueueManager::getInstance()->getPartiesInQueue() << std::endl;
                QueueManager::getInstance()->decreasePartiesInQueue(assignedParties);
                std::cout << "AFTER decrement " << QueueManager::getInstance()->getPartiesInQueue() << std::endl;
                
                // Stop program when all parties are assinged (i.e., no more parties in queue)
                // TODO: make separate func?
                if (QueueManager::getInstance()->getPartiesInQueue() == 0) {
                    this->isRunning = false;
                    break;
                }
            }
        }

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

void Driver::checkProgramTermination()
{
    // Stop program when all parties are assinged (i.e., no more parties in queue)
    if (QueueManager::getInstance()->getPartiesInQueue() == 0) {
        this->isRunning = false;
    }
}

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
        std::cout << "Total time served: " << dungeon->getTotalTimeServed() << std::endl << std::endl;
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

