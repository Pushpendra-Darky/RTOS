#include<stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"

TaskHandle_t pressure_task1handle,temperature_task2handle,processing_task3handle;
EventGroupHandle_t sensor_ef;

void pressure_task1(void *data)
{
	int pdata=200;
	printf("Pressure Task1: Starting The Pressure Task\n");
	while(1)
	{
		pdata++;
		//setting the bit
		xEventGroupSetBits(sensor_ef,(1<<0));
		printf("Pressure Task1: Setting Bit..Event Generated\n");
		vTaskDelay(pdMS_TO_TICKS(5000));
	}
	vTaskDelete(NULL);
}

void temperature_task2(void *data)
{
	int tdata=100;
	printf("Temperature Task2: Starting The Temperature Task\n");
	while(1)
	{
		tdata++;
		//setting the bit
		xEventGroupSetBits(sensor_ef,(1<<1));
		printf("Temperature Task2: Setting Bit..Event Generated\n");
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
	vTaskDelete(NULL);
}

void processing_task3(void *data)
{
	int buffer;
	printf("Processing Task3: Starting The Processing Task\n");
	while(1)
	{
		//wait for event
		xEventGroupWaitBits(sensor_ef,(1<<0)|(1<<1),pdTRUE,pdTRUE,portMAX_DELAY);
		printf("Processing Task3: Received Events.\n");
	}
	vTaskDelete(NULL);
}


void app_main()
{
    BaseType_t res;
    printf("MT: Event Flag Project[All Bit Set]\n");
    printf("MT: Tasks Created Successfully\n");
    //Creating Event flag
    sensor_ef = xEventGroupCreate();
    res = xTaskCreate(pressure_task1,"PRESSURETASK1",2048,NULL,8,&pressure_task1handle);
    res = xTaskCreate(temperature_task2,"TEMPERATURETASK2",2048,NULL,8,&temperature_task2handle);
    res = xTaskCreate(processing_task3,"PROCESSINGTASK3",2048,NULL,8,&processing_task3handle);   
   
}
