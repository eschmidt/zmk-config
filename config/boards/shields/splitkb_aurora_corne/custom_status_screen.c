/*
 * Copyright (c) 2020 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */
#include <zmk/display/widgets/layer_status.h>
#include <zmk/display/status_screen.h>
#include <logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

struct bongo_cat_widget {
    sys_snode_t node;
    lv_obj_t *obj;
};

static struct bongo_cat_widget widget;

LV_IMG_DECLARE(slow_img);

lv_obj_t *zmk_display_status_screen() {
    lv_obj_t *screen;
    lv_obj_t *center_frame;

    widget->obj = lv_img_create(parent, NULL);
    lv_img_set_auto_size(widget->obj, true);
    sys_slist_append(&widgets, &widget->node);

    lv_img_set_src(widget->obj, &slow_img);

/*
    lv_style_init(&global_style);
    lv_style_set_text_font(&global_style, LV_STATE_DEFAULT, &lv_font_montserrat_26);
    lv_style_set_text_letter_space(&global_style, LV_STATE_DEFAULT, 1);
    lv_style_set_text_line_space(&global_style, LV_STATE_DEFAULT, 1);
    screen = lv_obj_create(NULL, NULL);
    lv_obj_add_style(screen, LV_LABEL_PART_MAIN, &global_style);

    center_frame = lv_cont_create(screen, NULL);
    lv_obj_set_auto_realign(center_frame, true);
    lv_obj_align(center_frame, NULL, LV_ALIGN_CENTER, 0,
                 0);
    lv_cont_set_fit(center_frame, LV_FIT_TIGHT);
    lv_cont_set_layout(center_frame, LV_LAYOUT_CENTER);

    zmk_widget_layer_status_init(&layer_status_widget, screen);
    lv_obj_align(zmk_widget_layer_status_obj(&layer_status_widget), NULL, LV_ALIGN_IN_BOTTOM_LEFT,
                 0, 0);

    zmk_widget_hello_init(&hello_widget, screen)
    lv_obj_align(zmk_widget_hello_obj(&hello_widget), NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0)
 */

    return screen;
}