#pragma once
#include <iostream>
#include <queue>
#include <mutex>

#include "config.h"
//#include "Party.h"

class QueueManager
{
public:
    static QueueManager* getInstance();

    //std::queue<Party*> getPartyQueue();
    //std::queue<Tank*> getTankQueue();
    //std::queue<Healer*> getHealerQueue();
    //std::queue<DPS*> getDPSQueue();

    //Party* getParty();
    //Party* getFrontPartyQueue();

    //void initialize();
    void createParties();

private:
    static QueueManager* P_SHARED_INSTANCE;

private:
    QueueManager();
    QueueManager(const QueueManager&);
    QueueManager& operator = (const QueueManager&);

    std::mutex guard;

    //std::queue<Party*> partyQueue;
    //std::queue<Tank*> tankQueue;
    //std::queue<Healer*> healerQueue;
    //std::queue<DPS*> dpsQueue;

    unsigned int partiesInQueue = 0;
    unsigned int tanksInQueue = 0;
    unsigned int healersInQueue = 0;
    unsigned int dpsInQueue = 0;

    unsigned int leftoverTanks = 0;
    unsigned int leftoverHealers = 0;
    unsigned int leftoverDPS = 0;

    //bool canCreateParty();
    //Party* createParty();
    //void handleLeftoverPlayers();
};

