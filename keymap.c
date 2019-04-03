#include QMK_KEYBOARD_H
#include "version.h"

#include "keymap_french.h"

#define BASE 0 // default layer
#define LY_CH_1 1 // char 1 layer
#define LY_CH_2 8 // char 2 layer
#define LY_NUMB 2 // symbols/numbers
#define LY_MOUSE 3 // mouse

#define LY_GAME 5
// #define LY_AZERTY 5 // azerty layer
// #define LY_QWERTY 6 // qwerty layer

#define KC___ KC_NO
#define KC____ KC_TRNS

enum custom_keycodes {
  EPRM = SAFE_RANGE, // Wiping the EEPROM (Persistent Storage)
  VRSN,
  COPY,
  PAST,
  HEHE,
  UNICODE_MODE_WIN,
  UNICODE_MODE_WINC,
  UNICODE_MODE_LNX
};

// Unicode
#define STAR 0x2605 // ★
#define APOSTR 0x2019 // ’
#define LGUILMET 0x00AB // « (not working)
#define RGUILMET 0x00BB // »
#define LYOLO  0x2E04 // ⸄
#define RYOLO 0x2E05 //
#define LQUOTATION 0x201C // “
#define RQUOTATION 0x201D // ”
#define OE 0x0153 // œ


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |      |indent|indent|      |      |      |           |      |      |      |      |      |      | PSCREEN|
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   B  |   ,  |P/Numb|O/Sft |   W  |  Ly- |           |      |   Z  |V/Sft |D/Muse|   L  |  J   |        |
 * |--------+------+------+------+------+------| Game |           |      |------+------+------+------+------+--------|
 * |  PgUp  |A/GUI |U/Alt |I/Ctrl| E/?1 |   M  |------|           |------|   K  | T/?1 |S/Ctrl| R/Alt| N/GUI|  PgUp  |
 * |--------+------+------+------+------+------|      |           |  ~Ly |------+------+------+------+------+--------|
 * |  PgDn  |      |   Y  |   X  | C/?2 | Coms |      |           | Mouse|   .  |   Q  |   G  |  H   |  F   |  PgDn  |
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
  KC_ESC,          KC___,        LSFT(KC_TAB), KC_TAB,            KC___,             KC___,      KC___,
  KC_F11,          KC_B,         FR_COMM,      LT(LY_NUMB, KC_P), SFT_T(KC_O),       FR_W,       TG(LY_GAME),
  KC_PGUP,         LGUI_T(FR_A), ALT_T(KC_U),  CTL_T(KC_I),       LT(LY_CH_1, KC_E), FR_M,
  KC_PGDN,         KC___,        KC_Y,         KC_X,              LT(LY_CH_2, KC_C), LCTL(KC_KP_SLASH), KC___,
  KC_DOWN,         KC_UP,        KC___,        KC_LEFT,           KC_RGHT,
                                                                   KC_DEL,  KC___,
                                                                            KC_HOME,
                                                           KC_SPC, KC_BSPC, KC_END,

  // right hand
  KC___,      KC___,  KC___,             KC___,              KC___,        KC___,        KC_PSCREEN,
  KC___,      FR_Z,   SFT_T(KC_V),       LT(LY_MOUSE, KC_D), KC_L,         KC_J,         KC_F11,
              KC_K,   LT(LY_CH_1, KC_T), CTL_T(KC_S),        ALT_T(KC_R),  LGUI_T(KC_N), KC_PGUP,
  KC_FN1,     FR_DOT, LT(LY_CH_2, FR_Q), KC_G,               KC_H,         KC_F,         KC_PGDN,
                      KC_UP,             KC_DOWN,            KC___,        KC_UP,        KC_DOWN,

  KC___,   KC___,
  KC_PGUP,
  KC_PGDN, KC_TAB, KC_ENT
),

