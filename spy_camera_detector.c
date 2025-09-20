#include <furi.h>
#include <gui/gui.h>
#include <input/input.h>
#include <dolphin/dolphin.h>
#include <stdlib.h>
#include <string.h>

#define BLINK_DELAY 100 // milliseconds, can be made configurable

static bool blinking = false;
static int blink_rate = BLINK_DELAY; // allow changing this for future adjustment

void draw_blinking_indicator(Canvas* canvas) {
    canvas_draw_str(canvas, 5, 60, "BLINKING...");
}

void blink_led() {
    furi_hal_light_write(FuriHalLightIR, true);
    furi_delay_ms(blink_rate);
    furi_hal_light_write(FuriHalLightIR, false);
    furi_delay_ms(blink_rate);
}

int32_t spy_camera_detector_app(void* p) {
    UNUSED(p);

    // Setup GUI, Input, etc.
    FuriMessageQueue* event_queue = furi_message_queue_alloc(8, sizeof(InputEvent));
    ViewPort* view_port = view_port_alloc();
    view_port_draw_callback_set(view_port, 
        (ViewPortDrawCallback)draw_blinking_indicator, NULL);

    Gui* gui = furi_record_open(RECORD_GUI);
    gui_add_view_port(gui, view_port, GuiLayerFullscreen);

    blinking = true;

    while(blinking) {
        blink_led();

        // Add input handling for cancellation (not shown for brevity)
        // If cancelled, set blinking = false;
    }

    gui_remove_view_port(gui, view_port);
    view_port_free(view_port);
    furi_message_queue_free(event_queue);
    furi_record_close(RECORD_GUI);

    return 0;
}