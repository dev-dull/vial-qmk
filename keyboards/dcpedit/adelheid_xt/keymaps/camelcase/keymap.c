/* Copyright 2021 dcpedit
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#define ANIM_SIZE 512
#define SPLIT_SIZE 128

enum adelheid_layers {
  _BASE,
  _SECONDARY
};

#define MO_SEC MO(_SECONDARY)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_HELP, KC_EXEC,      KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_MUTE,      KC_PSCR, KC_SCRL, KC_PAUS,      KC_MUTE, KC_VOLD, KC_VOLU, KC_SLEP,
    KC_STOP, KC_AGIN,      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,         KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC,      KC_INS,  KC_HOME, KC_PGUP,      KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
    KC_MENU, KC_UNDO,      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,      KC_DEL,  KC_END,  KC_PGDN,      KC_P7,   KC_P8,   KC_P9,   _______,
    KC_CUT,  KC_COPY,      KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,                                       KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
    KC_SLCT, KC_PSTE,      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         MO_SEC,  KC_N,    KC_M,    KC_COMM, KC_DOT,           KC_SLSH,          KC_RSFT,               KC_UP,                 KC_P1,   KC_P2,   KC_P3,   _______,
    KC_FIND, KC_CUT,       KC_LCTL,                   KC_LALT, KC_SPC,  KC_LGUI,               KC_SPC,  KC_RALT,                                              KC_RCTL,      KC_LEFT, KC_DOWN, KC_RGHT,      KC_P0,   _______, KC_PDOT, KC_PENT
  ),

  [_SECONDARY] = LAYOUT(
    RESET,   _______,      _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______,          _______,      _______, _______, _______,      _______, _______, _______, _______,
    _______, _______,      _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______,      _______, _______, _______, _______,
    _______, _______,      _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______,      _______, _______, _______, _______,
    _______, _______,      _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______,          _______,                                      _______, _______, _______, _______,
    _______, _______,      _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______,          _______,          _______,               _______,               _______, _______, _______, _______,
    _______, _______,      _______,                   _______, _______, _______,               _______, _______,                                              _______,      _______, _______, _______,      _______, _______, _______, _______
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
}

/*
static void render_logo(void) {
    static const char PROGMEM oled_logo[ANIM_SIZE] = {
      // 'sun_inverted', 128x32px
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x80, 0x30, 
      0x70, 0xec, 0xde, 0xbf, 0x73, 0xe6, 0xce, 0x9c, 0x38, 0x70, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe0, 0x70, 0x10, 0x18, 
      0x08, 0x08, 0x0c, 0x0c, 0x0c, 0x18, 0xf8, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0x70, 0x38, 0x9c, 0xce, 0xe7, 0x73, 0xb8, 0xdd, 0xeb, 0x67, 
      0xee, 0xdc, 0x39, 0x33, 0x37, 0x3e, 0xdd, 0xe3, 0x77, 0x3a, 0x9c, 0xce, 0xe7, 0x73, 0xb8, 0xdc, 
      0xe8, 0xe0, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x7f, 0xff, 0xf0, 0xe0, 0xc0, 
      0x80, 0x80, 0x00, 0x00, 0x00, 0x20, 0x11, 0x10, 0x08, 0x8c, 0xfc, 0xfc, 0x1c, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x80, 0xf0, 0xfc, 0x3c, 0x04, 0x00, 0x00, 0x20, 0x10, 0x08, 0x08, 0xec, 0xfc, 0xfc, 
      0x08, 0x80, 0x40, 0x20, 0x10, 0x18, 0x8c, 0xfc, 0xfc, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x1b, 0x1d, 0x4e, 0xe7, 0x73, 0xb9, 0x5c, 0xee, 
      0xc7, 0x93, 0x7c, 0xfc, 0xcc, 0x9c, 0x3b, 0x77, 0xe7, 0xd7, 0xbb, 0x1d, 0xce, 0xe7, 0x73, 0x39, 
      0x1c, 0x0e, 0x07, 0x01, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 
      0x07, 0x0f, 0xff, 0xfe, 0x7c, 0x00, 0x80, 0xe0, 0xfe, 0x7f, 0x0f, 0x01, 0x00, 0x80, 0x40, 0x30, 
      0xc8, 0xfe, 0x7f, 0x0f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf0, 0xfe, 0x3f, 0x0f, 0x06, 
      0x03, 0x00, 0x00, 0x00, 0xe0, 0xfc, 0x7f, 0x1f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0e, 
      0x1d, 0x3b, 0x77, 0xee, 0xfd, 0x7b, 0x37, 0x0e, 0x1c, 0x09, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x1f, 0x18, 0x10, 0x10, 0x10, 0x10, 0x10, 0x18, 0x08, 
      0x0c, 0x07, 0x03, 0x01, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x18, 0x0c, 0x06, 0x03, 0x01, 0x00, 0x1f, 
      0x1f, 0x1f, 0x18, 0x08, 0x04, 0x02, 0x01, 0x00, 0x10, 0x1c, 0x1f, 0x0f, 0x01, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x18, 0x08, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

    };

    oled_write_raw_P(oled_logo, ANIM_SIZE);
}
*/