/* Keymap: Char1 Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |  ^.^ |   ;  |   ^  |   è  |      |      |           |      |      |   [  |   ]  |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   à  |   ù  |   '  |   é  |VerMaj|------|           |------|   €  |   (  |   )  |   <  |   >  | vol up |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   ¨  |   `  |   "  |   ç  |   ?  |      |           |      |   !  |   {  |   }  |   “  |   ”  | vol dow|
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |   œ  |                                       |   :  |      |      |      |      |
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
  KC____, KC____,   KC____,  KC____,     KC____,  KC____,    KC____,
  KC____, HEHE,     FR_SCLN, FR_CIRC,    FR_EGRV, KC____,    KC____,
  KC____, FR_AGRV,  FR_UGRV, FR_APOS,    FR_EACU, KC_CAPSLOCK,
  KC____, FR_UMLT,  FR_GRV,  FR_QUOT,    FR_CCED, FR_QUES,   KC____,
  KC____, KC____,   KC____,  KC____,     UC(OE),
                                               KC____, KC____,
                                                       KC____,
                                       KC____, KC____, KC____,
  // right hand
  KC____, KC____,   KC____,   KC____,   KC____,         KC____,         KC____,
  KC____, KC____,   FR_LBRC, FR_RBRC,   UC(LYOLO),      UC(RYOLO),      KC____,
          FR_EURO,  FR_LPRN, FR_RPRN,   FR_LESS,        FR_GRTR,        KC_VOLU,
  KC____, FR_EXLM,  FR_LCBR, FR_RCBR,   UC(LQUOTATION), UC(RQUOTATION), KC_VOLD,
                    FR_COLN, KC____,    KC____,         KC____,         KC____,

  KC____, KC____,
  KC____,
  KC____, KC____, KC____
),

/* Keymap: Char2 Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |      |      | W sch|      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |  ESC | Save |Search|      |      |      |           |      |   ~  |  _   |   *  |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |  Cut | Copy | Past |      |      |------|           |------|   \  |  |   |   /  |   =  |   $  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |W fav | Undo | Redo |      |      |      |           |      |      |  &   |   %  |   #  |   @  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  F5  |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Brwser|Brwser|  F12 |       |      |      |      |
 *                                 |  back|  next|------|       |------|      |      |
 *                                 |      |      |  F11 |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[LY_CH_2] = LAYOUT_ergodox(
  // left hand
  KC____, KC____,           KC____,     KC_WWW_SEARCH, KC____, KC____, KC____,
  KC____, KC_ESC,           LCTL(KC_S), LCTL(KC_F),    KC____, KC____, KC____,
  KC____, LCTL(KC_X),       COPY,       PAST,          KC____, KC____,
  KC____, KC_WWW_FAVORITES, LCTL(FR_Z), LCTL(KC_Y),    KC____, KC____, KC____,
  KC____, KC____,           KC____,     KC____,        KC____,
                                                       KC_F5,  KC____,
                                                               KC_F12,
                                  KC_WWW_BACK, KC_WWW_FORWARD, KC_F11,
  // right hand
  KC____, KC____,   KC____,  KC____,      KC____,   KC____, KC____,
  KC____, FR_TILD,  FR_UNDS, FR_ASTR,     KC____,   KC____, KC____,
          FR_BSLS,  FR_PIPE, KC_KP_SLASH, KC_EQL,   FR_DLR, KC____,
  KC____, KC____,   FR_AMP,  FR_PERC,     FR_HASH,  FR_AT,  KC____,
  KC____, KC____,   KC____,  KC____,      KC____,

  KC____, KC____,
  KC____,
  KC____, KC____, KC____
),

/* Keymap: Numbers Layer
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
 *                                 |   -  |   +  |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[LY_NUMB] = LAYOUT_ergodox(
  // left hand
  KC____, KC_F1,  KC_F2,   KC_F3,       KC_F4,  KC_F5,  KC_F6,
  KC____, KC____, KC____,  TG(LY_NUMB), KC____, KC____, KC____,
  KC____, KC____, KC____,  KC____,      KC____, KC____,
  KC____, KC____, KC____,  KC____,      KC____, KC____, KC____,
  KC____, KC____, KC____,  KC____,      KC____,
                                                 KC____, KC____,
                                                         KC____,
                                       FR_MINS, FR_PLUS, KC____,
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

/* Keymap: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |  RESET |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | WhUp | MsUp | WhDwn|      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |  Ly- |------+------+------+------+------+--------|
 * |        |      |      |      |      |MdlClk|      |           |  Out |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |MdlClk|                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Lclk | Rclk |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */ // KC_MS_WH_UP KC_MS_WH_DOWN  Cclik=>KC_BTN3
[LY_MOUSE] = LAYOUT_ergodox(
  // left handtmk_core
  KC____, KC____, KC____,      KC____,  KC____,        KC____,  KC____,
  KC____, KC____, KC_MS_WH_UP, KC_MS_U, KC_MS_WH_DOWN, KC____,  KC____,
  KC____, KC____, KC_MS_L,     KC_MS_D, KC_MS_R,       KC____,
  KC____, KC____, KC____,      KC____, KC____,       KC_BTN3, KC____,
  KC____, KC____, KC____,      KC____,  KC_BTN3,
                                               KC____, KC____,
                                                        KC____,
                                      KC_BTN1, KC_BTN2, KC____,
  // right hand
  KC____,       KC____,  KC____,  KC____,  KC____,  KC____, RESET,
  KC____,       KC____,  KC____,  KC____,  KC____,  KC____, KC____,
                KC____,  KC____,  KC____,  KC____,  KC____, KC____,
  TG(LY_MOUSE), KC____,  KC____,  KC____,  KC____,  KC____, KC____,
                KC_VOLU, KC_VOLD, KC_MUTE, KC____,  KC____,
  KC____, KC____,
  KC____,
  KC____, KC____, KC____
),

