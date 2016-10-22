obj-m := scdriver.o
obj-m += scdevice.o
obj-m += ../bus/scbus.o

KDIR := /lib/modules/$(shell uname -r)/build

.PHONY: all clean install

all:
	make -C $(KDIR) M=$(PWD) modules
clean:
	rm -fr *.ko *.o *.mod.o *.mod.c *.symvers *.order .scdriver* .scdevice* .tmp_versions
	make -C ../bus clean
