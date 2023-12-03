/*
author: adamf
keyboard: corne 3x6
layout: colemak-dh
version: 23
*/

// TO DO:
// SCROLL   KC_LALT 
//



#include QMK_KEYBOARD_H

// MACROS ----------------------------------------------------------------------------------------------------------------------------
// defines scroll mode for ploopy trackball
enum custom_keycodes {
    SCROLL = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SCROLL:
        if (record->event.pressed) {
            // when keycode SCROLL is pressed
            tap_code(KC_NUM_LOCK);
            tap_code(KC_NUM_LOCK);
        } else {
            // when keycode SCROLL is released
            tap_code(KC_NUM_LOCK);  // experimenting with hold and release, delete this line and next if errors
            tap_code(KC_NUM_LOCK);  //
        }
        break;
    }
    return true;
};

// MAIN KEYMAP ----------------------------------------------------------------------------------------------------------------------
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_DEL,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_LALT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_MINS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCTL, KC_LSFT, KC_BTN1,  LT(1, KC_SPC), LT(2, KC_BSPC), KC_LGUI 
                                      //`--------------------------'  `--------------------------'
  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_LCBR, KC_LBRC, KC_LPRN, KC_BSLS,   KC_LT,                        KC_GT, KC_SLSH, KC_RPRN, KC_RBRC, KC_RCBR, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_PIPE,  KC_EQL, KC_PERC, KC_PLUS,  KC_DLR,                        KC_AT, KC_CIRC, KC_AMPR, KC_HASH, KC_ASTR, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    XXXXXXX, XXXXXXX, _______
                                      //`--------------------------'  `--------------------------' 
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX,                      XXXXXXX, KC_PSCR, KC_CAPS, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX,                      KC_PGUP, KC_LEFT,   KC_UP, KC_RGHT, KC_LSFT, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX,                      KC_PGDN, KC_HOME, KC_DOWN,  KC_END,  KC_APP, _______,                 
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    XXXXXXX, XXXXXXX, _______
                                      //`--------------------------'  `--------------------------'
  )
};

// COMBOS ----------------------------------------------------------------------------------------------------------------------------
enum combo_events {
    DELETE_COMBO,    // layer 1, left
    RCLICK_COMBO,  
    SCROLL_COMBO,
    VOLD_COMBO,  
    VOLU_COMBO,  
    ENTER_COMBO,  // layer 1, right
    QUES_COMBO, 
    EXLM_COMBO,  
    COMBO_LENGTH  // marks end of array
};
uint16_t COMBO_LEN = COMBO_LENGTH;   // sets combo lenth to end of array

const uint16_t PROGMEM delete_combo[] = {KC_W, KC_F, COMBO_END};    // layer 1, left
const uint16_t PROGMEM rclick_combo[] = {KC_R, KC_S, COMBO_END};  
const uint16_t PROGMEM scroll_combo[] = {KC_S, KC_T, COMBO_END}; 
const uint16_t PROGMEM vold_combo[] = {KC_X, KC_C, COMBO_END}; 
const uint16_t PROGMEM volu_combo[] = {KC_C, KC_D, COMBO_END};  
const uint16_t PROGMEM enter_combo[] = {KC_E, KC_I, COMBO_END};   // layer 1, right
const uint16_t PROGMEM ques_combo[] = {KC_H, KC_COMM, COMBO_END}; 
const uint16_t PROGMEM exlm_combo[] = {KC_COMM, KC_DOT, COMBO_END};  

combo_t key_combos[] = {
    [DELETE_COMBO] = COMBO(delete_combo, KC_DEL),       // layer 1, left
    [RCLICK_COMBO] = COMBO(rclick_combo, KC_BTN2),     
    [SCROLL_COMBO] = COMBO(scroll_combo, SCROLL), 
    [VOLD_COMBO] = COMBO(vold_combo, KC_VOLD), 
    [VOLU_COMBO] = COMBO(volu_combo, KC_VOLU), 
    [ENTER_COMBO] = COMBO(enter_combo, KC_ENT),    // layer 1, right
    [QUES_COMBO] = COMBO(ques_combo, KC_QUES), 
    [EXLM_COMBO] = COMBO(exlm_combo, KC_EXLM),  
};

// KEY OVERIDES ---------------------------------------------------------------------------------------------------------------------
const key_override_t semicolon_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCLN);
const key_override_t colon_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLN);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &semicolon_key_override,
    &colon_key_override,
    NULL
};