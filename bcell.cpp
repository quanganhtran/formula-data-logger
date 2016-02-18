#include "bcell.h"

BCell::BCell()
{

}

BCell::BCell(int16_t id0) : id(id0)
{

}

BCell::BCell(int16_t id0, int16_t voltage0, int16_t temp0) : id(id0), voltage(voltage0), temp(temp0)
{

}

