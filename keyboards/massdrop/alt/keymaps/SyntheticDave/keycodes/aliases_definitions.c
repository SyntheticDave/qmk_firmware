// VS Code Shortcuts
#define CG_LEFT C(G(KC_LEFT))   // Ctrl + Meta + Left Arrow - Move Code Panel Left
#define CG_RGHT C(G(KC_RIGHT))  // Ctrl + Meta + Right Arrow - Move Code Panel Right
#define AS_LBRC A(S(KC_LBRC))   // Alt + Shift + [ - Move to Left Panel
#define AS_RBRC A(S(KC_RBRC))   // Alt + Shift + ] - Move to Right Panel
#define SA_QUOT S(A(KC_QUOT))   // Alt + Shift + ' - VS Code Terminal Focus
#define VS_FLIP HYPR(KC_SCOLON) // Rails - FlipFlop
#define VS_DEFN KC_F12
#define VS_NMCH C(A(KC_DOT))    // Next Match (+ Shift to select next match)
#define VS_PMCH C(A(KC_COMM))    // Previous Match (+ Shift to undo last cursor)

// CMD + ... shortcuts - Making up for the lack of a right CMD key
#define G_BSPC G(KC_BSPC)       // Meta + Backspace
#define G_ENTR G(KC_ENT)        // Meta + Enter

// Misc Keys
#define HPR_RGT HYPR(KC_RGHT)
#define HPR_LFT HYPR(KC_LEFT)
#define MAC_FN KC_F20 // Karabiner listens for F20 and turns it into an apple keyboard fn

// Keyboard Layer Control
#define WIN_S MO(WIN_SPECIAL)
#define MAC_S MO(MAC_SPECIAL)
#define MAC_OSL OSL(MAC_ONE_SHOTS)

// Keyboard toggles
#define SNK_TOG TG(SNAKE)       // Toggle snake case layer (space sends underscore)
#define RGB_PRV TG(KB_RGB_PRV)  // Preview RGB lighting while in config layer

// Music Control - Alfred Spotify Mini Player
#define SPOT_MP MEH(KC_S)       // Show Mini Player Control
#define SPOT_QU MEH(KC_DOT)     // Play Queue
#define SPOT_CT MEH(KC_SLASH)   // Current Track
#define SPOT_PPL MEH(KC_P)      // Private Playlists
#define SPOT_ATP MEH(KC_EQL)    // Add Current Track to Playlist
#define SPOT_RFP MEH(KC_MINS)   // Remove Current Track from Playlist
#define SPOT_PPS MEH(KC_ENT)    // Play/Pause
#define SPOT_NTK HYPR(KC_RBRC)   // Next Track
#define SPOT_LTK HYPR(KC_LBRC)   // Previous Track

//  Workflow Triggers
//      Misc
// TODO: Global, so consider making F Keys. Once app focus keys tidied up
#define DICT HYPR(KC_D)  // Selected word to dictionary
#define APP_HLP HYPR(KC_H)          // Show cheatsheet for focused application
//      Code
#define S3_OP MEH(KC_3)     // S3 Bucket
#define S3_ROP HYPR(KC_3)   // s3 Bucket with previous client
//      House Lights
#define DST_OFF LCAG(KC_LEFT)       // Dave Study Lights Off
#define DST_WRK LCAG(KC_UP)         // Dave Study Lights Work/Concentrate
#define DST_STD LCAG(KC_RIGHT)      // Dave Study Reading Lights
#define DST_RLX LCAG(KC_DOWN)       // Dave Study Lights Relax
