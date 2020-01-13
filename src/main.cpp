#include <mbed.h>

#include "RS775_017_Motor.h"
#include "PR_Mecanum.h"
#include "RDS5160_Servo.h"
#include "PickUp.h"

namespace
{
DigitalIn UB(USER_BUTTON);
//足回り
uint32_t WHEEL_POWER = 100;

PwmOut FRpout(PA_8); //MD1
PwmOut FLpout(PA_0); //MD2
PwmOut RRpout(PA_6); //MD3
PwmOut RLpout(PB_6); //MD4

DigitalOut FRdout(PC_11);
DigitalOut FLdout(PD_2);
DigitalOut RRdout(PC_9);
DigitalOut RLdout(PB_9);

RS775Motor FRmotor(FRpout, FRdout, WHEEL_POWER, true);
RS775Motor FLmotor(FLpout, FLdout, WHEEL_POWER, true);
RS775Motor RRmotor(RRpout, RRdout, WHEEL_POWER, true);
RS775Motor RLmotor(RLpout, RLdout, WHEEL_POWER, true);

Mecanum mecanum(FRmotor, FLmotor, RRmotor, RLmotor, 150);

PwmOut ServoLout(PB_5);
PwmOut ServoRout(PB_4);

RDS5160Servo ServoL(ServoLout, 1400, true);
RDS5160Servo ServoR(ServoRout, 1600, false);

PickUp pickup(ServoL, ServoR);

DigitalOut PickUpClose(PC_4);

//その他
float CLOCK = 0.5;

Serial pc(USBTX, USBRX);

} // namespace

int main()
{
  /*
  mecanum.Brake();
  wait(1);
  mecanum.East(50);
  wait(1);
  mecanum.North(50);
  wait(1);
  mecanum.West(50);
  wait(1);
  mecanum.South(50);
  wait(1);
  */
}

void PickUpFlow() {

  /*
  while(1) {
    if(!UB.read()) {
      pickup.Horizontal();
    }
    else{
      pickup.Vertical();
    }
  }*/

  pickup.Vertical();
  PickUpClose.write(0);
  wait_ms(4000);

  pickup.Horizontal();
  wait_ms(4000);

  PickUpClose.write(1);
  wait_ms(4000);

  for (float i = 0.0f; i <= 90.0f; i += 1)
  {
    pickup.MoveTo(i);
    wait_ms(5);
  }
  /*
  pickup.MoveTo(30.0f);
  wait_ms(1000);
  //pickup.MoveTo(60.0f);
  wait_ms(1000);
  pickup.Vertical();*/
  wait_ms(2000);

  PickUpClose.write(0);
  /*
  while(1) {
    if(!UB.read()) {
      PickUpClose.write(1);
    }
    else {
      PickUpClose.write(0);
    }
  }*/
}