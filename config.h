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

// no dungeons reused, whole parties, has leftover
// 4 parties, leftover: 1 tank, 1 healer, 2 dps
//const unsigned int MAX_INSTANCES = 4;
//const unsigned int TANK_PLAYERS = 17;
//const unsigned int HEALER_PLAYERS = 17;
//const unsigned int DPS_PLAYERS = 50;
//const unsigned int MIN_TIME = 1;
//const unsigned int MAX_TIME = 5;

// dungeons reused, nonwhole parties, no leftover
// 4 + 2 1/2 parties, 0 leftover
//const unsigned int MAX_INSTANCES = 4;
//const unsigned int TANK_PLAYERS = 26;
//const unsigned int HEALER_PLAYERS = 26;
//const unsigned int DPPLAYERS = 78;
//const unsigned int MIN_TIME = 1;
//const unsigned int MAX_TIME = 5;

// dungeons reused, nonwhole parties, has leftover
// 4 + 2 1/2 parties, leftover: 0 tank, 1 healer, 2 dps
const unsigned int MAX_INSTANCES = 4;
const unsigned int TANK_PLAYERS = 26;
const unsigned int HEALER_PLAYERS = 27;
const unsigned int DPS_PLAYERS = 80;
const unsigned int MIN_TIME = 1;
const unsigned int MAX_TIME = 5;

const unsigned int MAX_DUNGEONS = MAX_INSTANCES;
const unsigned int MAX_PARTIES = MAX_INSTANCES;

