CC=gcc

CFLAGS= -I. 
LIBS = -lm 

EXE=find_anom
DEPS=Makefile structs.h
OBJ=analyze.o purchase.o initialize.o user.o read_files.o stack.o list.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(DEFINES) $(CPPFLAGS) $(LDFLAGS)

all: $(OBJ)
	$(CC) -o $(EXE) $^ $(CFLAGS) $(LIBS) $(CPPFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	rm -f *.o

realclean:
	rm -f *.o $(EXE)
