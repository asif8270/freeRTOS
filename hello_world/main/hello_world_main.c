#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"

/* CONFIG_FREERTOS_HZ 100 - It means that there are 100 ticks per second in the system.
   1s = 1000ms
   1s = 100 ticks
   1000ms = 100 ticks
   1 tick = 1000 / 100 
   1 tick = 10ms
   */

const TickType_t Delay = pdTICKS_TO_MS(7); // 7 * 10 = 70ms

void app_main(void)
{
    int counter = 0;
    while (true)
    {
        printf("%d: Hello world!\n\r", counter);
        counter++;
        vTaskDelay(Delay);
    }
    
}
