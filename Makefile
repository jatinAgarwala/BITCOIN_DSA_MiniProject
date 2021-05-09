
IDIR=include
SDIR=src
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=$(SDIR)/obj
LDIR =lib

_DEPS = transaction.h user.h block.h UI.h
		
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = transaction.o user.o block.o UI.o main.o
_OBJ_TEST = transaction.o user.o block.o UI.o test.o

OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))
OBJ_TEST = $(patsubst %,$(ODIR)/%,$(_OBJ_TEST))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -g -o $@ $< $(CFLAGS)

bitcoin: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

tests: $(OBJ_TEST)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
