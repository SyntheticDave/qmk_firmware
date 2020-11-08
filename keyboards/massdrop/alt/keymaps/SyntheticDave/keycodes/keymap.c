const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEFAULT] = LAYOUT_65_ansi_blocker(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_LEAD, KC_DEL,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, \
        KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  TD_DM1 , \
        KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,          KC_UP ,  TD_DM2, \
        TD_LCL , TD_LAT,  KC_LGUI,                            KC_SPC,                             TD_RAT , KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [MAC] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, DM_PLY1, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, DM_PLY2, \
        _______, _______, _______,                            _______,                            _______, MAC_S  , _______, _______, _______  \
    ),
    [MAC_SPECIAL] = LAYOUT_65_ansi_blocker(
        KC_CAPS, _______, TD_S3C ,  DICT  , TD_FNF , _______, _______, _______, _______, _______, VS_FLIP, SA_QUOT,           MS_ENT, TD_PUP , \
        KC_GRV ,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11 , KC_F12 ,  G_BSPC, TD_DEL , \
        _______, _______, TYP_EXB, TYP_EXT, _______, _______, _______, _______, _______, _______, _______, TD_FLB , TD_FRB , MAC_OSL, TD_HME , \
        SNK_TOG, _______, _______, TD_FNC , TD_FNV , _______, _______, TD_KCM , VS_PMCH, VS_NMCH ,TD_SLS , _______,          KC_PGUP, TD_PDN , \
        _______, _______, _______,                            MAC_OSL,                             MAC_FN, _______, KC_HOME, KC_PGDN, KC_END   \
    ),
    [MAC_ONE_SHOTS] = LAYOUT_65_ansi_blocker(
        KC_ESC , DM_REC1, _______, _______, _______, _______, _______, _______, _______, _______, _______,SPOT_RFP,SPOT_ATP, _______, _______, \
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
        KC_LCTL, KC_LALT, KC_LGUI,                            _______,                            KC_RALT,  WIN_S , _______, _______, _______  \
    ),
    [WIN_GAMING] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______,  KC_NO , _______,                            _______,                            _______,  WIN_S , _______, _______, _______  \
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
