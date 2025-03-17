#pragma once

/*
    Program parameters:
        (1) MAX_INSTANCES  - max. no. of concurrent instances
            * max. no. of dungeons
            * max. no. of parties in a dungeon
        (2) TANK_PLAYERS   - no. of tank players in the queue
        (3) HEALER_PLAYERS - no. of healer players in the queue
        (4) DPS_PLAYERS    - no. of DPS players in the queue
        (5) MIN_TIME       - min. time before an instance is finished
        (6) MAX_TIME       - max. time before an instance is finished
*/

//const unsigned int MAX_INSTANCES = 4;
//const unsigned int TANK_PLAYERS = 17;
//const unsigned int HEALER_PLAYERS = 17;
//const unsigned int DPS_PLAYERS = 51;
//const unsigned int MIN_TIME = 1;
//const unsigned int MAX_TIME = 5;
const unsigned int MAX_INSTANCES = 4;
const unsigned int TANK_PLAYERS = 26;
const unsigned int HEALER_PLAYERS = 26;
const unsigned int DPS_PLAYERS = 78;
const unsigned int MIN_TIME = 1;
const unsigned int MAX_TIME = 5;

const unsigned int MAX_DUNGEONS = MAX_INSTANCES;
const unsigned int MAX_PARTIES = MAX_INSTANCES;

