// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _GAME,
    _NAV,
    _MEDIA,
    _SYMR,
    _NUMP,
    _SYML,
    _FUNC
};

// Tap Dance declarations
enum {
    TD_GAME,
    TD_BASE
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_GAME] = ACTION_TAP_DANCE_LAYER_MOVE(KC_MPLY,_GAME),
    [TD_BASE] = ACTION_TAP_DANCE_LAYER_MOVE(KC_MPLY,_BASE)
};


/*
 * Base Mod Taps
 */
#define M_AW LGUI_T(KC_A)
#define M_RA LALT_T(KC_R)
#define M_SC LCTL_T(KC_S)
#define M_TC LSFT_T(KC_T)
#define M_XA KC_X
#define M_OW LGUI_T(KC_O)
#define M_IA LALT_T(KC_I)
#define M_EC LCTL_T(KC_E)
#define M_NC LSFT_T(KC_N)
#define M_DOTA KC_DOT
#define LT_ESC LT(_MEDIA, KC_ESC)
#define LT_TAB LT(_SYMR, KC_TAB)
#define LT_SPC LT(_NAV, KC_SPC)
#define LT_DEL LT(_FUNC, KC_DEL)
#define LT_BSPC LT(_SYML, KC_BSPC)
#define LT_ENT LT(_NUMP, KC_ENT)
#define T_GAME TD(TD_GAME)
#define T_BASE TD(TD_BASE)

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
  KC_ESC,   KC_Q,     KC_W,     KC_F,     KC_P,         KC_B,                       KC_J,       KC_L,       KC_U,       KC_Y,       KC_QUOT,    KC_NO,
  KC_BSPC,  M_AW,     M_RA,     M_SC,     M_TC,         KC_G,                       KC_M,       M_NC,       M_EC,       M_IA,       M_OW,       KC_NO,
  KC_DEL,   KC_Z,     M_XA,     KC_C,     KC_D,         KC_V,   KC_MUTE,  T_GAME,   KC_K,       KC_H,       KC_COMM,    M_DOTA,     KC_SLSH,    KC_NO,
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
  KC_LCTL,    KC_Z,     KC_X,       KC_C,     KC_V,     KC_B,   KC_TRNS,  T_BASE,     KC_N,     KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_F4,
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
  KC_NO,    QK_BOOT,    KC_NO,      KC_NO,    KC_NO,    KC_NO,                      KC_AGIN,    KC_UNDO,    KC_CUT,     KC_COPY,    KC_PSTE,    KC_NO,
  KC_NO,    KC_LGUI,    KC_LALT,    KC_LCTL,  KC_LSFT,  KC_NO,                      KC_CAPS,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    KC_NO,
  KC_NO,    KC_NO,      KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,    KC_INS,     KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     KC_NO,
                        KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,                    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
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
  KC_NO,    QK_BOOT,    KC_NO,      KC_NO,    KC_NO,    KC_NO,                      RGB_MOD,    RGB_HUI,    RGB_SAI,    RGB_VAI,    RGB_TOG,    KC_NO,
  KC_NO,    KC_LGUI,    KC_LALT,    KC_LCTL,  KC_LSFT,  KC_NO,                      KC_NO,      KC_MPRV,    KC_VOLD,    KC_VOLU,    KC_MNXT,    KC_NO,
  KC_NO,    KC_NO,      KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,
                        KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,                    KC_TRNS,    KC_MSTP,    KC_MPLY,    KC_MUTE
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
  KC_NO,    QK_BOOT,    KC_NO,      KC_NO,    KC_NO,    KC_NO,                      KC_PLUS,    KC_LBRC,    KC_RBRC,    KC_BSLS,  KC_DQT,     KC_NO,
  KC_NO,    KC_LGUI,    KC_LALT,    KC_LCTL,  KC_LSFT,  KC_NO,                      KC_MINS,    KC_LPRN,    KC_RPRN,    KC_EXLM,  KC_EQL,     KC_NO,
  KC_NO,    KC_NO,      KC_NO,      KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_NO,    KC_PERC,    KC_LCBR,    KC_RCBR,    KC_PIPE,  KC_UNDS,    KC_NO,
                        KC_NO,      KC_NO,    KC_NO,    KC_NO,                      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
  ),
