#include "lvgl.h"
#include "hal/hal_display.h"

static void flush_cb(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_p) {
    hal_display_flush(area->x1, area->y1, area->x2, area->y2, (uint16_t*)color_p);
    lv_disp_flush_ready(drv);
}

void lvgl_port_init(void) {
    lv_init();

    static lv_color_t buf[320 * 20];
    static lv_disp_draw_buf_t draw_buf;

    lv_disp_draw_buf_init(&draw_buf, buf, NULL, 320 * 20);

    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);

    disp_drv.hor_res = 320;
    disp_drv.ver_res = 480;
    disp_drv.flush_cb = flush_cb;
    disp_drv.draw_buf = &draw_buf;

    lv_disp_drv_register(&disp_drv);
}