// Boy, I hope nobody finds this terrible code on the internet
// TODO: Split into multiple files - Setup, Lighting, Tap Dance, Keystroke Processing

#include QMK_KEYBOARD_H

#include <print.h>

enum layers { DEFAULT = 0, MAC, MAC_SPECIAL, MAC_ONE_SHOTS, WIN, WIN_GAMING, WIN_SPECIAL, SNAKE, KB_CONFIG, KB_RGB_PRV };

// TODO: There must be a better way to check for the state of these keys
bool r_alt_down = false;
bool meta_down = false;
bool mac_fn_down = false;
bool work_mode = false;

#include "tap_dance/tap_dance.c"
#include "led_control/led_control.c"
#include "leader/leader.c"

enum alt_keycodes {
    U_T_AUTO = SAFE_RANGE,  // USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,               // USB Toggle Automatic GCR control
    DBG_TOG,                // DEBUG Toggle On / Off
    DBG_MTRX,               // DEBUG Toggle Matrix Prints
    DBG_KBD,                // DEBUG Toggle Keyboard Prints
    DBG_MOU,                // DEBUG Toggle Mouse Prints
    MD_BOOT,                // Restart into bootloader after hold timeout
    RGB_WRK,                // Set RGB to white (for work)
    TYP_EXT,                // Type exit and press enter
    TYP_EXB,                // Type exit! and press enter
    MS_ENT,                 // MAC special layer enter
    IVT_MIN,               // Inverted KC_MINS
};

// VS Code Shortcuts
#define CG_LEFT C(G(KC_LEFT))   // Ctrl + Meta + Left Arrow - Move Code Panel Left
#define CG_RGHT C(G(KC_RIGHT))  // Ctrl + Meta + Right Arrow - Move Code Panel Right
#define AS_LBRC A(S(KC_LBRC))   // Alt + Shift + [ - Move to Left Panel
#define AS_RBRC A(S(KC_RBRC))   // Alt + Shift + ] - Move to Right Panel
#define SA_QUOT S(A(KC_QUOT))   // Alt + Shift + ' - VS Code Terminal Focus
#define VS_FLIP HYPR(KC_SCOLON) // Rails - FlipFlop
#define VS_DEFN KC_F12
#define VS_NMCH C(A(KC_DOT))    // Next Match (+ Shift to select next match)
#define VS_PMCH C(A(KC_COMM))    // Previous Match (+ Shift to undo last cursor)

// CMD + ... shortcuts - Making up for the lack of a right CMD key
#define G_BSPC G(KC_BSPC)       // Meta + Backspace
#define G_ENTR G(KC_ENT)        // Meta + Enter

// Misc Keys
#define HPR_RGT HYPR(KC_RGHT)
#define HPR_LFT HYPR(KC_LEFT)

// Keyboard Layer Control
#define WIN_S MO(WIN_SPECIAL)
#define MAC_S MO(MAC_SPECIAL)
#define MAC_OSL OSL(MAC_ONE_SHOTS)

// Keyboard toggles
#define SNK_TOG TG(SNAKE)       // Toggle snake case layer (space sends underscore)
#define RGB_PRV TG(KB_RGB_PRV)  // Preview RGB lighting while in config layer

// App Focus Shortcuts
#define TERM_D MEH(KC_T)  // Open dedicated terminal window
#define TERM_S HYPR(KC_T) // Show/Hide all terminal windows
#define MAC_FN KC_F20 // Karabiner listens for F20 and turns it into an apple keyboard fn
#define TRELLO HYPR(KC_F13)
#define FINDER HYPR(KC_F14)
#define VS_CODE HYPR(KC_F15)
#define FORK MEH(KC_F15)
#define SLACK HYPR(KC_F16)
#define BROWSER HYPR(KC_F18)
#define MUSIC   HYPR(KC_M) // Show the music Player
#define EMAIL HYPR(KC_F19)

// Music Control - Alfred Spotify Mini Player
#define SPOT_MP MEH(KC_S)       // Show Mini Player Control
#define SPOT_QU MEH(KC_DOT)     // Play Queue
#define SPOT_CT MEH(KC_SLASH)   // Current Track
#define SPOT_PPL MEH(KC_P)      // Private Playlists
#define SPOT_ATP MEH(KC_EQL)    // Add Current Track to Playlist
#define SPOT_RFP MEH(KC_MINS)   // Remove Current Track from Playlist
#define SPOT_PPS MEH(KC_ENT)    // Play/Pause
#define SPOT_NTK HYPR(KC_RBRC)   // Next Track
#define SPOT_LTK HYPR(KC_LBRC)   // Previous Track

