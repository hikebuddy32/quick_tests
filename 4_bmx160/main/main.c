/* i2c - Example

*/
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>
#include "sdkconfig.h"

#include "hal_i2c.h"
#include "lsm303.h"

static const char *TAG = "BME test";

void demo_lsm(void) {

    vTaskDelay(2000 / portTICK_PERIOD_MS);
}

void app_main()
{
  i2c_init();
  ESP_LOGI(TAG, "Read lsm303 test");
  while(1) {
      demo_lsm();
  }
  vTaskDelete(NULL);
}
