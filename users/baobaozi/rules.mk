SRC += baobaozi.c

NKRO_ENABLE = yes
TAP_DANCE_ENABLE = yes

# CONSOLE_ENABLE = yes
# DEBUG = yes

ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
  SRC += rgb_layers.c
endif

# ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
#   SRC += rgb_matrix.c
# endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
    SRC += tap_dances.c
endif
