#include <stdio.h>
#include <stdint.h>
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

const uint16_t *blueLED = (uint16_t *) BLUELED;
const uint16_t *redLED = (uint16_t *) REDLED;

/**
 * @brief   The task function.
 * @param   pvParam is a void pointer (void *) that can point to any type of data. In this case we are pointing
 *          to GPIO pin.
 * @return  OK on success
 */
void genTask(void *pvParam)
{
    uint32_t ledGPIO;
    ledGPIO = (uint32_t)pvParam;
    /**
     * @brief   Sets the mode of the GPIO to input_only, output_only, or input_output.
     * @return  OK on success
     */
    gpio_set_direction(ledGPIO, GPIO_MODE_INPUT_OUTPUT);

    while (1)
    {
        /**
         * @brief   This function toggles gpio by performing the XOR operation with the current gpio level.
         *          If the level is 0 -> becomes 1, and if the level is 1 -> becomes 0.
         *          To use gpio_get_level always set direction to GPIO_MODE_INPUT_OUTPUT.
         * @param   pvParam points to the LED pin e.g. BLUELED
         * @return  OK on success
         */
        gpio_set_level(ledGPIO, (gpio_get_level(ledGPIO) ^ 1)); 
        printf("Task: %ld\n\r", ledGPIO);
    }
    vTaskDelete(NULL);
}

void app_main(void)
{
    /*Block for 10ms*/
    vTaskDelay(10 / portTICK_PERIOD_MS);

    /* As this task has higher priority so, only this will run*/
    xTaskCreate(genTask, "BLUE blinky", 2048, (void *)blueLED, (1), NULL);

    xTaskCreate(genTask, "RED blinky", 2048, (void *)redLED, (1), NULL);
}
