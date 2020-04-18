#include QMK_KEYBOARD_H

#include <print.h>

enum layers {
  DEFAULT = 0,
  MAC = 1,
  MAC_SPECIAL = 2,
  WIN = 3,
  WIN_GAMING = 4,
  WIN_SPECIAL = 5,
  RGB_CONFIG = 6
};

enum alt_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEFAULT] = LAYOUT_65_ansi_blocker(
        KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, \
        KC_LEAD, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
        KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,          KC_UP,   KC_PGDN, \
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RALT, KC_RGUI,   KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [MAC] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, MO(MAC_SPECIAL), _______, _______, _______  \
    ),
    [MAC_SPECIAL] = LAYOUT_65_ansi_blocker(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_MUTE, \
        _______, _______, _______, _______, _______, _______, _______, U_T_AUTO,U_T_AGCR,_______, KC_PSCR, KC_SLCK, KC_PAUS, _______, KC_END, \
        _______, _______,_______, _______, _______, _______, _______, _______, _______, _______, HYPR(KC_S), HYPR(KC_P),          _______, KC_VOLU, \
        _______, _______, _______, _______, _______, MD_BOOT, NK_TOGG, DBG_TOG, HYPR(KC_LBRC), HYPR(KC_RBRC), HYPR(KC_I), _______,          KC_PGUP, KC_VOLD, \
        _______, _______, _______,                            _______,                            _______, _______, KC_HOME, KC_PGDN, KC_END  \
    ),
    [WIN] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, MO(WIN_SPECIAL), _______, _______, _______  \
    ),
    [WIN_GAMING] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, KC_NO,                            _______,                            _______, MO(WIN_SPECIAL), _______, _______, _______  \
    ),
    [WIN_SPECIAL] = LAYOUT_65_ansi_blocker(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    [RGB_CONFIG] = LAYOUT_65_ansi_blocker(
        _______,  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,  _______,  _______,  _______, _______, \
        _______, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, _______,_______,_______, _______, _______, _______, _______, _______, \
        _______, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, RGB_TOG, RGB_M_P, RGB_M_R, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),

    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    */
};

LEADER_EXTERNS();

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

bool r_alt_down = false;

// Sets a list of keys to the same color
void rgb_matrix_set_collection_color(uint8_t keys[], int keyCount, uint8_t red, uint8_t green, uint8_t blue){
  for (int i = 0; i < keyCount; i++) {
    rgb_matrix_set_color(keys[i], red, green, blue);
  }
};

void show_mac_base_keys(void) {
  rgb_matrix_set_color(60, RGB_MAGENTA);
}

void show_mac_gpm_keys(void) {
  uint8_t lit_keys[] = {54, 53, 52, 41, 40};
  uint8_t unlit_keys[] = {25, 26, 27, 38, 39, 51};

  rgb_matrix_set_collection_color(lit_keys, sizeof(lit_keys) / sizeof(uint8_t), RGB_GPM_ORANGE);
  rgb_matrix_set_collection_color(unlit_keys, sizeof(unlit_keys) / sizeof(uint8_t), 0,0,0);
}

void show_mac_window_snap_keys(void) {
  // Window snapping cluster
  // TODO: Choose highlight colour based on the current colour.
  //        I'm not sure how to read current values
  // Want to show a different colour if key was already white
  uint8_t lit_keys[] = {54, 53, 52, 41, 40, 28, 27, 26};
  uint8_t unlit_keys[] = {11, 12, 13, 25, 38, 39, 42, 51};

  rgb_matrix_set_collection_color(lit_keys, sizeof(lit_keys) / sizeof(uint8_t), RGB_WHITE);
  rgb_matrix_set_collection_color(unlit_keys, sizeof(unlit_keys) / sizeof(uint8_t), 0,0,0);
}

void show_win_base_keys(void) {
  rgb_matrix_set_color(60, RGB_BLUE);
}

void show_win_gaming_keys(void) {
  // Light up WASD and disable windows button
  uint8_t lit_keys[] = {17, 31, 32, 33};
  uint8_t unlit_keys[] = {60};

  rgb_matrix_set_collection_color(lit_keys, sizeof(lit_keys) / sizeof(uint8_t), RGB_RED);
  rgb_matrix_set_collection_color(unlit_keys, sizeof(unlit_keys) / sizeof(uint8_t), 0,0,0);
}

void show_layer_indicator(int layer) {
  // Layer indicator to help me keep my bearings
  if(layer > 0) {
    rgb_matrix_set_color(layer, RGB_MAGENTA);
    // rgb_matrix_set_color(63, RGB_MAGENTA); // Fn key
  }
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
  // Find the current layer
  uint8_t layer = biton32(layer_state);

  // Set lighting based on the current layer
  show_layer_indicator(layer);
  switch (layer) {
    case MAC_SPECIAL:
      show_mac_gpm_keys();
    case MAC:
      show_mac_base_keys();
      break;
    case WIN_SPECIAL:
    case WIN:
      show_win_base_keys();
      break;
    case WIN_GAMING:
      show_win_gaming_keys();
      break;
  }

  // Set lighting based on individully held key
  if(r_alt_down && layer == MAC) {
    show_mac_window_snap_keys();
  }

  // Handle Leader Key Behaviour
  LEADER_DICTIONARY() {
    leading = false;

    // Activate CapsLock on double tapping the leader key
    SEQ_ONE_KEY(KC_LEAD) {
      register_code(KC_CAPS);
    }
    SEQ_ONE_KEY(KC_M) {
      layer_move(MAC);	 // Activate Mac OS Layer (only)
    }
    SEQ_ONE_KEY(KC_W) {
      layer_move(WIN); // Activate Windows Layer (only)
    }
    SEQ_TWO_KEYS(KC_W, KC_G) {
      layer_move(WIN); // Activate Windows Layer (only)
      layer_on(WIN_GAMING); // Then activate the gaming layer
    }    SEQ_TWO_KEYS(KC_K, KC_L) {
      layer_invert(RGB_CONFIG); // Toggle the lighting config layer
    }

    leader_end();
  }
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

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
                  }
                  break;
                case LED_FLAG_KEYLIGHT: {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
        case KC_RALT:
          r_alt_down = record->event.pressed;
          return true;
        default:
            return true; //Process all other keycodes normally
    }
}
