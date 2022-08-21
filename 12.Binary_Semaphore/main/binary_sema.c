#include<stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

TaskHandle_t adc_task_handle,processing_task_handle;
SemaphoreHandle_t adcSignal;

void adc_task(void *data)
{
    printf("ADC T: Starting The ADC Task\n");
    vTaskDelay(1000/portTICK_PERIOD_MS);

    xSemaphoreGive(adcSignal);
    printf("ADC T: Posted Signal To Processing Task\n");

    vTaskDelete(NULL);//vTaskDelete(adc_task_handle);
}

void processing_task(void *data)
{
    printf("PR T: Starting The Processing Task\n");
    xSemaphoreTake(adcSignal,0);
    printf("PR T: Got The Signal\n");

    vTaskDelete(NULL);//vTaskDelete(processing_task_handle);
}


void app_main()
{
    BaseType_t res;
    printf("MT: Binary Semaphore Project\n");
    printf("MT: Tasks Created Successfully\n");
    //Creating Semaphore
    adcSignal = xSemaphoreCreateBinary();
    res = xTaskCreate(adc_task,"ADCTASK",2048,NULL,5,&adc_task_handle);
    res = xTaskCreate(processing_task,"PROCESSINGTASK",2048,NULL,8,&processing_task_handle);   
   
}
