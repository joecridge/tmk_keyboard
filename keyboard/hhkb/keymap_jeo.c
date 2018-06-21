/*
 * Jeo layout for HHKB.
 *
 * ,---.
 * |   | = Falls through to layer below.
 * `---'
 * ,---.
 * |  A| = Prints `A'.
 * `---'
 * ,---.
 * | 1 | = Keypad 1.
 * `---'
 * ,---.
 * |Act| = Non-printing action.
 * `---'
 * ,---.
 * |XXX| = No action at all.
 * `---'
 */

#include "keymap_common.h"

#ifdef KEYMAP_SECTION_ENABLE
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
#endif

    /* Layer 0: Default Layer
     * ,-----------------------------------------------------------.
     * |Num|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|XXX|VoD|Mut|VoU|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  G|  M|  L|  W|  Y|  F|  U|  B|  –|BSp|Esc|Save |
     * |-----------------------------------------------------------|
     * |Symbol|  D|  S|  T|  N|  R|  I|  A|  E|  O|  H|Sym|Enter   |
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  J|  K|  P|  ,|  .|  •|Shift |Num|
     * `-----------------------------------------------------------'
     *       |Ctl|Gui  |         Space         |Alt  |Ctl|
     *       `-------------------------------------------'
     */
    KEYMAP(FN1, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   NO,  VOLD,MUTE,VOLU,  \
           TAB, Q,   G,   M,   L,   W,   Y,   F,   U,   B,   FN3, BSPC,ESC, FN2,        \
           FN0, D,   S,   T,   N,   R,   I,   A,   E,   O,   H,   FN0, ENT,             \
           LSFT,Z,   X,   C,   V,   J,   K,   P,   COMM,DOT, FN4, RSFT,FN1,             \
                LCTL,LGUI,          SPC,                RALT,RCTL),

    /* Layer 1: Symbol layer
     * ,-----------------------------------------------------------.
     * |   |XXX|  @|  £|XXX|XXX|XXX|  “|  ”|  ‘|  ’|XXX|Pre|Pau|Nex|
     * |-----------------------------------------------------------|
     * |     |  …|  _|  [|  ]|  ^|  !|  <|  >|  =|  &|   |   |     |
     * |-----------------------------------------------------------|
     * |      |  \|  /|  {|  }|  *|  ?|  (|  )|  -|  :|   |        |
     * |-----------------------------------------------------------|
     * |        |  #|  $|  ||  ~|  `|  +|  %|  "|  '|  ;|      |   |
     * `-----------------------------------------------------------'
     *       |   |     |                       |     |   |
     *       `-------------------------------------------'
     */
    KEYMAP(TRNS,NO,  FN5, FN6, NO,  NO,  NO,  FN7, FN8, FN9, FN10,NO,  MPRV,MPLY,MNXT,  \
           TRNS,FN11,FN12,LBRC,RBRC,FN13,FN14,FN15,FN16,EQL, FN17,TRNS,TRNS,TRNS,       \
           TRNS,BSLS,SLSH,FN18,FN19,FN20,FN21,FN22,FN23,MINS,FN24,TRNS,TRNS,            \
           TRNS,FN25,FN26,FN27,FN28,GRV, FN29,FN30,FN31,QUOT,SCLN,TRNS,TRNS,            \
                TRNS,TRNS,          TRNS,               TRNS,TRNS),

    /* Layer 2: Numpad layer
     * ,-----------------------------------------------------------.
     * |   | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|F13|F14|
     * |-----------------------------------------------------------|
     * |     |PgU|BSp|Up |Del|PgD|Tab| 7 | 8 | 9 | - |   |   |     |
     * |-----------------------------------------------------------|
     * |      |Hom|Lef|Dow|Rig|End| * | 4 | 5 | 6 | + |   | Enter  |
     * |-----------------------------------------------------------|
     * |        |F15|F16|F17|F18|F19| / | 1 | 2 | 3 | . |      |   |
     * `-----------------------------------------------------------'
     *       |   |     |                     0 |     |   |
     *       `-------------------------------------------'
     *
     * NOTE: macOS will (by default) assign legacy shortcuts to F11 (Exposé),
     *   F12 (Dashboard), F14/F15 (decrease/increase brightness).  You can
     *   disable all of these from System Preferences: the first two under
     *   Mission Control, and the last two in Keyboard -> Shortcuts -> Display.
     */
    KEYMAP(TRNS,F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, F13, F14,   \
           TRNS,PGUP,BSPC,UP,  DEL, PGDN,TAB, P7,  P8,  P9,  PMNS,TRNS,TRNS,TRNS,       \
           TRNS,HOME,LEFT,DOWN,RGHT,END, PAST,P4,  P5,  P6,  PPLS,TRNS,PENT,            \
           TRNS,F15, F16, F17, F18, F19, PSLS,P1,  P2,  P3,  PDOT,TRNS,TRNS,            \
                TRNS,TRNS,          P0,                 TRNS,TRNS),

};


