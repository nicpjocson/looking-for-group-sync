#pragma once
#include <iostream>
#include <algorithm>
#include <queue>
#include <mutex>

class PartyManager
{
public:
    static PartyManager* getInstance();
    void initialize(unsigned int tankPlayers, unsigned int healerPlayers, unsigned int dpsPlayers);
    void createParties();

    // Getters
    unsigned int getPartiesInQueue();
    unsigned int getTanksInQueue();
    unsigned int getHealersInQueue();
    unsigned int getDPSInQueue();

    // Other
    void decreasePartiesInQueue();

private:
    static PartyManager* P_SHARED_INSTANCE;

private:
    PartyManager();
    PartyManager(const PartyManager&);
    PartyManager& operator = (const PartyManager&);

    std::mutex guard;

    unsigned int partiesInQueue = 0;
    unsigned int tanksInQueue = 0;
    unsigned int healersInQueue = 0;
    unsigned int dpsInQueue = 0;
};

