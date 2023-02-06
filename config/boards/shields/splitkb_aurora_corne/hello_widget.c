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

struct zmk_widget_hello {
    sys_snode_t node;
    lv_obj_t *obj;
};

static sys_slist_t widgets = SYS_SLIST_STATIC_INIT(&widgets);

struct hello_state {
    bool connected;
};

static struct hello_state get_state(const zmk_event_t *_eh) {
    return (struct hello_state){.connected = zmk_split_bt_peripheral_is_connected()};
}

static void output_status_update_cb(struct hello_state state) {
    struct zmk_widget_hello *widget;
    SYS_SLIST_FOR_EACH_CONTAINER(&widgets, widget, node) { lv_label_set_text(widget->obj, "HI"); }
}

ZMK_DISPLAY_WIDGET_LISTENER(widget_hello, struct hello_state,
                            hello_update_cb, get_state)
ZMK_SUBSCRIPTION(widget_hello, zmk_split_peripheral_status_changed);

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
