// LED Sets
// TODO: Surely there's a better way to define these
uint8_t all_leds[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101};
uint8_t key_leds[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66};
uint8_t key_leds_no_top_row[] = {15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66};
uint8_t base_leds[] = {67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103,104};
uint8_t base_leds_front[] = {67,68,69,70,71,72,73,74,75,76,77,78,79,80,81};
uint8_t base_leds_right[] = {82,83,84,85};
uint8_t base_leds_back[] = {86,87,88,89,90,91,92,93,94,95,96,97,98,99,100};
uint8_t base_leds_left[] = {101,102,103,104};
uint8_t arrow_keys[] = {56,64,65,66};

// Sets a list of keys to the same color
void rgb_matrix_set_collection_color(uint8_t keys[], int keyCount, uint8_t red, uint8_t green, uint8_t blue) {
    for (int i = 0; i < keyCount; i++) {
        rgb_matrix_set_color(keys[i], red, green, blue);
    }
};

void key_leds_off(bool top_row) {
    if(top_row) {
        rgb_matrix_set_collection_color(key_leds_no_top_row, sizeof(key_leds_no_top_row) / sizeof(uint8_t), RGB_OFF);
    } else {
        rgb_matrix_set_collection_color(key_leds, sizeof(key_leds) / sizeof(uint8_t), RGB_OFF);
    }
}

// Highlight macro key in red if currently recording
void show_macro_recording_keys(void) {
    if(recording_macro_1) {
        rgb_matrix_set_color(43, RGB_RED);
        rgb_matrix_set_color(1, RGB_RED);
    } else if (recording_macro_2)
    {
        rgb_matrix_set_color(57, RGB_RED);
        rgb_matrix_set_color(2, RGB_RED);
    }
}

void show_mac_base_leds(void) {
    rgb_matrix_set_collection_color(base_leds_back, sizeof(base_leds_back) / sizeof(uint8_t), RGB_MAGENTA);
}

void show_mac_gpm_leds(void) {
    uint8_t lit_keys[]   = {45, 54, 56, 61, 64, 65, 66};
    rgb_matrix_set_collection_color(lit_keys, sizeof(lit_keys) / sizeof(uint8_t), RGB_GPM_ORANGE);
}

void show_mac_spotify_leds(void) {
    uint8_t lit_keys[]   = {11, 12, 25, 42, 53, 54, 64, 66};
    rgb_matrix_set_collection_color(lit_keys, sizeof(lit_keys) / sizeof(uint8_t), RGB_GREEN);
}

void show_mac_vs_code_leds(void) {
    uint8_t lit_keys[] = { 26, 27, 34, 40, 41, 47, 48, 52, 53, 54};
    rgb_matrix_set_collection_color(lit_keys, sizeof(lit_keys) / sizeof(uint8_t), RGB_BLUE);
}

void show_arrow_leds(uint8_t red, uint8_t green, uint8_t blue) {
    uint8_t lit_keys[] = {56,64,65,66};
    rgb_matrix_set_collection_color(lit_keys, sizeof(lit_keys) / sizeof(uint8_t), red, green, blue);
}

void show_snake_leds(void) {
    rgb_matrix_set_color(61, RGB_TURQUOISE);  // Space Key
}

void show_mac_special_leds(void) {
    key_leds_off(true);
    show_mac_vs_code_leds();
    show_arrow_leds(RGB_WHITE);

    // Exit keys
    rgb_matrix_set_color(18, RGB_ORANGE);
    rgb_matrix_set_color(17, RGB_RED);

    // Backspace (sends CMD+Backspace, often used for deletion)
    rgb_matrix_set_color(13, RGB_RED);

    // Enter (sends CMD+Enter)
    rgb_matrix_set_color(42, RGB_WHITE);

    // RAlt - Sends F20 - Karabiner catches this and turns it into Mac OS fn key
    rgb_matrix_set_color(62, RGB_WHITE);

    // Capslock
    rgb_matrix_set_color(30, RGB_YELLOW);

    // Snake Case lock - l-shift
    rgb_matrix_set_color(44, RGB_YELLOW);

    // One shot layer trigger space
    rgb_matrix_set_color(61, RGB_GREEN);

    // Spotify
    rgb_matrix_set_color(51, RGB_GREEN);

    // Dictionary
    rgb_matrix_set_color(33, RGB_GOLD);

    // Neptune workflow triggers
    uint8_t trigger_keys[]   = {32};
    rgb_matrix_set_collection_color(trigger_keys, sizeof(trigger_keys) / sizeof(uint8_t), RGB_BLUE);

    // Show Trello - Del
    rgb_matrix_set_color(14, RGB_BLUE);
    // Show Finder/Browser - Home
    rgb_matrix_set_color(29, RGB_TEAL);
    // Show VS Code/Terminal/Fork - PgUp
    rgb_matrix_set_color(43, RGB_PURPLE);
    // Show Slack/Mail/Chat - PgDn
    rgb_matrix_set_color(57, RGB_MAGENTA);
}

void show_mac_meta_leds(void) {
    rgb_matrix_set_color(16, RGB_RED);  // Q Key
    rgb_matrix_set_color(17, RGB_YELLOW);  // W Key
}

void show_mac_one_shot_leds(void) {
    key_leds_off(false);
    show_mac_spotify_leds();

    // Move Spaces
    uint8_t trigger_keys[]   = {43, 57};
    rgb_matrix_set_collection_color(trigger_keys, sizeof(trigger_keys) / sizeof(uint8_t), RGB_WHITE);
}

