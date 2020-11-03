LEADER_EXTERNS();

void handle_leader_key(void) {
    LEADER_DICTIONARY() {
        leading = false;

        SEQ_ONE_KEY(KC_GESC) {
            // Put the keyboard into bootloading mode for flashing
            reset_keyboard();
        }
        SEQ_ONE_KEY(KC_M) {
            layer_move(MAC);  // Activate Mac OS Layer (only)
        }
        SEQ_TWO_KEYS(KC_M, KC_M) {
            layer_move(MAC);  // Activate Mac OS Layer (only)
            toggle_work_mode(true); // Toggle work mode - Close work applications if deactivating
        }
        // Double tap leader key
        SEQ_ONE_KEY(KC_LEAD) {
            // Deactivate all layers except the base layer
            layer_move(DEFAULT);
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
