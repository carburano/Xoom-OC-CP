#
# Makefile for the linux kernel.
#

ifeq ($(CONFIG_MACH_STINGRAY),y)
KBUILD_CFLAGS  += $(call cc-option,-O3)
KBUILD_CFLAGS  += $(call cc-option,-ffast-math)
KBUILD_CFLAGS  += $(call cc-option,-fgraphite-identity)
KBUILD_CFLAGS  += $(call cc-option,-floop-block)
KBUILD_CFLAGS  += $(call cc-option,-floop-strip-mine)
KBUILD_CFLAGS  += $(call cc-option,-fmodulo-sched)
KBUILD_CFLAGS  += $(call cc-option,-fsched-spec-load)
KBUILD_CFLAGS  += $(call cc-option,-ftree-loop-distribution)
KBUILD_CFLAGS  += $(call cc-option,-mfloat-abi=softfp,-msoft-float)
KBUILD_CFLAGS  += $(call cc-option,-mfpu=vfpv3-d16)
KBUILD_CFLAGS  += $(call cc-option,--param l2-cache-size=1024)
KBUILD_CFLAGS  += $(call cc-option,--param l1-cache-size=32)

KBUILD_AFLAGS  += $(call as-option,-Wa$(comma)-mfloat-abi=softfp,-Wa$(comma)-msoft-float)
KBUILD_AFLAGS  += $(call as-option,-Wa$(comma)-mfpu=vfpv3-d16)

tune-y         += $(call cc-option,-mtune=cortex-a9)
tune-y         += $(call cc-option,-mcpu=cortex-a9)
tune-y         += $(call as-option,-Wa$(comma)-march=armv7-a)
tune-y         += $(call as-option,-Wa$(comma)-mcpu=cortex-a9)
endif # CONFIG_MACH_STINGRAY
