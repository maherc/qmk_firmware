#include QMK_KEYBOARD_H
#include <stdio.h>

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _COLEMAK,
    _WCOLEMAK,
    _QWERTY,
    _WQWERTY,
    _SYMBL,
    _NAV  ,
    _OTHER,
};

enum custom_keycodes {
    KC_COLEMAK = SAFE_RANGE,
    KC_WCOLEMAK,
    KC_QWERTY,
    KC_WQWERTY,
    KC_SYMBL,
    KC_NAV  ,
    KC_OTHER,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_GUI_SPC,
    KC_GUI_ENT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |SYMBL | /Enter  /       \Space \  |NAV   | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
  _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______, \
  _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______, \
  _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,     _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______, \
    KC_ASTG,  KC_LALT, KC_LCTRL, LT(_SYMBL, KC_DEL), KC_GUI_ENT,   KC_GUI_SPC,  LT(_NAV  , KC_BSPC), KC_RCTRL, KC_RALT, RGUI(KC_ESC) \
),
/*
 * WINDOWS QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |SYMBL | /Enter  /       \Space \  |NAV   | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_WQWERTY] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, \
                    _______, _______, _______, _______, KC_ENT,      KC_SPC,  _______, _______, _______, KC_RGUI \
),
/*
 * COLEMAK DH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |SYMBL | /Enter  /       \Space \  |NAV   | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_COLEMAK] = LAYOUT( \
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_BSPC, \
  KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                      KC_K,    KC_L,    KC_U,    KC_Y,    KC_SCLN,  KC_MINS, \
  KC_ESC,   KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O,  KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_D,    KC_V, KC_MUTE,      XXXXXXX,KC_J,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT, \
    KC_ASTG,  KC_LALT, KC_LCTRL, LT(_SYMBL, KC_DEL), KC_GUI_ENT,   KC_GUI_SPC,  LT(_NAV  , KC_BSPC), KC_RCTRL, KC_RALT, RGUI(KC_ESC) \
),
/*
 * WINDOWS COLEMAK DH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |SYMBL | /Enter  /       \Space \  |NAV   | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_WCOLEMAK] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______, \
                    _______, _______, _______, _______, KC_ENT,      KC_SPC,  _______, _______, _______, KC_RGUI \
),
/* SYMBL
 * ,-----------------------------------------.                    ,-----------------------------------------.  |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |SYMBL | /Enter  /       \Space \  |NAV   | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_SYMBL] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, KC_7   , KC_8   , KC_9   , XXXXXXX, XXXXXXX,\
  KC_GRV , KC_AMPR, KC_PIPE, KC_CIRC, KC_DLR , KC_LBRC,                         KC_RBRC, KC_4   , KC_5   , KC_6   , KC_MINS, KC_EQL , \
  KC_HASH, KC_EXLM, KC_AT  , KC_HASH, KC_ASTR, KC_LCBR,                         KC_RCBR, KC_1   , KC_2   , KC_3   , KC_PLUS, KC_ASTR, \
  _______, XXXXXXX, XXXXXXX, KC_LABK, KC_RABK, KC_LPRN, _______,       _______, KC_RPRN, KC_0   , KC_SCLN, KC_COLN, KC_BSLS, KC_PERC, \
                    _______, _______, _______, _______, _______,       _______, KC_OTHER,_______, _______, _______\
),
/* NAV  
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd |      | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |SYMBL | /Enter  /       \Space \  |NAV   | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NAV  ] = LAYOUT( \
  _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  _______ ,_______, \
  _______,  KC_INS,  KC_PSCR,   KC_APP,  XXXXXXX, XXXXXXX,                        KC_PGUP, KC_PRVWD,   KC_UP, KC_NXTWD, XXXXXXX, KC_BSPC, \
  _______, KC_LALT,  KC_LCTL,  KC_LSFT,  XXXXXXX, KC_CAPS,                       KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, KC_BSPC, \
  _______,KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, XXXXXXX,  _______,       _______,  XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND,   XXXXXXX, _______, \
                         _______, _______, _______, KC_OTHER, _______,       _______, _______, _______, _______, _______ \
),
/* OTHER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RESET|      |QWERTY|COLEMAK|      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |SYMBL | /Enter  /       \Space \  |NAV   | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_OTHER] = LAYOUT( \
  XXXXXXX , XXXXXXX, XXXXXXX  , XXXXXXX   , XXXXXXX, XXXXXXX,                       XXXXXXX, KC_F7  , KC_F8  , KC_F9  , XXXXXXX, XXXXXXX, \
  RESET   , KC_WQWERTY, KC_QWERTY, KC_COLEMAK, KC_WCOLEMAK, XXXXXXX,                XXXXXXX, KC_F4  , KC_F5  , KC_F6  , XXXXXXX, XXXXXXX, \
  XXXXXXX , XXXXXXX, KC_VOLD  , KC_MUTE   , KC_VOLU, XXXXXXX,                       XXXXXXX, KC_F1  , KC_F2  , KC_F3  , XXXXXXX, XXXXXXX, \
  XXXXXXX , XXXXXXX, KC_MPRV  , KC_MPLY   , KC_MNXT, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_F10 , KC_F11 , KC_F12 , XXXXXXX, XXXXXXX, \
                     _______  , _______   , _______, _______, _______,     _______, _______, _______, _______, _______ \
  )
};

#ifdef OLED_DRIVER_ENABLE

/* static void render_logo(void) { */
/*     static const char PROGMEM qmk_logo[] = { */
/*         0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94, */
/*         0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4, */
/*         0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0 */
/*     }; */
/*  */
/*     oled_write_P(qmk_logo, false); */
/* } */

