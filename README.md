## AAL
 - projekt
Autor: Przemys³aw Bede³ek

Nazwa projektu: AAL-6-LS vururuk
Jêzyk implementacji: C++
Treœæ zadania:
W wiosce plemienia Vururuk co 10 lat odbywaj¹ siê masowe œluby ma³¿eñskie.
Wszystkie pe³noletnie panny i pe³noletni kawalerowie stawiaj¹ siê przed rad¹ starszych, 
która dokonuje swatania w sposób zgodny z wielowiekow¹ tradycj¹ plemienia. 
Po pierwsze, m¹¿ musi mieæ wiêkszy wzrost i wiêkszy obwód g³owy ni¿ ¿ony. 
Po drugie, ka¿da panna i ka¿dy kawaler musi znaleŸæ ma³¿onka. 
Po trzecie, ³¹czna suma ró¿nic wzrostów i obwodów g³ów ma³¿onków w ca³ym plemieniu 
ma byæ jak najmniejsza. W przypadku niemo¿noœci spe³nienia dwóch pierwszych warunków, 
proces swatania koñczy siê niepowodzeniem i jest odraczany na nastêpne 10 lat. 
Nale¿y pomóc radzie starszych przeprowadziæ proces swatania.

#Uruchamianie programu:
1. Sklonuj repozytorium i pobierz cmake(co najmniej wersja 3.7.2).
2. W folderze z pobranym repozytorium wywo³aj komendy:
	cmake ./
	make
3. Nastêpnie aby uruchomiæ program nale¿y wpisaæ:
	./AAL

#Dzia³anie programu:
Algorytm mo¿na uruchomiæ w trzech trybach. Po uruchamieniu programu u¿ytkownik zostanie
poproszony o wybór jednego z trzech trybów wykonania:
	1.wg danych dostarczonych ze strumienia wejœciowego (standardowego lub pliku) dla sekwencji 
	konkretnych problemów; ten tryb pozwala testowaæ poprawnoœci dla ma³ych instancji
	2.wg  danych  generowanych  automatycznie(losowo)z ewentualn¹  parametryzacj¹
	generacji okreœlan¹ przezu¿ytkownik; ten tryb tak¿e s³u¿y do testowania poprawnoœci  
	3.wykonanie z generacj¹ danych, pomiarem czasu i prezentacj¹ wyników pomiarów

Po zgromadzeniu danych wejœciowych stworzy graf dwudzielny, w którym jednym zbiorem wierzcho³ków
bêdzie zbiór mê¿czyzn, a drugim zbiór kobiet. Nastêpnie za pomoc¹ algorytmu Hopcrofta-Karpa zostanie
znalezione maksymalne skojarzenie w tym grafie, które odpowiada sparowaniu kobiet i mê¿czyzn z plemienia
w ma³¿eñstwa.

Na sam koniec zostanie zaprezentowana informacja, o tym czy uda³o siê sparowaæ wszystkich cz³onków
plemienia, ile par uda³o sie "zeswataæ" i czasy wykonania poszczególnych czêœci algorytmu.

#Opis plików Ÿród³owych:
	AAL.cpp, AAL.h - plik zawieraj¹cy funkcjê main programu, w której jest zawarta ca³a
	komunikacja z u¿ytkownikiem odnoœnie wyboru trybu wykonania i prezentacja wyników
	Graph.cpp, Graph.h - pliki zawieraj¹c¹ klasê grafu dwudzielnego i algorytmu Hopcrofta-Karpa.
	Person.cpp - plik zawieraj¹cy klasê osoby, która zawiera pola: p³eæ, wzrost, obwód g³owy, indeks.
	Node.cpp, Node.h, RankingTree.cpp, RankingTree.h - nieu¿ywane - pliki zawieraj¹ce implementacjê drzewa obs³uguj¹cego
	zapytania odnoœnie rangi mê¿czyzn wzglêdem kobiet.

#Konwencja zapisu danych w pliki
W pierwszym trybie wykonania program odczytuje dane z plików "males.txt" i "females.txt", które znajduj¹
siê w tym samym folderze co AAL.cpp. Ka¿da osoba jest reprezentowana w pliku zgodnie z poni¿sz¹ konwencj¹:

wzrost1 obwod1
wzrost2 obwod2

#Inne informacje
 - wzrost i obwód g³owy s¹ uznawane za liczby naturalne
 - wzrosty i obwody g³ów w 2. i 3. trybie wykonania s¹ losowane zgodnie z rozk³adem normalnym.
 - graf dwudzielny jest reprezentowany poprzez macierz nXn int-ów, gdzie n to liczba osób jednej p³ci.
   Ten fakt powoduje, ¿e dla n>15000 mo¿e zabrakn¹æ pamiêci w zale¿noœci od mo¿liwoœci maszyny, na której
   jest uruchamiany program.
 


