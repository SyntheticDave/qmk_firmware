enum alt_keycodes {
    U_T_AUTO = SAFE_RANGE,  // USB Extra Port Toggle Auto Detect / Always Active
    DYNAMIC_MACRO_RANGE,
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
    IVT_MIN,                // Inverted KC_MINS
    KC_LOCK,                // Lock Mac OS (using alfred)
};