/*
 * Fn action definitions
 */

enum jeo_layer_id {
  JEO_DEFAULT_LAYER,
  JEO_SYMBOL_LAYER,
  JEO_NUMPAD_LAYER,
};

#ifdef KEYMAP_SECTION_ENABLE
const action_t fn_actions[] __attribute__ ((section (".keymap.fn_actions"))) = {
#else
const action_t fn_actions[] PROGMEM = {
#endif

    /*
     * Synthetic modifiers
     */

    [0]  = ACTION_LAYER_MOMENTARY(JEO_SYMBOL_LAYER), /* Symbol */
    [1]  = ACTION_LAYER_MOMENTARY(JEO_NUMPAD_LAYER), /* Numpad */

    /*
     * Custom actions
     */

    [2]  = ACTION_MODS_KEY(MOD_LGUI, KC_S), /* Save */

    /*
     * Shortcuts for various symbols; some of these are macOS (UK) specific.
     */

    /* Default layer */
    [3]  = ACTION_MODS_KEY(MOD_LALT, KC_MINUS), /* – */
    [4]  = ACTION_MODS_KEY(MOD_LALT, KC_8),     /* • */

    /* Symbol layer: number row */
    [5]  = ACTION_MODS_KEY(MOD_LSFT, KC_2),                   /* @ */
    [6]  = ACTION_MODS_KEY(MOD_LSFT, KC_3),                   /* £ */
    [7]  = ACTION_MODS_KEY(MOD_LALT, KC_LBRACKET),            /* “ */
    [8]  = ACTION_MODS_KEY(MOD_LALT | MOD_LSFT, KC_LBRACKET), /* ” */
    [9]  = ACTION_MODS_KEY(MOD_LALT, KC_RBRACKET),            /* ‘ */
    [10] = ACTION_MODS_KEY(MOD_LALT | MOD_LSFT, KC_RBRACKET), /* ’ */

    /* Symbol layer: upper row */
    [11] = ACTION_MODS_KEY(MOD_LALT, KC_SCOLON), /* … */
    [12] = ACTION_MODS_KEY(MOD_LSFT, KC_MINUS),  /* _ */
    [13] = ACTION_MODS_KEY(MOD_LSFT, KC_6),      /* ^ */
    [14] = ACTION_MODS_KEY(MOD_LSFT, KC_1),      /* ! */
    [15] = ACTION_MODS_KEY(MOD_LSFT, KC_COMMA),  /* < */
    [16] = ACTION_MODS_KEY(MOD_LSFT, KC_DOT),    /* > */
    [17] = ACTION_MODS_KEY(MOD_LSFT, KC_7),      /* & */

    /* Symbol layer: home row */
    [18] = ACTION_MODS_KEY(MOD_LSFT, KC_LBRACKET), /* { */
    [19] = ACTION_MODS_KEY(MOD_LSFT, KC_RBRACKET), /* } */
    [20] = ACTION_MODS_KEY(MOD_LSFT, KC_8),        /* * */
    [21] = ACTION_MODS_KEY(MOD_LSFT, KC_SLASH),    /* ? */
    [22] = ACTION_MODS_KEY(MOD_LSFT, KC_9),        /* ( */
    [23] = ACTION_MODS_KEY(MOD_LSFT, KC_0),        /* ) */
    [24] = ACTION_MODS_KEY(MOD_LSFT, KC_SCOLON),   /* : */

    /* Symbol layer: lower row */
    [25] = ACTION_MODS_KEY(MOD_LALT, KC_3),      /* # */
    [26] = ACTION_MODS_KEY(MOD_LSFT, KC_4),      /* $ */
    [27] = ACTION_MODS_KEY(MOD_LSFT, KC_BSLASH), /* | */
    [28] = ACTION_MODS_KEY(MOD_LSFT, KC_GRAVE),  /* ~ */
    [29] = ACTION_MODS_KEY(MOD_LSFT, KC_EQUAL),  /* + */
    [30] = ACTION_MODS_KEY(MOD_LSFT, KC_5),      /* % */
    [31] = ACTION_MODS_KEY(MOD_LSFT, KC_QUOTE),  /* " */

};
