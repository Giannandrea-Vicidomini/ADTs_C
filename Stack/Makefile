balance: Item.o stack.o client.o
	gcc Item.o stack.o client.o -o balance

Item.o: Item.c
	gcc -c Item.c

stack.o: stack.c
	gcc -c stack.c

client.o: client.c
	gcc -c client.c

clean:
	rm -f *.o

build:
	make balance
	make clean