/* KEYBOARD PET START */

/* settings */
#define MIN_WALK_SPEED 10
#define MIN_RUN_SPEED 40

/* advanced settings */
#define ANIM_FRAME_DURATION 200 // how long each frame lasts in ms
#define ANIM_SIZE 96 // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

/* timers */
uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;

/* current frame */
uint8_t current_frame = 0;

/* status variables */
int current_wpm = 0;
led_t led_usb_state;

bool isSneaking = false;
bool isJumping = false;
bool showedJump = true;

/* logic */
static void render_luna(int LUNA_X, int LUNA_Y) {

    /* Sit */
    static const char PROGMEM sit[2][ANIM_SIZE] = {
        /* 'sit1', 32x22px */
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c,
            0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28,
            0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        },

        /* 'sit2', 32x22px */
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c,
            0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28,
            0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        }
    };

    /* Walk */
    static const char PROGMEM walk[2][ANIM_SIZE] = {
        /* 'walk1', 32x22px */
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80,
            0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
            0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03,
            0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        },

        /* 'walk2', 32x22px */
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00,
            0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
            0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e,
            0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        }
    };

    /* Run */
    static const char PROGMEM run[2][ANIM_SIZE] = {
        /* 'run1', 32x22px */
        {
            0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
            0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01,
            0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
        },

        /* 'run2', 32x22px */
        {
            0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
            0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37,
            0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        }
    };

    /* Bark */
    static const char PROGMEM bark[2][ANIM_SIZE] = {
        /* 'bark1', 32x22px */
        {
            0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40,
            0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02,
            0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        },

        /* 'bark2', 32x22px */
        {
            0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40,
            0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02,
            0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        }
    };

    /* Sneak */
    static const char PROGMEM sneak[2][ANIM_SIZE] = {
        /* 'sneak1', 32x22px */
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04,
            0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06,
            0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
        },

        /* 'sneak2', 32x22px */
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04,
            0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04,
            0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
        }
    };

    /* animation */
    void animate_luna(void) {

        /* jump */
        if (isJumping || !showedJump) {

            /* clear */
            oled_set_cursor(LUNA_X,LUNA_Y +2);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X,LUNA_Y -1);

            showedJump = true;
        } else {

            /* clear */
            oled_set_cursor(LUNA_X,LUNA_Y -1);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X,LUNA_Y);
        }

        /* switch frame */
        current_frame = (current_frame + 1) % 2;

        /* current status */
        if(led_usb_state.caps_lock) {
            oled_write_raw_P(bark[abs(1 - current_frame)], ANIM_SIZE);

        } else if(isSneaking) {
            oled_write_raw_P(sneak[abs(1 - current_frame)], ANIM_SIZE);

        } else if(current_wpm <= MIN_WALK_SPEED) {
            oled_write_raw_P(sit[abs(1 - current_frame)], ANIM_SIZE);

        } else if(current_wpm <= MIN_RUN_SPEED) {
            oled_write_raw_P(walk[abs(1 - current_frame)], ANIM_SIZE);

        } else {
            oled_write_raw_P(run[abs(1 - current_frame)], ANIM_SIZE);
        }
    }

    /* animation timer */
    if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
        anim_timer = timer_read32();
        animate_luna();
    }

    /* this fixes the screen on and off bug */
    if (current_wpm > 0) {
        oled_on();
        anim_sleep = timer_read32();
    } else if(timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
        oled_off();
    }

}

/* KEYBOARD PET END */

static void print_keymap(void) {
    oled_set_cursor(0,0);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
            oled_write("12345", false);
            oled_write("QWFPB", false);
            oled_write("ARSTG", false);
            oled_write("ZXCDV", false);

            oled_write("     ", false);

            oled_write("67890", false);
            oled_write("KLUY;", false);
            oled_write("MNEIO", false);
            oled_write("JH,./", false);
            break;
        case _QWERTY:
            oled_write("Base ", false);
            break;
        case _NAV  :
            oled_write("Nav  ", false);
            break;
        case _SYMBL:
            oled_write("Symbl", false);
            break;
        case _OTHER:
            oled_write("Other", false);
            break;
        default:
            oled_write("Undef", false);
    }
}

