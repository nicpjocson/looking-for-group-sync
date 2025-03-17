#pragma once
#include <iostream>
#include <queue>
#include <mutex>

#include "config.h"

class QueueManager
{
public:
    static QueueManager* getInstance();

    void createParties();

    // Getters
    unsigned int getPartiesInQueue();
    unsigned int getLeftoverTanks();
    unsigned int getLeftoverHealers();
    unsigned int getLeftoverDPS();

    // Other
    void decreasePartiesInQueue(int numParties);

private:
    static QueueManager* P_SHARED_INSTANCE;

private:
    QueueManager();
    QueueManager(const QueueManager&);
    QueueManager& operator = (const QueueManager&);

    std::mutex guard;

    unsigned int partiesInQueue = 0;
    unsigned int tanksInQueue = 0;
    unsigned int healersInQueue = 0;
    unsigned int dpsInQueue = 0;

    unsigned int leftoverTanks = 0;
    unsigned int leftoverHealers = 0;
    unsigned int leftoverDPS = 0;
};