/* Keymap: Game
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |Screen|   L  |  up  |   F  |A(Tab)| Ly-  |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|  Out |           |      |------+------+------+------+------+--------|
 * |        |      | left | down | right|  Tab |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   D  |  Esc | Enter|      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |   H  |   I  |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |   J  |       |      |      |      |
 *                                 |   A  |   X  |------|       |------|      |      |
 *                                 |      |      | Lock |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[LY_GAME] = LAYOUT_ergodox(
  // left handtmk_cored
  KC____,  KC____,           KC____,  KC____,     KC____,   KC____,       KC____,
  KC____,  LGUI(KC_PSCREEN), KC_L,    KC_UP,      KC_F,     LALT(KC_TAB), TG(LY_GAME),
  KC_VOLU, KC____,           KC_LEFT, KC_DOWN,    KC_RGHT,  KC_TAB,
  KC_VOLD, KC____,           KC_D,    KC_ESC,     KC_ENT,   KC____,       KC____,
  KC____,  KC____,           KC____,  KC____,     KC____,
                                            KC_H, KC_I,
                                                  KC_J,
                                      FR_A, KC_X, KC_LOCK,
  // right hand
  KC____, KC____,  KC____,  KC____,  KC____,  KC____, KC____,
  KC____, KC____,  KC____,  KC____,  KC____,  KC____, KC____,
          KC____,  KC____,  KC____,  KC____,  KC____, KC____,
  KC____, KC____,  KC____,  KC____,  KC____,  KC____, KC____,
          KC____,  KC____,  KC____,  KC____,  KC____,
  KC____, KC____,
  KC____,
  KC____, KC____, KC____
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(LY_MOUSE) // KC_FN1 : Momentary Layer if pressed and toogle if taped
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t key_timer;
  static bool is_long_press;
  switch (keycode) {
    case COPY:
      if(record->event.pressed){ // Key Down, start timer
        key_timer = timer_read();
      }
      else { // key release
        // simple copy: LCTL(KC_C)
        // here, we want copy if fast press and copy+Maj if long pressed (shell copy)
        is_long_press = timer_elapsed(key_timer) > 150;
        if(is_long_press)
          register_code(KC_LSHIFT);

        register_code(KC_LCTRL);
        register_code(KC_C);
        unregister_code(KC_C);
        unregister_code(KC_LCTRL);

        if(is_long_press)
          unregister_code(KC_LSHIFT);
      }
      return false; // Skip all further processing of this key
    case PAST:
      if(record->event.pressed){ // Key Down, start timer
        key_timer = timer_read();
      }
      else { // key release
        // here, we want past if fast press and past+Maj if long pressed (shell past)
        is_long_press = timer_elapsed(key_timer) > 150;
        if(is_long_press)
          register_code(KC_LSHIFT);

        register_code(KC_LCTRL);
        register_code(KC_V);
        unregister_code(KC_V);
        unregister_code(KC_LCTRL);

        if(is_long_press)
          unregister_code(KC_LSHIFT);
      }
      return false;
    case HEHE:
      // SEND_STRING ("^.^"); // doesn’t work
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

    case UNICODE_MODE_WIN:
      if (record->event.pressed) {
        set_unicode_input_mode(UC_WIN);
      }
      return false;
    case UNICODE_MODE_WINC:
      if (record->event.pressed) {
        set_unicode_input_mode(UC_WINC);
      }
      return false;
    case UNICODE_MODE_LNX:
      if (record->event.pressed) {
        set_unicode_input_mode(UC_LNX);
      }
      return false;

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
        // ergodox_right_led_1_on();
        break;
      case 5:
        // ergodox_right_led_1_on();
        // ergodox_right_led_3_on();
        break;
      case 6:
        // ergodox_right_led_1_on();
        // ergodox_right_led_2_on();
        break;
      case 7:
        // ergodox_right_led_1_on();
        // ergodox_right_led_2_on();
        // ergodox_right_led_3_on();
        break;
      case 8:
        // ergodox_right_led_3_on();
        break;
      default:
        break;
    }

  return state;
};
