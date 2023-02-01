CC = gcc

OBJECTS = list.o test_list.o

CFLAGS = -c -Wall

RM = rm -f

EXEC = List_Exec

List_Exec: $(OBJECTS)
	$(CC) $(OBJECTS) -o List_Exec

test_list.o: test_list.c list.h
	$(CC) -c test_list.c

list.o: list.c list.h
	$(CC) -c list.c

clean: $(RM) $(OBJECTS) $(EXEC)


