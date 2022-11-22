OBJS = read_file.o main.o
EXEC = main

$(EXEC): $(OBJS)
	gcc -o $(EXEC) $(OBJS)
	
$(EXEC).o: main.c
	gcc -c main.c

read_file.o: read_file.c
	gcc -c read_file.c

