#include <sdkconfig.h>

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/timers.h>
#include <esp_err.h>
#include <esp_log.h>
#include <driver/gpio.h>

#include "pins.h"
#include "leds.h"

static const char *TAG = "board_leds";
// The buffer used to hold the software timer's data structure.
static StaticTimer_t xPWM_timer_buffer;
static TimerHandle_t pwm_timer;

static led_color sColor;

static void pwm_timer_callback(TimerHandle_t xExpiredTimer) {

}

esp_err_t leds_set_color(led_color color) {

    return ESP_OK;
}

esp_err_t leds_init(void) {
    gpio_pad_select_gpio(PIN_LED_R);
    gpio_set_direction(PIN_LED_R, GPIO_MODE_OUTPUT);
    gpio_pad_select_gpio(PIN_LED_G);
    gpio_set_direction(PIN_LED_G, GPIO_MODE_OUTPUT);
    gpio_pad_select_gpio(PIN_LED_B);
    gpio_set_direction(PIN_LED_B, GPIO_MODE_OUTPUT);

    gpio_set_level(PIN_LED_R, 1);
    gpio_set_level(PIN_LED_G, 1);
    gpio_set_level(PIN_LED_B, 1);
    vTaskDelay(100 / portTICK_PERIOD_MS);

    gpio_set_level(PIN_LED_R, 0);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    gpio_set_level(PIN_LED_R, 1);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    gpio_set_level(PIN_LED_G, 0);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    gpio_set_level(PIN_LED_G, 1);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    gpio_set_level(PIN_LED_B, 0);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    gpio_set_level(PIN_LED_B, 1);
    vTaskDelay(500 / portTICK_PERIOD_MS);

	  return ESP_OK;
}
