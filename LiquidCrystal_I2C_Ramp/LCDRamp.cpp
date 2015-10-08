#ifndef LCDRAMP_CPP
#define LCDRAMP_CPP

#include "LCDRamp.h"

LCDRamp::LCDRamp(byte address, int rampLow, int rampHigh)
    : rampLow(rampLow),rampHigh(rampHigh) {
  *lcd = LiquidCrystal_I2C(address, COLUMNS, ROWS);
}

void LCDRamp::lcdRamp (int value) {
  lcd->clear();

  value = value > rampHigh ? rampHigh : value;
  value = value < rampLow ? rampLow : value;

  int lcdValue = map(value, rampLow, rampHigh, 0, COLUMNS);

  if (lcdValue > COLUMNS) {
    lcdValue = COLUMNS;
  } else if (lcdValue < 0) {
    lcdValue = 0;
  }

  for (int i = 0; i < lcdValue; i++){
    lcd->setCursor(i, 1);
    
    if (i == 0) {
      lcd->write(i);
    } else if (i > COLUMNS / 2) {
      lcd->write(COLUMNS / 2 - 1);

      lcd->setCursor(i, 0);
      lcd->write(i - (COLUMNS / 2 + 1));
    } else {
      lcd->write(i - 1);
    }
  }
} 

void LCDRamp::makeLcdChars() {
  byte ramp[COLUMNS / 2][8] = { 
      { 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b11111 }, 
      { 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b11111, 0b11111 }, 
      { 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b11111, 0b11111, 0b11111 }, 
      { 0b00000, 0b00000, 0b00000, 0b00000, 0b11111, 0b11111, 0b11111, 0b11111 }, 
      { 0b00000, 0b00000, 0b00000, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111 }, 
      { 0b00000, 0b00000, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111 }, 
      { 0b00000, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111 }, 
      { 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111 } 
    };
    
  for (int i = 0; i < COLUMNS / 2; i++) {
    lcd->createChar(i, ramp[i]);
  }
}

void LCDRamp::setUpLcd() {
  lcd->begin(COLUMNS, ROWS);
  lcd->init();
  lcd->backlight();
  
  // set up ramp
  makeLcdChars(); 
}

#endif
