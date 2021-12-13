#include <iostream>
#include <omp.h>

int main()
{

//#pragma omp parallel
//#pragma omp single
//#pragma omp master
#pragma omp critical
	std::cout << "Witaj z watku nr " << omp_get_thread_num()// omp_get_thread_num()		<--- zwraca numer w�tku
		<< " sposrod " << omp_get_num_threads() << "\n"; //omp_get_num_threads()		<--- zwraca liczb� w�tk�w
}



// Zadanie 1.1
//
// Wynik dzia�ania programu jest taki sam, poniewa� konstrukcja #pragma omp parallel domy�lnie
// uruchamia zesp� w�tk�w wykonyj�cy identyczne instrukcje, kt�re si� mieszaj�.



// Zadanie 1.2
//
// Komunikaty wy�wietlane przez program wchodz� sobie w drog� przez b��dy wsp�bie�no�ci - Data Races, kt�re
// mog� by� spowodowane uzyskaniem dost�pu do tej samej lokalizacji pami�ci przez niezsynchronizowane w�tki,
// w tym samym czasie.



// Zadanie 2
//
// (#pragma omp single) : wyszczeg�lnienie bloku kodu, kt�ry b�dzie przetwarzany przez tylko jeden w�tek, z barier� na ko�cu.
//
// Wady:
// - praca pojedy�czego w�tku jest znacznie d�u�sza ni� gdyby by� wykonywany przez wszystkie w�tki. 
//
// Zalety:
// - wi�ksza kontrola nad poprawno�ci� wykonanego polecenia prez w�tek.



// (#pragma omp master) :  wyszczeg�lnienie bloku kodu, kt�ry b�dzie przetwarzany przez tylko jeden w�tek - w�tek g��wny, bez bariery na ko�cu w przeciwie�stwie do single. 
//		Inne w�tki pomijaj� ten fragment kodu.
//
// Wady:
// - 
//
// Zalety:
// - w�tki inne ni� w�tek g��wny nie b�d� wykonywa� bloku instrukcji skojarzonego z t� konstrukcj� i kontynuuj� wykonywanie kodu dalej.



// (#pragma omp critical) : dany blok instrukcji ma by� wykonany jednocze�nie przez tylko jeden w�tek w danym czasie, a nie jednocze�cie przez kilka. 
//		Inne w�tki b�d� wstrzymane do czasu opuszczenia bloku przez zajmuj�cy blok w�tek (tzw. bariera). 
//
// Wady:
// - wszystkie konstrukcje krytyczne bez nazwy maj� t� sam� nieokre�lon� nazw�.
//
// Zalety:
// -  ochrona wsp�dzielonych danych przed b��dnym stanem tj. przed Data Races.
// -  uniemo�liwia wielu w�tkom dost�p do sekcji krytycznej, dzi�ki czemu tylko jeden aktywny w�tek mo�e aktualizowa� dane.

