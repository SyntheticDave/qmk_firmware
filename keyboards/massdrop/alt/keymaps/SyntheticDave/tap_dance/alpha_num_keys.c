// Custom tapdance behaviour for Alpha-numeric + Symbol keys
// Mostly mapped to Fn+Key, as I don't want to deal with TD Delay and accidental triggers on the keys otherwise

/*
 Fn + M key control
*/
void m_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    // Spotify Mini Player on tap
    case SINGLE_TAP: SEND_STRING(SS_LCTL(SS_LSFT(SS_LALT(SS_TAP(X_S))))); break;
    // Spotify on hold
    case SINGLE_HOLD: SEND_STRING(SS_LCTL(SS_LSFT(SS_LGUI(SS_LALT(SS_TAP(X_M)))))); break;
  }
}

/*
 Fn + / key control
*/
// REVISE: I don't use these a whole lot. Consider moving/removing
void slash_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    // VS Code Go to definition
    case SINGLE_TAP: SEND_STRING(SS_TAP(X_F12)); break;
    // VS Code Show References
    case SINGLE_HOLD: SEND_STRING(SS_LSFT(SS_TAP(X_F12))); break;
  }
}

/*
 Fn + S key control
*/
void s3c_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    // S3 Command
    case SINGLE_TAP: SEND_STRING(SS_LCTL(SS_LSFT(SS_LALT(SS_TAP(X_3))))); break;
    // S3 Command with last used client
    case SINGLE_HOLD: SEND_STRING(SS_LCTL(SS_LSFT(SS_LGUI(SS_LALT(SS_TAP(X_3)))))); break;
  }
}

/*
 Fn + F key control
*/
void fn_f_finished (qk_tap_dance_state_t *state, void *user_data) {
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
 Fn + V key control
*/
void fn_v_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    // Ctrl + Alt + V - Search Snippets Lab
    case SINGLE_TAP: SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_V)))); break;
    // Hyper V - Trigger enhanced snippets on selected text
    // case SINGLE_HOLD: SEND_STRING(SS_LCTL(SS_LSFT(SS_LGUI(SS_LALT(SS_TAP(X_V)))))); break;
    case SINGLE_HOLD: SEND_STRING(SS_HYPR(X_V)); break;
    // Meh V - Trigger text massager on selected text
    case DOUBLE_TAP: SEND_STRING(SS_LCTL(SS_LSFT(SS_LALT(SS_TAP(X_V))))); break;
  }
}

/*
 Fn + C key control
*/
void fn_c_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    // Meh C - Trigger text massager on clipboard text
    case SINGLE_TAP: SEND_STRING(SS_LCTL(SS_LSFT(SS_LALT(SS_TAP(X_C))))); break;
    // Hyper B - Trigger enhanced snippets on clipboard text (HYPER C being swallowed by something)
    case DOUBLE_TAP: SEND_STRING(SS_LCTL(SS_LSFT(SS_LGUI(SS_LALT(SS_TAP(X_B)))))); break;
  }
}

/*
  Fn + Left Bracket control
*/
void flb_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    // Move to left panel
    case SINGLE_TAP: SEND_STRING(SS_LALT(SS_LCTL(SS_LGUI(SS_TAP(X_LBRC))))); break;
    // Move to left panel with current file
    case SINGLE_HOLD: SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT(SS_LGUI(SS_TAP(X_LBRC)))))); break;
  }
}

/*
  Fn + Right Bracket control
*/
void frb_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    // Move to right panel
    case SINGLE_TAP: SEND_STRING(SS_LALT(SS_LCTL(SS_LGUI(SS_TAP(X_RBRC))))); break;
    // Move to right panel with current file
    case SINGLE_HOLD: SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT(SS_LGUI(SS_TAP(X_RBRC)))))); break;
  }
}
