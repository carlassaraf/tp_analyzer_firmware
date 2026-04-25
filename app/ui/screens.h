#include "screens/scr_boot.h"
#include "screens/scr_home.h"

#define SCR_REGISTER(scr_name)  { scr_name##_init, scr_name##_deinit, scr_name##_step }

/** 
 * @enum screen_id_t
 * @brief A way of keeping count and order screens in the application
 */
typedef enum screen_id {
  SCREEN_BOOT,
  SCREEN_HOME,
  SCREEN_COUNT
} screen_id_t;