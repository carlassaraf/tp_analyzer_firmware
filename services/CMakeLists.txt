add_library(services STATIC
  lvgl/lvgl_port.c
)

target_include_directories(services PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(services
  hal
  lvgl
)