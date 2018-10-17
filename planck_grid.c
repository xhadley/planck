#include "planck.h"
#include "action_layer.h"
#include "eeconfig.h"
#ifdef BACKLIGHT_ENABLE
  #include "backlight.h"
#endif

extern keymap_config_t keymap_config;

#define _QWERTY 0 // QWERTY layer
#define _LOWER  1 // Lower layer
#define _RAISE  2 // Raise layer
#define _NAV    3 // Navigation layer
#define _MENU 4 // Menu layer


//Macro shortcuts
#define EXIT  M(_QWERTY)
#define LOWER M(_LOWER)
#define RAISE M(_RAISE)

// Layer shortcuts
#define NAV   MO(_NAV)


// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   "  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |      | Win  | ALT  | Lower| NAV  | Space| Raise| MPRV | MPLY | MNXT | Mute |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT },
  {KC_ESC,  XXXXXXX, KC_LGUI, KC_LALT, LOWER,   NAV,     KC_SPC,  RAISE,   KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE}
},

/* Nav layer
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |      |      |  Up  |      |      |      | Home | PgUp | Ins  |PrtScn| Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|      | Left | Down |Right |      |      | End  | PgDn |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      |      |      |      |      |      |      |      |      |      | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Win  | Alt  |      | NAV  |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_NAV] = {
  {_______, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGUP, KC_INS,  KC_PSCR, KC_DEL },
  {_______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, KC_END,  KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______},
  {XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   1  |   2  |   3  |   4  |   5  |      |   !  |   @  |   #  |   $  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   6  |   7  |   8  |   9  |   0  |      |   %  |   ^  |   &  |   *  |   "  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  F1  |  F2  |      |  F5  |  F12 |      |   `  |   ,  |   .  |   /  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Win  | Alt  | Lower|      | Space| Raise|      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  _______},
  {_______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, _______},
  {_______, KC_F1,   KC_F2,   XXXXXXX, KC_F5,   KC_F12,  XXXXXXX, KC_GRV,  KC_COMM, KC_DOT,  KC_SLSH, _______},
  {XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |  F1  |  F2  |  F3  |  F4  |      |      |   (  |   )  |   _  |   +  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|  F5  |  F6  |  F7  |  F8  |      |      |   {  |   }  |   -  |   =  |   "  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  F9  |  F10 |  F11 |  F12 |      |      |   [  |   ]  |   \  |   |  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Win  | Alt  | Lower|      | Space| Raise|      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, _______},
  {_______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, KC_MINS, KC_EQL,  _______},
  {_______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_BSLS, KC_PIPE, _______},
  {XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
},

/* Menu
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      | CAD  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | NKRO |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | Lower|      |      | Raise|      |      |      | Reset|
 * `-----------------------------------------------------------------------------------'
 */
[_MENU] = {
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LALT(LCTL(KC_DEL))},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MAGIC_TOGGLE_NKRO},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, RESET  }
}

};

// Macro actions
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch (id) {
    case _QWERTY: // exit back to default layer
      if (record->event.pressed) {
        layer_clear();
        clear_keyboard();
      }
      break;
    case _LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _MENU);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _MENU);
      }
      break;
    case _RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _MENU);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _MENU);
      }
      break;
  }
  return MACRO_NONE;
}