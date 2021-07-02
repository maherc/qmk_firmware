#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/
#undef TAPPING_TERM
#define TAPPING_TERM 200

#undef ENCODER_RESOLUTION
#define ENCODER_RESOLUTION 4

#define AUTO_SHIFT_TIMEOUT 180
#define AUTO_SHIFT_MODIFIERS
#define OLED_TIMEOUT 120000
