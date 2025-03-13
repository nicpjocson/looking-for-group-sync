#include "Driver.h"

void Driver::initialize()
{
    // Create dungeons/threads
    for (int i = 0; i < MAX_DUNGEONS; i++) {
        this->dungeons.push_back(new Dungeon(i));
    }

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

void Driver::run()
{
    this->isRunning = true;
    this->createParties();

    while (isRunning)
    {
        // For each dungeon, search for parties
        for (Dungeon* dungeon : this->dungeons) {

            // At least one party looking for dungeon
            if (this->partyQueue.size() > 0) {
                dungeon->startDungeon();
            }
        }
    }

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

    Party-creation-related

*/
bool Driver::canCreateParty()
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

Party* Driver::createParty()
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

// Create as many full parties as possible
void Driver::createParties()
{
    while (this->canCreateParty()) 
    {
        Party* newParty = this->createParty();
        this->partyQueue.push(newParty);
    }

    this->handleLeftoverPlayers();
}

void Driver::handleLeftoverPlayers()
{
    this->leftoverTanks = this->tankQueue.size();
    this->leftoverHealers = this->healerQueue.size();
    this->leftoverDPS = this->dpsQueue.size();
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

void const Driver::displayLeftoverPlayers()
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

