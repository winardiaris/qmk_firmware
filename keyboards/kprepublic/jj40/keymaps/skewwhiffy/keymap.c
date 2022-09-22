/* Copyright 2017 Kenny Hung
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "keymap_uk.h"

// Layer shorthand
enum Layers {
  cm, // colemak
  dv, // dvorak
  qw, // qwerty
  nbl, // numbers left
  nbr, // numbers right
  syl, // symbols left
  syr, // symbols right
  nal, // navigation left
  nar // navigation right
};

// Layer buttons
#define _Z_SFT SFT_T(UK_Z)
#define _SCLSH SFT_T(UK_SCLN)
#define _SLSH SFT_T(UK_SLSH)

#define _X_NB LT(nbl, UK_X)
#define _Q_NB LT(nbl, UK_Q)
#define _DOT_NB LT(nbr, UK_DOT)
#define _V_NB LT(nbr, UK_V)
#define __NBL LT(nbl, _______)
#define __NBR LT(nbr, _______)

#define _C_SY LT(syl, UK_C)
#define _J_SY LT(syl, UK_J)
#define _W_SY LT(syr, UK_W)
#define _COM_SY LT(syr, UK_COMM)
#define __SYL LT(syl, _______)
#define __SYR LT(syr, _______)

#define _V_NAL LT(nal, UK_V)
#define _K_NAL LT(nal, UK_K)
#define _M_NAR LT(nar, UK_M)
#define __NAL LT(nal, _______)
#define __NAR LT(nar, _______)

// Custom hotkeys
#define _TERM LCTL(UK_QUOT) // Hotkey for terminal
#define _S_TAB S(KC_TAB)
#define _C_LEFT LCTL(KC_LEFT)
#define _C_RGHT LCTL(KC_RGHT)
#define _A_LEFT LALT(KC_LEFT)
#define _A_RGHT LALT(KC_RGHT)

// Custom hotkeys
#define _TERM LCTL(UK_QUOT) // Hotkey for terminal
#define _S_TAB S(KC_TAB)
#define _C_LEFT LCTL(KC_LEFT)
#define _C_RGHT LCTL(KC_RGHT)
#define _A_LEFT LALT(KC_LEFT)
#define _A_RGHT LALT(KC_RGHT)

enum custom_keycodes {
  IJ_OMN = SAFE_RANGE // IntelliJ Omnibox
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 * .-----------------------------------------------------------------------------------------------------------.
 * | Q      | W      | F      | P      | G      |        |        | J      | L      | U      | Y      | ;      |
 * |-----------------------------------------------------------------------------------------------------------|
 * | A      | R      | S      | T      | D      |        |        | H      | N      | E      | I      | O      |
 * |-----------------------------------------------------------------------------------------------------------|
 * | Z      | X      | C      | V      | B      |        |        | K      | M      | ,      | .      | /      |
 * | SHIFT  | NUMBER | SYMBOL | NAV    |        |        |        |        | NAV    | SYMBOL | FUNC   | SHIFT  |
 * |-----------------------------------------------------------------------------------------------------------|
 * | LSHIFT | LCTRL  | LALT   | LGUI   | SPACE  | ENT    | DEL    | BKSPC  | RGUI   | RALT   | RCTRL  | RSHIFT |
 * .-----------------------------------------------------------------------------------------------------------.
 */
 [cm] = LAYOUT_ortho_4x12( \
   UK_Q,    UK_W,    UK_F,    UK_P,    UK_G,    _______, _______, UK_J,    UK_L,    UK_U,    UK_Y,    UK_SCLN, \
   UK_A,    UK_R,    UK_S,    UK_T,    UK_D,    _______, _______, UK_H,    UK_N,    UK_E,    UK_I,    UK_O, \
   _Z_SFT,  _X_NB,   _C_SY,   _V_NAL,  UK_B,    _______, _______, UK_K,    _M_NAR,  _COM_SY, _DOT_NB, _SLSH, \
   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,  KC_ENT,  KC_DEL,  KC_BSPC, KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT \
 ),

