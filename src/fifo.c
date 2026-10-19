#include <FreeRTOS.h>
#include <pico/stdlib.h>
#include <pico/multicore.h>
#include <pico/cyw43_arch.h>
#include <stdio.h>

#include "fifo.h"

void fifo_worker_handler(QueueHandle_t requests, QueueHandle_t results, int id)
{
    //take requests, results, and id
    while(1) {
        //make enough data for a request_msg in data (input and output)
        struct request_msg data = {};
        //recieve the request, copy the data into our struct
        xQueueReceive(requests, &data, portMAX_DELAY);
        //add 5 to the input
        data.output = data.input + 5;
        //put the results back in the queue, 
        xQueueSend(results, &data, portMAX_DELAY);
    }
}