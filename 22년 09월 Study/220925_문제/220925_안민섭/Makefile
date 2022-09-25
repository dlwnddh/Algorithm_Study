CC=gcc
RESULT = ssafy
result: run.o main.o
	gcc -o $(RESULT) $^
run.o : run.c
	gcc -c $^
main.o : main.c
	gcc -c $^

clean: 
	rm *.o $(RESULT)
