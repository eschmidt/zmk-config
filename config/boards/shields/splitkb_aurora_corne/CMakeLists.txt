# Find Zephyr. This also loads Zephyr's build system.
#find_package(Zephyr REQUIRED HINTS ../zephyr)
#project(zmk)
#
#zephyr_linker_sources(RODATA include/linker/zmk-events.ld)
#
# Add your source file to the "app" target. This must come after
# find_package(Zephyr) which defines the target.
#target_include_directories(app PRIVATE include)
#target_sources_ifdef(CONFIG_ZMK_WPM app PRIVATE src/wpm.c)
#target_sources_ifdef(CONFIG_ZMK_WPM app PRIVATE src/events/wpm_state_changed.c)

zephyr_library()
zephyr_library_include_directories(${ZEPHYR_LVGL_MODULE_DIR})
zephyr_library_include_directories(${ZEPHYR_BASE}/lib/gui/lvgl/)
zephyr_library_sources_ifdef(CONFIG_ZMK_DISPLAY status_screen.c)
zephyr_library_sources_ifdef(CONFIG_BONGO_CAT bongo_cat_widget.c)
zephyr_library_sources_ifdef(CONFIG_BONGO_CAT bongo_cat_images.c)
zephyr_library_sources(${ZEPHYR_BASE}/misc/empty_file.c)
zephyr_library_include_directories(${CMAKE_SOURCE_DIR}/include)
zephyr_library_include_directories(${ZEPHYR_BASE}/drivers)