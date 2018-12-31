/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#define COMBO_COUNT 3 // to set correcly in the end ?
#define COMBO_TERM 800 // wait 4s before flooding the key that could combo

#undef TAPPING_TERM
#define TAPPING_TERM 120
// https://beta.docs.qmk.fm/features/feature_advanced_keycodes#permissive-hold
// #define PERMISSIVE_HOLD
// #define RETRO_TAPPING

// #define IGNORE_MOD_TAP_INTERRUPT


#undef MOUSEKEY_MAX_SPEED
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_MAX_SPEED         4
#define MOUSEKEY_TIME_TO_MAX       60

// save memory of unused features
#define NO_ACTION_ONESHOT
