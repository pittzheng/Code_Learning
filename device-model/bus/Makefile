obj-m := scbus.o
obj-m += scdevice.o
obj-m += scbus_scdevice.o

KDIR := /lib/modules/$(shell uname -r)/build

.PHONY: all clean install

all:
	make -C $(KDIR) M=$(PWD) modules
clean:
	rm -fr *.ko *.o *.mod.o *.mod.c *.symvers *.order .scbus*
