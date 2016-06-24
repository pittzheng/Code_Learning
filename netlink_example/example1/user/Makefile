ifdef VERBOSE
        Q =
        E = @true 
else
        Q = @
        E = @echo 
endif

CFILES := $(shell find . -mindepth 1 -maxdepth 4 -name "*.c")

INFILES := $(CFILES) $(CXXFILES)

OBJFILES := $(CFILES:%.c=%)
DEPFILES := $(CFILES:%.c=%)
OFILES := $(OBJFILES:%=obj/%.o)

BINFILE = netlink_user

COMMONFLAGS = -Wall -Wextra -pedantic
LDFLAGS =-lnl-3

ifdef DEBUG
        COMMONFLAGS := $(COMMONFLAGS) -g
endif
COMMONFLAGS +=-I/usr/include/libnl3
CFLAGS = $(COMMONFLAGS) --std=c99
DEPDIR = deps
all: $(BINFILE)
ifeq ($(MAKECMDGOALS),)
-include Makefile.dep
endif
ifneq ($(filter-out clean, $(MAKECMDGOALS)),)
-include Makefile.dep
endif

CC = gcc


-include Makefile.local

.PHONY: clean all depend
.SUFFIXES:
obj/%.o: %.c
	$(E)C-compiling $<
	$(Q)if [ ! -d `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(Q)$(CC) -o $@ -c $< $(CFLAGS)
Makefile.dep: $(CFILES) $(CXXFILES)
	$(E)Depend
	$(Q)for i in $(^); do $(CXX) $(CXXFLAGS) -MM "$${i}" -MT obj/`basename $${i%.*}`.o; done > $@

        
$(BINFILE): $(OFILES)
	$(E)Linking $@
	$(Q)$(CC) -o $@ $(OFILES) $(LDFLAGS)
clean:
	$(E)Removing files
	$(Q)rm -rf $(BINFILE) obj Makefile.dep
