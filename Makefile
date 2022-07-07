.PHONY: all clean

all: 
	gcc src/main.c src/file_.c src/convert_.c -I ./inc
clean: 
	rm -rf obj/* ./a.out
