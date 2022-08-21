#include<stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

TaskHandle_t serial_task_handle,ethernet_task_handle;

void serial_task(void *data)
{
    
    printf("Serial Task: Started\n");
    vTaskDelete(serial_task_handle);
}

void ethernet_task(void *data)
{
    printf("Ethernet Task: Started\n");
    vTaskDelete(ethernet_task_handle);
}


void app_main()
{
    BaseType_t res;
    printf("MT: Two Task Creation Project\n");
   
    res = xTaskCreate(serial_task,"SERIALTASK",2048,NULL,5,&serial_task_handle);
    res = xTaskCreate(ethernet_task,"ETHERTASK",2048,NULL,8,&ethernet_task_handle);
    if(res==pdPASS)
    {
        printf("Tasks Created Successfully\n");
    }
    
}