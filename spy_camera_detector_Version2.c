#include <furi.h>
#include <gui/gui.h>
#include <input/input.h>
#include <irda/irda_tx.h>

#define BLINK_DELAY 100 // ms

static void spy_camera_detector_draw(Canvas* canvas, void* context) {
    canvas_clear(canvas);
    canvas_set_font(canvas, FontPrimary);
    canvas_draw_str(canvas, 5, 15, "Spy Camera Detector");
    canvas_set_font(canvas, FontSecondary);
    canvas_draw_str(canvas, 5, 35, "Scan for reflections!");
    canvas_draw_str(canvas, 5, 50, "Press BACK to exit.");
}

static void spy_camera_detector_input(InputEvent* event, void* ctx) {
    bool* running = ctx;
    if(event->type == InputTypeShort && event->key == InputKeyBack) {
        *running = false;
    }
}

int32_t spy_camera_detector_app(void* p) {
    UNUSED(p);

    Gui* gui = furi_record_open("gui");
    ViewPort* viewport = viewport_alloc();
    viewport_draw_callback_set(viewport, spy_camera_detector_draw, NULL);

    bool running = true;
    Input* input = furi_record_open("input");
    input_set_callback(input, spy_camera_detector_input, &running);

    gui_add_view_port(gui, viewport, GuiLayerFullscreen);

    IrdaTx* irda = irda_tx_alloc();

    while(running) {
        // Blink the IR LED
        irda_tx_burst(irda, 38000, 100); // 38kHz, 100 pulses
        furi_delay_ms(BLINK_DELAY);
        furi_delay_ms(BLINK_DELAY); // Pause between blinks
    }

    irda_tx_free(irda);

    gui_remove_view_port(gui, viewport);
    viewport_free(viewport);
    furi_record_close("gui");
    furi_record_close("input");

    return 0;
}