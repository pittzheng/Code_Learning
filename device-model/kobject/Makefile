obj-m := kobj-example.o
obj-m += kobject-example.o
KDIR := /lib/modules/$(shell uname -r)/build

.PHONY: all clean install

all:
	make -C $(KDIR) M=$(PWD) modules
clean:
	rm -fr *.ko *.o *.mod.o *.mod.c *.symvers *.order .kobj-example* .tmp_versions .kobject-example*
