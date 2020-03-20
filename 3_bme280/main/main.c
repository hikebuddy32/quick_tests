/* i2c - Example

*/
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>
#include "sdkconfig.h"

#include "hal_i2c.h"
#include "bme280.h"

static const char *TAG = "BME test";

void demo_bme_normal(void) {
    // bme_init();
    set_base_pressure();
    read_temperature();
    read_humidity();
    read_altitude();
    vTaskDelay(2000 / portTICK_PERIOD_MS);
}

void demo_bme_forced(void) {
    ESP_LOGI(TAG, "Forced mode read test");
    bme_init();
    bme_forced_measure();
    set_base_pressure();
    bme_forced_measure();
    read_temperature();
    read_humidity();
    read_altitude();
    vTaskDelay(2000 / portTICK_PERIOD_MS);
}

void app_main()
{
  i2c_init();
  demo_bme_forced();
  ESP_LOGI(TAG, "Normal mode read test");
  while(1) {
      demo_bme_normal();
  }
  vTaskDelete(NULL);
}
