#include "portmacro.h"
#include "projdefs.h"
#include "signaling.h"

void signal_handle_calculation(SemaphoreHandle_t request,
                               SemaphoreHandle_t response,
                               struct signal_data *data)
{
	if (xSemaphoreTake(request, portMAX_DELAY) == pdPASS) {
		data->output = data->input + 5;
		xSemaphoreGive(response);
	}
}

BaseType_t signal_request_calculate(SemaphoreHandle_t request,
                                    SemaphoreHandle_t response,
                                    struct signal_data *data)
{
	xSemaphoreGive(request);
	return xSemaphoreTake(response, portMAX_DELAY);
}
