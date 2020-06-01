SRC += baobaozi.c

NKRO_ENABLE = yes
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
EXTRAFLAGS += -flto
LEADER_ENABLE = no # leaders are pretty costly, might as well make a layer
# UNICODE_ENABLE = yes
UNICODEMAP_ENABLE = no

# CONSOLE_ENABLE = yes
# DEBUG = yes

ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
  SRC += rgb_layers.c
endif

# ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
#     SRC += rgb_matrix.c
# endif

ifeq ($(strip $(COMBO_ENABLE)), yes)
    SRC += combos.c
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
    SRC += tap_dances.c
endif

ifeq ($(strip $(UNICODEMAP_ENABLE)), yes)
  SRC += unicode.c
endif
