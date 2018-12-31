#include QMK_KEYBOARD_H
#include "version.h"

#include "keymap_french.h"

#define BASE 0 // default layer
#define LY_CH_1 1 // char 1 layer
#define LY_CH_2 8 // char 2 layer
#define LY_NUMB 2 // symbols/numbers
#define LY_MOUSE 3 // mouse
#define LY_AZERTY 5 // azerty layer (only for litle games)
#define LY_QWERTY 6 // qwerty layer (only for litle games)

#define KC___ KC_NO
#define KC____ KC_TRNS

enum custom_keycodes {
  // RESET // Reseting the keyboard (already defined)
  EPRM = SAFE_RANGE, // Wiping the EEPROM (Persistent Storage)
  VRSN,
  COPY,
  PAST,
  HEHE
};


 /*
  *    Combo !!!   COMBO    COMBO      COMBO !!!!!!!!
 */
enum combos {
  CB_RESET,
  // CB_CAPSLOCK,
  CB_LY_NUMB,
  CB_LY_MOUSE
};

const uint16_t PROGMEM cb_reset[] = {KC_Y, KC_H, KC_F, COMBO_END};
// const uint16_t PROGMEM cb_capslock[] = {KC_P, KC_L, COMBO_END};
const uint16_t PROGMEM cb_ly_numb[] = {KC_L, KC_J, COMBO_END};
const uint16_t PROGMEM cb_ly_mouse[] = {KC_B, FR_COMM, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [CB_RESET] = COMBO_ACTION(cb_reset),
  // [CB_CAPSLOCK] = COMBO(cb_capslock, KC_CAPSLOCK),
  [CB_LY_NUMB] = COMBO_ACTION(cb_ly_numb),
  [CB_LY_MOUSE] = COMBO_ACTION(cb_ly_mouse)
};

void process_combo_event(uint8_t combo_index, bool pressed) {
  switch(combo_index) {
    case CB_LY_NUMB:
      if (pressed) {
        layer_on(LY_NUMB);
      }
      break;
    case CB_LY_MOUSE:
      if (pressed) {
        layer_on(LY_MOUSE);
      }
      break;

    case CB_RESET:
      if (pressed) {
        reset_keyboard();
      }
      break;
  }
}

// Unicode
#define STAR 0x2605 // ★
#define APOSTR 0x2019 // ’
#define LGUILMET 0x00AB // «
#define RGUILMET 0x00BB // »
#define LQUOTATION 0x201C // “
#define RQUOTATION 0x201D // ”
#define OE 0x0153 // œ


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   B  |   ,  |P/Numb|O/Sft |   W  |      |           |      |   Z  |V/Sft |D/Muse|   L  |  J   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  PgUp  |   A  |U/Alt |I/Ctrl| E/?1 |   M  |------|           |------|   K  | T/?1 |S/Ctrl| R/Alt|  N   |  PgUp  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  PgDn  |   .  |   Y  |   X  | C/?2 | Save |      |           |      |      |   Q  |   G  |  H   |  F   |  PgDn  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Down |  Up  |      | Left | Right|                                       |  Up  | Down |      |  Up  | Down |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  Del |      |       |      |      |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */

[BASE] = LAYOUT_ergodox(
  // left hand
  KC_ESC,          KC___,       KC___,       KC___,             KC___,             KC___,      KC___,
  KC___,           KC_B,        FR_COMM,     LT(LY_NUMB, KC_P), SFT_T(KC_O),       FR_W,       KC___,
  KC_PGUP,         FR_A,        ALT_T(KC_U), CTL_T(KC_I),       LT(LY_CH_1, KC_E), FR_M,
  KC_PGDN,         FR_DOT,      KC_Y,        KC_X,              LT(LY_CH_2, KC_C), LCTL(KC_S), KC___,
  KC_DOWN,         KC_UP,       KC___,       KC_LEFT,           KC_RGHT,
                                                                   KC_DEL,  KC___,
                                                                            KC_HOME,
                                                           KC_SPC, KC_BSPC, KC_END,

  // right hand
  KC___,      KC___,  KC___,             KC___,              KC___,        KC___,     KC___,
  KC___,      FR_Z,   SFT_T(KC_V),       LT(LY_MOUSE, KC_D), KC_L,         KC_J,      KC___,
              KC_K,   LT(LY_CH_1, KC_T), CTL_T(KC_S),        ALT_T(KC_R),  KC_N,      KC_PGUP,
  KC___,      KC___,  LT(LY_CH_2, FR_Q), KC_G,               KC_H,         KC_F,      KC_PGDN,
  KC_UP,      KC_DOWN,  KC___,           KC_UP,              KC_DOWN,
  KC___,   KC___,
  KC_PGUP,
  KC_PGDN, KC_TAB, KC_ENT
),

