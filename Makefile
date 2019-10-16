
CC=g++
CFLAGS= -I$(IDIR) -std=c++11

IDIR  =include
ODIR  =obj
SDIR  =src
PDIR  =problems
PPDIR =permanentProblems

_DEPS = problem.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_DGOBJ = data_gen.o problem.o
DGOBJ = $(patsubst %,$(ODIR)/%,$(_DGOBJ))
_OOJB = opt.o problem.o
OOBJ = $(patsubst %,$(ODIR)/%,$(_OOBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

opt.exe: $(ODIR)/opt.o $(ODIR)/problem.o
		$(CC) -o $@ $^ $(CFLAGS)

run: opt.exe $(PDIR)/index.p
	./opt.exe $@ $(PDIR)/index.p

$(PDIR)/index.p: data_gen.exe
	 cp $(shell ls $(PPDIR)/*.p) $(PDIR)/
	./data_gen.exe $(PDIR)/index.p 4 4 4


data_gen.exe: $(ODIR)/data_gen.o $(ODIR)/problem.o
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ $(PDIR)/*.p *.exe run
