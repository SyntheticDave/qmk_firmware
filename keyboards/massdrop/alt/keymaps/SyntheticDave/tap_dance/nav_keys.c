// Navigation key cluster
// Primarily used to launch/focus applications

/*
 Fn + Del key control
*/
void del_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    // Trello
    case SINGLE_TAP: SEND_STRING(SS_TAP(X_F13)); break;
    // Jira
    case SINGLE_HOLD: SEND_STRING(SS_LALT(SS_LGUI(SS_TAP(X_F13)))); break;
    // Show Gmail
    case DOUBLE_TAP: SEND_STRING(SS_LGUI(SS_TAP(X_F13))); break;
    // Show Outlook
    case DOUBLE_HOLD: SEND_STRING(SS_LALT(SS_TAP(X_F13))); break;
    // Calendar
    case TRIPLE_TAP: SEND_STRING(SS_LCTL(SS_TAP(X_F13))); break;
  }
}

/*
 Fn + Home key control
*/
void home_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    // Safari
    case SINGLE_TAP: SEND_STRING(SS_LCTL(SS_LSFT(SS_LGUI(SS_LALT(SS_TAP(X_F18)))))); break;
    // Firefox
    case SINGLE_HOLD: SEND_STRING(SS_LCTL(SS_LGUI(SS_LALT(SS_TAP(X_F18))))); break;
    // Finder on double tap
    case DOUBLE_TAP: SEND_STRING(SS_LSFT(SS_LGUI(SS_LALT(SS_TAP(X_F18))))); break;
  }
}

/*
 Fn + Pg Up key control
*/
void pg_up_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    // Show VS Code
    case SINGLE_TAP: SEND_STRING(SS_LCTL(SS_LSFT(SS_LGUI(SS_LALT(SS_TAP(X_F15)))))); break;
    // Show session
    case SINGLE_HOLD: SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_F15)))); break;
    // Show terminal
    case DOUBLE_TAP: SEND_STRING(SS_LCTL(SS_LSFT(SS_LGUI(SS_LALT(SS_TAP(X_T)))))); break;
    // Show global terminal
    case DOUBLE_HOLD: SEND_STRING(SS_LCTL(SS_LSFT(SS_LALT(SS_TAP(X_T))))); break;
    // Show Fork
    case TRIPLE_TAP: SEND_STRING(SS_LCTL(SS_LSFT(SS_LGUI(SS_TAP(X_F15))))); break;
  }
}

/*
 Fn + Pg Down key control
*/
void pg_down_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    // VS Code Go to definition
    // Show Slack
    case SINGLE_TAP: SEND_STRING(SS_LCTL(SS_LSFT(SS_LGUI(SS_LALT(SS_TAP(X_F16)))))); break;
    // Show Zoom
    case SINGLE_HOLD: SEND_STRING(SS_LCTL(SS_LGUI(SS_LALT(SS_TAP(X_F16))))); break;
    // Chat
    case DOUBLE_TAP: SEND_STRING(SS_LCTL(SS_LSFT(SS_LALT(SS_TAP(X_F19))))); break;
    // TODO: Discord
    // case DOUBLE_HOLD: SEND_STRING(SS_LCTL(SS_LSFT(SS_LALT(SS_TAP(X_...))))); break;
  }
}
