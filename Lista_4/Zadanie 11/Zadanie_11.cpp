#include <iostream>
#include <omp.h>

int main()
{

//#pragma omp parallel
//#pragma omp single
//#pragma omp master
#pragma omp critical
	std::cout << "Witaj z watku nr " << omp_get_thread_num()// omp_get_thread_num()		<--- zwraca numer w¹tku
		<< " sposrod " << omp_get_num_threads() << "\n"; //omp_get_num_threads()		<--- zwraca liczbê w¹tków
}



// Zadanie 1.1
//
// Wynik dzia³ania programu jest taki sam, poniewa¿ konstrukcja #pragma omp parallel domyœlnie
// uruchamia zespó³ w¹tków wykonyj¹cy identyczne instrukcje, które siê mieszaj¹.



// Zadanie 1.2
//
// Komunikaty wyœwietlane przez program wchodz¹ sobie w drogê przez b³êdy wspó³bie¿noœci - Data Races, które
// mog¹ byæ spowodowane uzyskaniem dostêpu do tej samej lokalizacji pamiêci przez niezsynchronizowane w¹tki,
// w tym samym czasie.



// Zadanie 2
//
// (#pragma omp single) : wyszczególnienie bloku kodu, który bêdzie przetwarzany przez tylko jeden w¹tek, z barier¹ na koñcu.
//
// Wady:
// - praca pojedyñczego w¹tku jest znacznie d³u¿sza ni¿ gdyby by³ wykonywany przez wszystkie w¹tki. 
//
// Zalety:
// - wiêksza kontrola nad poprawnoœci¹ wykonanego polecenia prez w¹tek.



// (#pragma omp master) :  wyszczególnienie bloku kodu, który bêdzie przetwarzany przez tylko jeden w¹tek - w¹tek g³ówny, bez bariery na koñcu w przeciwieñstwie do single. 
//		Inne w¹tki pomijaj¹ ten fragment kodu.
//
// Wady:
// - 
//
// Zalety:
// - w¹tki inne ni¿ w¹tek g³ówny nie bêd¹ wykonywaæ bloku instrukcji skojarzonego z t¹ konstrukcj¹ i kontynuuj¹ wykonywanie kodu dalej.



// (#pragma omp critical) : dany blok instrukcji ma byæ wykonany jednoczeœnie przez tylko jeden w¹tek w danym czasie, a nie jednoczeœcie przez kilka. 
//		Inne w¹tki bêd¹ wstrzymane do czasu opuszczenia bloku przez zajmuj¹cy blok w¹tek (tzw. bariera). 
//
// Wady:
// - wszystkie konstrukcje krytyczne bez nazwy maj¹ t¹ sam¹ nieokreœlon¹ nazwê.
//
// Zalety:
// -  ochrona wspó³dzielonych danych przed b³êdnym stanem tj. przed Data Races.
// -  uniemo¿liwia wielu w¹tkom dostêp do sekcji krytycznej, dziêki czemu tylko jeden aktywny w¹tek mo¿e aktualizowaæ dane.

