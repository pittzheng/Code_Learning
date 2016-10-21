obj-m := scclass.o
obj-m += test_class.o
obj-m += test_class_scdevice.o
obj-m += test_class_parent_scdevice.o

KDIR := /lib/modules/$(shell uname -r)/build

.PHONY: all clean install

all:
	make -C $(KDIR) M=$(PWD) modules
clean:
	rm -fr *.ko *.o *.mod.o *.mod.c *.symvers *.order .scclass* .test_class* .tmp_versions
