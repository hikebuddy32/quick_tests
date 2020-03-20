#include <esp_log.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "math.h"

#include "hal_i2c.h"
#include "max17260.h"

static const char *TAG = "MAX17260";