/* Numpad
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |RESET |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      | LSHFT| LCTRL| LALT | LGUI |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_NUMP] = LAYOUT(
  KC_NO,    KC_NO,      KC_NO,      KC_NO,    KC_NO,    KC_NO,                      KC_NO,      KC_NO,      KC_NO,      KC_NO,    KC_NO,      KC_NO,
  KC_NO,    KC_LBRC,    KC_7,       KC_8,     KC_9,     KC_RBRC,                    KC_NO,      KC_NO,      KC_NO,      KC_NO,    QK_BOOT,    KC_NO,
  KC_NO,    KC_SCLN,    KC_4,       KC_5,     KC_6,     KC_EQL,                     KC_NO,      KC_LSFT,    KC_LCTL,    KC_LALT,  KC_LGUI,    KC_NO,
  KC_NO,    KC_GRV,     KC_1,       KC_2,     KC_3,     KC_BSLS,  KC_NO,  KC_NO,    KC_NO,      KC_NO,      KC_NO,      KC_NO,    KC_NO,      KC_NO,
                        KC_NO,      KC_NO,    KC_NO,    KC_0,                      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
  ),
/* Symbol Left
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |RESET |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      | LSHFT| LCTRL| LALT | LGUI |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_SYML] = LAYOUT(
  KC_NO,    KC_NO,      KC_NO,      KC_NO,    KC_NO,    KC_NO,                      KC_NO,      KC_NO,      KC_NO,      KC_NO,    KC_NO,      KC_NO,
  KC_NO,    KC_NO,      KC_AMPR,    KC_LABK,  KC_RABK,  KC_CIRC,                    KC_NO,      KC_NO,      KC_NO,      KC_NO,    QK_BOOT,    KC_NO,
  KC_NO,    KC_NO,      KC_TILD,    KC_COLN,  KC_SCLN,  KC_ASTR,                    KC_NO,      KC_LSFT,    KC_LCTL,    KC_LALT,  KC_LGUI,    KC_NO,
  KC_NO,    KC_NO,      KC_AT,      KC_DLR,   KC_PIPE,  KC_HASH,  KC_NO,  KC_NO,    KC_NO,      KC_NO,      KC_NO,      KC_NO,    KC_NO,      KC_NO,
                        KC_NO,      KC_NO,    KC_NO,    KC_NO,                      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
  ),
/* Functions
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |RESET |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      | LSHFT| LCTRL| LALT | LGUI |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_FUNC] = LAYOUT(
  KC_NO,    KC_NO,      KC_NO,      KC_NO,    KC_NO,    KC_NO,                      KC_NO,      KC_NO,      KC_NO,      KC_NO,    KC_NO,      KC_NO,
  KC_NO,    KC_F12,     KC_F7,      KC_F8,    KC_F9,    KC_PSCR,                    KC_NO,      KC_NO,      KC_NO,      KC_NO,    QK_BOOT,    KC_NO,
  KC_NO,    KC_F11,     KC_F4,      KC_F5,    KC_F6,    KC_SLCK,                    KC_NO,      KC_LSFT,    KC_LCTL,    KC_LALT,  KC_LGUI,    KC_NO,
  KC_NO,    KC_F10,     KC_F1,      KC_F2,    KC_F3,    KC_BRK,   KC_NO,  KC_NO,    KC_NO,      KC_NO,      KC_NO,      KC_NO,    KC_NO,      KC_NO,
                        KC_NO,      KC_NO,    KC_NO,    KC_NO,                      KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
  )
};

#ifdef OLED_ENABLE
bool oled_task_user(void) {

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(baselyr, false);
            break;
        case _NAV:
            oled_write_ln_P(baselyr, false);
            break;
        case _MEDIA:
            oled_write_ln_P(medialyr, false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(baselyr, false);
    }
    
    return false;
}

static const unsigned char PROGMEM baselyr[] = {
    0x00, 0x00, 0x00, 0x18, 0x18, 0x18,
    0xF8, 0x18, 0x18, 0x18, 0x18, 0xF8,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xF8,
    0x80, 0xC0, 0x78, 0x18, 0x08, 0xF0,
    0x00, 0x00, 0x00, 0x00, 0x98, 0x98,
    0x98, 0x98, 0x98, 0xD8, 0x68, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x98, 0x98,
    0x98, 0x98, 0x98, 0xD8, 0x68, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xF8, 0x80,
    0xC0, 0x70, 0x18, 0x08, 0xF0, 0x00,
    0x00, 0x58, 0x58, 0x58, 0x58, 0x58,
    0x50, 0xB0, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x78, 0xD8, 0x98,
    0x98, 0x98, 0xD8, 0xF8, 0x18, 0x18,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFE, 0xFE, 0x06, 0x06, 0x66, 0x66,
    0x66, 0x66, 0x66, 0x66, 0x66, 0x66,
    0xE6, 0xE6, 0x06, 0x06, 0xE6, 0xE6,
    0x66, 0x66, 0xE6, 0xE6, 0x66, 0x66,
    0xE6, 0xE6, 0x06, 0x06, 0xFE, 0xFE,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x66,
    0x66, 0x76, 0x56, 0x56, 0x5E, 0x4E,
    0x4E, 0x4E, 0x00, 0x00, 0x0E, 0x18,
    0x10, 0x30, 0x39, 0x28, 0x6C, 0x44,
    0x44, 0xC6, 0x00, 0x00, 0x00, 0x00,
    0xD8, 0x6C, 0x66, 0x66, 0x66, 0x66,
    0x66, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFC, 0x66, 0x66, 0x7C, 0x60, 0x60,
    0x3C, 0x00, 0x00, 0x0E, 0x18, 0x10,
    0x30, 0x39, 0x28, 0x6C, 0x44, 0x44,
    0xC6, 0x00, 0x00, 0xF1, 0x19, 0x0D,
    0xFD, 0x8D, 0xD9, 0x71, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xFC,
    0x66, 0x66, 0x7C, 0x60, 0x60, 0x3C,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00,
    0xFE, 0xFE, 0x06, 0x06, 0x7E, 0x7E,
    0x66, 0x66, 0x7F, 0x7F, 0x06, 0x06,
    0x7F, 0x7F, 0x66, 0x66, 0x7F, 0x7F,
    0x66, 0x66, 0x7F, 0x7F, 0x00, 0x00,
    0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x2B, 0x2B, 0x2B,
    0x2B, 0x2B, 0x2A, 0x36, 0x00, 0x80,
    0x00, 0x00, 0x2B, 0x2B, 0x2B, 0x2B,
    0x2B, 0x2A, 0x36, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x1C, 0x1C, 0x14, 0x36,
    0x36, 0x26, 0x63, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xAB, 0x2B, 0x2B, 0x2B,
    0x2B, 0x2A, 0xB6, 0x00, 0x00, 0x78,
    0x6C, 0x66, 0x66, 0x66, 0x6C, 0x78,
    0x60, 0x60, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x3E, 0x30, 0xB0, 0xBE, 0x86,
    0x06, 0x3C, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,
    0x00, 0x00, 0x67, 0x67, 0x66, 0x66,
    0x66, 0x66, 0x66, 0x66, 0xFE, 0xFE,
    0x60, 0x60, 0xFE, 0xFE, 0x66, 0x66,
    0x60, 0x60, 0xFE, 0xFE, 0x66, 0x66,
    0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x1C,
    0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
    0x06, 0x07, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x0F, 0x02,
    0x02, 0x02, 0x36, 0x36, 0x1B, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x1E, 0x03, 0x01,
    0x1F, 0x11, 0x1B, 0x0E, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x7F, 0x7F, 0x60, 0x60, 0x66, 0x66,
    0x66, 0x66, 0x66, 0x66, 0x66, 0x66,
    0x67, 0x67, 0x60, 0x60, 0x67, 0x67,
    0x66, 0x66, 0x60, 0x60, 0x67, 0x67,
    0x66, 0x66, 0x60, 0x60, 0x7F, 0x7F,
    0x00, 0x00,
};

static const unsigned char PROGMEM medialyr[] = {
    0x00, 0x00, 0x00, 0x18, 0x18, 0x18,
    0xF8, 0x18, 0x18, 0x18, 0x18, 0xF8,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xF8,
    0x80, 0xC0, 0x78, 0x18, 0x08, 0xF0,
    0x00, 0x00, 0x00, 0x00, 0x98, 0x98,
    0x98, 0x98, 0x98, 0xD8, 0x68, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x98, 0x98,
    0x98, 0x98, 0x98, 0xD8, 0x68, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xF8, 0x80,
    0xC0, 0x70, 0x18, 0x08, 0xF0, 0x00,
    0xF8, 0xA4, 0xA6, 0xA6, 0xA6, 0xA6,
    0xAE, 0x4E, 0xFE, 0xFC, 0xF8, 0x00,
    0x00, 0x00, 0x00, 0x78, 0xD8, 0x98,
    0x98, 0x98, 0xD8, 0xF8, 0x18, 0x18,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFE, 0xFE, 0x06, 0x06, 0x66, 0x66,
    0x66, 0x66, 0x66, 0x66, 0x66, 0x66,
    0xE6, 0xE6, 0x06, 0x06, 0xE6, 0xE6,
    0x66, 0x66, 0xE6, 0xE6, 0x66, 0x66,
    0xE6, 0xE6, 0x06, 0x06, 0xFE, 0xFE,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x66,
    0x66, 0x76, 0x56, 0x56, 0x5E, 0x4E,
    0x4E, 0x4E, 0x00, 0x00, 0x0E, 0x18,
    0x10, 0x30, 0x39, 0x28, 0x6C, 0x44,
    0x44, 0xC6, 0x00, 0x00, 0x00, 0x00,
    0xD8, 0x6C, 0x66, 0x66, 0x66, 0x66,
    0x66, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFC, 0x66, 0x66, 0x7C, 0x60, 0x60,
    0x3C, 0x00, 0x00, 0x0E, 0x18, 0x10,
    0x30, 0x39, 0x28, 0x6C, 0x44, 0x44,
    0xC6, 0x00, 0xFF, 0x0E, 0xE6, 0xF2,
    0x02, 0x72, 0x26, 0x8E, 0xFF, 0xFF,
    0xFF, 0x00, 0x00, 0x00, 0x00, 0xFC,
    0x66, 0x66, 0x7C, 0x60, 0x60, 0x3C,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00,
    0xFE, 0xFE, 0x06, 0x06, 0x7E, 0x7E,
    0x66, 0x66, 0x7F, 0x7F, 0x06, 0x06,
    0x7F, 0x7F, 0x66, 0x66, 0x7F, 0x7F,
    0x66, 0x66, 0x7F, 0x7F, 0x00, 0x00,
    0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x2B, 0x2B, 0x2B,
    0x2B, 0x2B, 0x2A, 0x36, 0x00, 0x80,
    0x00, 0x00, 0x2B, 0x2B, 0x2B, 0x2B,
    0x2B, 0x2A, 0x36, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x1C, 0x1C, 0x14, 0x36,
    0x36, 0x26, 0x63, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xAB, 0x2B, 0x2B, 0x2B,
    0x2B, 0x2A, 0xB6, 0x00, 0x7F, 0x87,
    0x93, 0x99, 0x99, 0x99, 0x93, 0x87,
    0x9F, 0x9F, 0x7F, 0x00, 0x00, 0x00,
    0x00, 0x3E, 0x30, 0xB0, 0xBE, 0x86,
    0x06, 0x3C, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,
    0x00, 0x00, 0x67, 0x67, 0x66, 0x66,
    0x66, 0x66, 0x66, 0x66, 0xFE, 0xFE,
    0x60, 0x60, 0xFE, 0xFE, 0x66, 0x66,
    0x60, 0x60, 0xFE, 0xFE, 0x66, 0x66,
    0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x1C,
    0x06, 0x06, 0x06, 0x06, 0x06, 0x06,
    0x06, 0x07, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x0F, 0x02,
    0x02, 0x02, 0x36, 0x36, 0x1B, 0x00,
    0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x1E, 0x03, 0x01,
    0x1F, 0x11, 0x1B, 0x0E, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x7F, 0x7F, 0x60, 0x60, 0x66, 0x66,
    0x66, 0x66, 0x66, 0x66, 0x66, 0x66,
    0x67, 0x67, 0x60, 0x60, 0x67, 0x67,
    0x66, 0x66, 0x60, 0x60, 0x67, 0x67,
    0x66, 0x66, 0x60, 0x60, 0x7F, 0x7F,
    0x00, 0x00,
};


#endif