#define TAPPING_TOGGLE 2

// tap dance quad function
typedef struct {
    bool is_press_action;
    int  state;
} tap;

enum {
    SINGLE_TAP        = 1,
    SINGLE_HOLD       = 2,
    DOUBLE_TAP        = 3,
    DOUBLE_HOLD       = 4,
    DOUBLE_SINGLE_TAP = 5,  // send two single taps
    TRIPLE_TAP        = 6,
    TRIPLE_HOLD       = 7,
    HOLD              = 8  // For modifier keys
};

// Tap dance enums
enum {
    T_DEL,
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
    T_DM1,
    T_DM2,
    T_FLB,
    T_FRB,
};

#define TD_DEL TD(T_DEL)
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
#define TD_DM1 TD(T_DM1)
#define TD_DM2 TD(T_DM2)
#define TD_FLB TD(T_FLB)
#define TD_FRB TD(T_FRB)

int cur_dance(qk_tap_dance_state_t *state);

void tap_dance_reset(qk_tap_dance_state_t *state, void *user_data);
void del_finished(qk_tap_dance_state_t *state, void *user_data);
void home_finished(qk_tap_dance_state_t *state, void *user_data);
void s3c_finished(qk_tap_dance_state_t *state, void *user_data);
void m_finished(qk_tap_dance_state_t *state, void *user_data);
void fn_c_finished(qk_tap_dance_state_t *state, void *user_data);
void fn_v_finished(qk_tap_dance_state_t *state, void *user_data);
void fn_f_finished(qk_tap_dance_state_t *state, void *user_data);
void slash_finished(qk_tap_dance_state_t *state, void *user_data);
void pg_down_finished(qk_tap_dance_state_t *state, void *user_data);
void pg_up_finished(qk_tap_dance_state_t *state, void *user_data);
void lctrl_finished(qk_tap_dance_state_t *state, void *user_data);
void lctrl_reset(qk_tap_dance_state_t *state, void *user_data);
void lshft_finished(qk_tap_dance_state_t *state, void *user_data);
void lshft_reset(qk_tap_dance_state_t *state, void *user_data);
void rshft_finished(qk_tap_dance_state_t *state, void *user_data);
void rshft_reset(qk_tap_dance_state_t *state, void *user_data);
void lalt_finished(qk_tap_dance_state_t *state, void *user_data);
void lalt_reset(qk_tap_dance_state_t *state, void *user_data);
void ralt_finished(qk_tap_dance_state_t *state, void *user_data);
void ralt_reset(qk_tap_dance_state_t *state, void *user_data);
void dm1_finished(qk_tap_dance_state_t *state, void *user_data);
void dm2_finished(qk_tap_dance_state_t *state, void *user_data);
void flb_finished(qk_tap_dance_state_t *state, void *user_data);
void frb_finished(qk_tap_dance_state_t *state, void *user_data);

qk_tap_dance_action_t tap_dance_actions[] = {
    [T_DEL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, del_finished, tap_dance_reset),
    [T_HME] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, home_finished, tap_dance_reset),
    [T_KCM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, m_finished, tap_dance_reset),
    [T_SLS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, slash_finished, tap_dance_reset),
    [T_PDN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, pg_down_finished, tap_dance_reset),
    [T_PUP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, pg_up_finished, tap_dance_reset),
    [T_LSH] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lshft_finished, lshft_reset),
    [T_RSH] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rshft_finished, rshft_reset),
    [T_LCL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lctrl_finished, lctrl_reset),
    [T_LAT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lalt_finished, lalt_reset),
    [T_RAT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ralt_finished, ralt_reset),
    [T_S3C] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, s3c_finished, tap_dance_reset),
    [T_FNC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, fn_c_finished, tap_dance_reset),
    [T_FNV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, fn_v_finished, tap_dance_reset),
    [T_FNF] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, fn_f_finished, tap_dance_reset),
    [T_DM1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dm1_finished, tap_dance_reset),
    [T_DM2] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dm2_finished, tap_dance_reset),
    //  REVISE: Deprecated behaviour, but docs are a little light on new implementation
    // Didn't have any luck with custom get_tapping_term
    [T_FLB] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, flb_finished, tap_dance_reset, TAPPING_TERM_QUICK),
    [T_FRB] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, frb_finished, tap_dance_reset, TAPPING_TERM_QUICK),
};

// Shared tapdance functions

int cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        // key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        /*
         * DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
         * action when hitting 'pp'. Suggested use case for this return value is when you want to send two
         * keystrokes of the key, and not the 'double tap' action/macro.
         */
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed)
            return TRIPLE_TAP;
        else
            return TRIPLE_HOLD;
    } else
        return 9;  // magic number. At some point this method will expand to work for more presses
}

// Slightly modified cur_dance for modifier keys
// They're often considered 'interrupted' by cur_dance, because we hold them then press another key in quick succession.
// In this case, we still want to consider them held
int cur_modifier_dance(qk_tap_dance_state_t *state) {
    if (state->pressed) {
        return HOLD;
    } else if (state->count == 1) {
        if (!state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    } else
        return cur_dance(state);
}

// initialize an instance of 'tap' for the 'x' tap dance.
static tap xtap_state = {.is_press_action = true, .state = 0};

void tap_dance_reset(qk_tap_dance_state_t *state, void *user_data) { xtap_state.state = 0; }
