#include "Party.h"

Party::Party(Tank* tank, Healer* healer, DPS* dps1, DPS* dps2, DPS* dps3) {
	this->tank = tank;
	this->healer = healer;
	this->dps1 = dps1;
	this->dps2 = dps2;
	this->dps3 = dps3;
}

