// Dynamic Macro record start/stop
// These are recorded on the base layer on PgUp and PgDn for Macro 1 and 2 respectively, then triggered on OS specific layers

// Dynamic Macro Recording/Playing control
void dm_finished(qk_tap_dance_state_t *state, void *user_data, uint16_t rec_key, uint16_t play_key, bool *rec_flag) {
  xtap_state.state = cur_dance(state);

  keyrecord_t kr;
  // fudging pressed state, regardless of current state, to make dynamic macros trigger appropriately
  kr.event.pressed = false;
  uint16_t action = DYN_REC_STOP;
  bool valid = false;

  switch (xtap_state.state) {
    // Finish macro recording
    case SINGLE_TAP:
        action = DYN_REC_STOP;
        kr.event.pressed = true;
        *rec_flag = false;
        valid = true;
        break;
    // Start macro recording
    case SINGLE_HOLD:
        action = rec_key;
        valid = true;
        *rec_flag = true;
        break;
    // Play macro - Only here for testing. Use DM_PLY1/2 to play w/o tap dance delay
    case DOUBLE_TAP:
        action = play_key;
        valid = true;
        break;
  }

  //  Call the regular macro processing with our constructed event and key code
  if(valid) {
    process_dynamic_macro( action, &kr);
  }
}

/*
    Pg Up key control (Dynamic Macro 1)
*/
void dm1_finished (qk_tap_dance_state_t *state, void *user_data) {
    dm_finished(state, user_data, DYN_REC_START1, DYN_MACRO_PLAY1, &recording_macro_1);
}

/*
    Pg Dn key control (Dynamic Macro 2)
*/
void dm2_finished (qk_tap_dance_state_t *state, void *user_data) {
    dm_finished(state, user_data, DYN_REC_START2, DYN_MACRO_PLAY2, &recording_macro_2);
}
