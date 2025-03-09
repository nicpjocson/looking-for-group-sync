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

const int MAX_INSTANCES = 10;
const int TANK_PLAYERS = 10;
const int HEALER_PLAYERS = 10;
const int DPS_PLAYERS = 30;
const int MIN_TIME = 5;
const int MAX_TIME = 15;

const int MAX_DUNGEONS = MAX_INSTANCES;
const int MAX_PARTIES = MAX_INSTANCES;

