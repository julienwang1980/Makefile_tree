#主Makefile：作用是制定规则来说明如何在当前目录下生成终极目标文件.out
#指定生成的终极目录文件
TGT = target.out
#指定子目录（生成a.out只会依赖于这些目录）
#SUB_DIR = main tst algorithm tool
SUB_DIR = main dataStructure

#指定子目标
export SUB_TGT = built-in.o

#指定当前所在目录
export TOP_DIR = $(shell pwd)
#指定头文件所在目录
export HEAD_DIR = $(TOP_DIR)/head
#CROSS_COMPILER = arm-linux-
export CC = $(CROSS_COMPILER)gcc
#指定编译选项
#export CFLAGS = -I$(HEAD_DIR) -Wall -lm
export CFLAGS = -I$(HEAD_DIR) -Wall -Wextra -MMD -MP  -lm 
#指定链接器
export LD = ld
#指定链接选项
export LDFLAGS =

#终极目标所在规则
$(TGT): $(SUB_DIR)
	$(CC) $(^:=/$(SUB_TGT)) $(CFLAGS) -o $(TGT) $(LDFLAGS) 

#下面的规则，用来告诉make，进入到生成目标文件所需要依赖的那些子目录
$(SUB_DIR):
	make -C $@
# -C选项，可以让make进入到后面指定的目录

clean:
	rm -vf $(TGT)
	for dir in $(SUB_DIR); do \
		make -C $$dir clean;\
	done
	
.PHONY: clean $(SUB_DIR)