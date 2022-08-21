#include<stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/message_buffer.h"

TaskHandle_t task1_handle, task2_handle;
MessageBufferHandle_t mb_t1_t2;

void task1(void *data)
{
	printf("Task1: Starting the task\n");
	printf("Task1: Sending Message\n");
	xMessageBufferSend(mb_t1_t2,"1st Message\n",13,pdMS_TO_TICKS(20000));
	xMessageBufferSend(mb_t1_t2,"2nd Message\n",13,pdMS_TO_TICKS(20000));
	xMessageBufferSend(mb_t1_t2,"3rd Message\n",13,pdMS_TO_TICKS(20000));
	
	printf("Task1: Finished Sending Message\n");
	vTaskDelete(NULL);
}

void task2(void *data)
{
	size_t nbytes =0;
	unsigned char rbuff[200];
	printf("Task2: Starting The Task2\n");
	
    	while(1)
    	{
    		printf("Task2: Requesting Data To Be Received\n");
        	nbytes = xMessageBufferReceive(mb_t1_t2,rbuff, 200, pdMS_TO_TICKS(20000));
        	printf("Task2: Received Data: %s And Number Of Bytes: %d\n", rbuff,nbytes);
    	}
    	vTaskDelete(NULL);
}


void app_main()
{
    BaseType_t res;
    printf("MT: Message Buffer Project\n");
    printf("MT: Tasks Created Successfully\n");
    //Creating Messasge BUffer
    	mb_t1_t2 = xMessageBufferCreate(200);
    	res = xTaskCreate(task1, "Task1", 2048, NULL, 8, &task1_handle);
	res = xTaskCreate(task2, "Task2", 2048, NULL, 8, &task2_handle);
	
}
