#include "Driver.h"

void Driver::initialize()
{
    DungeonManager::getInstance()->initialize(this->maxInstances, this->minTime, this->maxTime);
    PartyManager::getInstance()->initialize(this->tankPlayers, this->healerPlayers, this->dpsPlayers);

    DungeonManager::getInstance()->createDungeons();
    PartyManager::getInstance()->createParties();
}

void Driver::run()
{
    DungeonManager::getInstance()->run();
    this->displaySummary();
}

/*

    Configuration-related functions

*/
bool Driver::getConfig()
{
    String filename = "config.txt";
    strList strConfigs = this->readConfig(filename);

    // File is empty or failed to read
    if (strConfigs.empty()) {
        std::cerr << "Error: Failed to read config file or it is empty." << std::endl;
        return false;
    }

    uintList numConfigs = this->validateConfig(strConfigs);

    // Validation failed
    if (numConfigs.empty()) {
        std::cerr << "Error: Configuration validation failed." << std::endl;
        return false;
    }

    this->setParams(numConfigs);

    return true;
}

strList Driver::readConfig(String filename) 
{
    String line, key, value;
    strList configValues;

    std::ifstream f(filename);

    if (!f.is_open()) {
        std::cerr << "Error opening the file.";
        return {};
    }

    while (getline(f, line)) {
        std::istringstream iss(line);
        iss >> key;
        getline(iss >> std::ws, value);

        if (value.front() == '\"' && value.back() == '\"') {
            value = value.substr(1, value.length() - 2);
        }
        configValues.push_back(value);
    }

    f.close();

    return configValues;
}

uintList Driver::validateConfig(strList strConfigs)
{
    uintList numConfigs(strConfigs.size(), 0);
    bool valid = true;

    if (!this->isValid("MAX_INSTANCES", strConfigs[0])) valid = false;
    else numConfigs[0] = std::stoi(strConfigs[0]);

    if (!this->isValid("TANK_PLAYERS", strConfigs[1])) valid = false;
    else numConfigs[1] = std::stoi(strConfigs[1]);

    if (!this->isValid("HEALER_PLAYERS", strConfigs[2])) valid = false;
    else numConfigs[2] = std::stoi(strConfigs[2]);

    if (!this->isValid("DPS_PLAYERS", strConfigs[3])) valid = false;
    else numConfigs[3] = std::stoi(strConfigs[3]);

    if (!this->isValid("MIN_TIME", strConfigs[4])) valid = false;
    else numConfigs[4] = std::stoi(strConfigs[4]);

    if (!this->isValid("MAX_TIME", strConfigs[5])) valid = false;
    else numConfigs[5] = std::stoi(strConfigs[5]);

    if (!valid) {
        return {};
        std::cout << std::endl;
    }

    return numConfigs;
}

bool Driver::isValid(String param, String value)
{
    // Check for empty input
    if (value.empty()) {
        std::cerr << "Error: " << param << " is empty." << std::endl;
        return false;
    }

    // Check for non-integer characters
    for (char c : value) {
        if (!isdigit(c)) {
            std::cerr << "Error: " << param << " contains non-numeric characters." << std::endl;
            return false;
        }
    }

    // Convert String to unsigned int
    unsigned int num = std::stoi(value);

    // Check exceeding max for unsigned int
    if (num > std::numeric_limits<unsigned int>::max()) {
        std::cerr << "Error: " << param << " exceeds the max unsigned int value." << std::endl;
        return false;
    }

    return true;
}

void Driver::setParams(uintList parameters)
{
    this->maxInstances = parameters[0];
    this->tankPlayers = parameters[1];
    this->healerPlayers = parameters[2];
    this->dpsPlayers = parameters[3];
    this->minTime = parameters[4];
    this->maxTime = parameters[5];
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
    for (Dungeon* dungeon : DungeonManager::getInstance()->getDungeons()) {
        std::cout << "DUNGEON " << dungeon->getId() << std::endl;
        std::cout << "Status: " << this->getStatus(dungeon->getIsActive()) << std::endl;
        std::cout << "Parties served: " << dungeon->getPartiesServed() << std::endl;
        std::cout << "Total time served: " << dungeon->getTotalTimeServed() << std::endl << std::endl;
    }
}

void Driver::displayLeftoverPlayers()
{
    unsigned int leftoverTanks = PartyManager::getInstance()->getTanksInQueue();
    unsigned int leftoverHealers = PartyManager::getInstance()->getHealersInQueue();
    unsigned int leftoverDPS = PartyManager::getInstance()->getDPSInQueue();

    std::cout << "Leftover Tanks: " << leftoverTanks << std::endl;
    std::cout << "Leftover Healers: " << leftoverHealers << std::endl;
    std::cout << "Leftover DPS: " << leftoverDPS << std::endl;
}

String Driver::getStatus(bool isActive)
{
    // At leats one party in instance
    if (isActive) return "Active";

    /// Empty instance
    else return "Empty";
}

