INCLUE_DIR	:= /home/user/Documents/CSC310/assignment2
CC			:= g++
CFLAGS		:= -I$(INCLUE_DIR)

OBJS		:= binaryFile.o customErrorClass.o

excBinaryFile: main.cpp $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

binaryFile.o: binaryFile.cpp binaryFile.h customErrorClass.o
	$(CC) -c -o $@ $< $(CFLAGS)

customErrorClass.o: customErrorClass.cpp customErrorClass.h
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm *.o excBinaryFile