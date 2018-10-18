#include "orthodox.h"
#include "action_layer.h"
#include "eeconfig.h"
#ifdef BACKLIGHT_ENABLE
	#include "backlight.h"
#endif

extern keymap_config_t keymap_config;

#define _QWERTY 0 // QWERTY layer
#define _NAV    1 // Navigation layer
#define _LOWER  2 // Lower layer
#define _RAISE  3 // Raise layer
#define _MENU	4 // Menu layer
#define _SADS	5 // Sad layer
#define _CELLY	6 // Celly layer
#define _UG     7 // Underglow

#define _SAD	10 // sad face
#define _cTEAM	11 // cellyTEAM
#define _cLOVE	12 // cellyLOVE
#define _cRADIO	13 // cellyRADIO
#define _cCHAMP	14 // cellyCHAMP
#define _cPLS	15 // cellyPLS
#define _cSAD	16 // cellySAD
#define _cWTF	17 // cellyWTF
#define _cS		18 // cellyS
#define _cLUL	19 // cellyWTF
#define _cAY	20 // cellyAY
#define _cRAGE	21 // cellyRAGE
#define _cWUT	22 // cellyWUT

//Macro shortcuts
#define EXIT	M(_QWERTY)
#define LOWER   M(_LOWER)
#define RAISE   M(_RAISE)
#define SAD		M(_SAD)
#define cTEAM	M(_cTEAM)
#define cLOVE	M(_cLOVE)
#define cRADIO	M(_cRADIO)
#define cCHAMP	M(_cCHAMP)
#define cPLS	M(_cPLS)
#define cSAD	M(_cSAD)
#define cWTF	M(_cWTF)
#define cS		M(_cS)
#define cLUL	M(_cLUL)
#define cAY		M(_cAY)
#define cRAGE	M(_cRAGE)
#define cWUT	M(_cWUT)

// Layer shortcuts
#define NAV		MO(_NAV)
#define SADS	TG(_SADS)
#define CELLY	TG(_CELLY)
#define UG		TG(_UG)


// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * .-----------------------------------------.                                                                                  .-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                                                                                  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------.                                        .------+------+------+------+------+------+------+------+------|
 * | Shift|   A  |   S  |   D  |   F  |   G  |   `  |\/\/\/| Esc  |                                        |      |\/\/\/| Win  |   H  |   J  |   K  |   L  |   ;  |   "  |
 * |------+------+------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------+------+------|
 * | Ctrl |   Z  |   X  |   C  |   V  |   B  | LOWER| Space| Alt  |                                        | NAV  | Space| RAISE|   N  |   M  |   ,  |   .  |   /  | Enter|
 * '--------------------------------------------------------------'                                        '--------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                                  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_GRV,  XXXXXXX, KC_ESC,          XXXXXXX, XXXXXXX, KC_LGUI, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    LOWER,   KC_SPC,  KC_LALT,         NAV,     KC_SPC,  RAISE,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT }
},

/* Nav layer
 * .-----------------------------------------.                                                                                  .-----------------------------------------.
 * | Tab  |      | MWL  |  Up  | MWR  |      |                                                                                  |      | Home | PgUp | Ins  |PrtScn| Del  |
 * |------+------+------+------+------+------+------+------+------.                                        .------+------+------+------+------+------+------+------+------|
 * | Shift|      | Left | Down | Right|      |      |\/\/\/|      |                                        |      |\/\/\/| Win  |      | End  | PgDn |      |      |      |
 * |------+------+------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------+------+------|
 * | Ctrl |      |      |      |      |      |      |      | Alt  |                                        | NAV  |      |      |      |      |      |      |      | Enter|
 * '--------------------------------------------------------------'                                        '--------------------------------------------------------------'
 */

[_NAV] = {
  {_______, XXXXXXX, KC_WH_L, KC_UP,   KC_WH_R, XXXXXXX,                                                               XXXXXXX, KC_HOME, KC_PGUP, KC_INS,  KC_PSCR, KC_DEL },
  {_______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, _______, XXXXXXX, KC_END,  KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX},
  {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,         _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______}
},

/* Lower
 * .-----------------------------------------.                                                                                  .-----------------------------------------.
 * | Tab  |   1  |   2  |   3  |   4  |   5  |                                                                                  |      |   !  |   @  |   #  |   $  | Bksp |
 * |------+------+------+------+------+------+------+------+------.                                        .------+------+------+------+------+------+------+------+------|
 * | Shift|   6  |   7  |   8  |   9  |   0  |      |\/\/\/|      |                                        |      |\/\/\/| Win  |      |   %  |   ^  |   &  |   *  |   "  |
 * |------+------+------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------+------+------|
 * | Ctrl |  F1  |  F2  |      |  F5  | F12  | LOWER| Space| Alt  |                                        |      | Space| RAISE|      |      |   ,  |   .  |   /  | Enter|
 * '--------------------------------------------------------------'                                        '--------------------------------------------------------------'
 */
[_LOWER] = {
  {_______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                                                  XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  _______},
  {_______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, _______, XXXXXXX, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, _______},
  {_______, KC_F1,   KC_F2,   XXXXXXX, KC_F5,   KC_F12,  _______, _______, _______,         XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______}
},

/* Raise
 * .-----------------------------------------.                                                                                  .-----------------------------------------.
 * | Tab  |  F1  |  F2  |  F3  |  F4  |      |                                                                                  |      |   (  |   )  |   _  |   +  | Bksp |
 * |------+------+------+------+------+------+------+------+------.                                        .------+------+------+------+------+------+------+------+------|
 * | Shift|  F5  |  F6  |  F7  |  F8  |      |      |\/\/\/|      |                                        |      |\/\/\/| Win  |      |   {  |   }  |   -  |   =  |    " |
 * |------+------+------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------+------+------|
 * | Ctrl |  F9  | F10  | F11  | F12  |      | LOWER| Space| Alt  |                                        |      | Space| RAISE|      |   [  |   ]  |   \  |   |  | Enter|
 * '--------------------------------------------------------------'                                        '--------------------------------------------------------------'
 */
[_RAISE] = {
  {_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,                                                               XXXXXXX, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS, _______},
  {_______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, _______, XXXXXXX, KC_LCBR, KC_RCBR, KC_MINS, KC_EQL,  _______},
  {_______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, _______, _______, _______,         XXXXXXX, _______, _______, XXXXXXX, KC_LBRC, KC_RBRC, KC_BSLS, KC_PIPE, _______}
},

/* Menu
 * .-----------------------------------------.                                                                                  .-----------------------------------------.
 * | Celly|      |      |      |      |      |                                                                                  |      |      |      |      |      | CAD  |
 * |------+------+------+------+------+------+------+------+------.                                        .------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |\/\/\/|      |                                        |      |\/\/\/|      |      |      |      |      |      | NKRO |
 * |------+------+------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------+------+------|
 * |  UG  | SAD  |      |      |      |      | LOWER|      |      |                                        |      |      | RAISE|      |      |      |      |      | Reset|
 * '--------------------------------------------------------------'                                        '--------------------------------------------------------------'
 */
[_MENU] = {
  {CELLY,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LALT(LCTL(KC_DEL))},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MAGIC_TOGGLE_NKRO},
  {UG,      SADS,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET  }
},

/* Sad layer
 * .-----------------------------------------.                                                                                  .-----------------------------------------.
 * |  :(  |  :(  |  :(  |  :(  |  :(  |  :(  |                                                                                  |  :(  |  :(  |  :(  |  :(  |  :(  |  :(  |
 * |------+------+------+------+------+------+------+------+------.                                        .------+------+------+------+------+------+------+------+------|
 * |  :(  |  :(  |  :(  |  :(  |  :(  |  :(  |      |\/\/\/| EXIT |                                        |      |\/\/\/|      |  :(  |  :(  |  :(  |  :(  |  :(  |  :(  |
 * |------+------+------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------+------+------|
 * |  :(  |  :(  |  :(  |  :(  |  :(  |  :(  |      | Bksp | Del  |                                        | Enter| Space|      |  :(  |  :(  |  :(  |  :(  |  :(  |  :(  |
 * '--------------------------------------------------------------'                                        '--------------------------------------------------------------'
 */

[_SADS] = {
  {SAD,     SAD,     SAD,     SAD,     SAD,     SAD,                                                                   SAD,     SAD,     SAD,     SAD,     SAD,     SAD    },
  {SAD,     SAD,     SAD,     SAD,     SAD,     SAD,     XXXXXXX, XXXXXXX, EXIT,            XXXXXXX, XXXXXXX, XXXXXXX, SAD,     SAD,     SAD,     SAD,     SAD,     SAD    },
  {SAD,     SAD,     SAD,     SAD,     SAD,     SAD,     XXXXXXX, KC_BSPC, KC_DEL,          KC_ENT,  KC_SPC,  XXXXXXX, SAD,     SAD,     SAD,     SAD,     SAD,     SAD    }
},

/* Celly layer
 * .-----------------------------------------.                                                                                  .-----------------------------------------.
 * |      |      | TEAM | RADIO| PLS  |      |                                                                                  |      | WTF  | LUL  | RAGE |      |      |
 * |------+------+------+------+------+------+------+------+------.                                        .------+------+------+------+------+------+------+------+------|
 * |      |      | LOVE | CHAMP| SAD  |      |      |\/\/\/| EXIT |                                        |      |\/\/\/|      |      |   S  |  AY  | WUT  |      |      |
 * |------+------+------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |                                        |      |      |      |      |      |      |      |      |      |
 * '--------------------------------------------------------------'                                        '--------------------------------------------------------------'
 */

[_CELLY] = {
  {XXXXXXX, XXXXXXX, cTEAM,   cRADIO,  cPLS,    XXXXXXX,                                                               XXXXXXX, cWTF,    cLUL,    cRAGE,   XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, cLOVE,   cCHAMP,  cSAD,    XXXXXXX, XXXXXXX, XXXXXXX, EXIT,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, cS,      cAY,     cWUT,    XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
}

/* Underglow layer
 * .-----------------------------------------.                                                                                  .-----------------------------------------.
 * |      |      |      | Hue+ |On/Off|      |                                                                                  |      | Light| Sat+ |      |      |      |
 * |------+------+------+------+------+------+------+------+------.                                        .------+------+------+------+------+------+------+------+------|
 * |      |      |      | Hue- | Mode |      |      |\/\/\/| EXIT |                                        |      |\/\/\/|      |      | Dark | Sat- |      |      |      |
 * |------+------+------+------+------+------+------+------+------|                                        |------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |                                        |      |      |      |      |      |      |      |      |      |
 * '--------------------------------------------------------------'                                        '--------------------------------------------------------------'
 */

[_UG] = {
  {XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUI, RGB_TOG, XXXXXXX,                                                               XXXXXXX, RBG_VAI, RGB_SAI, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUD, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, EXIT,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_VAD, RGB_SAD, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
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
		case _SAD: // sad face
			if (record->event.pressed) {
				SEND_STRING(":(");
			}
			break;
		case _cTEAM:
			if (record->event.pressed) {
				SEND_STRING("cellyTEAM ");
			}
			break;
		case _cLOVE:
			if (record->event.pressed) {
				SEND_STRING("cellyLOVE ");
			}
			break;
		case _cRADIO:
			if (record->event.pressed) {
				SEND_STRING("cellyRADIO ");
			}
			break;
		case _cCHAMP:
			if (record->event.pressed) {
				SEND_STRING("cellyCHAMP ");
			}
			break;
		case _cPLS:
			if (record->event.pressed) {
				SEND_STRING("cellyPLS ");
			}
			break;
		case _cSAD:
			if (record->event.pressed) {
				SEND_STRING("cellySAD ");
			}
			break;
		case _cWTF:
			if (record->event.pressed) {
				SEND_STRING("cellyWTF ");
			}
			break;
		case _cS:
			if (record->event.pressed) {
				SEND_STRING("cellyS ");
			}
			break;
		case _cLUL:
			if (record->event.pressed) {
				SEND_STRING("cellyLUL ");
			}
			break;
		case _cAY:
			if (record->event.pressed) {
				SEND_STRING("cellyAY ");
			}
			break;
		case _cRAGE:
			if (record->event.pressed) {
				SEND_STRING("cellyRAGE ");
			}
			break;
		case _cWUT:
			if (record->event.pressed) {
				SEND_STRING("cellyWUT ");
			}
			break;
	}
	return MACRO_NONE;
}