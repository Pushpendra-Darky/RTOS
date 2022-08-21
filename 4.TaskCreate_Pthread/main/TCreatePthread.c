#include<stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "pthread.h"


void *serial_task(void *data)
{
    printf("Serial Task: Started\n");
    vTaskDelete(NULL);
}

void app_main()
{

    printf("MT: Task Created Using Pthread Project\n");
    
    pthread_t sid;
    pthread_create(&sid,NULL,serial_task,NULL);
    pthread_join(sid,NULL);
}
