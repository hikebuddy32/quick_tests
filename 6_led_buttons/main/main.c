/* i2c - Example

*/
#include <driver/i2c.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>
#include "sdkconfig.h"

#include "leds.h"
#include "input.h"
#include "pins.h"

#define SCL_PIN 21
#define SDA_PIN 22

void app_main()
{
    init_buttons();

    // Turn on all voltage regulators
    gpio_pad_select_gpio(PIN_EN_GPS);
    gpio_set_direction(PIN_EN_GPS, GPIO_MODE_OUTPUT);
    gpio_set_level(PIN_EN_GPS, 1);

    // gpio_pad_select_gpio(PIN_EN_LCD);
    // gpio_set_direction(PIN_EN_LCD, GPIO_MODE_OUTPUT);
    // gpio_set_level(PIN_EN_LCD, 1);
    //
    gpio_pad_select_gpio(PIN_EN_SDC);
    gpio_set_direction(PIN_EN_SDC, GPIO_MODE_OUTPUT);
    gpio_set_level(PIN_EN_SDC, 1);

    // blink LED
    while(1){
        leds_init();
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}
