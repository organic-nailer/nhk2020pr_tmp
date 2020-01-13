#include "PR_Mecanum.h"
#include <math.h>

int8_t ufo(int8_t a);

Mecanum::Mecanum(RS775Motor &_FR, RS775Motor &_FL, RS775Motor &_RR, RS775Motor &_RL, uint32_t _pow) : FR(_FR), FL(_FL), RR(_RR), RL(_RL), pow(_pow)
{
}

void Mecanum::Brake(void)
{
    FR.Brake();
    FL.Brake();
    RR.Brake();
    RL.Brake();
}

// CW: 右回転 CCW: 左回転のつもり

void Mecanum::North(uint32_t pulsewidth)
{
    FR.CCW(pulsewidth);
    FL.CW(pulsewidth);
    RR.CW(pulsewidth);
    RL.CCW(pulsewidth);
}

void Mecanum::East(uint32_t pulsewidth)
{
    FR.CW(pulsewidth);
    FL.CW(pulsewidth);
    RR.CW(pulsewidth);
    RL.CW(pulsewidth);
}

void Mecanum::West(uint32_t pulsewidth)
{
    FR.CCW(pulsewidth);
    FL.CCW(pulsewidth);
    RR.CCW(pulsewidth);
    RL.CCW(pulsewidth);
}

void Mecanum::South(uint32_t pulsewidth)
{
    FR.CW(pulsewidth);
    FL.CCW(pulsewidth);
    RR.CCW(pulsewidth);
    RL.CW(pulsewidth);
}