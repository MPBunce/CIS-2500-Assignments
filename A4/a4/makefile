A4:	testA4.o	queueFunctions.o	miscFunctions.o	helper.o
	gcc	-Wall	-std=c99	testA4.o	queueFunctions.o	miscFunctions.o	helper.o	-o	A4
testA4.o:	testA4.c	headerA4.h
	gcc	-Wall	-std=c99	-c	testA4.c
queueFunctions.o:	queueFunctions.c	headerA4.h
	gcc	-Wall	-std=c99	-c	queueFunctions.c
miscFunctions.o:	miscFunctions.c	headerA4.h
	gcc	-Wall	-std=c99	-c	miscFunctions.c
helper.o:	helper.c	headerA4.h
	gcc	-Wall	-std=c99	-c	helper.c
clean:
	rm*.o	A4
