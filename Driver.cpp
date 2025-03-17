#include "Driver.h"

// CHECKPOINT: program frozen if any value = -1 so idek if this function is useful at all
bool Driver::inputValidation()
{
    bool valid = true;

    valid &= this->checkBoundary("MAX_INSTANCES", MAX_INSTANCES);
    valid &= this->checkBoundary("TANK_PLAYERS", TANK_PLAYERS);
    valid &= this->checkBoundary("HEALER_PLAYERS", HEALER_PLAYERS);
    valid &= this->checkBoundary("DPS_PLAYERS", DPS_PLAYERS);
    valid &= this->checkBoundary("MIN_TIME", MIN_TIME);
    valid &= this->checkBoundary("MAX_TIME", MAX_TIME);

    return valid;
}

bool Driver::checkBoundary(const String& param, unsigned int value)
{
    // Unsigned integer
    unsigned int min = 0; // Minimum possible value
    // !! HAS WARNING
    unsigned int max = std::numeric_limits<unsigned int>::max(); // Max possible value

    std::cout << "checking " << param << " with expected range: " << min << ", " << max << std::endl;

    if (value < min) {
        std::cerr << "Error: " << param << " with value " << value << " is invalid. Minimum posssible value: " << std::endl;
        return false;
    }

    if (value > max) {
        std::cerr << "Error: " << param << " with value " << value << " is invalid. Minimum possible value: " << std::endl;
        return false;
    }

    std::cout << std::endl;
    return true;
}

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

    // Program is running
    while (isRunning)
    {
        for (Dungeon* dungeon : this->dungeons)
        {
            //int numParties = QueueManager::getInstance()->getPartiesInQueue();

            //if (numParties > 0)
            //{
            //    std::cout << "enter lop" << std::endl;

            //    int assignedParties = std::min(numParties, MAX_PARTIES);

            //    dungeon->startDungeon(assignedParties);
            //    
            //    QueueManager::getInstance()->decreasePartiesInQueue(assignedParties);
            //    std::cout << "after clear " << QueueManager::getInstance()->getPartiesInQueue() << std::endl << std::endl;
            //    
            //    checkProgramTermination();
            //}
        }
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

