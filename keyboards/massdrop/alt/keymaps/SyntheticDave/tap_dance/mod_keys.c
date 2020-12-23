// Custom modifier key behaviour
// Not currently in use, as I'm just using space cadet shift for round brackets, and not customising other modifiers at present.
// Mostly here for reference, and will probably be removed

/*
  Left Shift key control
*/
void lshft_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_modifier_dance(state);
  switch (xtap_state.state) {
    case HOLD: register_code(KC_LSFT); break;
    // (
    case SINGLE_TAP: SEND_STRING(SS_LSFT(SS_TAP(X_9))); break;
    // [
    case DOUBLE_TAP: SEND_STRING(SS_TAP(X_LBRC)); break;
  }
}

void lshft_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (xtap_state.state) {
    case HOLD: unregister_code(KC_LSFT); break;
  }

  xtap_state.state = 0;
}

/*
  Right Shift key control
*/
void rshft_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_modifier_dance(state);
  switch (xtap_state.state) {
    case HOLD: register_code(KC_RSFT); break;
    // (
    case SINGLE_TAP: SEND_STRING(SS_RSFT(SS_TAP(X_0))); break;
    // [
    case DOUBLE_TAP: SEND_STRING(SS_TAP(X_RBRC)); break;
  }
}

void rshft_reset (qk_tap_dance_state_t *state, void *user_data) {
  unregister_code(KC_RSFT);
  xtap_state.state = 0;
}

/*
  Left Control key control
*/
void lctrl_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_modifier_dance(state);
  switch (xtap_state.state) {
    case HOLD: register_code(KC_LCTRL); break;
    // {
    case SINGLE_TAP: SEND_STRING(SS_LSFT(SS_TAP(X_LBRC))); break;
  }
}

void lctrl_reset (qk_tap_dance_state_t *state, void *user_data) {
  unregister_code(KC_LCTRL);
  xtap_state.state = 0;
}

/*
  Left Alt Key control
*/
void lalt_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_modifier_dance(state);
  switch (xtap_state.state) {
    case HOLD: register_code(KC_LALT); break;
    // {
    case SINGLE_TAP: SEND_STRING(SS_TAP(X_LBRC)); break;
  }
}

void lalt_reset (qk_tap_dance_state_t *state, void *user_data) {
  unregister_code(KC_LALT);
  xtap_state.state = 0;
}

/*
  Right Alt Key control
*/
void ralt_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_modifier_dance(state);
  switch (xtap_state.state) {
    case HOLD: register_code(KC_RALT); break;
    // {
    case SINGLE_TAP: SEND_STRING(SS_TAP(X_RBRC)); break;
    case DOUBLE_TAP: SEND_STRING(SS_LSFT(SS_TAP(X_RBRC))); break;
  }
}

void ralt_reset (qk_tap_dance_state_t *state, void *user_data) {
  unregister_code(KC_RALT);
  xtap_state.state = 0;
}
