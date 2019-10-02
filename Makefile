
CC=g++
CFLAGS= -I$(IDIR) -std=c++11

IDIR =include
ODIR =obj
SDIR =src
PDIR =problems

_DEPS = problem.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_DGOBJ = data_gen.o problem.o
DGOBJ = $(patsubst %,$(ODIR)/%,$(_DGOBJ))
_OOJB = opt.o problem.o
OOBJ = $(patsubst %,$(ODIR)/%,$(_OOBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

solutions.sol: opt.exe data_gen.exe
	#./data_gen.exe 4 4 4
	./opt.exe $@ $(shell ls problems/*.p)

opt.exe: $(ODIR)/opt.o $(ODIR)/problem.o
	$(CC) -o $@ $^ $(CFLAGS)

data_gen.exe: $(ODIR)/data_gen.o $(ODIR)/problem.o
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ $(PDIR)/*.p *.exe *.sol
