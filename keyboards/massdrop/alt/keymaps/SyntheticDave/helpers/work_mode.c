bool work_mode = false;

void toggle_work_mode(bool quit_apps) {
    work_mode = !work_mode;

    if(work_mode) {
        // Bright Office Lights
        SEND_STRING(SS_LCTL(SS_LGUI(SS_LALT(SS_TAP(X_UP)))));
    } else {
        // Relaxed Office Lights
        SEND_STRING(SS_LCTL(SS_LGUI(SS_LALT(SS_TAP(X_DOWN)))));
        // Quit work applications - Hyper 0
        if(quit_apps) {
            SEND_STRING(SS_LCTL(SS_LGUI(SS_LALT(SS_LSFT(SS_TAP(X_0))))));
        }
    }
}
