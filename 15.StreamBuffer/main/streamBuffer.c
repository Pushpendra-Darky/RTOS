#include<stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/stream_buffer.h"

TaskHandle_t task1_handle, task2_handle;
StreamBufferHandle_t sb_t1_t2;
unsigned char rbuff[200];
void task1(void *data)
{
	printf("Task1: Starting the task\n");
	printf("Task1: Sending Message\n");
	xStreamBufferSend(sb_t1_t2,"1st Message\n",11,pdMS_TO_TICKS(20000));
	xStreamBufferSend(sb_t1_t2,"2nd Message\n",11,pdMS_TO_TICKS(20000));
	xStreamBufferSend(sb_t1_t2,"3rd Message\n",11,pdMS_TO_TICKS(20000));
	
	
	printf("Task1: Finished Sending Message\n");
	vTaskDelete(NULL);
}

void task2(void *data)
{
	size_t nbytes =0;
	
	printf("Task2: Starting The Task2\n");
	
    	while(1)
    	{
    		printf("Task2: Requesting Data To Be Received\n");
        	nbytes = xStreamBufferReceive(sb_t1_t2,rbuff, 200, pdMS_TO_TICKS(20000));
        	printf("Task2: Received Data: %s And Number Of Bytes: %d\n", rbuff,nbytes);
    	}
    	vTaskDelete(NULL);
}


void app_main()
{
    BaseType_t res;
    printf("MT: Message Buffer Project\n");
    printf("MT: Tasks Created Successfully\n");
    //Creating StreamBUffer
    	sb_t1_t2 = xStreamBufferCreate(200,23);
    	res = xTaskCreate(task1, "Task1", 2048, NULL, 8, &task1_handle);
		res = xTaskCreate(task2, "Task2", 2048, NULL, 8, &task2_handle);
	
}