/* Keymap: Char1 Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |  ^.^ |   ^  |   è  |   ¨  |      |           |      |      |   [  |   ]  |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   à  |   ù  |   '  |   é  |   €  |------|           |------|VerMaj|   (  |   )  |   <  |   >  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   `  |   "  |   '  |   ç  |   œ  |      |           |      |      |   {  |   }  |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[LY_CH_1] = LAYOUT_ergodox(
  // left hand
  KC____, KC____,   KC____,  KC____,     KC____,  KC____,  KC____,
  KC____, UC(STAR), HEHE,    FR_CIRC,    FR_EGRV, FR_UMLT, KC____,
  KC____, FR_AGRV,  FR_UGRV, UC(APOSTR), FR_EACU, FR_EURO,
  KC____, FR_GRV,   FR_QUOT, FR_APOS,    FR_CCED, UC(OE),  KC____,
  KC____, KC____,   KC____,  KC____,     KC____,
                                               KC____, KC____,
                                                        KC____,
                                      KC____, KC____, KC____,
  // right hand
  KC____, KC____,      KC____,   KC____,   KC____,         KC____,         KC____,
  KC____, KC____,      FR_LBRC, FR_RBRC,   UC(LGUILMET),   UC(RGUILMET),   KC____,
          KC_CAPSLOCK, FR_LPRN, FR_RPRN,   FR_LESS,        FR_GRTR,        KC____,
  KC____, KC____,      FR_LCBR, FR_RCBR,   UC(LQUOTATION), UC(RQUOTATION), KC____,
  KC____, KC____,      KC____,    KC____,  KC____,
  KC____, KC____,

  KC____,
  KC____, KC____, KC____
),

/* Keymap: Char2 Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |  ESC |      |Search|   ?  |      |      |           |      |   ~  |  _   |   *  | F11  | F12  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  Cut | Copy | Past |   !  |      |------|           |------|   \  |  |   |   /  |   =  |   $  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   ;  | Undo | Redo |   :  |      |      |           |      |      |  &   |   %  |   #  |   @  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[LY_CH_2] = LAYOUT_ergodox(
  // left hand
  KC____, KC____,     KC____,     KC____,     KC____,   KC____, KC____,
  KC____, KC_ESC,     KC____,     LCTL(KC_F), FR_QUES,  KC____, KC____,
  KC____, LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), FR_EXLM,  KC____,
  KC____, FR_SCLN,    LCTL(FR_Z), LCTL(KC_Y), FR_COLN,  KC____, KC____,
  KC____, KC____, KC____, KC____, KC____,
                                               KC____, KC____,
                                                        KC____,
                                      KC____, KC____, KC____,
  // right hand
  KC____, KC____,   KC____,  KC____,      KC____,   KC____, KC____,
  KC____, FR_TILD,  FR_UNDS, FR_ASTR,     KC_F11,   KC_F12, KC____,
          FR_BSLS,  FR_PIPE, KC_KP_SLASH, KC_EQL,   FR_DLR,  KC____,
  KC____, KC____,   FR_AMP,  FR_PERC,     FR_HASH,  FR_AT,  KC____,
  KC____, KC____,   KC____,  KC____,      KC____,
  KC____, KC____,
  KC____,
  KC____, KC____, KC____
),

/* Keymap 2: Numbers Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      | LyOut|      |      |      |           |      |   *  |   7  |   8  |   9  |   /  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------|   +  |   4  |   5  |   6  |   -  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |   =  |   1  |   2  |   3  |   %  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |   0  |   .  |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[LY_NUMB] = LAYOUT_ergodox(
  // left hand
  KC____, KC_F1,  KC_F2,  KC_F3,       KC_F4,  KC_F5,  KC_F6,
  KC____, KC____, KC____, TG(LY_NUMB), KC____, KC____, KC____,
  KC____, KC____, KC____, KC____,      KC____, KC____,
  KC____, KC____, KC____, KC____,      KC____, KC____, KC____,
  KC____, KC____, KC____, KC____,      KC____,
                                               KC____, KC____,
                                                       KC____,
                                       KC____, KC____, KC____,
  // right hand
  KC_F7,  KC_F8,   KC_F9, KC_F10,  KC_F11, KC_F12,      KC____,
  KC____, FR_ASTR, FR_7,  FR_8,    FR_9,   KC_KP_SLASH, KC____,
          FR_PLUS, FR_4,  FR_5,    FR_6,   FR_MINS,     KC____,
  KC____, FR_EQL,  FR_1,  FR_2,    FR_3,   FR_PERC,     KC____,
                   FR_0,  FR_DOT,  KC____, KC____,      KC____,
  KC____, KC____,
  KC____,
  KC____, KC____, KC____
),

/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | WhUp | MsUp | WhDwn|      |      |           |      |      |      |LyOut |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |Cclk  |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      | Cclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 | Lclk | Rclk |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */ // KC_MS_WH_UP KC_MS_WH_DOWN  Cclik=>KC_BTN3
[LY_MOUSE] = LAYOUT_ergodox(
  // left handtmk_core
  KC____, KC____, KC____,     KC____, KC____,       KC____, KC____,
  KC____, KC____, KC_MS_WH_UP, KC_MS_U, KC_MS_WH_DOWN, KC____, KC____,
  KC____, KC____, KC_MS_L,     KC_MS_D, KC_MS_R,       KC____,
  KC____, KC____, KC____,     KC____, KC____,       KC_BTN3, KC____,
  KC____, KC____, KC____,     KC____, KC_BTN3,
                                               KC____, KC____,
                                                        KC____,
                                      KC_BTN1, KC_BTN2, KC____,
  // right hand
  KC____, KC____, KC____, KC____, KC____, KC____, KC____,
  KC____, KC____, KC____, TG(LY_MOUSE), KC____, KC____, KC____,
           KC____, KC____, KC____, KC____, KC____, KC_MPLY,
  KC____, KC____, KC____, KC_MPRV, KC_MNXT, KC____, KC____,
                    KC_VOLU, KC_VOLD, KC_MUTE, KC____, KC____,
  KC____, KC____,
  KC____,
  KC____, KC____, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(LY_NUMB)                // FN1 - Momentary Layer 1 (Symbols)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COPY:
      if (record->event.pressed) {
        // simple copy: LCTL(KC_C)
        // here, we want copy if fast press, Maj+copy if long press (shell copy)

      }
    case EPRM:
      if (record->event.pressed) {
        SEND_STRING ("pressed");
        // Do something when pressed
      } else {
        SEND_STRING ("release");
        // Do something else when release
      }
      return false; // Skip all further processing of this key
    case HEHE:
      // SEND_STRING ("^.^"); // display 6:66...
      if (record->event.pressed) {
        register_code(FR_CIRC);
        unregister_code(FR_CIRC);
        register_code(KC_SPC);
        unregister_code(KC_SPC);

        // FR_DOT:
        register_code(KC_LSFT);
        register_code(FR_SCLN);
        unregister_code(FR_SCLN);
        unregister_code(KC_LSFT);

        register_code(FR_CIRC);
        unregister_code(FR_CIRC);
        register_code(KC_SPC);
        unregister_code(KC_SPC);
      }
      return false;
    // case KC_ENTER:
    //   if (record->event.pressed) {
    //   }
    //   return true; // Let QMK send the enter press/release events
    default:
      return true; // Process all other keycodes normally
  }
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    set_unicode_input_mode(UC_LNX);
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  // ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
    // layer is in binary mode, from right to left: 011 => L3 => midle and right light ON
      case 0:
        break;
      case 1:
        // ergodox_right_led_3_on();
        break;
      case 2:
        // ergodox_right_led_2_on();
        break;
      case 3:
        // ergodox_right_led_2_on();
        // ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 8:
        // ergodox_right_led_3_on();
        break;
      default:
        break;
    }

  return state;
};
