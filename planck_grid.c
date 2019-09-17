#include "planck.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER  1
#define _RAISE  2
#define _MENU   16

enum custom_keycodes {
  EXIT = SAFE_RANGE,
  LOWER,
  RAISE
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |      | Win  | ALT  | Lower| Space| Space| Raise| MPRV | MPLY | MNXT | Mute |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {KC_ESC,  XXXXXXX, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   `  | Home |  Up  |  End | PgUp |      |  F1  |  F2  |  F3  |  F4  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift| Pause| Left | Down | Right| PgDn |      |  F5  |  F6  |  F7  |  F8  |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  F1  |  F2  | Stop |  F5  |  F12 |      |  F9  |  F10 |  F11 |  F12 | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |      | Win  | Alt  | Lower| Space| Space| Raise|      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {_______, KC_GRV,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______},
  {_______, KC_PAUS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_DEL },
  {_______, KC_F1,   KC_F2,   KC_STOP, KC_F5,   KC_F12,  XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______},
  {_______, XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   1  |   2  |   3  |   4  |   /  |      |   (  |   )  |   _  |      | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   5  |   6  |   7  |   8  |   *  |      |   {  |   }  |   \  |      |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   9  |   0  |   -  |   +  |   =  |      |   [  |   ]  |   |  |      | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |      | Win  | Alt  | Lower| Space| Space| Raise|      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_SLSH, XXXXXXX, KC_LPRN, KC_RPRN, KC_UNDS, XXXXXXX, _______},
  {_______, KC_5,    KC_6,    KC_7,    KC_8,    KC_ASTR, XXXXXXX, KC_LCBR, KC_RCBR, KC_BSLS, XXXXXXX, KC_DEL },
  {_______, KC_9,    KC_0,    KC_MINS, KC_PLUS, KC_EQL,  XXXXXXX, KC_LBRC, KC_RBRC, KC_PIPE, XXXXXXX, _______},
  {_______, XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
},

/* Menu
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | Lower|      |      | Raise|      |      |      | Reset|
 * `-----------------------------------------------------------------------------------'
 */
[_MENU] = {
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, RESET  }
}

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case EXIT:
      if (record->event.pressed) {
        layer_clear();
        clear_keyboard();
      }
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _MENU);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _MENU);
      }
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _MENU);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _MENU);
      }
      break;
  }
  return true;
}