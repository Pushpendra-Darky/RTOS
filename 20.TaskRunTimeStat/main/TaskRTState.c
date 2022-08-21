#include<stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

char stat_buffer[4096];

void app_main()
{
	printf("Task RunTime Stat Demo\n");
	while(1)
	{
		vTaskGetRunTimeStats(stat_buffer);
		printf("Stat Buffer: %s\n",stat_buffer);
		vTaskDelay(pdMS_TO_TICKS(5000));
	}
}
