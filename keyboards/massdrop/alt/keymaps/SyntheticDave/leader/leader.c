LEADER_EXTERNS();

void handle_leader_key(void) {
    LEADER_DICTIONARY() {
        leading = false;

        SEQ_ONE_KEY(KC_GESC) {
            // Put the keyboard into bootloading mode for flashing
            reset_keyboard();
        }
        SEQ_ONE_KEY(KC_0) {
            // Deactivate all layers except the base layer
            layer_move(DEFAULT);
        }
        SEQ_ONE_KEY(KC_M) {
            layer_move(MAC);  // Activate Mac OS Layer (only)
        }
        SEQ_TWO_KEYS(KC_M, KC_M) {
            layer_move(MAC);  // Activate Mac OS Layer (only)
            toggle_work_mode(true);
        }
        // Double tap leader key
        SEQ_ONE_KEY(KC_LEAD) {
          // TODO: Consider sending backspace on double lead (has moved to the backspace key)
          // TODO: Only activate mac oneshot layer if we're on the mac base layer or the osl
          // layer_state_is(MAC)
          // Doesn't act like a oneshot layer here, so not particularly useful. I'm not sure what the call to active a layer as a oneshot is, as I can't find it in the docs.
          layer_invert(MAC_ONE_SHOTS);
        }
        SEQ_ONE_KEY(KC_X) {
            toggle_work_mode(false);
        }
        SEQ_ONE_KEY(KC_W) {
            layer_move(WIN);  // Activate Windows Layer (only)
        }
        SEQ_ONE_KEY(KC_G) {
            layer_move(WIN);       // Activate Windows Layer (only)
            layer_on(WIN_GAMING);  // Then activate the gaming layer
        }
        SEQ_ONE_KEY(KC_K) {
            layer_invert(KB_CONFIG);  // Toggle the keyboard config layer
        }
        leader_end();
    }
}