//  Workflow Triggers
//      Code
#define S3_OP MEH(KC_3)     // S3 Bucket
#define S3_ROP HYPR(KC_3)   // s3 Bucket with previous client
#define NEP_MOD MEH(KC_M)   // Rails Model
#define NEP_AAT MEH(KC_A)   // Rails Model Attribute
//      House Lights
#define DST_OFF LCAG(KC_LEFT)       // Dave Study Lights Off
#define DST_WRK LCAG(KC_UP)         // Dave Study Lights Work/Concentrate
#define DST_STD LCAG(KC_RIGHT)      // Dave Study Reading Lights
#define DST_RLX LCAG(KC_DOWN)       // Dave Study Lights Relax

// ==================
// Key Map
// ==================

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEFAULT] = LAYOUT_65_ansi_blocker(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_LEAD, KC_DEL,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, \
        KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
        KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,          KC_UP ,  KC_PGDN, \
        TD_LCL , TD_LAT,  KC_LGUI,                            KC_SPC,                             TD_RAT , KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [MAC] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, MAC_S  , _______, _______, _______  \
    ),
    [MAC_SPECIAL] = LAYOUT_65_ansi_blocker(
        KC_GRV ,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  G_BSPC, TRELLO , \
        _______, _______, TYP_EXB, TYP_EXT, _______, _______, _______, _______, _______, _______, CG_LEFT, AS_LBRC, AS_RBRC, CG_RGHT, TD_HME , \
        KC_CAPS, NEP_AAT, TD_S3C , _______, TD_FNF , _______, _______, _______, _______, _______, VS_FLIP, SA_QUOT,           MS_ENT, TD_PUP , \
        SNK_TOG, _______, _______, TD_FNC , TD_FNV , _______, _______, TD_KCM , VS_PMCH, VS_NMCH ,TD_SLS , _______,          KC_PGUP, TD_PDN , \
        _______, _______, _______,                            MAC_OSL,                             MAC_FN, _______, KC_HOME, KC_PGDN, KC_END   \
    ),
    [MAC_ONE_SHOTS] = LAYOUT_65_ansi_blocker(
        KC_ESC , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,SPOT_RFP,SPOT_ATP, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,SPOT_PPL, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_MPLY, HPR_LFT, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, SPOT_QU, SPOT_CT, _______,          _______, HPR_RGT, \
        _______, _______, _______,                            _______,                            _______, _______, KC_MPRV, _______, KC_MNXT  \
    ),
    [WIN] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______,  WIN_S , _______, _______, _______  \
    ),
    [WIN_GAMING] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, KC_NO,                              _______,                            _______,  WIN_S , _______, _______, _______  \
    ),
    [WIN_SPECIAL] = LAYOUT_65_ansi_blocker(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, \
        _______, KC_PWR , KC_SLEP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_END , \
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MSEL, KC_MPLY,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MNXT, _______, _______,          KC_PGUP, _______, \
        _______, _______, _______,                            _______,                            _______, _______, KC_HOME, KC_PGDN, KC_END   \
    ),
    [SNAKE] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            KC_UNDS,                            _______, _______, _______, _______, _______  \
    ),
    [KB_CONFIG] = LAYOUT_65_ansi_blocker(
        RESET  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, \
        XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD, RGB_SPI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_PRV, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        _______, RGB_HUD, RGB_SAD, RGB_VAD,RGB_RMOD, RGB_SPD, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, RGB_WRK, RGB_TOG, XXXXXXX, MD_BOOT, NK_TOGG, DBG_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          DST_WRK, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            _______, _______, DST_OFF, DST_RLX, DST_STD  \
    ),
    [KB_RGB_PRV] = LAYOUT_65_ansi_blocker(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD, RGB_SPI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD,RGB_RMOD, RGB_SPD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, RGB_WRK, RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
    ),
    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),

    [X] = RGB INDEX (
        ESC 0 , ONE 1  , TWO 2  , THR 3  , FOR 4  , FVE 5  , SIX 6  ,  SVN 7 ,  EHT 8  , NIN  9 , ZRO 10 ,  -_ 11 ,  =+ 12 , BPSC 13, DEL 14 , \
        TAB 15,  Q  16 ,  W  17 ,  E  18 ,  R  19 ,  T  20 ,  Y  21 ,  U  22 ,  I  23  ,  O  24 ,  P 25  ,  [{ 26 ,  ]} 27 , \|  28 , HME 29 , \
        CAP 30,  A  31 ,  S  32 ,  D  33 ,  F  34 ,  G  35 ,  H  36 ,  J  37 ,  K  38  ,  L  39 ,  ;: 40 ,  '" 41 ,          ENT 42 , PGUP 43, \
        SFT 44,  Z  45 ,  X  46 ,  C  47 ,  V  48 ,  B  49 ,  N  50 ,  M  51 , ,<  52  , .>  53 ,  /? 54 , RSFT 55,          UP  56 , PGDN 57, \
        CTL 58, ALT 59 , GUI 60 ,                            SPC 61 ,                             ALT 62 ,  FN 63 , LEFT 64, DOWN 65, RGHT 66  \
    ),

    */
};

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
