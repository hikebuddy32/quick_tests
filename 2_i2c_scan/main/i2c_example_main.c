/* i2c - Example

*/
#include <driver/i2c.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>
#include "sdkconfig.h"

#define SCL_PIN 21
#define SDA_PIN 22

void app_main()
{
  ESP_LOGI("test", ">> i2cScanner");
  ESP_LOGI("test", ">> Expected addresses:");
  ESP_LOGI("test", ">> 0x19: LSM303 Accelerometer");
  ESP_LOGI("test", ">> 0x1E: LSM303 Magnetometer");
  ESP_LOGI("test", ">> 0x5A: DRV2605 Haptic Motor Driver");
  ESP_LOGI("test", ">> 0x76: BME280 Temperature, pressure and humidity sensor");
  ESP_LOGI("test", ">> 0x36: MAX17260 Couloumb counter");
  i2c_config_t conf;
  conf.mode = I2C_MODE_MASTER;
  conf.sda_io_num = SDA_PIN;
  conf.scl_io_num = SCL_PIN;
  conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
  conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
  conf.master.clk_speed = 100000;
  i2c_param_config(I2C_NUM_0, &conf);

  i2c_driver_install(I2C_NUM_0, I2C_MODE_MASTER, 0, 0, 0);

  int i;
  esp_err_t espRc;
  printf("     0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f\n");
  printf("00:         ");
  for (i=3; i< 0x78; i++) {
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (i << 1) | I2C_MASTER_WRITE, 1 /* expect ack */);
    i2c_master_stop(cmd);

    espRc = i2c_master_cmd_begin(I2C_NUM_0, cmd, 10/portTICK_PERIOD_MS);
    if (i%16 == 0) {
      printf("\n%.2x:", i);
    }
    if (espRc == 0) {
      printf(" %.2x", i);
    } else {
      printf(" --");
    }
    //ESP_LOGD(tag, "i=%d, rc=%d (0x%x)", i, espRc, espRc);
    i2c_cmd_link_delete(cmd);
  }
  printf("\n");
  vTaskDelete(NULL);

}
