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
    std::string filename = "config.txt";
    this->configValues = this->readConfig(filename);

    if (configValues.empty()) {
        std::cerr << "Error: Failed to read config file or it is empty." << std::endl;
        return false;
    }

    return this->validateConfig();
}

HashMap Driver::readConfig(String filename)
{
    HashMap config;
    std::ifstream f(filename);
    std::string line, key, value;

    if (!f.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return {};
    }

    while (getline(f, line)) {
        std::istringstream iss(line);
        iss >> key;

        if (iss.eof()) {
            value = "";
        }
        else {
            getline(iss >> std::ws, value);
            if (!value.empty() && value.front() == '"' && value.back() == '"') {
                value = value.substr(1, value.length() - 2);
            }
        }
        config[key] = value;
    }

    f.close();

    return config;
}

bool Driver::validateConfig() 
{
    bool valid = true;

    valid &= this->isValid("n", configValues["n"]);
    this->maxInstances = std::stoi(configValues["n"]);

    valid &= this->isValid("t", configValues["t"]);
    this->tankPlayers = std::stoi(configValues["t"]);

    valid &= this->isValid("h", configValues["h"]);
    this->healerPlayers = std::stoi(configValues["h"]);

    valid &= this->isValid("d", configValues["d"]);
    this->dpsPlayers = std::stoi(configValues["d"]);

    valid &= this->isValid("t1", configValues["t1"]);
    this->minTime = std::stoi(configValues["t1"]);

    valid &= this->isValid("t2", configValues["t2"]);
    this->maxTime = std::stoi(configValues["t2"]);

    return valid;
}

bool Driver::isValid(String param, String value)
{
    // Check for empty input
    if (value.empty()) {
        std::cerr << "Error in config.txt: " << param << " is empty." << std::endl;
        return false;
    }

    // Check for non-integer characters
    for (char c : value) {
        if (!isdigit(c)) {
            std::cerr << "Error in config.txt: " << param << " contains non-numeric characters: " << param << " = " << value << std::endl;
            return false;
        }
    }

    // Convert String to unsigned int
    unsigned int num = std::stoi(value);

    // Check exceeding max for unsigned int
    if (num > std::numeric_limits<unsigned int>::max()) {
        std::cerr << "Error in config.txt: " << param << " exceeds the max unsigned int value: " << param << " = " << value << std::endl;
        return false;
    }

    // Check dungeon and time == 0
    if (param == "n" || param == "t1" || param == "t2") {
        if (num == 0) {
            std::cerr << "Error in config.txt: " << param << " must be greater than 0." << std::endl;
            return false;
        }
    }

    // Handle checking time range
    if (param == "t2") {
        // Check if t2 <= 15
        if (num > 15) {
            std::cerr << "Error in config.txt: " << param << " is greater than 15: t2 = " << num << std::endl;
            return false;
        }
        // Check if t1 <= t2
        if (this->minTime > num) {
            std::cerr << "Error in config.txt: t1 is greater than t2." << std::endl;
            std::cerr << "t1 = " << this->minTime << ", t2 = " << num << std::endl;
            return false;
        }
    }

    return true;
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

