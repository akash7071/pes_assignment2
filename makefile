make:
	gcc -Wall -Werror  main.c cbfifo.c test_cbfifo.c llfifo.c test_llfifo.c  -o main
