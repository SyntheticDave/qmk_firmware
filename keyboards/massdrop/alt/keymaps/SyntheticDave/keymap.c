#include QMK_KEYBOARD_H

#include <print.h>

enum layers { DEFAULT = 0, MAC, MAC_SPECIAL, MAC_ONE_SHOTS, WIN, WIN_GAMING, WIN_SPECIAL, SNAKE, KB_CONFIG, KB_RGB_PRV };

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
};

// LED Sets
uint8_t all_leds[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101};
uint8_t key_leds[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66};
uint8_t key_leds_no_top_row[] = {15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66};
uint8_t base_leds[] = {67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104};
uint8_t base_leds_front[] = {67,68,69,70,71,72,73,74,75,76,77,78,79,80,81};
uint8_t base_leds_right[] = {82,83,84,85};
uint8_t base_leds_back[] = {86,87,88,89,90,91,92,93,94,95,96,97,98,99,100};
uint8_t base_leds_left[] = {101,102,103,104};
uint8_t arrow_keys[] = {56,64,65,66};

// VS Code Shortcuts
#define CG_LEFT C(G(KC_LEFT))   // Ctrl + Meta + Left Arrow - Move Code Panel Left
#define CG_RGHT C(G(KC_RIGHT))  // Ctrl + Meta + Right Arrow - Move Code Panel Right
#define AS_LBRC A(S(KC_LBRC))   // Alt + Shift + [ - Move to Left Panel
#define AS_RBRC A(S(KC_RBRC))   // Alt + Shift + ] - Move to Right Panel
#define SA_QUOT S(A(KC_QUOT))   // Alt + Shift + ' - VS Code Terminal Focus
#define VS_FLIP HYPR(KC_SCOLON) // Rails - FlipFlop

// CMD + ... shortcuts - Making up for the lack of a right CMD key
#define G_BSPC G(KC_BSPC)       // Meta + Backspace
#define G_ENTR G(KC_ENT)        // Meta + Enter

// Keyboard Layer Control
#define WIN_S MO(WIN_SPECIAL)
#define MAC_S MO(MAC_SPECIAL)
#define MAC_OSL OSL(MAC_ONE_SHOTS)

// Keyboard toggles
#define SNK_TOG TG(SNAKE)       // Toggle snake case layer (space sends underscore)
#define RGB_PRV TG(KB_RGB_PRV)  // Preview RGB lighting while in config layer

