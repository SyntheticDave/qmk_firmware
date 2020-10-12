// ==================
//   Tap Dance Logic
//   From https://pastebin.com/TGXRxbvk
// ==================

/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */

// TODO: Define hyper, meh, etc. so we can stop writing SS_LCTL(SS_LSFT(SS_TAP everywhere

#define TAPPING_TOGGLE 2

//tap dance quad function
typedef struct {
  bool is_press_action;
  int state;
} tap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //send two single taps
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7,
  HOLD = 8
};

//Tap dance enums
enum {
    T_HME,
    T_KCM,
    T_SLS,
    T_PDN,
    T_PUP,
    T_LSH,
    T_RSH,
    T_LCL,
    T_LAT,
    T_RAT,
    T_S3C,
    T_FNC,
    T_FNV,
    T_FNF,
};

#define TD_HME TD(T_HME)
#define TD_KCM TD(T_KCM)
#define TD_SLS TD(T_SLS)
#define TD_PDN TD(T_PDN)
#define TD_PUP TD(T_PUP)
#define TD_LSH TD(T_LSH)
#define TD_RSH TD(T_RSH)
#define TD_LCL TD(T_LCL)
#define TD_LAT TD(T_LAT)
#define TD_RAT TD(T_RAT)
#define TD_S3C TD(T_S3C)
#define TD_FNC TD(T_FNC)
#define TD_FNV TD(T_FNV)
#define TD_FNF TD(T_FNF)

int cur_dance (qk_tap_dance_state_t *state);

void tap_dance_reset (qk_tap_dance_state_t *state, void *user_data);
void home_finished (qk_tap_dance_state_t *state, void *user_data);
void s3c_finished (qk_tap_dance_state_t *state, void *user_data);
void m_finished (qk_tap_dance_state_t *state, void *user_data);
void fn_c_finished (qk_tap_dance_state_t *state, void *user_data);
void fn_v_finished (qk_tap_dance_state_t *state, void *user_data);
void fn_f_finished (qk_tap_dance_state_t *state, void *user_data);
void slash_finished (qk_tap_dance_state_t *state, void *user_data);
void pg_down_finished (qk_tap_dance_state_t *state, void *user_data);
void pg_up_finished (qk_tap_dance_state_t *state, void *user_data);
void lctrl_finished (qk_tap_dance_state_t *state, void *user_data);
void lctrl_reset (qk_tap_dance_state_t *state, void *user_data);
void lalt_finished (qk_tap_dance_state_t *state, void *user_data);
void lalt_finished (qk_tap_dance_state_t *state, void *user_data);
void ralt_reset (qk_tap_dance_state_t *state, void *user_data);
void ralt_reset (qk_tap_dance_state_t *state, void *user_data);

int cur_dance (qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)  return SINGLE_TAP;
    //key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    /*
     * DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
     * action when hitting 'pp'. Suggested use case for this return value is when you want to send two
     * keystrokes of the key, and not the 'double tap' action/macro.
    */
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  //Assumes no one is trying to type the same letter three times (at least not quickly).
  //If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
  //an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
  if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return 9; //magic number. At some point this method will expand to work for more presses
}

// Slightly modified behaviour for modifier keys
// They're often considered 'interrupted', as we hold them, then press another key in quick succession.
// In this case, we still want to consider them held
int cur_modifier_dance (qk_tap_dance_state_t *state) {
  if(state->pressed) {
      return HOLD;
  }
  else if (state->count == 1) {
    if (!state->pressed)  return SINGLE_TAP;
    else return SINGLE_HOLD;
  }
  else if (state->count == 2) {
    if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  else return cur_dance(state);
}

//instanalize an instance of 'tap' for the 'x' tap dance.
static tap xtap_state = {
  .is_press_action = true,
  .state = 0
};

void tap_dance_reset (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = 0;
}

/*
 Fn + Home key control
*/
void home_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    // Finder on single tap
    case SINGLE_TAP: SEND_STRING(SS_LCTL(SS_LSFT(SS_LGUI(SS_LALT(SS_TAP(X_F14)))))); break;
    // Browser on double tap
    case DOUBLE_TAP: SEND_STRING(SS_LCTL(SS_LSFT(SS_LGUI(SS_LALT(SS_TAP(X_F18)))))); break;
  }
}

