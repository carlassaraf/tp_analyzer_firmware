#include "scr_plot.h"
#include "lvgl.h"
#include "ui/screens.h"

lv_obj_t *scr_plot = NULL;
lv_obj_t *scr_plot_chart = NULL;

void scr_plot_init(void) {
  // Screen creation
  scr_plot = lv_obj_create(NULL);
  lv_obj_set_style_bg_color(scr_plot, lv_color_black(), LV_PART_MAIN);

  scr_plot_chart = lv_chart_create(scr_plot);
  lv_obj_set_style_size(scr_plot_chart, 0, 0, LV_PART_INDICATOR);
  lv_obj_set_size(scr_plot_chart, 460, 300);
  lv_obj_align(scr_plot_chart, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_style_border_color(scr_plot_chart, lv_color_black(), LV_PART_MAIN);
  lv_obj_set_style_border_width(scr_plot_chart, 2, LV_PART_MAIN);
  lv_chart_set_update_mode(scr_plot_chart, LV_CHART_UPDATE_MODE_CIRCULAR);
  lv_chart_set_point_count(scr_plot_chart, 480);
  lv_chart_series_t *series = lv_chart_add_series(scr_plot_chart, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);
  /*Prefill with data*/
  uint32_t i;
  for(i = 0; i < 480; i++) {
      lv_chart_set_next_value(scr_plot_chart, series, (int32_t)lv_rand(10, 90));
  }

  lv_screen_load_anim(scr_plot, LV_SCR_LOAD_ANIM_FADE_IN, 300, 0, true);
}

void scr_plot_deinit(void) {

}

void scr_plot_step(void) {

  lv_chart_series_t *series = lv_chart_get_series_next(scr_plot_chart, NULL);

  lv_chart_set_next_value(scr_plot_chart, series, (int32_t)lv_rand(10, 90));

  uint32_t p = lv_chart_get_point_count(scr_plot_chart);
  uint32_t s = lv_chart_get_x_start_point(scr_plot_chart, series);
  int32_t *a = lv_chart_get_series_y_array(scr_plot_chart, series);

  a[(s + 1) % p] = LV_CHART_POINT_NONE;
  a[(s + 2) % p] = LV_CHART_POINT_NONE;
  a[(s + 2) % p] = LV_CHART_POINT_NONE;

  lv_chart_refresh(scr_plot_chart);
}