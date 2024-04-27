#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "esp_log.h"

#include "driver/gpio.h"

#define ESP_INTR_FLAG_DEFAULT 0

#define BOARD_LED GPIO_NUM_2 //blue led
#define BOARD_BTN GPIO_NUM_0 //BOOT btn, EN - reset btn

void app_main(void)
{
    gpio_set_direction(BOARD_LED, GPIO_MODE_OUTPUT);

    gpio_set_direction(BOARD_BTN, GPIO_MODE_INPUT);
    gpio_set_pull_mode(BOARD_BTN, GPIO_PULLUP_ONLY);

    int cnt = 0;
    while (1) {
        printf("cnt: %d\n", cnt++);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }

    vTaskSuspend(NULL);

}