/*
 Fn + M key control
*/
void m_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    // Spotify Mini Player on single tap
    case SINGLE_TAP: SEND_STRING(SS_LCTL(SS_LSFT(SS_LALT(SS_TAP(X_S))))); break;
    // Spotify on double tap
    case DOUBLE_TAP: SEND_STRING(SS_LCTL(SS_LSFT(SS_LGUI(SS_LALT(SS_TAP(X_M)))))); break;
  }
}

/*
 Fn + / key control
*/
void slash_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    // VS Code Go to definition
    case SINGLE_TAP: SEND_STRING(SS_TAP(X_F12)); break;
    // VS Code Show References
    case DOUBLE_TAP: SEND_STRING(SS_LSFT(SS_TAP(X_F12))); break;
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
    case DOUBLE_TAP: SEND_STRING(SS_LCTL(SS_LSFT(SS_LGUI(SS_LALT(SS_TAP(X_3)))))); break;
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
    // Meh V - Trigger text massager on selected text
    case SINGLE_TAP: SEND_STRING(SS_LCTL(SS_LSFT(SS_LALT(SS_TAP(X_V))))); break;
    // Ctrl + Alt + V - Search Snippets Lab
    case DOUBLE_TAP: SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_V)))); break;
    // Hyper V - Trigger enhanced snippets on selected text
    case TRIPLE_TAP: SEND_STRING(SS_LCTL(SS_LSFT(SS_LGUI(SS_LALT(SS_TAP(X_V)))))); break;
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
 Fn + Pg Down key control
*/
void pg_down_finished (qk_tap_dance_state_t *state, void *user_data) {
  xtap_state.state = cur_dance(state);
  switch (xtap_state.state) {
    // VS Code Go to definition
    // Show Slack
    case SINGLE_TAP: SEND_STRING(SS_LCTL(SS_LSFT(SS_LGUI(SS_LALT(SS_TAP(X_F16)))))); break;
    // Show Email
    case DOUBLE_TAP: SEND_STRING(SS_LCTL(SS_LSFT(SS_LGUI(SS_LALT(SS_TAP(X_F19)))))); break;
    // Chat
    case TRIPLE_TAP: SEND_STRING(SS_LCTL(SS_LSFT(SS_LALT(SS_TAP(X_F19))))); break;
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
    // Show terminal
    case DOUBLE_TAP: SEND_STRING(SS_LCTL(SS_LSFT(SS_LGUI(SS_LALT(SS_TAP(X_T)))))); break;
    // Show global terminal
    case DOUBLE_HOLD: SEND_STRING(SS_LCTL(SS_LSFT(SS_LALT(SS_TAP(X_T))))); break;
    // Show Fork
    case TRIPLE_TAP: SEND_STRING(SS_LCTL(SS_LSFT(SS_LGUI(SS_TAP(X_F15))))); break;
  }
}

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

qk_tap_dance_action_t tap_dance_actions[] = {
  [T_HME] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,home_finished, tap_dance_reset),
  [T_KCM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,m_finished, tap_dance_reset),
  [T_SLS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,slash_finished, tap_dance_reset),
  [T_PDN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,pg_down_finished, tap_dance_reset),
  [T_PUP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,pg_up_finished, tap_dance_reset),
  [T_LSH] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,lshft_finished, lshft_reset),
  [T_RSH] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,rshft_finished, rshft_reset),
  [T_LCL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,lctrl_finished, lctrl_reset),
  [T_LAT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,lalt_finished, lalt_reset),
  [T_RAT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,ralt_finished, ralt_reset),
  [T_S3C] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,s3c_finished, tap_dance_reset),
  [T_FNC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,fn_c_finished, tap_dance_reset),
  [T_FNV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,fn_v_finished, tap_dance_reset),
  [T_FNF] = ACTION_TAP_DANCE_FN_ADVANCED(NULL,fn_f_finished, tap_dance_reset),
};
