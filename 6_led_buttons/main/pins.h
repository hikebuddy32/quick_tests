/** @file board_pins.h */
#ifndef PINS_H
#define PINS_H

#include "sdkconfig.h"

//#ifdef CONFIG_HB_BOARD_V0

#define PIN_LCD_CLK       14
#define PIN_LCD_MOSI      13
#define PIN_LCD_CS        15
#define PIN_LCD_EXTCOMM   32

#define PIN_SDC_CLK       18
#define PIN_SDC_MISO      19
#define PIN_SDC_MOSI      23
#define PIN_SDC_CS         5

#define PIN_SW1           36
#define PIN_SW2           37
#define PIN_SW3           38
#define PIN_SW4           39
#define PIN_FLASH          0
#define PIN_INT_BMX       34

#define PIN_EN_HAP        35
#define PIN_EN_GPS        27
#define PIN_EN_LCD         4
#define PIN_EN_SDC         2

#define PIN_LED_R          12
#define PIN_LED_G          25
#define PIN_LED_B          26

#define PIN_I2C_CLK        21
#define PIN_I2C_DATA       22

#define PIN_UART2_RX       16
#define PIN_UART2_TX       17

#endif // PINS_H
