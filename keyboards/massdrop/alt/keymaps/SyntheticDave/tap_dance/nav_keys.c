// Navigation key cluster
// Primarily used to launch/focus applications

/*
    Fn + Del key control
*/
void del_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        // Trello
        case SINGLE_TAP:
            SEND_STRING(SS_TAP(X_F13));
            break;
        // Jira
        case SINGLE_HOLD:
            SEND_STRING(SS_LGUI(SS_TAP(X_F13)));
            break;
        // Show Gmail
        case DOUBLE_TAP:
            SEND_STRING(SS_LSG(X_F13));
            break;
        // Show Outlook
        case DOUBLE_HOLD:
            SEND_STRING(SS_LCG(X_F13));
            break;
        // Calendar
        case TRIPLE_TAP:
            SEND_STRING(SS_LAG(X_F13));
            break;
        // Currently Unused
        case TRIPLE_HOLD:
            SEND_STRING(SS_LSCG(X_F13));
            break;
    }
}

/*
    Fn + Home key control
*/
void home_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        // Personal Browser
        case SINGLE_TAP:
            SEND_STRING(SS_LSAG(X_F13));
            break;
        // Work Browser
        case SINGLE_HOLD:
            SEND_STRING(SS_LCAG(X_F13));
            break;
        // Finder
        case DOUBLE_TAP:
            SEND_STRING(SS_HYPR(X_F13));
            break;
        // Currently Unused
        // IDEA: PF -> iTerm
        case DOUBLE_HOLD:
            SEND_STRING(SS_LSFT(SS_TAP(X_F13)));
            break;
        case TRIPLE_TAP:
            SEND_STRING(SS_LSC(X_F13));
            break;
        case TRIPLE_HOLD:
            SEND_STRING(SS_LSA(X_F13));
            break;
    }
}

/*
    Fn + Pg Up key control
*/
void pg_up_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        // Show VS Code
        case SINGLE_TAP:
            SEND_STRING(SS_TAP(X_F14));
            break;
        // Show session
        case SINGLE_HOLD:
            SEND_STRING(SS_LGUI(SS_TAP(X_F14)));
            break;
        // Show terminal
        case DOUBLE_TAP:
            SEND_STRING(SS_LSG(X_F14));
            break;
        // Show global terminal
        case DOUBLE_HOLD:
            SEND_STRING(SS_LCG(X_F14));
            break;
        // Show Fork
        case TRIPLE_TAP:
            SEND_STRING(SS_LAG(X_F14));
            break;
        // Currently Unused
        case TRIPLE_HOLD:
            SEND_STRING(SS_LSCG(X_F14));
            break;
    }
}

/*
    Fn + Pg Down key control
*/
void pg_down_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        // Chat
        case SINGLE_TAP:
            SEND_STRING(SS_LSAG(X_F14));
            break;
        // Show Slack
        case SINGLE_HOLD:
            SEND_STRING(SS_LCAG(X_F14));
            break;
        // Discord
        case DOUBLE_TAP:
            SEND_STRING(SS_HYPR(X_F14));
            break;
        // Show Zoom
        case DOUBLE_HOLD:
            SEND_STRING(SS_LSFT(SS_TAP(X_F14)));
            break;
        // Currently Unused
        case TRIPLE_TAP:
            SEND_STRING(SS_LSC(X_F14));
            break;
        case TRIPLE_HOLD:
            SEND_STRING(SS_LSA(X_F14));
            break;
    }
}
