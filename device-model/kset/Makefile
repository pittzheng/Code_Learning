OBJ_NAME := kset-example
obj-m := $(OBJ_NAME).o
KDIR := /lib/modules/$(shell uname -r)/build

.PHONY: all clean install

all:
	make -C $(KDIR) M=$(PWD) modules
clean:
	rm -fr *.ko *.o *.mod.o *.mod.c *.symvers *.order .kset-example* .tmp_versions