// App Focus Shortcuts
// iTerm
#define TERM_D MEH(KC_T)  // Open dedicated terminal window
#define TERM_S HYPR(KC_T) // Show/Hide all terminal windows
#define MAC_FN KC_F20 // Karabiner listens for F20 and turns it into an apple keyboard fn
#define TRELLO HYPR(KC_F13)
#define FINDER HYPR(KC_F14)
#define VS_CODE HYPR(KC_F15)
#define SLACK HYPR(KC_F16)


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
#define NEP_MOD MEH(KC_M)   // Rails Model
#define NEP_AAT MEH(KC_A)   // Rails Model Attribute
//      House Lights
#define DST_OFF LCAG(KC_LEFT)       // Dave Study Lights Off
#define DST_WRK LCAG(KC_UP)         // Dave Study Lights Work/Concentrate
#define DST_STD LCAG(KC_RIGHT)      // Dave Study Reading Lights
#define DST_RLX LCAG(KC_DOWN)       // Dave Study Lights Relax

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEFAULT] = LAYOUT_65_ansi_blocker(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, \
        KC_LEAD, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP, \
        KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,          KC_UP,   KC_PGDN, \
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RALT, KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [MAC] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, MAC_S  , _______, _______, _______  \
    ),
    [MAC_SPECIAL] = LAYOUT_65_ansi_blocker(
        KC_GRV ,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  G_BSPC, TRELLO, \
        _______, _______, TYP_EXB, TYP_EXT, _______, TERM_S ,  TERM_D, _______, _______, _______, CG_LEFT, AS_LBRC, AS_RBRC, CG_RGHT, FINDER , \
        KC_CAPS, NEP_AAT,  S3_OP , _______, _______, _______, _______, _______, _______, _______, VS_FLIP, SA_QUOT,           MS_ENT, VS_CODE, \
        SNK_TOG, _______, _______, _______, _______, _______, _______, SPOT_MP, _______, _______ ,_______, _______,          KC_PGUP, SLACK  , \
        _______, _______, _______,                            MAC_OSL,                             MAC_FN, _______, KC_HOME, KC_PGDN, KC_END   \
    ),
    [MAC_ONE_SHOTS] = LAYOUT_65_ansi_blocker(
        KC_ESC , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,SPOT_RFP,SPOT_ATP, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,SPOT_PPL, _______, _______, _______, _______, \
        KC_LEAD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_MPLY, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, SPOT_QU, SPOT_CT, _______,          _______, _______, \
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
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
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

LEADER_EXTERNS();

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

bool r_alt_down = false;
bool meta_down = false;
bool work_mode = false;
bool mac_fn_down = false;

// HACK: Can't figure out how to determine current hue/saturation, so using this workaround
void toggle_work_mode(void) {
    work_mode = !work_mode;

    // FIXME: Changed shortcuts
    if(work_mode) {
        // DST_WRK LCAG(KC_UP)
        // SS_HYPR doesn't work?
        SEND_STRING(SS_LCTL(SS_LSFT(SS_LGUI(SS_LALT("1")))));
    } else {
        SEND_STRING(SS_LCTL(SS_LSFT(SS_LGUI(SS_LALT("2")))));
        // DST_RLX LCAG(KC_DOWN)
    }
}

// Sets a list of keys to the same color
void rgb_matrix_set_collection_color(uint8_t keys[], int keyCount, uint8_t red, uint8_t green, uint8_t blue) {
    for (int i = 0; i < keyCount; i++) {
        rgb_matrix_set_color(keys[i], red, green, blue);
    }
};

void key_leds_off(bool top_row) {
    if(top_row) {
        rgb_matrix_set_collection_color(key_leds_no_top_row, sizeof(key_leds_no_top_row) / sizeof(uint8_t), RGB_OFF);
    } else {
        rgb_matrix_set_collection_color(key_leds, sizeof(key_leds) / sizeof(uint8_t), RGB_OFF);
    }
}

void show_mac_base_leds(void) {
    rgb_matrix_set_collection_color(base_leds_back, sizeof(base_leds_back) / sizeof(uint8_t), RGB_MAGENTA);
}

void show_mac_gpm_leds(void) {
    uint8_t lit_keys[]   = {45, 54, 56, 61, 64, 65, 66};
    rgb_matrix_set_collection_color(lit_keys, sizeof(lit_keys) / sizeof(uint8_t), RGB_GPM_ORANGE);
}

void show_mac_spotify_leds(void) {
    uint8_t lit_keys[]   = {11, 12, 25, 42, 53, 54, 64, 66};
    rgb_matrix_set_collection_color(lit_keys, sizeof(lit_keys) / sizeof(uint8_t), RGB_GREEN);
}

void show_mac_vs_code_leds(void) {
    uint8_t lit_keys[] = {25, 26, 27, 28, 40, 41};
    rgb_matrix_set_collection_color(lit_keys, sizeof(lit_keys) / sizeof(uint8_t), RGB_BLUE);
}

void show_arrow_leds(uint8_t red, uint8_t green, uint8_t blue) {
    uint8_t lit_keys[] = {56,64,65,66};
    rgb_matrix_set_collection_color(lit_keys, sizeof(lit_keys) / sizeof(uint8_t), red, green, blue);
}

void show_snake_leds(void) {
    rgb_matrix_set_color(61, RGB_TURQUOISE);  // Space Key
}

void show_mac_special_leds(void) {
    key_leds_off(true);
    show_mac_vs_code_leds();
    show_arrow_leds(RGB_WHITE);

    // Exit keys
    rgb_matrix_set_color(18, RGB_ORANGE);
    rgb_matrix_set_color(17, RGB_RED);

    // Backspace (sends CMD+Backspace, often used for deletion)
    rgb_matrix_set_color(13, RGB_RED);

    // Enter (sends CMD+Enter)
    rgb_matrix_set_color(42, RGB_WHITE);

    // RAlt - Sends F20 - Karabiner catches this and turns it into Mac OS fn key
    rgb_matrix_set_color(62, RGB_WHITE);

    // Capslock
    rgb_matrix_set_color(30, RGB_YELLOW);

    // Snake Case lock - l-shift
    rgb_matrix_set_color(44, RGB_YELLOW);

    // One shot layer trigger space
    rgb_matrix_set_color(61, RGB_GREEN);

    // Spotify Mini Player
    rgb_matrix_set_color(51, RGB_GREEN);

    // Neptune workflow triggers
    uint8_t trigger_keys[]   = {31, 32};
    rgb_matrix_set_collection_color(trigger_keys, sizeof(trigger_keys) / sizeof(uint8_t), RGB_BLUE);

    // iTerm Shortcuts
    uint8_t iterm_keys[]   = {20, 21};
    rgb_matrix_set_collection_color(iterm_keys, sizeof(iterm_keys) / sizeof(uint8_t), RGB_GOLD);

    // Show Trello
    rgb_matrix_set_color(14, RGB_BLUE);
    // Show Finder
    rgb_matrix_set_color(29, RGB_TEAL);
    // Show VS Code
    rgb_matrix_set_color(43, RGB_PURPLE);
    // Show Slack
    rgb_matrix_set_color(57, RGB_MAGENTA);
}

void show_mac_meta_leds(void) {
    rgb_matrix_set_color(16, RGB_RED);  // Q Key
    rgb_matrix_set_color(17, RGB_YELLOW);  // W Key
}

void show_mac_one_shot_leds(void) {
  key_leds_off(false);
//   show_mac_gpm_leds();
    show_mac_spotify_leds();
}

void show_mac_window_snap_keys(void) {
    uint8_t lit_keys[]   = {54, 53, 52, 41, 40, 28, 27, 26};

    // HACK: Using this to show snap keys as different colour.
    // Would be much better if we could just read the current hue/sat
    if(work_mode) {
        rgb_matrix_set_collection_color(lit_keys, sizeof(lit_keys) / sizeof(uint8_t), RGB_PURPLE);
    } else {
        rgb_matrix_set_collection_color(lit_keys, sizeof(lit_keys) / sizeof(uint8_t), RGB_WHITE);
    }
}

void show_win_base_leds(void) {
    rgb_matrix_set_collection_color(base_leds_back, sizeof(base_leds_back) / sizeof(uint8_t), RGB_BLUE);
}

void show_win_gaming_leds(void) {
    // Light up WASD and disable windows button light
    uint8_t lit_keys[]   = {17, 31, 32, 33};
    uint8_t unlit_keys[] = {60};

    rgb_matrix_set_collection_color(lit_keys, sizeof(lit_keys) / sizeof(uint8_t), RGB_RED);
    rgb_matrix_set_collection_color(unlit_keys, sizeof(unlit_keys) / sizeof(uint8_t), 0, 0, 0);
    show_arrow_leds(RGB_RED);
}

void show_layer_indicator(int layer) {
    // Layer indicator to help me keep my bearings
    if (layer > 0) {
        rgb_matrix_set_color(layer, RGB_WHITE);
    }
}

void show_win_media_control_leds(void) {
    uint8_t lit_keys[]   = {53, 52, 41, 40};
    rgb_matrix_set_collection_color(lit_keys, sizeof(lit_keys) / sizeof(uint8_t), RGB_GPM_ORANGE);
}

void show_win_special_leds(void) {
    key_leds_off(true);
    rgb_matrix_set_color(16, RGB_RED);  // Q Key Shutdown
    rgb_matrix_set_color(17, RGB_YELLOW);  // W Key - Sleep
    show_win_media_control_leds();
    show_arrow_leds(RGB_WHITE);
    // Capslock
    rgb_matrix_set_color(30, RGB_YELLOW);
}

void show_kb_config_keys(void) {
    key_leds_off(false);

    // HUE
    rgb_matrix_set_color(16, RGB_BLUE);             // hue up
    rgb_matrix_set_color(31, RGB_ORANGE);           // hue down

    // SAT
    rgb_matrix_set_color(17, RGB_RED);              // sat up
    rgb_matrix_set_color(32, 0xFF, 0x9B, 0x9B);     // sat down

    // WORK MODE - Sets keys white and toggles a boolean so we know the current state
    rgb_matrix_set_color(46, RGB_WHITE);

    // VALUE
    rgb_matrix_set_color(18, RGB_MAGENTA);          // value up
    rgb_matrix_set_color(33, 0x32,0x00,0x32);       // value down
    rgb_matrix_set_color(47, 0x32,0x32,0x32);       // RGB Toggle

    //RGB MODE
    rgb_matrix_set_color(19, RGB_TEAL);             // cycle left
    rgb_matrix_set_color(34, RGB_TEAL);             // cycle right

    //RGB SPEED
    rgb_matrix_set_color(20, RGB_YELLOW);           // slower
    rgb_matrix_set_color(35, RGB_YELLOW);           // faster

    // Light KL, as they're the exit keys for this layer
    rgb_matrix_set_color(38, 0x5A,0x5A,0x5A);
    rgb_matrix_set_color(39, 0x5A,0x5A,0x5A);

    // Dave Study Lighting
    uint8_t study_keys[] = {56,64,65,66};
    rgb_matrix_set_collection_color(study_keys, sizeof(study_keys) / sizeof(uint8_t), RGB_GOLD);
}

void show_custom_lighting(void) {
    if(work_mode) {
        rgb_matrix_set_color_all(RGB_WHITE);
    }

    // Find the current layer
    uint8_t layer = biton32(layer_state);

    // Set lighting based on the current layer
    // TODO: Fix snake case lighting - Completely breaks other lighting atm, as it's the last active layer. Could consider using a modifier, rather than an entire layer to implement this. Would be much easier on the lighting side, at least
    switch (layer) {
        case MAC_ONE_SHOTS:
          show_mac_one_shot_leds();
          break;
        case MAC_SPECIAL:
            show_mac_special_leds();
        case MAC:
            show_mac_base_leds();
            break;
        case WIN_SPECIAL:
            show_win_special_leds();
        case WIN:
            show_win_base_leds();
            break;
        case WIN_GAMING:
            show_win_base_leds();
            show_win_gaming_leds();
            break;
        case KB_CONFIG:
            show_kb_config_keys();
            break;
    }

    // Set lighting based on individully held key
    if (r_alt_down && layer == MAC) {
        show_mac_window_snap_keys();
    }

    if (meta_down && layer == MAC) {
        show_mac_meta_leds();
    }

    show_layer_indicator(layer);
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    // Handle Leader Key Behaviour
    LEADER_DICTIONARY() {
        leading = false;

        SEQ_ONE_KEY(KC_GESC) {
            layer_clear();  // Disable all layers except base
        }
        SEQ_ONE_KEY(KC_M) {
            layer_move(MAC);  // Activate Mac OS Layer (only)
        }
        // Double tap leader key
        SEQ_ONE_KEY(KC_LEAD) {
          // TODO: Only activate mac oneshot layer if we're on the mac base layer or the osl
          // layer_state_is(MAC)
          layer_invert(MAC_ONE_SHOTS);
        }
        SEQ_ONE_KEY(KC_W) {
            layer_move(WIN);  // Activate Windows Layer (only)
        }
        SEQ_TWO_KEYS(KC_G, KC_G) {
            layer_move(WIN);       // Activate Windows Layer (only)
            layer_on(WIN_GAMING);  // Then activate the gaming layer
        }
        SEQ_TWO_KEYS(KC_K, KC_L) {
            layer_invert(KB_CONFIG);  // Toggle the keyboard config layer
        }
        leader_end();
    }
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
        case KC_RALT:
            r_alt_down = record->event.pressed;
            return true;
        case MAC_FN:
            mac_fn_down = record->event.pressed;
            return true;
        case MS_ENT:
            // Mac Special layer enter handling
            if(record->event.pressed) {
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
        default:
            return true;  // Process all other keycodes normally
    }
}

void rgb_matrix_indicators_user(void)
{
    show_custom_lighting();

	uint8_t this_led = host_keyboard_leds();

    if (this_led & (1 << USB_LED_CAPS_LOCK)) {
        rgb_matrix_set_collection_color(base_leds_left, sizeof(base_leds_left) / sizeof(uint8_t), RGB_RED);
    }
}
