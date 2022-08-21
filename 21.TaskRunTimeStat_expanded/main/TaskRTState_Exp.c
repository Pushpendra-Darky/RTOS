#include<stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

TaskHandle_t task_handle;
char stat_buffer[4096];

void task(void *data)
{
	printf("Task: New Task Started\n");
	vTaskGetRunTimeStats(&stat_buffer);
	printf("%s\n",stat_buffer);
	vTaskDelay(pdMS_TO_TICKS(1000));
	vTaskDelete(NULL);
}

void app_main()
{
	BaseType_t res;
	printf("Main Task: Task RunTime Stat Demo\n");
	res = xTaskCreate(task,"TASK",2048,NULL,5,&task_handle);
	if(res != pdPASS)
	{
		printf("Task Not Created\n");
	}
}
