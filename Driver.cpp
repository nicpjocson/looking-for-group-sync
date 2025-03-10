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
            // Assign Parties to Dungeon??
            while (MAX_PARTIES < this->partyQueue.size()) {
                dungeon->setIsFull(true);
                dungeon->setIsActive(true);

                for (int i = 0; i < MAX_PARTIES; i++) {
                    this->partyQueue.pop();
                }
            }

            dungeon->startDungeon();
        }
            //    // Assign Parties to Dungeon
            //    while (MAX_PARTIES < this->partyQueue.size()) {
            //        dungeon->setIsFull(true);
            //        dungeon->setIsActive(true);

        this->waitForThreadsToFinish();
            //        for (int i = 0; i < MAX_PARTIES; i++) {
            //            this->partyQueue.pop();
            //        }
            //    }

            //    dungeon->startDungeon();
            //}

            //this->waitForThreadsToFinish();
        }
    }
}

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

// Create as many full parties as possible
void Driver::createParties()
{
    while (this->canCreateParty()) 
    {
        this->createParty();
    }

    // TODO
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

void Driver::createParty()
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

    Party* newParty = new Party(newTank, newHealer, newDPS1, newDPS2, newDPS3);
    this->partyQueue.push(newParty);
    // DEBUG
    std::cout << "created new party " << this->partyQueue.size() - 1 << std::endl;
}

/*

    Printing functions

*/
void Driver::displayAllInstances(int maxDungeons) 
{
    for (int i = 0; i < maxDungeons; i++) {
        Dungeon* currDungeon = this->dungeons[i];

        // Only access available instances
        if (currDungeon->getIsAvailable()) {
            // DOUBLE CHECK: is this at the end of execution also????
            // If there is a party in the instance, the status should say "active"
            // If the instance is empty, the status should say "empty"
            bool isActive = currDungeon->getIsActive();
            displayStatus(isActive);
            
            // At the end of the execution there should be a summary of 
            // how many parties an instance have served and total time served
            int partiesServed = currDungeon->getPartiesServed();
            float totalTimeServed = currDungeon->getTotalTimeServed();
            std::cout << partiesServed << std::endl;
            std::cout << totalTimeServed << std::endl;

            // Leftover Players
            int leftoverTank = tankQueue.size();
            int leftoverHealer = healerQueue.size();
            int leftoverDPS = dpsQueue.size();

            if (leftoverTank > 0) {
                std::cout << "Leftover Tank Players: " << leftoverTank << std::endl;
            }
            if (leftoverHealer > 0) {
                std::cout << "Leftover Healer Players: " << leftoverHealer << std::endl;
            }
            if (leftoverDPS > 0) {
                std::cout << "Leftover DPS Players: " << leftoverDPS << std::endl;
            }
        }
    }
}

void Driver::displayStatus(bool isActive) 
{
    // Active Dungeon
    if (isActive) {
        std::cout << "Active" << std::endl;
    }
    // Empty Dungeon
    else {
        std::cout << "Empty" << std::endl;
    }
}

