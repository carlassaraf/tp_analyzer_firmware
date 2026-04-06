/**
 * @brief Enables API to check stack usage on task
 * @see AWS, "The FreeRTOS™ Reference Manual", Section 2.26
 */
#define INCLUDE_uxTaskGetStackHighWaterMark 1
/**
 * @brief Enables stack overflow detection via hook (vApplicationStackOverflowHook)
 * @see Barry, R. "Mastering the FreeRTOS Real Time Kernel", Section 13.3.2
 */
#define configCHECK_FOR_STACK_OVERFLOW  2
/**
 * @brief Static memory allocation support
 * @see Barry, R. "Mastering the FreeRTOS Real Time Kernel", Seccion 3.4
 */
#define configSUPPORT_STATIC_ALLOCATION 1