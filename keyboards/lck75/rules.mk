# MCU name
MCU = atmega32a

# Processor frequency
F_CPU = 16000000

# Bootloader selection
BOOTLOADER = usbasploader

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = lite     # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no        # Console for debug
COMMAND_ENABLE = no        # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no            # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
UNICODE_ENABLE = yes
OLED_ENABLE = yes
OLED_DRIVER = SSD1306
ENCODER_ENABLE = yes
WPM_ENABLE = yes
LTO_ENABLE = no
AUTO_SHIFT_ENABLE = no
