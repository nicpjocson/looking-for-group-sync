#pragma once
#include "Tank.h"
#include "Healer.h"
#include "DPS.h"

class Party
{
public:
	Party(Tank* tank, Healer* healer, DPS* dps1, DPS* dps2, DPS* dps3);

private:
	Tank* tank;
	Healer* healer;
	DPS* dps1;
	DPS* dps2;
	DPS* dps3;
};

