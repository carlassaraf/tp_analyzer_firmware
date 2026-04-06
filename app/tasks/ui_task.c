#include "FreeRTOS.h"
#include "task.h"
#include "services/lvgl/lgvl_port.h"

void ui_task(void *params) {

  lvgl_port_init();

  while (true) {
    lv_task_handler();
    vTaskDelay(pdMS_TO_TICKS(10)); 
  }
}