#include "Driver.h"

void Driver::initialize()
{
}

void Driver::run()
{
}



    }


        }
    }
}

void displayAllInstances(int maxDungeons) {

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

