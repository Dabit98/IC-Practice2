
CC=g++
CFLAGS= -I$(IDIR) -std=c++11

IDIR  =include
ODIR  =obj
SDIR  =src
PDIR  =problems
PPDIR =permanentProblems

_DEPS = problem.h nodo.h solution.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))


_OBJ = problem.o nodo.o solution.o
_DGOBJ = data_gen.o $(_OBJ)
DGOBJ = $(patsubst %,$(ODIR)/%,$(_DGOBJ))
_OOBJ = opt.o $(_OBJ)
OOBJ = $(patsubst %,$(ODIR)/%,$(_OOBJ))

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

opt.exe: $(OOBJ)
		$(CC) -o $@ $^ $(CFLAGS)

run: opt.exe $(PDIR)/index.p
	./opt.exe $@ $(PDIR)/index.p

$(PDIR)/index.p: data_gen.exe $(PPDIR)/index.p
	 cp $(shell ls $(PPDIR)/*.p) $(PDIR)/
	./data_gen.exe $(PDIR)/index.p 4 4 4 4

data_gen.exe: $(DGOBJ)
	$(CC) -o $@ $^ $(CFLAGS)

$(PPDIR)/index.p:
	touch $@

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ $(PDIR)/*.p *.exe run
