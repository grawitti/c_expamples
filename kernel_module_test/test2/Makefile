
obj-m += lkm_hello.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

test:
	-sudo rmmod lkm_hello.ko
	sudo dmesg -C
	sudo insmod lkm_hello.ko
	dmesg
