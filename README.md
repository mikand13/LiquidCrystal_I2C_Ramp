# LiquidCrystal_I2C_Ramp
Ramp Animation for Arduino LCD I2C Screen

## Usage

* This will connect to an I2C lcd at address 0x3F with lowest user value of 200 and highest of 1024.

```
  LCDRamp lcd(0x3F, 200, 1024);
```

* This will display 1000 as a computed value based on lcd columns.

```
  lcd.lcdRamp(1000);
```
