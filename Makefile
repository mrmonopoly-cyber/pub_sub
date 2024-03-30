CXX_FLAGS= -Wall -Wextra -g -fsanitize=address

all: main 

broker: message_broker.c message_broker.h
	gcc $(FLAGS) main.c message_broker.c -o main

clean:
	rm main
