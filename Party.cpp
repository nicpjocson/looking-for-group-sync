#include "Party.h"

Party::Party(Tank* tank1, Tank* tank2, Tank* tank3, Healer* healer, DPS* dps) {
	this->tank1 = tank1;
	this->tank2 = tank2;
	this->tank3 = tank3;
	this->healer = healer;
	this->dps = dps;
}

