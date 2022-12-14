#include<stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#define MQ_SIZE 4
#define MSG_SIZE 64

TaskHandle_t pressure_task1handle,temperature_task2handle,processing_task3handle,highpriority_tak4handle;
QueueHandle_t sensor_q;


void pressure_task1(void *data)
{
	int pdata = 200;
	printf("Pressure Task1: Starting The Pressure Task\n");
	while(1)
	{
		pdata++;
		//send data to the queue
		xQueueSend(sensor_q,&pdata,pdMS_TO_TICKS(5000));
		//vTaskDelay(1000 / portTICK_PERIOD_MS);
		vTaskDelay(pdMS_TO_TICKS(500));
	}
	vTaskDelete(NULL);
}

void temperature_task2(void *data)
{
	int tdata = 50;
	printf("Temperature Task2: Starting The Temperature Task\n");
	while(1)
	{
		tdata++;
		//send data to the queue
		xQueueSend(sensor_q,&tdata,pdMS_TO_TICKS(5000));
		//vTaskDelay(1000 / portTICK_PERIOD_MS);
		vTaskDelay(pdMS_TO_TICKS(100));
	}
	vTaskDelete(NULL);
}


void processing_task3(void *data)
{
	int buffer;
	printf("Processing Task3: Starting The Processing Task\n");
	while(1)
	{
		//received data from the queue
		xQueueReceive(sensor_q,&buffer,portMAX_DELAY);
		printf("Processing Task: Received data: %d\n",buffer);
	}
	vTaskDelete(NULL);
}


void highpriority_task4(void *data)
{
	int buffer;
	printf("High Priority Task4: Starting The High Priority Task\n");
	int count = 0;
	while(1)
	{
		//received data from the queue
		xQueueReceive(sensor_q,&buffer,pdMS_TO_TICKS(1000));
		printf("High Priority Task: Received data: %d\n",buffer);
		count++;
		if(count>50)
		{
			//vTaskDelete(NULL);
			vTaskDelay(pdMS_TO_TICKS(10000));
			//vTaskDelay(1000 / portTICK_PERIOD_MS);
		}
	}
	vTaskDelete(NULL);
}



void app_main()
{
    BaseType_t res;
    printf("MT: Message Queue Project\n");
    printf("MT: Tasks Created Successfully\n");
    //Creating Message Queue
    	sensor_q = xQueueCreate(MQ_SIZE,MSG_SIZE);
    	res = xTaskCreate(pressure_task1, "PRESSURETASK", 2048, NULL, 8, &pressure_task1handle);
	res = xTaskCreate(temperature_task2, "TEMPERATURETASK", 2048, NULL, 8, &temperature_task2handle);
	res = xTaskCreate(processing_task3, "PROCESSINGTASK", 2048, NULL, 8, &processing_task3handle);
	res = xTaskCreate(highpriority_task4, "HIGHPRIORITYTASK", 2048, NULL, 10, &highpriority_tak4handle);
}
