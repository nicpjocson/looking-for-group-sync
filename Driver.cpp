#include "Driver.h"

void Driver::initialize()
{
}

void Driver::run()
{
}

/*
    Get the following parameters from the `config.txt` file:
        (1) n - max number of concurrent instances
        (2) t - no. of tank players in the queue
        (3) h - no. of healer players in the queue
        (4) d - no. of DPS players in the queue
        (5) t1 - min. time before an instance is finished
        (6) t2 - max. time before an instance is finished
*/
bool Driver::readConfig() {
    String line, key, value, scheduler;
    std::vector<String> parameters;
    int n, t, h, d, t1, t2;

    std::ifstream f("config.txt");

    if (!f.is_open()) {
        std::cerr << "Error opening the file!";
        return false;
    }

    while (getline(f, line)) {
        std::istringstream iss(line);
        iss >> key;
        getline(iss >> std::ws, value);

        if (value.front() == '\"' && value.back() == '\"') {
            value = value.substr(1, value.length() - 2);
        }
        parameters.push_back(value);
    }

    f.close();

    n = std::stoi(parameters[0]);
    t;
    h;
    d;
    t1;
    t2;

    //Start Detached Scheduler Thread
    std::thread schedulerThread([] {
        Scheduler::getInstance()->startScheduler();
        });

    schedulerThread.detach(); // Detach the thread

    return true;
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

