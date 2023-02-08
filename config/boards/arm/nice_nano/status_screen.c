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
    screen = lv_obj_create(NULL, NULL);

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