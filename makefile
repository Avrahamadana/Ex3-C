CC=gcc
OBJECTS_MAIN_SORT=iSortFunction.o
OBJECTS_MAIN_TXT_FIND=txtfind.o
FLAGS= -Wall -g -fPIC
PROGRAMS= isort txtfind

all: $(PROGRAMS)
isort: $(OBJECTS_MAIN_SORT)
	$(CC) $(FLAGS) -o isort $(OBJECTS_MAIN_SORT) -lm
iSortFunction.o: iSortFunction.c iSortFunction.h
	$(CC) $(FLAGS) -c iSortFunction.c
isort.o: iSortFunction.c iSortFunction.h 
	$(CC) $(FLAGS) -c isort.c

txtfind: $(OBJECTS_MAIN_TXT_FIND)
	$(CC) $(FLAGS) -o txtfind $(OBJECTS_MAIN_TXT_FIND) -lm
txtfind.o: txtfind.c txtFind.h 
	$(CC) $(FLAGS) -c txtfind.c

.PHONY: clean all

clean:
	rm -f *.o *.so $(PROGRAMS)