static void render_locks(void) {
  static const char PROGMEM caps_lock[SPLIT_SIZE] = {
    0xfc, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x81, 0xc1, 0x61, 0x21, 0x31, 0x19, 
    0x19, 0x31, 0x21, 0x61, 0xc1, 0x81, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0xfc, 
    0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x07, 0x05, 0x06, 0xfe, 0xfe, 0x00, 0x00, 
    0x00, 0x00, 0xfe, 0xfe, 0x06, 0x05, 0x07, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 
    0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x9f, 0x98, 0x98, 
    0x98, 0x98, 0x9f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 
    0x3f, 0x40, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x8f, 0x9f, 0x99, 0x99, 
    0x99, 0x99, 0x9f, 0x8f, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x3f
  };

  static const char PROGMEM empty[SPLIT_SIZE] = {
    0xfc, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0xfc, 
    0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 
    0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 
    0x3f, 0x40, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x3f
  };

  static const char PROGMEM num_lock[SPLIT_SIZE] = {
  	0xfc, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x81, 0xe1, 0xf1, 0x39, 0x19, 0x0d, 0x0d, 
    0x0d, 0x0d, 0x19, 0x39, 0xf1, 0xe1, 0x81, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0xfc, 
    0xff, 0x00, 0x00, 0x00, 0xf0, 0xf8, 0xf8, 0xf8, 0xf8, 0xff, 0xff, 0x7f, 0x78, 0x18, 0x18, 0x78, 
    0x78, 0x18, 0x18, 0x78, 0x7f, 0xff, 0xff, 0xf8, 0xf8, 0xf8, 0xf8, 0xf0, 0x00, 0x00, 0x00, 0xff, 
    0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe6, 0xe6, 0x80, 0x80, 0xe6, 
    0xe6, 0x80, 0x80, 0xe6, 0xe6, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 
    0x3f, 0x40, 0x80, 0x80, 0x8f, 0x9f, 0x97, 0x93, 0x93, 0x93, 0x93, 0x93, 0x93, 0x93, 0x93, 0x93, 
    0x93, 0x93, 0x93, 0x93, 0x93, 0x93, 0x93, 0x93, 0x93, 0x97, 0x9f, 0x8f, 0x80, 0x80, 0x40, 0x3f
  };

  static const char PROGMEM scroll_lock[SPLIT_SIZE] = {
    0xfc, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xf1, 0xf9, 0x19, 0x19, 
    0x19, 0x19, 0xf9, 0xf1, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0xfc, 
    0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 
    0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 
    0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x0e, 0x1a, 0x36, 0x67, 0x47, 0xc0, 0x80, 
    0x80, 0xc0, 0x47, 0x67, 0x36, 0x1a, 0x0e, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 
    0x3f, 0x40, 0x80, 0x88, 0x9c, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94, 0x95, 
    0x95, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94, 0x94, 0x9c, 0x88, 0x80, 0x40, 0x3f
  };

  static const char PROGMEM xt_logo[SPLIT_SIZE] = {
    0xfc, 0x02, 0x01, 0xf1, 0x49, 0xf1, 0x01, 0xf9, 0x09, 0xf1, 0x01, 0xf9, 0x29, 0x01, 0xf9, 0x01, 
    0x01, 0xf9, 0x21, 0xf9, 0x01, 0xf9, 0x29, 0x01, 0xf9, 0x01, 0xf9, 0x09, 0xf1, 0x01, 0x02, 0xfc, 
    0xff, 0x00, 0x00, 0x71, 0xf8, 0xf9, 0xf8, 0xf1, 0xe1, 0x80, 0x80, 0xe1, 0xf1, 0xf8, 0xf9, 0xf9, 
    0x70, 0x01, 0x70, 0xf9, 0xf8, 0xf9, 0xf9, 0xf8, 0xf9, 0xf8, 0xf9, 0xf9, 0x70, 0x00, 0x00, 0xff, 
    0xff, 0x00, 0x00, 0x00, 0x81, 0xc3, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xc3, 0x81, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 
    0x3f, 0x40, 0x80, 0x8e, 0x9f, 0x9f, 0x9f, 0x8f, 0x87, 0x81, 0x81, 0x87, 0x8f, 0x9f, 0x9f, 0x9f, 
    0x8e, 0x80, 0x80, 0x80, 0x80, 0x8f, 0x9f, 0x9f, 0x9f, 0x8f, 0x80, 0x80, 0x80, 0x80, 0x40, 0x3f
  };

  static char PROGMEM rendered_image[ANIM_SIZE];
  led_t led_state = host_keyboard_led_state();
  int imgi = -1;
  const int WIDTH = 128;
  for (int i=0; i<ANIM_SIZE; i++) {
    imgi = i%32+(32*(i/128));

    if (i%WIDTH >= WIDTH-32) {
      rendered_image[i] = led_state.num_lock? num_lock[imgi] : empty[imgi];
    } else if (i%WIDTH >= WIDTH-64) {
      rendered_image[i] = led_state.scroll_lock? scroll_lock[imgi] : empty[imgi];
    } else if (i%WIDTH >= WIDTH-96) {
      rendered_image[i] = led_state.caps_lock? caps_lock[imgi] : empty[imgi];
    } else {
      rendered_image[i] = xt_logo[imgi];
    }
  }
  oled_write_raw_P(rendered_image, ANIM_SIZE);
}

bool oled_task_user(void) {
    oled_set_cursor(0,0);
    render_locks();
    return false;
}
#endif
