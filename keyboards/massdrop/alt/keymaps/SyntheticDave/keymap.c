// Boy, I hope nobody finds this terrible code on the internet
// TODO: Split into multiple files - Setup, Lighting, Tap Dance, Keystroke Processing

#include QMK_KEYBOARD_H

#include <print.h>

// TODO: There must be a better way to check for the state of these keys
bool r_alt_down = false;
bool meta_down = false;
bool mac_fn_down = false;
bool work_mode = false;

#include "layers/layers_definitions.c"
#include "tap_dance/tap_dance.c"
#include "led_control/led_control.c"
#include "leader/leader.c"
#include "keycodes/custom_keycodes.c"
#include "keycodes/aliases_definitions.c"
#include "keycodes/keymap.c"    // Actual keymap

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable = true;
    debug_matrix = true;
    // debug_keyboard=true;
    // debug_mouse=true;
    print("keyboard started\n");
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) { print("keyboard starting\n"); };

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    handle_leader_key();
};

#define MODS_SHIFT (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

// If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif

    switch (keycode) {
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
                switch (rgb_matrix_get_flags()) {
                    case LED_FLAG_ALL: {
                        rgb_matrix_set_flags(LED_FLAG_KEYLIGHT);
                        rgb_matrix_set_color_all(0, 0, 0);
                    } break;
                    case LED_FLAG_KEYLIGHT: {
                        rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                        rgb_matrix_set_color_all(0, 0, 0);
                    } break;
                    case LED_FLAG_UNDERGLOW: {
                        rgb_matrix_set_flags(LED_FLAG_NONE);
                        rgb_matrix_disable_noeeprom();
                    } break;
                    default: {
                        rgb_matrix_set_flags(LED_FLAG_ALL);
                        rgb_matrix_enable_noeeprom();
                    } break;
                }
            }
            return false;
        case RGB_WRK:
            if(record->event.pressed) {
                toggle_work_mode();
            }
            return false;
        case TD_RAT:
            r_alt_down = record->event.pressed;
            return true;
        case MAC_FN:
            mac_fn_down = record->event.pressed;
            return true;
        case MS_ENT:
            // Mac Special layer enter handling
            if(record->event.pressed) {
                // Just send enter if we're effectively sending fn
                if(mac_fn_down) {
                    SEND_STRING(SS_TAP(X_ENT));
                    return false;
                }
                // Send CMD + Enter if ralt not being held
                SEND_STRING(SS_DOWN(X_RGUI));
                SEND_STRING(SS_TAP(X_ENT));
                SEND_STRING(SS_UP(X_RGUI));
                return false;
            }
        case KC_LCMD:
            meta_down = record->event.pressed;
            return true;
        case TYP_EXT:
            if (record->event.pressed) {
                SEND_STRING("exit\n");
            }
            return false;
        case TYP_EXB:
            if (record->event.pressed) {
                SEND_STRING("exit!\n");
            }
            return false;
        // Inverted minus — Sends underscore by default
        case IVT_MIN:
            if (record->event.pressed) {
                // FIXME: Handle both shifts
                if(MODS_SHIFT) {
                    unregister_code(KC_LSHIFT);
                    register_code(KC_MINS);
                    unregister_code(KC_MINS);
                    register_code(KC_LSHIFT);
                } else {
                    SEND_STRING("_");
                }
            }
            return false;
        default:
            return true;  // Process all other keycodes normally
    }
}
