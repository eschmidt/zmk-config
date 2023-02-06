/*
 * Copyright (c) 2022 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <kernel.h>
#include <bluetooth/services/bas.h>

#include <logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#include <zmk/display.h>
#include <zmk/display/widgets/layer_status.h>

struct zmk_widget_hello {
    sys_snode_t node;
    lv_obj_t *obj;
};

struct layer_status_state {
    uint8_t index;
    const char *label;
};

static sys_slist_t widgets = SYS_SLIST_STATIC_INIT(&widgets);

struct hello_state {
    bool connected;
};

static struct layer_status_state layer_status_get_state(const zmk_event_t *eh) {
    uint8_t index = zmk_keymap_highest_layer_active();
    return (struct layer_status_state){.index = index, .label = zmk_keymap_layer_label(index)};
}

static void output_status_update_cb(struct hello_state state) {
    struct zmk_widget_hello *widget;
    SYS_SLIST_FOR_EACH_CONTAINER(&widgets, widget, node) { lv_label_set_text(widget->obj, "HI"); }
}

ZMK_DISPLAY_WIDGET_LISTENER(widget_hello, struct hello_state,
                            hello_update_cb, get_state)
ZMK_SUBSCRIPTION(widget_hello, zmk_layer_state_changed);

int zmk_widget_hello_init(struct zmk_widget_hello *widget,
                                      lv_obj_t *parent) {
    widget->obj = lv_label_create(parent, NULL);

    lv_obj_set_size(widget->obj, 40, 15);
    lv_label_set_text(widget->obj, "HI");

    sys_slist_append(&widgets, &widget->node);

    return 0;
}

lv_obj_t *zmk_widget_hello_obj(struct zmk_widget_hello *widget) {
    return widget->obj;
}
