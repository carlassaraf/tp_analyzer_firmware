SET(SOURCES screens/ui_boot.c
    screens/ui_plotter.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    images/ui_img_icons_icon_back_png.c)

add_library(ui ${SOURCES})
