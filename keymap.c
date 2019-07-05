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
  DOUBLE_TAP_GRAVE,
  // UNICODE_MODE_WIN,
  // UNICODE_MODE_WINC,
  // UNICODE_MODE_LNX
};

// Unicode used with UC(STAR)  up to 0x7FFF
#define STAR 0x2605 // ★
#define APOSTR 0x2019 // ’
#define LGUILMET 0x00AB // « (not working)
#define RGUILMET 0x00BB // »
#define LYOLO  0x2E04 // ⸄
#define RYOLO 0x2E05 // ⸅
#define CHECK 0x2713 // ✓
#define LQUOTATION 0x201C // “
#define RQUOTATION 0x201D // ”
#define OE 0x0153 // œ

// used with X(STAR)  up to 0x10FFFF
// enum unicode_names {
//   SNEK,
//   STAR,
//   APOSTR,
//   LGUILMET,
//   RGUILMET,
//   LYOLO,
//   RYOLO,
//   CHECK,
//   LQUOTATION,
//   RQUOTATION,
//   OE
// };

// const uint32_t PROGMEM unicode_map[] = {
//     [SNEK]  = 0x1F40D, // 🐍
//     [STAR] = 0x2605, // ★
//     [APOSTR] = 0x2019, // ’
//     [LGUILMET] = 0x00AB, // « (not working)
//     [RGUILMET] = 0x00BB, // »
//     [LYOLO] =  0x2E04, // ⸄
//     [RYOLO] = 0x2E05, // ⸅
//     [CHECK] = 0x2713, // ✓
//     [LQUOTATION] = 0x201C, // “
//     [RQUOTATION] = 0x201D, // ”
//     [OE] = 0x0153 // œ
// };

//Tap Dance Declarations
enum tap_dance {
  TD_SEARCH_SEARCHALL = 0,
  TD_HEHE_ETC = 1
};

// FR_SCLN, UC(CHECK)
void dance_hehe_etc (qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            send_unicode_hex_string("5E 2E 5E");
            break;
        case 2:
            send_unicode_hex_string("2713");
            break;
        case 3:
            send_unicode_hex_string("0028 30CE 0CA0 75CA 0CA0 0029 30CE 5F61 253B 2501 253B");
            break;
        default:
            break;
    }
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Search, twice for Shift Search
  [TD_SEARCH_SEARCHALL] = ACTION_TAP_DANCE_DOUBLE(LCTL(KC_F), LSFT(LCTL(KC_F))),
  [TD_HEHE_ETC] = ACTION_TAP_DANCE_FN(dance_hehe_etc), // FR_SCLN, UC(CHECK)
// Other declarations would go here, separated by commas, if you have them
};


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
 *   | Down |  Up  |      | Up  |  Down |                                       | Left |Right |      |  Up  | Down |
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
  KC___,           KC_B,         FR_COMM,      LT(LY_NUMB, KC_P), SFT_T(KC_O),       FR_W,       TG(LY_GAME),
  KC_UP,           LGUI_T(FR_A), ALT_T(KC_U),  CTL_T(KC_I),       LT(LY_CH_1, KC_E), FR_M,
  KC_DOWN,         KC___,        KC_Y,         KC_X,              LT(LY_CH_2, KC_C), LCTL(KC_KP_SLASH), KC___,
  KC___,           KC___,        KC___,        KC_LEFT,           KC_RGHT,
                                                                   KC_DEL,  KC___,
                                                                            KC_HOME,
                                                    MEH_T(KC_SPC), KC_BSPC, LCA_T(KC_END),

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
  KC____, KC____,          KC____,           KC____,     KC____,  KC____,    KC____,
  KC____, TD(TD_HEHE_ETC), FR_SCLN,          FR_CIRC,    FR_EGRV, KC____,    KC____,
  KC____, FR_AGRV,         FR_UGRV,          FR_APOS,    FR_EACU, KC_CAPSLOCK,
  KC____, FR_UMLT,         DOUBLE_TAP_GRAVE, FR_QUOT,    FR_CCED, FR_EXLM,   KC____,
  KC____, KC____,          KC____,           KC____,     UC(OE),
                                               KC____, KC____,
                                                       KC____,
                                       KC____, KC____, KC____,
  // right hand
  KC____, KC____,   KC____,   KC____,   KC____,         KC____,         KC____,
  KC____, KC____,   FR_LBRC, FR_RBRC,   UC(LYOLO),       UC(RYOLO),      KC____,
          FR_EURO,  FR_LPRN, FR_RPRN,   FR_LESS,        FR_GRTR,        KC_VOLU,
  KC____, FR_QUES,  FR_LCBR, FR_RCBR,   UC(LQUOTATION),  UC(RQUOTATION), KC_VOLD,
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
  KC____, KC____,           KC____,     KC_WWW_SEARCH,           KC____, KC____, KC____,
  KC____, KC_ESC,           LCTL(KC_S), TD(TD_SEARCH_SEARCHALL), KC____, KC____, KC____,
  KC____, LCTL(KC_X),       COPY,       PAST,                    KC____, KC____,
  KC____, KC_WWW_FAVORITES, LCTL(FR_Z), LCTL(KC_Y),              KC____, KC____, KC____,
  KC____, KC____,           KC____,     KC____,                  KC____,
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
    case DOUBLE_TAP_GRAVE:
      if (record->event.pressed) {
        // double FR_GRV: `
        register_code(KC_ALGR);

        register_code(KC_7);
        unregister_code(KC_7);
        register_code(KC_7);
        unregister_code(KC_7);

        unregister_code(KC_ALGR);
      }
      return false;

    // case UNICODE_MODE_WIN:
    //   if (record->event.pressed) {
    //     set_unicode_input_mode(UC_WIN);
    //   }
    //   return false;
    // case UNICODE_MODE_WINC:
    //   if (record->event.pressed) {
    //     set_unicode_input_mode(UC_WINC);
    //   }
    //   return false;
    // case UNICODE_MODE_LNX:
    //   if (record->event.pressed) {
    //     set_unicode_input_mode(UC_LNX);
    //   }
    //   return false;

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
