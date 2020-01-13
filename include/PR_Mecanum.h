#include <mbed.h>
#include "RS775_017_Motor.h"

/* 
 * オムニホイール4輪を制御するためのクラス．
 * motor.hをインクルードする前提．
 * メカナム4輪や，オムニ3輪も少し改造すれば簡単に実装できるはず．
 */

class Mecanum
{
private:
    RS775Motor &FR, &FL, &RR, &RL; // FrontRight, FrontLeft, RearRight, RearLeft
    const uint32_t pow;

public:
    /* Constructor */
    Mecanum(RS775Motor &, RS775Motor &, RS775Motor &, RS775Motor &, uint32_t pow);

    void Brake(void);
    void North(uint32_t PulseWidth);
    void East(uint32_t PulseWidth);
    void West(uint32_t PulseWidth);
    void South(uint32_t PulseWidth);
};
