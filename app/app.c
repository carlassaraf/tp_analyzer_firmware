#include "app.h"
#include "FreeRTOS.h"
#include "task.h"

extern void ui_task(void *params);

bool app_init() {
  // Initialize application resources here
  return true; // Return true if initialization is successful
}

bool app_run() {

  xTaskCreate(ui_task, "UI Task", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY + 1, NULL);

  // Main application loop
  while (true) {
      // Handle events, update state, render, etc.
      // Break the loop to exit the application
  }
  return true; // Return true if the application ran successfully
}