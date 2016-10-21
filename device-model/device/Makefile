obj-m := scdevice.o
obj-m += ../bus/scbus.o
obj-m += ../class/scclass.o
KDIR := /lib/modules/$(shell uname -r)/build

.PHONY: all clean install

all:
	make -C $(KDIR) M=$(PWD) modules
clean:
	rm -fr *.ko *.o *.mod.o *.mod.c *.symvers *.order .scdevice* .tmp_versions
	make -C ../bus/ clean
	make -C ../class/ clean