void show_mac_window_snap_keys(void) {
    uint8_t lit_keys[]   = {54, 53, 52, 41, 40, 28, 27, 26};

    // HACK: Using this to show snap keys as different colour.
    // Would be much better if we could just read the current hue/sat
    if(work_mode) {
        rgb_matrix_set_collection_color(lit_keys, sizeof(lit_keys) / sizeof(uint8_t), RGB_PURPLE);
    } else {
        rgb_matrix_set_collection_color(lit_keys, sizeof(lit_keys) / sizeof(uint8_t), RGB_WHITE);
    }
}

void show_win_base_leds(void) {
    rgb_matrix_set_collection_color(base_leds_back, sizeof(base_leds_back) / sizeof(uint8_t), RGB_BLUE);
}

void show_win_gaming_leds(void) {
    // Light up WASD and disable windows button light
    uint8_t lit_keys[]   = {17, 31, 32, 33};
    uint8_t unlit_keys[] = {60};

    rgb_matrix_set_collection_color(lit_keys, sizeof(lit_keys) / sizeof(uint8_t), RGB_RED);
    rgb_matrix_set_collection_color(unlit_keys, sizeof(unlit_keys) / sizeof(uint8_t), 0, 0, 0);
    show_arrow_leds(RGB_RED);
}

void show_layer_indicator(int layer) {
    // Layer indicator to help me keep my bearings
    // Assumes no more than 9 custom layers, which is true for now
    if (layer == 0) {
        // Zero key is at index 10 on the board
        rgb_matrix_set_color(10, RGB_BLUE);
    } else {
        rgb_matrix_set_color(layer, RGB_WHITE);
    }
}

void show_win_media_control_leds(void) {
    uint8_t lit_keys[]   = {53, 52, 41, 40};
    rgb_matrix_set_collection_color(lit_keys, sizeof(lit_keys) / sizeof(uint8_t), RGB_GPM_ORANGE);
}

void show_win_special_leds(void) {
    key_leds_off(true);
    rgb_matrix_set_color(16, RGB_RED);  // Q Key Shutdown
    rgb_matrix_set_color(17, RGB_YELLOW);  // W Key - Sleep
    show_win_media_control_leds();
    show_arrow_leds(RGB_WHITE);
    // Capslock
    rgb_matrix_set_color(30, RGB_YELLOW);
}

void show_kb_config_keys(void) {
    key_leds_off(false);

    // HUE
    rgb_matrix_set_color(16, RGB_BLUE);             // hue up
    rgb_matrix_set_color(31, RGB_ORANGE);           // hue down

    // SAT
    rgb_matrix_set_color(17, RGB_RED);              // sat up
    rgb_matrix_set_color(32, 0xFF, 0x9B, 0x9B);     // sat down

    // WORK MODE - Sets keys white and toggles a boolean so we know the current state
    rgb_matrix_set_color(46, RGB_WHITE);

    // VALUE
    rgb_matrix_set_color(18, RGB_MAGENTA);          // value up
    rgb_matrix_set_color(33, 0x32,0x00,0x32);       // value down
    rgb_matrix_set_color(47, 0x32,0x32,0x32);       // RGB Toggle

    //RGB MODE
    rgb_matrix_set_color(19, RGB_TEAL);             // cycle left
    rgb_matrix_set_color(34, RGB_TEAL);             // cycle right

    //RGB SPEED
    rgb_matrix_set_color(20, RGB_YELLOW);           // slower
    rgb_matrix_set_color(35, RGB_YELLOW);           // faster

    // Light K, as it's the exit key for this layer
    rgb_matrix_set_color(38, 0x5A,0x5A,0x5A);

    // Dave Study Lighting
    uint8_t study_keys[] = {56,64,65,66};
    rgb_matrix_set_collection_color(study_keys, sizeof(study_keys) / sizeof(uint8_t), RGB_GOLD);
}

void show_custom_lighting(void) {
    if(work_mode) {
        rgb_matrix_set_color_all(RGB_WHITE);
    }

    // Find the current layer
    uint8_t layer = biton32(layer_state);

    // Set lighting based on the current layer
    // TODO: Fix snake case lighting - Completely breaks other lighting atm, as it's the last active layer. Could consider using a modifier, rather than an entire layer to implement this. Would be much easier on the lighting side, at least
    switch (layer) {
        case MAC_ONE_SHOTS:
          show_mac_one_shot_leds();
          break;
        case MAC_SPECIAL:
            show_mac_special_leds();
        case MAC:
            show_mac_base_leds();
            break;
        case WIN_SPECIAL:
            show_win_special_leds();
        case WIN:
            show_win_base_leds();
            break;
        case WIN_GAMING:
            show_win_base_leds();
            show_win_gaming_leds();
            break;
        case KB_CONFIG:
            show_kb_config_keys();
            break;
    }

    // Set lighting based on individually held key
    if (r_alt_down && layer == MAC) {
        show_mac_window_snap_keys();
    }

    if (meta_down && layer == MAC) {
        show_mac_meta_leds();
    }

    show_macro_recording_keys();
    show_layer_indicator(layer);
}

void rgb_matrix_indicators_user(void)
{
    show_custom_lighting();

	uint8_t this_led = host_keyboard_leds();

    // FIXME: I seem to have broken the Capslock lighting
    if (this_led & (1 << USB_LED_CAPS_LOCK)) {
        rgb_matrix_set_collection_color(base_leds_left, sizeof(base_leds_left) / sizeof(uint8_t), RGB_RED);
    }
}
