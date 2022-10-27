CC=gcc
RESULT = ssafy
result: run.o main.o
	$(CC) -o $(RESULT) $^
run.o : run.c
	$(CC) -c $^
main.o : main.c
	$(CC) -c $^

clean: 
	rm *.o $(RESULT)
