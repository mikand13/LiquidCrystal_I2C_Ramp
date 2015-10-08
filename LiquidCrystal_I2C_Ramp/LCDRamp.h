#ifndef LCDRAMP_H
#define LCDRAMP_H

#define COLUMNS 16
#define ROWS 2

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/**
 * This class defines the ramp animator for an i2c liquid crystal screen. It initializes the LiquidCrystal_I2C lib
 * and accepts commands for ramping from users predefined rampLow and rampHigh. Values are defaulted if outside this,
 * respectively low or max. The input is then mapped to appropriate column value which is again computed to correct
 * animation.
 * 
 * @author Anders Mikkelsen
 * @version 04.10.2015
 */
class LCDRamp {
  public:
    LCDRamp(byte address, int rampLow, int rampHigh);

    void lcdRamp (int value);
  private:
    int rampLow;
    int rampHigh;

    void setUpLcd();
    void makeLcdChars();

    LiquidCrystal_I2C* lcd;
};

#endif
