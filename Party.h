#pragma once
#include "Tank.h"
#include "Healer.h"
#include "DPS.h"

class Party
{
public:
	Party(Tank* tank1, Tank* tank2, Tank* tank3, Healer* healer, DPS* dps);

private:
	Tank* tank1;
	Tank* tank2;
	Tank* tank3;
	Healer* healer;
	DPS* dps;
};