static void print_status_narrow(void) {
    // Print current mode
    oled_set_cursor(0,0);
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write("QWRTY", false);
            oled_set_cursor(0,1);
            oled_write("     ", false);
            break;
        case _COLEMAK:
            oled_write("COLMK", false);
            oled_set_cursor(0,1);
            oled_write("     ", false);
            break;
        case _WQWERTY:
            oled_write("QWRTY", false);
            oled_set_cursor(0,1);
            oled_write("Win", false);
            break;
        case _WCOLEMAK:
            oled_write("COLMK", false);
            oled_set_cursor(0,1);
            oled_write("Win", false);
            break;
        default:
            oled_write("UNDEF", false);
            oled_set_cursor(0,1);
            oled_write("     ", false);
    }

    // Print current layer
    oled_set_cursor(0,3);
    oled_write("LAYER", false);

    oled_set_cursor(0,4);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
        case _QWERTY:
            oled_write("Base ", false);
            break;
        case _NAV  :
            oled_write("Nav  ", false);
            break;
        case _SYMBL:
            oled_write("Symbl", false);
            break;
        case _OTHER:
            oled_write("Other", false);
            break;
        default:
            oled_write("Undef", false);
    }

    /* oled_set_cursor(0,5); */
    /* if (keymap_config.swap_lctl_lgui) { */
    /*     oled_write("WIN  ", false); */
    /* } else { */
    /*     oled_write("LINUX", false); */
    /* } */

    /* caps lock */
    oled_set_cursor(0,7);
    led_t led_usb_state = host_keyboard_led_state();
    if (led_usb_state.caps_lock) {
        oled_write("CPSLK", true);
    } else {
        oled_write("     ", false);
    }

    char wpm_str[8];
    oled_set_cursor(0,9);
    sprintf(wpm_str, " %03d", current_wpm);
    oled_write(wpm_str, false);

    oled_set_cursor(0,10);
    oled_write(" wpm", false);

    /* KEYBOARD PET RENDER START */

    render_luna(0,13);

    /* KEYBOARD PET RENDER END */
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void oled_task_user(void) {
    /* KEYBOARD PET VARIABLES START */

    current_wpm = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

    /* KEYBOARD PET VARIABLES END */

    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        print_keymap();
        oled_set_brightness(10);
    }
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t my_hash_timer;
    static uint16_t tap_time;

    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_WQWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_WQWERTY);
            }
            return false;
        case KC_COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case KC_WCOLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_WCOLEMAK);
            }
            return false;
        case KC_SYMBL:
            if (record->event.pressed) {
                layer_on(_SYMBL);
                update_tri_layer(_SYMBL, _NAV  , _OTHER);
            } else {
                layer_off(_SYMBL);
                update_tri_layer(_SYMBL, _NAV  , _OTHER);
            }
            return false;
        case KC_NAV  :
            if (record->event.pressed) {
                layer_on(_NAV  );
                update_tri_layer(_SYMBL, _NAV  , _OTHER);
            } else {
                layer_off(_NAV  );
                update_tri_layer(_SYMBL, _NAV  , _OTHER);
            }
            return false;
        case KC_OTHER:
            if (record->event.pressed) {
                layer_on(_OTHER);
            } else {
                layer_off(_OTHER);
            }
            return false;
        case KC_GUI_SPC:
            if(record->event.pressed) {
                my_hash_timer = timer_read();
                register_code(KC_LGUI);
            } else {
                tap_time = timer_elapsed(my_hash_timer);
                unregister_code(KC_LGUI); // Change the key that was held here, too!
                if (tap_time < TAPPING_TERM) {
                    isJumping = true;
                    showedJump = false;
                    register_code(KC_SPC); // Change the character(s) to be sent on tap here
                    _delay_ms(5);
                    unregister_code(KC_SPC); // Change the character(s) to be sent on tap here
                    isJumping = false;
                }
            }
            break;
        case KC_GUI_ENT:
            if(record->event.pressed) {
                my_hash_timer = timer_read();
                register_code(KC_RGUI);
            } else {
                tap_time = timer_elapsed(my_hash_timer);
                unregister_code(KC_RGUI); // Change the key that was held here, too!
                if (tap_time < TAPPING_TERM) {
                    register_code(KC_ENT); // Change the character(s) to be sent on tap here
                    unregister_code(KC_ENT); // Change the character(s) to be sent on tap here
                }
            }
            break;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;

        /* KEYBOARD PET STATUS START */

        case KC_LCTL:
        case KC_RCTL:
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
            break;
        case KC_SPC:
            if (record->event.pressed) {
                isJumping = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;

        /* KEYBOARD PET STATUS END */
    }
    return true;
}

#ifdef ENCODER_ENABLE

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDOWN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}

#endif
