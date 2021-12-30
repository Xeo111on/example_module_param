KERNEL_VERSION =$(shell uname -r)

all:
	sudo apt update
	sudo apt upgrade
	sudo apt install build-essential linux-headers-$(KERNEL_VERSION)
	sudo apt install terminator
	sudo apt install vim
