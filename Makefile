CC = g++
CFLAGS = -Wall
INC = -I inc
LIB =  
LINK = -lPocoFoundation -lPocoNet
SRC = main.cpp

all: main

main: 
	$(CC) $(CFLAGS) $(INC) -o pocoservertest $(SRC) $(DEPS) $(LIB) $(LINK)

clean:
	rm main main.o 
