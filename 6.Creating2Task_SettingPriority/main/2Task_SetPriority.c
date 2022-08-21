#include<stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

TaskHandle_t serial_task_handle,ethernet_task_handle;

void serial_task(void *data)
{
    UBaseType_t priority;
    while(1)
    {
    priority = uxTaskPriorityGet(serial_task_handle);
    printf("Serial Task: Started With Priority:%d\n",priority);
    }
    vTaskDelete(serial_task_handle);
}

void ethernet_task(void *data)
{
    UBaseType_t priority;
    while(1)
    {
    priority = uxTaskPriorityGet(ethernet_task_handle);   
    printf("Ethernet Task: Started With Priority:%d\n",priority);
    }
    vTaskDelete(ethernet_task_handle);
}


void app_main()
{
    BaseType_t res;
    UBaseType_t priority;
    printf("MT: Two Task Creation With Different Priority Project\n");
    priority = uxTaskPriorityGet(NULL);
   
    res = xTaskCreate(serial_task,"SERIALTASK",2048,NULL,5,&serial_task_handle);
    res = xTaskCreate(ethernet_task,"ETHERTASK",2048,NULL,8,&ethernet_task_handle);   
    if( res == pdPASS)
    {
        printf("MT: Tasks Created Successfully. MT Priority:%d\n",priority);
    }
}
