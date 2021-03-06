#include <stdio.h>
#include <time.h>
#include <omp.h>
int main()
{
	const int N = 1000000000;
	int i = 0;
	double sum = 0; // double zamiast float
	clock_t t0 = clock();
#pragma omp parallel for private(i) reduction(+:sum)
	for (i = N - 1; i >= 0; --i)
	{
		sum += 1.0 / (i + 1.0);
	}
	clock_t t1 = clock();
	printf("s = %g\n", sum);
	printf("t = %g\n", ((double)t1 - t0) / CLOCKS_PER_SEC);
}


//Opcja z -fopenmp:
//	
//		s = 19.0267
//		t = 3.631
//
//Opcja bez -fopenmp:
//
//		s = 18.8079
//		t = 9.62
//
//* Wersja równoległa nie daje tego samego wyniku co szeregowa.



//OMP_NUM_THREADS=1
//
//	s = 18.8079
//	t = 8.51412
//
//	real	0m8, 518s
//	user	0m8, 512s
//	sys		0m0, 004s

//s = 18.8079
//t = 8.60462
//8.60user 0.00system 0:08.60elapsed 99 % CPU(0avgtext + 0avgdata 1708maxresident)k
//0inputs + 0outputs(0major + 66minor)pagefaults 0swaps





//OMP_NUM_THREADS=2
//
//	s = 18.8079
//	t = 8.53297
//
//	real	0m8, 543s
//	user	0m8, 531s
//	sys		0m0, 006s

//s = 18.8079
//t = 8.45138
//8.44user 0.00system 0:08.45elapsed 99 % CPU(0avgtext + 0avgdata 1636maxresident)k
//0inputs + 0outputs(0major + 63minor)pagefaults 0swaps




//OMP_NUM_THREADS=4
//
//	s = 18.8079
//	t = 8.46755
//
//	real	0m8, 471s
//	user	0m8, 470s
//	sys		0m0, 000s

//s = 18.8079
//t = 8.45332
//8.45user 0.00system 0:08.45elapsed 99 % CPU(0avgtext + 0avgdata 1548maxresident)k
//0inputs + 0outputs(0major + 60minor)pagefaults 0swaps



//OMP_NUM_THREADS=8
//
//	s = 18.8079
//	t = 8.48146
//
//	real	0m8, 514s
//	user	0m8, 483s
//	sys		0m0, 001s


//s = 18.8079
//t = 8.46748
//8.46user 0.00system 0:08.47elapsed 99 % CPU(0avgtext + 0avgdata 1552maxresident)k
//0inputs + 0outputs(0major + 60minor)pagefaults 0swaps



//OMP_NUM_THREADS=16
//
//	s = 18.8079
//	t = 8.45321
//
//	real	0m8, 456s
//	user	0m8, 452s
//	sys		0m0, 004s

//s = 18.8079
//t = 8.46919
//8.47user 0.00system 0:08.47elapsed 99 % CPU(0avgtext + 0avgdata 1636maxresident)k
//0inputs + 0outputs(0major + 63minor)pagefaults 0swaps




// Kod jest napisany poprawnie, a wynik jest zawsze inny ponieważ za każdym razem z powodu dzielenia bliskich sobie liczb 'tracimy precyzję'. 

// Czas raportowany przez program funkcją clock() nie jest czasem rzeczywistym ponieważ clock zwraca ilość cykli procesora od początku programu.

//Czas ten nie nadaję się do oceny przyśpieszenia programu bo może się zdażyć że będzie on dłuższy mimo że czas rzeczywisty się skróci, gdyż clock sumuje cykle z każdego wątku.

// Fragment informacji wyświetlonych komendą /usr/bin/time o liczbie użytych wątków jest ilorazem wartości user - wartość rzeczystego czasu pracy programu, 
// a wartości real - wartości czasu jednego wątku.

