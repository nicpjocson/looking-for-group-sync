#include "Driver.h"

void Driver::initialize()
{
    // Create dungeons/threads
    for (int i = 0; i < MAX_DUNGEONS; i++) {
        Dungeon* dungeon = new Dungeon;
        this->dungeons.push_back(dungeon);
    }

    // Initialize Tank queue
    for (int i = 0; i < TANK_PLAYERS; i++) {
        Tank* tank = new Tank;
        this->tankQueue.push(tank);
    }

    // Initialize Healer queue
    for (int i = 0; i < HEALER_PLAYERS; i++) {
        Healer* healer = new Healer;
        this->healerQueue.push(healer);
    }

    // Initialize DPS queue
    for (int i = 0; i < DPS_PLAYERS; i++) {
        DPS* dps = new DPS;
        this->dpsQueue.push(dps);
    }
}

void Driver::run()
{
    this->isRunning = true;
    while (isRunning)
    {
        // Can't create anymore full parties
        if (!canCreateParty()) {
            // End program
            this->isRunning = false;
            break;
        }

        // Create party
        Party newParty = createParty();

        // Search for first non-full dungeon
        for (Dungeon* dungeon : this->dungeons) {
            // If Dungeon is not full
            if (!dungeon->getIsFull()) {
                // Assign party to dungeon
                dungeon->addParty(newParty);
                //dungeon->startDungeon();
            }
        }

        //waitForThreadsToFinish();
        
        // clear full dungeons
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

bool Driver::canCreateParty()
{
    // Less players in queue than players required for full party
    if (this->tankQueue.size() < 3 || 
        this->healerQueue.size() < 1 ||
        this->dpsQueue.size() < 1) {
        return false;
    }
    
    // Enough players
    return true;
}

Party Driver::createParty()
{
    // Assign 1 Tank to party
    Tank* newTank = tankQueue.front();
    tankQueue.pop();

    // Assign 1 Healer to party
    Healer* newHealer = healerQueue.front();
    healerQueue.pop();

    // Assign 1 DPS to party
    DPS* newDPS1 = dpsQueue.front();
    dpsQueue.pop();
    DPS* newDPS2 = dpsQueue.front();
    dpsQueue.pop();
    DPS* newDPS3 = dpsQueue.front();
    dpsQueue.pop();

    return Party(newTank, newHealer, newDPS1, newDPS2, newDPS3);
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

