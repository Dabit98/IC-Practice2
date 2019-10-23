
CC=g++
COREFLAGS= -I$(IDIR) -std=c++11
CFLAGS= $(COREFLAGS) -Ofast

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

#crea un opt seguro (lento)
secure_opt.exe: $(OOBJ)
		$(CC) -o $@ $^ $(COREFLAGS)



#crea data_gen
data_gen.exe: $(DGOBJ)
	$(CC) -o $@ $^ $(CFLAGS)

#make run: muestra los resultados
run: opt.exe $(PDIR)/index.p
	./opt.exe "results.sol" $(PDIR)/index.p

secure_run: secure_opt.exe $(PDIR)/index.p
	./secure_opt.exe "secure_results.sol" $(PDIR)/index.p
#make test: ejecuta las pruebas especificadas en sizes.test
test: opt.exe data_gen.exe
	./test.sh

diff: run secure_run
	#ANY TEXT BELLOW THE NEXT LINE IS A DIFFERENCE BETWEEN THE ALGORITHMS
	diff "secure_results.sol" "results.sol"

#copia los problemas permanentes
$(PDIR)/index.p: data_gen.exe $(PPDIR)/index.p
	 cp $(shell ls $(PPDIR)/*.p) $(PDIR)/

#si no hay problemas permanentes crea un indice vacio
$(PPDIR)/index.p:
	touch $@

.PHONY: clean, cleanProblems, run, secure_run, test, diff

clean: cleanProblems
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ *.exe *.sol

cleanProblems:
	rm -f $(PDIR)/*.p
