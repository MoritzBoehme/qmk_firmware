SRC += $(USER_PATH)/MoritzBoehme.c

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	SRC += $(USER_PATH)/tap_dances.c
endif

ifeq ($(strip $(OS_DETECTION_ENABLE)), yes)
	ifeq ($(strip $(DEFERRED_EXEC_ENABLE)), yes)
		SRC += $(USER_PATH)/os_specific.c
	endif
endif
