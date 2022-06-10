output:	main.o	iterativeFibonacci.o	recursiveFibonacci.o	iterativeOddSum.o	recursiveOddSum.o
	gcc	-Wall	-std=c99	main.o	iterativeFibonacci.o	recursiveFibonacci.o	iterativeOddSum.o	recursiveOddSum.o	-o	output
main.o:	main.c	header.h
	gcc	-Wall	-std=c99	-c	main.c
iterativeFibonacci.o:	iterativeFibonacci.c	header.h
	gcc	-Wall	-std=c99	-c	iterativeFibonacci.c
recursiveFibonacci.o:	recursiveFibonacci.c	header.h
	gcc	-Wall	-std=c99	-c	recursiveFibonacci.c
iterativeOddSum.o:	iterativeOddSum.c	header.h
	gcc	-Wall	-std=c99	-c	iterativeOddSum.c
recursiveOddSum.o:	recursiveOddSum.c	header.h
	gcc	-Wall	-std=c99	-c	recursiveOddSum.c
clean:
	rm	*.o	output
