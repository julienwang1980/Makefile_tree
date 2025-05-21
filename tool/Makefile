#子Makefile：用来告诉make如何生成当前目录下的子目标

SRCS = serial.c timer.c
SUB_DIR = 

LD ?= $(CC)

#下面的规则，说明了如何生成当前目录下的子目标（是由当前目录下的.c生成的.o和当前目录下的子目录下的子目标临时打包生成的）
$(SUB_TGT): $(SRCS:.c=.o) $(SUB_DIR)	#(SRCS:.c=.o)表示SRCS.c生成的.o
	$(LD) $(LDFLAGS) $(SRCS:.c=.o) $(SUB_DIR:=/$(SUB_TGT)) -r -o $@
	
%.o: %.c
	$(CC) $(CFLAGS) $< -c
	@echo '$$* = ' $*
	@echo '$$? = ' $?

#下面的这个模式规则中的$@.$$$$是当前这条进程执行过程中，临时产生的一个文件，之后对这个文件进行替换，替换完毕之后，删除这个临时的文件
%.d: %.c
	$(CC) $(CFLAGS) $< -MM > $@.$$$$; \
		sed 's/$*.o: /$*.o $*.d: /' $@.$$$$ > $@; \
	rm -vf $@.$$$$

sinclude $(SRCS:.c=.d)

$(SUB_DIR):
	make -C $@
	
clean:
	rm -vf $(SUB_TGT) $(SRCS:.c=.o) $(SRCS:.c=.d)
ifneq ($(strip $(SUB_DIR)),)
	for dir in $(SUB_DIR); do \
		make -C $$dir clean; \
	done
endif

.PHONY: clean $(SUB_DIR)
