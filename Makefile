INCLUDE_DIRS 	:= /home/timothy.sereda/AdvDataStruct/CSC310-Final-Project/
CC				:= g++
CFLAGS			:= -I$(INCLUDE_DIRS)

OBJS			:= main.o binaryFile.o customErrorClass.o
DEPS			:= binaryFile.h customErrorClass.h

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

excBinaryFile: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o binaryFile