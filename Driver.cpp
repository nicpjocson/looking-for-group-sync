#include "Driver.h"

void Driver::initialize()
{
    // TODO check
    for (int i = 0; i < MAX_DUNGEONS; i++) {
        //Dungeon dungeon();
        //this->dungeons.push_back(dungeon);
    }

    // Initialize Tank queue
    for (int i = 0; i < TANK_PLAYERS; i++) {
        Tank* tank = new Tank;
        tankQueue.push(tank);
    }

    // Initialize Healer queue
    for (int i = 0; i < HEALER_PLAYERS; i++) {
        Healer* healer = new Healer;
        healerQueue.push(healer);
    }

    // Initialize DPS queue
    for (int i = 0; i < DPS_PLAYERS; i++) {
        DPS* dps = new DPS;
        dpsQueue.push(dps);
    }
}

void Driver::run()
{
    while (isRunning) {
        Party newParty = createParty();

        // Search for first non-full dungeon
        for (int i = 0; i < MAX_DUNGEONS; i++) {
            Dungeon currDungeon = this->dungeons[i];

            // If Dungeon is not full
            if (!currDungeon.getIsFull()) {
                // Assign party to dungeon
                currDungeon.addParty(newParty);
            }
        }
    }
}

Party Driver::createParty() 
{
    // Assign 3 Tanks to party
    Tank* newTank1 = tankQueue.front();
    tankQueue.pop();
    Tank* newTank2 = tankQueue.front();
    tankQueue.pop();
    Tank* newTank3 = tankQueue.front();
    tankQueue.pop();

    // Assign 1 Healer to party
    Healer* newHealer = healerQueue.front();
    healerQueue.pop();

    // Assign 1 DPS to party
    DPS* newDPS = dpsQueue.front();
    dpsQueue.pop();

    return Party(newTank1, newTank2, newTank3, newHealer, newDPS);
}

    for (int i = 0; i < maxDungeons; i++) {
        Dungeon currDungeon = dungeons[i];

        // all available instances
        if (currDungeon.getIsAvailable()) {
            // If there is a party in the instance, the status should say "active"

            // If the instance is empty, the status should say "empty"
            // At the end of the execution there should be a summary of how many parties an instance have served and total time served.

        }
    }

}

/*

    Getters

*/
//bool Driver::getIsRunning() {
//    return this->isRunning;
//}

