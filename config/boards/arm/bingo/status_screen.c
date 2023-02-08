/*
 *
 * Copyright (c) 2021 Darryl deHaan
 * SPDX-License-Identifier: MIT
 *
 */

#include "status_screen.h"
#include "widgets/bongo_cat_widget.h"

#include <logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

//#if IS_ENABLED(CONFIG_BONGO_CAT)
static struct zmk_widget_bongo_cat bongo_cat_widget;
//#endif
static sys_slist_t widgets = SYS_SLIST_STATIC_INIT(&widgets);

lv_obj_t *zmk_display_status_screen() {

    lv_obj_t *screen;
    /*
    lv_obj_t *center_frame;

    lv_style_init(&global_style);
    lv_style_set_text_font(&global_style, LV_STATE_DEFAULT, &lv_font_montserrat_26);
    lv_style_set_text_letter_space(&global_style, LV_STATE_DEFAULT, 1);
    lv_style_set_text_line_space(&global_style, LV_STATE_DEFAULT, 1);
    screen = lv_obj_create(NULL, NULL);
    lv_obj_add_style(screen, LV_LABEL_PART_MAIN, &global_style);

    center_frame = lv_cont_create(screen, NULL);
    lv_obj_set_auto_realign(center_frame, true);
    lv_obj_align(center_frame, NULL, LV_ALIGN_CENTER, 0, 0);
    lv_cont_set_fit(center_frame, LV_FIT_TIGHT);
    lv_cont_set_layout(center_frame, LV_LAYOUT_CENTER);
    */

    bongo_cat_widget->obj = lv_label_create(screen, NULL);
    lv_obj_set_size(bongo_cat_widget->obj, 40, 15);
    lv_label_set_text(bongo_cat_widget->obj, "HI");
    sys_slist_append(&widgets, &bongo_cat_widget->node);
    lv_obj_align(bongo_cat_widget->obj, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);

//#if IS_ENABLED(CONFIG_BONGO_CAT)
//    zmk_widget_bongo_cat_init(&bongo_cat_widget, screen);
//    lv_obj_align(zmk_widget_bongo_cat_obj(&bongo_cat_widget), NULL, LV_ALIGN_IN_TOP_MID,
//                 0, 2);
//#endif

    // lv_task_handler();
    lv_refr_now(NULL);
    // display_blanking_off(display_dev);

    return screen;
}