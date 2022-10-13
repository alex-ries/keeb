// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _GAME,
    _NAV,
    _MEDIA,
    _SYMR,
    _NUM,
    _SYML,
    _FUNC
};

/*
 * Base Mod Taps
 */
#define M_AW MT(KC_A,KC_LGUI)
#define M_RA MT(KC_R,KC_LALT)
#define M_SC MT(KC_S,KC_LCTRL)
#define M_TC MT(KC_T,KC_LSFT)
#define M_XA MT(KC_X,KC_RALT)
#define M_OW MT(KC_O,KC_LGUI)
#define M_IA MT(KC_I,KC_LALT)
#define M_EC MT(KC_E,KC_LCTRL)
#define M_NC MT(KC_N,KC_LSFT)
#define M_DOTA MT(KC_DOT,KC_RALT)
#define LT_ESC LT(KC_ESC, _MEDIA)
#define LT_TAB LT(KC_TAB, _SYMR)
#define LT_SPC LT(KC_SPC, _NAV)
#define LT_DEL LT(KC_DEL, _FUNC)
#define LT_BSPC LT(KC_BSPC, _SYML)
#define LT_ENT LT(KC_ENT, _NUM)

/*
 * Base Layer Dance
 */
#define TD_GAME ACTION_TAP_DANCE_LAYER_MOVE(KC_MPLY, _GAME)
#define TD_BASE ACTION_TAP_DANCE_LAYER_MOVE(KC_MPLY, _BASE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 /* BASE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   '  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Bspc |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |      |
 * |------+------+------+------+------+------| Mute  |    | Play  |------+------+------+------+------+------|
 * | DEL  |   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | ESC  | TAB  | /Space  /       \Enter \  | Bspc |  DEL |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_BASE] = LAYOUT(
  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,        KC_NO,                      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
  KC_ESC,   KC_Q,     KC_W,     KC_F,     KC_P,         KC_B,                       KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN,    KC_NO,
  KC_BSPC,  M_AW,     M_RA,     M_SC,     M_TC,         KC_G,                       KC_M,       M_NC,       M_EC,       M_IA,       M_OW,       KC_NO,
  KC_DEL,   KC_Z,     M_XA,     KC_C,     KC_D,         KC_V,   KC_MUTE,  TD_GAME,  KC_K,       KC_H,       KC_COMM,    M_DOTA,     KC_SLSH,    KC_NO,
                      KC_NO,    LT_ESC,   LT_TAB,       LT_SPC,                     LT_ENT,     LT_BSPC,    LT_DEL,     KC_NO
),
/* GAME
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Lshft|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * | Lctrl|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |SPACE | /  ALT  /       \Enter \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_GAME] = LAYOUT(
  KC_ESC,     KC_1,     KC_2,       KC_3,     KC_4,     KC_5,                         KC_6,     KC_7,       KC_8,       KC_9,       KC_0,       KC_F1,
  KC_TAB,     KC_Q,     KC_W,       KC_E,     KC_R,     KC_T,                         KC_Y,     KC_U,       KC_I,       KC_O,       KC_P,       KC_F2,
  KC_LSFT,    KC_A,     KC_S,       KC_D,     KC_F,     KC_G,                         KC_H,     KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_F3,
  KC_LCTL,    KC_Z,     KC_X,       KC_C,     KC_V,     KC_B,   KC_TRNS,  TD_BASE,    KC_N,     KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_F4,
                        KC_NO,      KC_NO,    KC_SPC,   KC_LALT,                      KC_ENT,   KC_NO,      KC_NO,      KC_NO
),
/* NAV
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |RESET |      |      |      |      |                    | REDO | UNDO | CUT  | COPY | PASTE|      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | LGUI | LALT | LCTRL| LSHFT|      |-------.    ,-------| CAPS | LEFT | DOWN |  UP  |RIGHT |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------| INS  | HOME | PGUP | PGDN | END  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \Enter \  | Bspc | DEL  |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_NAV] = LAYOUT(
  KC_NO,    KC_NO,      KC_NO,      KC_NO,    KC_NO,    KC_NO,                      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
  KC_NO,    QK_RBT,     KC_NO,      KC_NO,    KC_NO,    KC_NO,                      KC_AGIN,    KC_UNDO,    KC_CUT,     KC_COPY,    KC_PSTE,    KC_NO,
  KC_NO,    KC_LGUI,    KC_LALT,    KC_LCTL,  KC_LSFT,  KC_NO,                      KC_CAPS,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    KC_NO,
  KC_NO,    KC_NO,      KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,    KC_INS,     KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     KC_NO,
                        KC_NO,      KC_NO,    KC_NO,    KC_NO,                      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
),
/* MEDIA
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |RESET |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | LGUI | LALT | LCTRL| LSHFT|      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_MEDIA] = LAYOUT(
  KC_NO,    KC_NO,      KC_NO,      KC_NO,    KC_NO,    KC_NO,                      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
  KC_NO,    QK_RBT,     KC_NO,      KC_NO,    KC_NO,    KC_NO,                      RGB_MOD,    RGB_HUI,    RGB_SAI,    RGB_VAI,    RGB_TOG,    KC_NO,
  KC_NO,    KC_LGUI,    KC_LALT,    KC_LCTL,  KC_LSFT,  KC_NO,                      KC_NO,      KC_MPRV,    KC_VOLD,    KC_VOLU,    KC_MNXT,    KC_NO,
  KC_NO,    KC_NO,      KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                        KC_NO,      KC_NO,    KC_NO,    KC_NO,                      KC_TRNS,    KC_MSTP,    KC_MPLY,    KC_MUTE
),
/* Symbols Right
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |RESET |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | LGUI | LALT | LCTRL| LSHFT|      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_SYMR] = LAYOUT(
  KC_NO,    KC_NO,      KC_NO,      KC_NO,    KC_NO,    KC_NO,                      KC_NO,      KC_NO,      KC_NO,      KC_NO,    KC_NO,      KC_NO,
  KC_NO,    QK_RBT,     KC_NO,      KC_NO,    KC_NO,    KC_NO,                      KC_6,       KC_7,       KC_8,       KC_9,     KC_0,       KC_NO,
  KC_NO,    KC_LGUI,    KC_LALT,    KC_LCTL,  KC_LSFT,  KC_NO,                      KC_NO,      KC_LEFT,    KC_DOWN,    KC_UP,    KC_RGHT,    KC_NO,
  KC_NO,    KC_NO,      KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,    KC_PLUS,    KC_MINS,    KC_EQL,     KC_LBRC,  KC_RBRC,    KC_BSLS,
                        KC_NO,      KC_NO,    KC_NO,    KC_NO,                      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
  ),
/* Numpad
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_NUM] = LAYOUT(
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO
  ),
/* Symbol Left
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_SYML] = LAYOUT(
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO
  ),
/* Functions
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_FUNC] = LAYOUT(
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
