#include<stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"

TaskHandle_t serial_task_handle;
TimerHandle_t serial_timer_handle;

void serial_timer_callback(TimerHandle_t xTimer)
{
    printf("Timer Fired\n");
}


void serial_task(void *data)
{
    printf("Starting The Serial Task\n");
    
    printf("Creating The Timer\n");
    serial_timer_handle = xTimerCreate("one_shot_timer",5000/portTICK_PERIOD_MS,pdFALSE,0,serial_timer_callback);
    printf("Starting The Timer\n");
    xTimerStart(serial_timer_handle,0);
    vTaskDelete(serial_task_handle);
    printf("Serial Task Dead\n");
}


void app_main()
{
    BaseType_t res;
    printf("MT: One Shot Timer Project\n");
    printf("MT: Tasks Created Successfully\n");
    res = xTaskCreate(serial_task,"SERIALTASK",2048,NULL,5,&serial_task_handle); 
    if (res != pdPASS)
    {
        printf("Task Not Created\n");
    }
}
