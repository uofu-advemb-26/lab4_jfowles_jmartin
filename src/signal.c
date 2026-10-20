#include "portmacro.h"
#include "projdefs.h"
#include "signaling.h"
#include <stdio.h>
#include <FreeRTOS.h>
#include <task.h>

void signal_handle_calculation(SemaphoreHandle_t request,
                               SemaphoreHandle_t response,
                               struct signal_data *data)
{
	xSemaphoreTake(request, portMAX_DELAY) == pdPASS;
	data->output = data->input + 5;
	vTaskDelay(10);
	xSemaphoreGive(response);
}

BaseType_t signal_request_calculate(SemaphoreHandle_t request,
                                    SemaphoreHandle_t response,
                                    struct signal_data *data)
{
	xSemaphoreGive(request);
    return xSemaphoreTake(response, 100);
}
