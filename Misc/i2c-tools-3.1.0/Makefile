# I2C tools for Linux
#
# Copyright (C) 2007  Jean Delvare <khali@linux-fr.org>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.

DESTDIR	=
prefix	= /home/peiqzhen/Projects/beagleboards_linux_distribution/examples/github/BeagleBoneHomework/Homework03/i2c-tools-3.1.0/ipkg_install
bindir	= $(prefix)/bin
sbindir	= $(prefix)/sbin
mandir	= $(prefix)/share/man
man8dir	= $(mandir)/man8
incdir	= $(prefix)/include

INSTALL		:= install
INSTALL_DATA	:= $(INSTALL) -m 644
INSTALL_DIR	:= $(INSTALL) -m 755 -d
INSTALL_PROGRAM	:= $(INSTALL) -m 755
RM		:= rm -f

CC	= arm-linux-gnueabihf-gcc

#CFLAGS	?= -O2
CFLAGS	= -O2
# When debugging, use the following instead
#CFLAGS	:= -O -g
CFLAGS	+= -Wall

KERNELVERSION	:= $(shell uname -r)

.PHONY: all strip clean install uninstall

all:

EXTRA	:=
#EXTRA	+= py-smbus
SRCDIRS	:= include eeprom stub tools $(EXTRA)
include $(SRCDIRS:%=%/Module.mk)
