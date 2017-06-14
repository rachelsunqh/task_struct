obj-m :=list_pro.o
	KDIR :=/lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)
all:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules -Wformat
clean:
	rm *.o *.mod.* *.ko *.gcno *.order