/* Dvorak
 * .-----------------------------------------------------------------------------------------------------------.
 * | '      | ,      | .      | P      | Y      |        |        | F      | G      | C      | R      | L      |
 * |-----------------------------------------------------------------------------------------------------------|
 * | A      | O      | E      | U      | I      |        |        | D      | H      | T      | N      | S      |
 * |-----------------------------------------------------------------------------------------------------------|
 * | ;      | Q      | J      | K      | X      |        |        | B      | M      | W      | V      | Z      |
 * | SHIFT  | NUMBER | SYMBOL | NAV    |        |        |        |        | NAV    | SYMBOL | FUNC   | SHIFT  |
 * |-----------------------------------------------------------------------------------------------------------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * |-----------------------------------------------------------------------------------------------------------|
 */
 [dv] = LAYOUT_ortho_4x12( \
   UK_QUOT, UK_COMM, UK_DOT,  UK_P,    UK_Y,    _______, _______, UK_F,    UK_G,    UK_C,    UK_R,    UK_L, \
   UK_A,    UK_O,    UK_E,    UK_U,    UK_I,    _______, _______, UK_D,    UK_H,    UK_T,    UK_N,    UK_S, \
   _SCLSH,  _Q_NB,   _J_SY,   _K_NAL,  UK_X,    _______, _______, UK_B,    _M_NAR,  _W_SY,   _V_NB,   _Z_SFT, \
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
 ),

/* QWERTY
 * .-----------------------------------------------------------------------------------------------------------.
 * | Q      | W      | E      | R      | T      |        |        | Y      | U      | I      | O      | P      |
 * |-----------------------------------------------------------------------------------------------------------|
 * | A      | S      | D      | F      | G      |        |        | H      | J      | K      | L      | ;      |
 * |-----------------------------------------------------------------------------------------------------------|
 * | Z      | X      | C      | V      | B      |        |        | N      | M      | ,      | .      | /      |
 * | SHIFT  | NUMBER | SYMBOL | NAV    |        |        |        |        | NAV    | SYMBOL | FUNC   | SHIFT  |
 * |-----------------------------------------------------------------------------------------------------------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * .-----------------------------------------------------------------------------------------------------------.
 */
 [qw] = LAYOUT_ortho_4x12( \
   UK_Q,    UK_W,    UK_E,    UK_R,    UK_T,    _______, _______, UK_Y,    UK_U,    UK_I,    UK_O,    UK_P, \
   UK_A,    UK_S,    UK_D,    UK_F,    UK_G,    _______, _______, UK_H,    UK_J,    UK_K,    UK_L,    UK_SCLN, \
   _Z_SFT,  _X_NB,   _C_SY,   _V_NAL,  UK_B,    _______, _______, UK_N,    _M_NAR,  _COM_SY, _DOT_NB, _SLSH, \
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
 ),

/* Numbers _NB
 * .-----------------------------------------------------------------------------------------------------------.
 * |        | F7     | F8     | F9     | F10    |        |        |        | 7      | 8      | 9      |        |
 * |-----------------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | F4     | F5     | F6     | F11    |        |        |        | 4      | 5      | 6      |        |
 * |-----------------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * |        | F1     | F2     | F3     | F12    |        |        | 0      | 1      | 2      | 3      | .      |
 * |-----------------+--------+--------+--------+--------+--------+--------+-----------------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------'
 */
 [nbl] = LAYOUT_ortho_4x12( \
   _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, _______, _______, UK_7,    UK_8,    UK_9,    _______, \
   _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______, _______, _______, UK_4,    UK_5,    UK_6,    _______, \
   _______, __NBL,   KC_F2,   KC_F3,   KC_F12,  _______, _______, UK_0,    UK_1,    UK_2,    UK_3,    UK_DOT, \
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
 ),
 [nbr] = LAYOUT_ortho_4x12( \
   _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, _______, _______, UK_7,    UK_8,    UK_9,    _______, \
   _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______, _______, _______, UK_4,    UK_5,    UK_6,    _______, \
   _______, KC_F1,   KC_F2,   KC_F3,   KC_F12,  _______, _______, UK_0,    UK_1,    UK_2,    __NBR,   UK_DOT, \
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
 ),

