#include "ui.h"
#include "lvgl/screens.h"
#include "lvgl/screen_manager.h"
#include "lvgl/helpers/chart.h"
#include "hal/hal_adc.h"
#include "board_config.h"

void scr_plotter_update_chart(const uint16_t *points, uint16_t count) {
  ui_chart_push_data(ui_scrPlotter_chartView, points, count);
}

static void on_btn_back(lv_event_t *e) {
  (void)e;
  screen_manager_go_to(SCREEN_BOOT);
}

static void on_btn_vrms(lv_event_t *e) {
  (void)e;
}

static void on_btn_freq(lv_event_t *e) {
  (void)e;
}

void scr_plotter_prepare(void) {
  lv_chart_add_series(ui_scrPlotter_chartView,
                      lv_palette_main(LV_PALETTE_BLUE),
                      LV_CHART_AXIS_PRIMARY_Y);
  lv_chart_set_point_count(ui_scrPlotter_chartView, HAL_ADC_BUFFER_SIZE);

  lv_obj_add_event_cb(ui_scrPlotter_btnBack, on_btn_back, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui_scrPlotter_btnVrms, on_btn_vrms, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui_scrPlotter_btnFreq, on_btn_freq, LV_EVENT_CLICKED, NULL);
}

void scr_plotter_init(void) {
  _ui_screen_change(&ui_scrPlotter, LV_SCR_LOAD_ANIM_NONE, 0, 0, &ui_scrPlotter_screen_init);

  SCR_ADD_TO_GROUP(ui_scrPlotter_btnVrms);
  SCR_ADD_TO_GROUP(ui_scrPlotter_btnFreq);
  SCR_ADD_TO_GROUP(ui_scrPlotter_btnBack);
}

void scr_plotter_deinit(void) {
  SCR_CLEAR_GROUP();
}

void scr_plotter_step(void) {
}