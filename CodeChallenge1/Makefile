INCLUDE_DIRS := Includes
CC 			 := g++
CFLAGS 		 := -I$(INCLUDE_DIRS)

OBJS 		 := customErrorClass.o Sorting.o
DEPS 		 := ${INCLUDE_DIRS}\customErrorClass.h

.PHONY: clean all

all: Buus_CodeChallengeOne customErrorClass.o Sorting.o

clean:
	rm $(OBJS) Buus_CodeChallengeOne

Buus_CodeChallengeOne: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

customErrorClass.o: customErrorClass.cpp
	$(CC) -c -o $@ $(CFLAGS) $<

Sorting.o: Sorting.cpp
	$(CC) -c -o $@ $(CFLAGS) $<