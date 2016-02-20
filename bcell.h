#ifndef BCELL_H
#define BCELL_H
#include <cstdint>

class BCell
{
public:
    explicit BCell();
    explicit BCell(int16_t id0);
    explicit BCell(int16_t id0, int16_t voltage0, int16_t temp0);
    int16_t id;
    int16_t voltage = 0;
    int16_t temp = 0;
};

#endif // BCELL_H
