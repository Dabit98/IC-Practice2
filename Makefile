
CC=g++
CFLAGS= -I$(IDIR) -std=c++11 -Ofast

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

#make: crea opt.exe
opt.exe: $(OOBJ)
		$(CC) -o $@ $^ $(CFLAGS)

#crea data_gen
data_gen.exe: $(DGOBJ)
	$(CC) -o $@ $^ $(CFLAGS)

#make run: muestra los resultados
run: opt.exe $(PDIR)/index.p
	./opt.exe "results.sol" $(PDIR)/index.p

#make test: ejecuta las pruebas especificadas en sizes.test
test: opt.exe data_gen.exe
	./test.sh

#copia los problemas permanentes
$(PDIR)/index.p: data_gen.exe $(PPDIR)/index.p
	 cp $(shell ls $(PPDIR)/*.p) $(PDIR)/


#si no hay problemas permanentes crea un indice vacio
$(PPDIR)/index.p:
	touch $@

.PHONY: clean, cleanProblems, run, test

clean: cleanProblems
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ *.exe results.sol

cleanProblems:
	rm -f $(PDIR)/*.p
