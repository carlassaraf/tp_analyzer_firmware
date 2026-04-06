add_library(drivers STATIC
  display/display.c
  display/ili9488.c
)

target_include_directories(drivers PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(drivers
  hal
)