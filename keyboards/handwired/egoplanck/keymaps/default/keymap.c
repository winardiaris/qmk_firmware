#include QMK_KEYBOARD_H

enum layer_names {
  _QWERTY  = 0,
  _COLEMAK,
  _FN1,
  _FN2,
  _FN3,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  ARST,
  SCRL,
};

#define FN1 MO(_FN1)
#define FN2 MO(_FN2)
#define FN3 MO(_FN3)
#define QWE TO(_QWERTY)
#define COL TO(_COLEMAK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
        _______,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,
        KC_LCTL,    KC_LGUI,    KC_LALT,    FN1,             KC_ESC,                 KC_SPC,            FN2,        FN3,        _______,    KC_ENT
        ),
	[_COLEMAK] = LAYOUT(
        KC_TAB,     KC_Q,       KC_W,       KC_F,       KC_P,       KC_G,       KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN,    KC_BSPC,
        _______,    KC_A,       KC_R,       KC_S,       KC_T,       KC_D,       KC_H,       KC_N,       KC_E,       KC_I,       KC_O,       KC_QUOT,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_K,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,
        KC_LCTL,    KC_LGUI,    KC_LALT,    FN1,             KC_ESC,                 KC_SPC,            FN2,        FN3,        _______,    KC_ENT
        ),
    [_FN1] = LAYOUT(
        KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,
        KC_TILD,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    KC_UNDS,
        _______,    _______,    _______,    _______,    _______,    _______,    KC_LBRC,    KC_RBRC,    KC_LCBR,    KC_RCBR,    KC_BSLS,    KC_PLUS,
        KC_TRNS,    _______,    _______,    _______,         KC_BSPC,                KC_ENT,            COL,        QWE,        KC_PIPE,    KC_EQL
        ),

	[_FN2] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_UP,      _______,    _______,    KC_DEL,
        KC_MSTP,    KC_MPRV,    KC_MPLY,    KC_MNXT,    _______,    _______,    _______,    KC_LEFT,    KC_DOWN,    KC_RGHT,    _______,    _______,
        _______,    KC_MUTE,    KC_VOLD,    KC_VOLU,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,          _______,                _______,          KC_TRNS,    _______,    _______,    _______
        ),
	[_FN3] = LAYOUT(
        _______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_HOME,    KC_PGUP,    _______,    KC_F12,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_END,     KC_PGDN,    _______,    KC_PSCR,
        ARST,       SCRL,       _______,    _______,          _______,                _______,          _______,    KC_TRNS,    _______,    _______
        )
};


#ifdef OLED_DRIVER_ENABLE
#    include "oled.c"
#endif


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_DRIVER_ENABLE
    if (record->event.pressed) {
        oled_timer = timer_read();
    }
#endif


  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
    case ARST:
      if (record->event.pressed) {
         logo = (logo) ? false : true;
      }
      return false;
    case SCRL:
      if (record->event.pressed) {
         scroll = (scroll) ? false : true;
      }
      return false;
  }
  return true;
}