/* Symbols _SY
 * .-----------------------------------------------------------------------------------------------------------.
 * | !      | £      | _      | -      | ~      |        |        | \      | {      | }      | /      | #      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | $      | %      | +      | =      |        |        |        | "      | (      | )      | '      | @      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | ^      | &      | *      | |      |        |        |        | <      | [      | ]      | >      | `      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------'
 */
 [syl] = LAYOUT_ortho_4x12( \
   UK_EXLM, UK_PND,  UK_UNDS, UK_MINS, UK_TILD, _______, _______, UK_BSLS, UK_LCBR, UK_RCBR, UK_SLSH, UK_HASH, \
   UK_DLR,  UK_PERC, UK_PLUS, UK_EQL,  _______, _______, _______, UK_DQUO, UK_LPRN, UK_RPRN, UK_QUOT, UK_AT, \
   UK_CIRC, UK_AMPR, __SYL,   UK_PIPE, _______, _______, _______, UK_LABK, UK_LBRC, UK_RBRC, UK_RABK, UK_GRV, \
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
 ),
 [syr] = LAYOUT_ortho_4x12( \
   UK_EXLM, UK_PND,  UK_UNDS, UK_MINS, UK_TILD, _______, _______, UK_BSLS, UK_LCBR, UK_RCBR, UK_SLSH, UK_HASH, \
   UK_DLR,  UK_PERC, UK_PLUS, UK_EQL,  _______, _______, _______, UK_DQUO, UK_LPRN, UK_RPRN, UK_QUOT, UK_AT, \
   UK_CIRC, UK_AMPR, UK_ASTR, UK_PIPE, _______, _______, _______, UK_LABK, UK_LBRC, __SYR,   UK_RABK, UK_GRV, \
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
 ),

/*
 * Navigation
 * .-----------------------------------------------------------------------------------------------------------.
 * | Esc    | Ctrl L | Up     | Ctrl R | RGB RMD| RGB HD | RGB HI | RGB_TG | PtSn   | ScLk   | Pause  | DVORAK |
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | Tab    | Left   | Down   | Right  | RGB MD | RGB SD | RGB SI | COLEMAK| Insert | Home   | PgUp   | Term   |
 * +--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | ShTab  | Alt L  | IJ Omni| Alt R  |        | RGB VD | RGB VI |        | ScLk   | End    | PgDn   | QWERTY |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * '-----------------------------------------------------------------------------------------------------------'
 */
 [nal] = LAYOUT_ortho_4x12( \
   KC_ESC,  _C_LEFT, KC_UP,   _C_RGHT, RGB_RMOD,RGB_HUD, RGB_HUI, RGB_TOG, KC_PSCR, KC_SLCK, KC_PAUS, DF(dv), \
   KC_TAB,  KC_LEFT, KC_DOWN, KC_RGHT, RGB_MOD, RGB_SAD, RGB_SAI, DF(cm),  KC_INS,  KC_HOME, KC_PGUP, _TERM, \
   _S_TAB,  _A_LEFT, IJ_OMN,  __NAL,   _______, RGB_VAD, RGB_VAI, _______, KC_SLCK, KC_END,  KC_PGDN, DF(qw), \
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
 ),
 [nar] = LAYOUT_ortho_4x12( \
   KC_ESC,  _C_LEFT, KC_UP,   _C_RGHT, RGB_RMOD,RGB_HUD, RGB_HUI, RGB_TOG, KC_PSCR, KC_SLCK, KC_PAUS, DF(dv), \
   KC_TAB,  KC_LEFT, KC_DOWN, KC_RGHT, RGB_MOD, RGB_SAD, RGB_SAI, DF(cm),  KC_INS,  KC_HOME, KC_PGUP, _TERM, \
   _S_TAB,  _A_LEFT, IJ_OMN,  _A_RGHT, _______, RGB_VAD, RGB_VAI, _______, __NAR,   KC_END,  KC_PGDN, DF(qw), \
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
 ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case IJ_OMN:
        SEND_STRING(SS_TAP(X_LSHIFT)SS_TAP(X_LSHIFT));
        return false;
    }
  }
  return true;
}
