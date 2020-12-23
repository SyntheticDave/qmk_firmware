// Custom tapdance behaviour for Alpha-numeric + Symbol keys
// Mostly mapped to Fn+Key, as I don't want to deal with TD Delay and accidental triggers on the keys otherwise

/*
 Fn + 3 key control
*/
void fn_3_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case SINGLE_TAP:
            SEND_STRING(SS_TAP(X_F3));
            break;
        // S3 Command with last used client
        case DOUBLE_TAP:
            SEND_STRING(SS_DT_1(X_F3));
            break;
        // S3 Command
        case DOUBLE_HOLD:
            SEND_STRING(SS_DH_1(X_F3));
            break;
    }
}

/*
  Fn + Left Bracket control
*/
void flb_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        // Move to left panel
        case SINGLE_TAP:
            SEND_STRING(SS_LALT(SS_LCTL(SS_LGUI(SS_TAP(X_LBRC)))));
            break;
        // Move to left panel with current file
        case SINGLE_HOLD:
            SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT(SS_LGUI(SS_TAP(X_LBRC))))));
            break;
    }
}

/*
  Fn + Right Bracket control
*/
void frb_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        // Move to right panel
        case SINGLE_TAP:
            SEND_STRING(SS_LALT(SS_LCTL(SS_LGUI(SS_TAP(X_RBRC)))));
            break;
        // Move to right panel with current file
        case SINGLE_HOLD:
            SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT(SS_LGUI(SS_TAP(X_RBRC))))));
            break;
    }
}

/*
 Fn + T key control
*/
void fn_t_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        // Text massager on selected text
        case SINGLE_TAP:
            SEND_STRING(SS_ST_2(X_F15));
            break;
        // Text massager on clipboard text
        case SINGLE_HOLD:
            SEND_STRING(SS_SH_2(X_F15));
            break;
        // Unused
        case DOUBLE_TAP:
            SEND_STRING(SS_DT_2(X_F15));
            break;
        case DOUBLE_HOLD:
            SEND_STRING(SS_DH_2(X_F15));
            break;
        case TRIPLE_TAP:
            SEND_STRING(SS_TT_2(X_F15));
            break;
        case TRIPLE_HOLD:
            SEND_STRING(SS_TH_2(X_F15));
            break;
    }
}

/*
 Fn + A key control
*/
void fn_a_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case SINGLE_TAP:
            SEND_STRING(SS_ST_1(X_F16));
            break;
        case SINGLE_HOLD:
            SEND_STRING(SS_SH_1(X_F16));
            break;
        case DOUBLE_TAP:
            SEND_STRING(SS_DT_1(X_F16));
            break;
        case DOUBLE_HOLD:
            SEND_STRING(SS_DH_1(X_F16));
            break;
        case TRIPLE_TAP:
            SEND_STRING(SS_TT_1(X_F16));
            break;
        case TRIPLE_HOLD:
            SEND_STRING(SS_TH_1(X_F16));
            break;
    }
}

/*
 Fn + S key control
*/
void fn_s_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        // Show ESL Snippet List
        case SINGLE_TAP:
            SEND_STRING(SS_ST_1(X_F15));
            break;
        // Send highlighted text to ES
        case SINGLE_HOLD:
            SEND_STRING(SS_SH_1(X_F15));
            break;
        // Show Alfred Snippets
        case DOUBLE_TAP:
            SEND_STRING(SS_DT_1(X_F15));
            break;
        // Unused
        case DOUBLE_HOLD:
            SEND_STRING(SS_DH_1(X_F15));
            break;
        case TRIPLE_TAP:
            SEND_STRING(SS_TT_1(X_F15));
            break;
        case TRIPLE_HOLD:
            SEND_STRING(SS_TH_1(X_F15));
            break;
    }
}

/*
 Fn + F key control
*/
void fn_f_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        // VS Code - Show File in Sidebar
        case SINGLE_TAP:
            SEND_STRING(SS_LGUI(SS_TAP(X_K)));
            SEND_STRING(SS_LGUI(SS_TAP(X_SCLN)));
            break;
        // VS Code - Show File in Finder
        case SINGLE_HOLD:
            SEND_STRING(SS_LGUI(SS_TAP(X_K)));
            SEND_STRING(SS_LGUI(SS_TAP(X_QUOT)));
            break;
    }
}

/*
 Fn + C key control
*/
void fn_c_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        // Meh C - Trigger text massager on clipboard text
        case SINGLE_TAP:
            SEND_STRING(SS_LCTL(SS_LSFT(SS_LALT(SS_TAP(X_C)))));
            break;
        // Hyper B - Trigger enhanced snippets on clipboard text (HYPER C being swallowed by something)
        case DOUBLE_TAP:
            SEND_STRING(SS_LCTL(SS_LSFT(SS_LGUI(SS_LALT(SS_TAP(X_B))))));
            break;
    }
}


/*
 Fn + V key control
*/
void fn_v_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        // Ctrl + Alt + V - Search Snippets Lab
        case SINGLE_TAP:
            SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_V))));
            break;
        // Hyper V - Trigger enhanced snippets on selected text
        // case SINGLE_HOLD: SEND_STRING(SS_LCTL(SS_LSFT(SS_LGUI(SS_LALT(SS_TAP(X_V)))))); break;
        case SINGLE_HOLD:
            SEND_STRING(SS_HYPR(X_V));
            break;
        // Meh V - Trigger text massager on selected text
        case DOUBLE_TAP:
            SEND_STRING(SS_LCTL(SS_LSFT(SS_LALT(SS_TAP(X_V)))));
            break;
    }
}

/*
 Fn + M key control
*/
void m_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        // Spotify Mini Player
        case SINGLE_TAP:
            SEND_STRING(SS_MEH(X_F13));
            break;
        // Spotify UI
        case SINGLE_HOLD:
            SEND_STRING(SS_LCTL(SS_TAP(X_F13)));
            break;
        case DOUBLE_TAP:
            SEND_STRING(SS_LCA(X_F13));
            break;
        case DOUBLE_HOLD:
            SEND_STRING(SS_LALT(SS_TAP(X_F13)));
            break;
    }
}

/*
 Fn + / key control
*/
// REVISE: I don't use these a whole lot. Something else might be better suited to this position
void slash_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        // VS Code Go to definition
        case SINGLE_TAP:
            SEND_STRING(SS_TAP(X_F12));
            break;
        // VS Code Show References
        case SINGLE_HOLD:
            SEND_STRING(SS_LSFT(SS_TAP(X_F12)));
            break;
    }
}
