#include<stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <unistd.h>

TaskHandle_t serial_task_handle;

void serial_task(void *data)
{
    printf("Serial Task: Started\n");
    vTaskDelete(NULL);
}

void app_main()
{
    BaseType_t res;


    printf("MT: Task Created Project\n");
    
    res = xTaskCreate(serial_task,"SERIALTASK",2048,NULL,5,&serial_task_handle);
    if(res==pdPASS)
    {
        printf("Task Created Successfully\n");
    }
    // while(1)
    // {
    //     sleep(1);
    // }
    
}