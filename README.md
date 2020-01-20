## AAL
 - projekt
Autor: Przemys�aw Bede�ek

Nazwa projektu: AAL-6-LS vururuk
J�zyk implementacji: C++
Tre�� zadania:
W wiosce plemienia Vururuk co 10 lat odbywaj� si� masowe �luby ma��e�skie.
Wszystkie pe�noletnie panny i pe�noletni kawalerowie stawiaj� si� przed rad� starszych, 
kt�ra dokonuje swatania w spos�b zgodny z wielowiekow� tradycj� plemienia. 
Po pierwsze, m�� musi mie� wi�kszy wzrost i wi�kszy obw�d g�owy ni� �ony. 
Po drugie, ka�da panna i ka�dy kawaler musi znale�� ma��onka. 
Po trzecie, ��czna suma r�nic wzrost�w i obwod�w g��w ma��onk�w w ca�ym plemieniu 
ma by� jak najmniejsza. W przypadku niemo�no�ci spe�nienia dw�ch pierwszych warunk�w, 
proces swatania ko�czy si� niepowodzeniem i jest odraczany na nast�pne 10 lat. 
Nale�y pom�c radzie starszych przeprowadzi� proces swatania.

#Uruchamianie programu:
1. Sklonuj repozytorium i pobierz cmake(co najmniej wersja 3.7.2).
2. W folderze z pobranym repozytorium wywo�aj komendy:
	cmake ./
	make
3. Nast�pnie aby uruchomi� program nale�y wpisa�:
	./AAL

#Dzia�anie programu:
Algorytm mo�na uruchomi� w trzech trybach. Po uruchamieniu programu u�ytkownik zostanie
poproszony o wyb�r jednego z trzech tryb�w wykonania:
	1.wg danych dostarczonych ze strumienia wej�ciowego (standardowego lub pliku) dla sekwencji 
	konkretnych problem�w; ten tryb pozwala testowa� poprawno�ci dla ma�ych instancji
	2.wg  danych  generowanych  automatycznie(losowo)z ewentualn�  parametryzacj�
	generacji okre�lan� przezu�ytkownik; ten tryb tak�e s�u�y do testowania poprawno�ci  
	3.wykonanie z generacj� danych, pomiarem czasu i prezentacj� wynik�w pomiar�w

Po zgromadzeniu danych wej�ciowych stworzy graf dwudzielny, w kt�rym jednym zbiorem wierzcho�k�w
b�dzie zbi�r m�czyzn, a drugim zbi�r kobiet. Nast�pnie za pomoc� algorytmu Hopcrofta-Karpa zostanie
znalezione maksymalne skojarzenie w tym grafie, kt�re odpowiada sparowaniu kobiet i m�czyzn z plemienia
w ma��e�stwa.

Na sam koniec zostanie zaprezentowana informacja, o tym czy uda�o si� sparowa� wszystkich cz�onk�w
plemienia, ile par uda�o sie "zeswata�" i czasy wykonania poszczeg�lnych cz�ci algorytmu.

#Opis plik�w �r�d�owych:
	AAL.cpp, AAL.h - plik zawieraj�cy funkcj� main programu, w kt�rej jest zawarta ca�a
	komunikacja z u�ytkownikiem odno�nie wyboru trybu wykonania i prezentacja wynik�w
	Graph.cpp, Graph.h - pliki zawieraj�c� klas� grafu dwudzielnego i algorytmu Hopcrofta-Karpa.
	Person.cpp - plik zawieraj�cy klas� osoby, kt�ra zawiera pola: p�e�, wzrost, obw�d g�owy, indeks.
	Node.cpp, Node.h, RankingTree.cpp, RankingTree.h - nieu�ywane - pliki zawieraj�ce implementacj� drzewa obs�uguj�cego
	zapytania odno�nie rangi m�czyzn wzgl�dem kobiet.

#Konwencja zapisu danych w pliki
W pierwszym trybie wykonania program odczytuje dane z plik�w "males.txt" i "females.txt", kt�re znajduj�
si� w tym samym folderze co AAL.cpp. Ka�da osoba jest reprezentowana w pliku zgodnie z poni�sz� konwencj�:

wzrost1 obwod1
wzrost2 obwod2

#Inne informacje
 - wzrost i obw�d g�owy s� uznawane za liczby naturalne
 - wzrosty i obwody g��w w 2. i 3. trybie wykonania s� losowane zgodnie z rozk�adem normalnym.
 - graf dwudzielny jest reprezentowany poprzez macierz nXn int-�w, gdzie n to liczba os�b jednej p�ci.
   Ten fakt powoduje, �e dla n>15000 mo�e zabrakn�� pami�ci w zale�no�ci od mo�liwo�ci maszyny, na kt�rej
   jest uruchamiany program.
 


