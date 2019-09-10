#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "keymap_steno.h"
#include "version.h"

#define BASE 0 // Default layer
#define SYMB 1 // Symbols
#define STENO 2 // Steno Virtual Serial

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE, // can always be here
    VRSN, // print version info
    EPRM, // enter program mode
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  | ESC  |           | STENO|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |      |           |  [   |   Y  |   U  |   I  |   O  |   P  |   ]    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|  FN  |           | FN   |------+------+------+------+------+--------|
 * | SC-LSh |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | SC-RSh |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LGui | LAlt |   \  |   -  |   =  |                                       | Left | Down |  Up  | Right|   \  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Al+Del| Del  |       | RAlt | RCtrl|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Enter | Space|
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
	// left hand
	KC_GRV,         KC_1,         KC_2,     KC_3,    KC_4,   KC_5,   KC_ESC,
	KC_TAB,         KC_Q,         KC_W,     KC_E,    KC_R,   KC_T,   KC_NO,
	KC_LCTL,       KC_A,         KC_S,     KC_D,    KC_F,   KC_G,
	KC_LSPO,        KC_Z,         KC_X,     KC_C,    KC_V,   KC_B,   MO(SYMB),
	KC_LWIN,        KC_LALT,      KC_BSLS,  KC_MINS, KC_EQL,
						      KC_ERAS, KC_DEL,
							       KC_HOME,
					      KC_SPC, KC_BSPC, KC_END,
	// right hand
	     TG(STENO),     KC_6,   KC_7,   KC_8,    KC_9,    KC_0,      KC_MINS,
	     KC_LBRC,       KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,      KC_RBRC,
			    KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN,   KC_QUOT,
	     MO(SYMB),      KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH,   KC_RSPC,
				    KC_LEFT,KC_DOWN, KC_UP,   KC_RGHT,   KC_BSLS,
	     KC_RALT,        KC_RCTL,
	     KC_PGUP,
	     KC_PGDN, KC_ENT, KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Version |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |           | F12  |  F6  |  F7  |  F8  |  F9  |  F10 |  Mute  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Bright+|      |      |      |      |      |      |           |      |      |      |      |      |      | Vol Up |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Bright-|      |      |      |      |      |------|           |------|      |      |      |      |      | Vol Dn |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | Prev | Stop | Play | Next |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F11,
       KC_BRIU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_BRID, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
				       KC_TRNS,KC_TRNS,
					       KC_TRNS,
			       KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_MUTE,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLU,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Stenography (Serial)
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | BKSPC  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   #  |   #  |   #  |   #  |   #  |      |           |      |   #  |   #  |   #  |   #  |   #  |   #    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   S  |   T  |   P  |   H  |   *  |------|           |------|   *  |   F  |   P  |   L  |   T  |   D    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   S  |   K  |   W  |   R  |   *  |      |           |      |   *  |   R  |   B  |   G  |   S  |   Z    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |   A  |   O  |------|       |------|   E  |   U  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Steno over Serial
[STENO] = LAYOUT_ergodox(
       KC_BSPC, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  KC_NO,
       KC_NO,   STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,
       KC_NO,   STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
					   KC_NO,   KC_NO,
						    KC_NO,
				  STN_A,   STN_O,   KC_NO,
       // right hand
       KC_TRNS,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,    STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,
		 STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
       KC_NO,    STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
			  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,
       KC_NO,
       KC_NO,   STN_E,   STN_U
),
};

// Custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
	switch (keycode) {
	    case EPRM:
		eeconfig_init();
		return false;
	    case VRSN:
		SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
		return false;
	}
    }
    return true;
}
// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    steno_set_mode(STENO_MODE_GEMINI); // STENO_MODE_GEMINI or STENO_MODE_BOLT
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
	case 1:
	    ergodox_right_led_1_on();
	    break;
	case 2:
	    ergodox_right_led_2_on();
	    break;
	default:
	    // none
	    break;
    }

};
