#CC=arm-linux-gnueabihf-gcc
CC=gcc
CFLAGS= -Wall -fPIC

all:  OBJ static_lib dynamic_lib main_fun

OBJ:
	$(CC) $(CFLAGS) -c foo.c

static_lib:
	ar rcs libfoo.a foo.o

dynamic_lib:
	$(CC) $(CFLAGS) --shared -o libfoo.so.1.0 foo.o
	ln -sf libctest.so.1.0 libctest.so
	ln -sf libctest.so.1.0 libctest.so.1
main_fun:
	$(CC) $(CFLAGS) -L. -lfoo -ldl -o main main.c

clean:
	rm *.so *.o *.a *.0 *.1 main
