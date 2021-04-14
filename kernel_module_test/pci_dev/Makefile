#############################################################################
# Makefile for building: bsodrv.c
#############################################################################

obj-m += test_bso.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
