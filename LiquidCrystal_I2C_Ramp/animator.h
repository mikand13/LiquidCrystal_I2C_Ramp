#ifndef ANIMATOR_H
#define ANIMATOR_H

#define COLUMNS 16
#define ROWS 2

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/**
 * This class defines the ramp animator for music. It initializes the LiquidCrystal_I2C lib
 * and accepts commands for ramping from 0 to 16. We default any values outside 0 - 16 to
 * 0 or 16 respectively.
 * 
 * @author Anders Mikkelsen
 * @version 04.10.2015
 */
class Animator {
  public:
    Animator(byte address, int rampLow, int rampHigh);

    void lcdRamp (int value);
  private:
    int rampLow;
    int rampHigh;

    void setUpLcd();
    void makeLcdChars();

    LiquidCrystal_I2C* lcd;
};

#endif
