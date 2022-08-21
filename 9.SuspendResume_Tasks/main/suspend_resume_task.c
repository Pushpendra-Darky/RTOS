#include<stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

TaskHandle_t serial_task_handle,ethernet_task_handle;

void serial_task(void *data)
{
    UBaseType_t priority;
    int count = 0;
    while(1)
    {
        count +=1;
        if(count>5)
        {
            vTaskResume(ethernet_task_handle);
            count = 0;
        }
    priority = uxTaskPriorityGet(serial_task_handle);
    printf("Serial Task: Started With Priority:%d\n",priority);
    vTaskDelay(5000/portTICK_PERIOD_MS);
    }
    vTaskDelete(serial_task_handle);
}

void ethernet_task(void *data)
{
    UBaseType_t priority;
    while(1)
    {
    vTaskSuspend(NULL);  //vTaskSuspend(ethernet_task_handle);
    priority = uxTaskPriorityGet(ethernet_task_handle);   
    printf("Ethernet Task: Started With Priority:%d\n",priority);
    vTaskDelay(5000/portTICK_PERIOD_MS);
    }
    vTaskDelete(ethernet_task_handle);
}


void app_main()
{
    BaseType_t res;
    UBaseType_t priority;
    printf("MT: Two Task Periodically Creation With Different Priority Project\n");
    priority = uxTaskPriorityGet(NULL);
    printf("MT: Tasks Created Successfully. MT Priority:%d\n",priority);
    res = xTaskCreate(serial_task,"SERIALTASK",2048,NULL,5,&serial_task_handle);
    res = xTaskCreate(ethernet_task,"ETHERTASK",2048,NULL,8,&ethernet_task_handle);   
   
}
