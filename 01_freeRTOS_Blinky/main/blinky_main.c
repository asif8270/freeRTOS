#include <stdio.h>
#include <inttypes.h>
#include "freeRTOS/FreeRTOSConfig.h"
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_err.h"
#include "esp_flash.h"

#define BLUELED     GPIO_NUM_2
#define REDLED      GPIO_NUM_5

typedef int TaskProfiler;

TaskProfiler BlueLEDProfiler;
TaskProfiler RedLEDProfiler;

/**
 * @brief   Convert the ticks to millisecond.
 *          CONFIG_FREERTOS_HZ 100 - It means that there are 100 ticks per second in the system.
 *          1s = 1000ms
 *          1s = 100 ticks
 *          1000ms = 100 ticks
 *          1 tick = 1000 / 100 
 *          1 tick = 10ms
 */
const TickType_t Delay = pdTICKS_TO_MS(7); // 7 * 10 = 70ms

void blueLEDTask(void *pvParameters)
{
    /**
     * @brief   Sets the mode of the GPIO to input_only, output_only, or input_output.
     * @return  OK on success
     */
    gpio_set_direction(BLUELED, GPIO_MODE_INPUT_OUTPUT);

    UBaseType_t priority = uxTaskPriorityGet(NULL);
    printf("Priority of blueLEDTask: %d\n\r", priority);

    while (1)
    {
        /* code */
        /**
         * @brief This function toggles gpio by performing the XOR operation with the current gpio level.
         *        If the level is 0 -> becomes 1, and if the level is 1 -> becomes 0.
         *        To use gpio_get_level always set direction to GPIO_MODE_INPUT_OUTPUT.
         * @return OK on success
         */
        gpio_set_level(BLUELED, (gpio_get_level(BLUELED) ^ 1)); 
        printf("%d: This Blinky task for BLUE LED\n\r", BlueLEDProfiler);
        BlueLEDProfiler++;
    }
    vTaskDelete(NULL);
}

void redLEDTask(void *pvParameters)
{
    /**
     * @brief   Sets the mode of the GPIO to input_only, output_only, or input_output.
     * @return  OK on success
     */
    gpio_set_direction(REDLED, GPIO_MODE_INPUT_OUTPUT);

    while (1)
    {
        /* code */
        /**
         * @brief This function toggles gpio by performing the XOR operation with the current gpio level.
         *        If the level is 0 -> becomes 1, and if the level is 1 -> becomes 0.
         *        To use gpio_get_level always set direction to GPIO_MODE_INPUT_OUTPUT.
         * @return OK on success
         */
        gpio_set_level(REDLED, (gpio_get_level(REDLED) ^ 1)); 
        printf("%d: This Blinky task for RED LED\n\r", RedLEDProfiler);
        RedLEDProfiler++;
    }
    vTaskDelete(NULL);
}

void app_main(void)
{
    vTaskDelay(100 / portTICK_PERIOD_MS); // Block for 100ms
    xTaskCreate(blueLEDTask, "BLUE blinky", 2048, NULL, (5), NULL); // As this task has higher priority so, only this will run
    xTaskCreate(redLEDTask, "RED blinky", 2048, NULL, (1), NULL);
}
