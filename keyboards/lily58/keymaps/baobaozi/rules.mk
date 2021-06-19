# VIA_ENABLE = yes (have to turn off mousekey and RGB if you have this porker on)
EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes
# RGB_MATRIX_ENABLE = yes
ENCODER_ENABLE = yes
TAP_DANCE_ENABLE = yes

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend

# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c \
        # ./lib/rgb_state_reader.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c \
