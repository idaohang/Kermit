hermite: main.o splines.o points.o aproksymator_hermite.o gaus/libge.a
	$(CC) -o hermite  main.o splines.o points.o aproksymator_hermite.o -L gaus -l ge

aprox: main.o splines.o points.o aproksymator_na_bazie.o gaus/libge.a
	$(CC) -o aprox  main.o splines.o points.o aproksymator_na_bazie.o -L gaus -l ge

intrp: main.o splines.o points.o interpolator.o gaus/libge.a
	$(CC) -o intrp  main.o splines.o points.o interpolator.o -L gaus -l ge

prosta: main.o splines.o points.o prosta.o
	$(CC) -o prosta  main.o splines.o points.o prosta.o	

aproksymator_hermite.o: makespl.h points.h gaus/piv_ge_solver.h
	$(CC) -I gaus -c aproksymator_hermite.c

aproksymator_na_bazie.o: makespl.h points.h gaus/piv_ge_solver.h
	$(CC) -I gaus -c aproksymator_na_bazie.c

interpolator.o: makespl.h points.h gaus/piv_ge_solver.h
	$(CC) -I gaus -c interpolator.c

.PHONY: clean test

clean:
	-rm *.o hermite aprox intrp prosta

test:
	./hermite -s spl_herm_test -p test/dane.hermite -g myplot_herm_test -f 5.51 -t 5.79 -n 600