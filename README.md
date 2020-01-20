## AAL

Autor: Przemysław Bedełek

Nazwa projektu: AAL-6-LS vururuk
Język implementacji: C++
Treść zadania:
W wiosce plemienia Vururuk co 10 lat odbywają się masowe śluby małżeńskie.
Wszystkie pełnoletnie panny i pełnoletni kawalerowie stawiają się przed radą starszych, 
która dokonuje swatania w sposób zgodny z wielowiekową tradycją plemienia. 
Po pierwsze, mąż musi mieć większy wzrost i większy obwód głowy niż żony. 
Po drugie, każda panna i każdy kawaler musi znaleźć małżonka. 
Po trzecie, łączna suma różnic wzrostów i obwodów głów małżonków w całym plemieniu 
ma być jak najmniejsza. W przypadku niemożności spełnienia dwóch pierwszych warunków, 
proces swatania kończy się niepowodzeniem i jest odraczany na następne 10 lat. 
Należy pomóc radzie starszych przeprowadzić proces swatania.

Uruchamianie programu:
1. Sklonuj repozytorium i pobierz cmake(co najmniej wersja 3.7.2).
2. W folderze z pobranym repozytorium wywołaj komendy:
	cmake ./
	make
3. Następnie aby uruchomić program należy wpisać:
	./AAL

Działanie programu:
Algorytm można uruchomić w trzech trybach. Po uruchamieniu programu użytkownik zostanie
poproszony o wybór jednego z trzech trybów wykonania:
	1.wg danych dostarczonych ze strumienia wejściowego (standardowego lub pliku) dla sekwencji 
	konkretnych problemów; ten tryb pozwala testować poprawności dla małych instancji
	2.wg  danych  generowanych  automatycznie(losowo)z ewentualną  parametryzacją
	generacji określaną przezużytkownik; ten tryb także służy do testowania poprawności  
	3.wykonanie z generacją danych, pomiarem czasu i prezentacją wyników pomiarów

Po zgromadzeniu danych wejściowych stworzy graf dwudzielny, w którym jednym zbiorem wierzchołków
będzie zbiór mężczyzn, a drugim zbiór kobiet. Następnie za pomocą algorytmu Hopcrofta-Karpa zostanie
znalezione maksymalne skojarzenie w tym grafie, które odpowiada sparowaniu kobiet i mężczyzn z plemienia
w małżeństwa.

Na sam koniec zostanie zaprezentowana informacja, o tym czy udało się sparować wszystkich członków
plemienia, ile par udało sie "zeswatać" i czasy wykonania poszczególnych części algorytmu.

Opis plików źródłowych:
AAL.cpp, AAL.h - plik zawierający funkcję main programu, w której jest zawarta cała
komunikacja z użytkownikiem odnośnie wyboru trybu wykonania i prezentacja wyników
Graph.cpp, Graph.h - pliki zawierającą klasę grafu dwudzielnego i algorytmu Hopcrofta-Karpa.
Person.cpp - plik zawierający klasę osoby, która zawiera pola: płeć, wzrost, obwód głowy, indeks.
Node.cpp, Node.h, RankingTree.cpp, RankingTree.h - nieużywane - pliki zawierające implementację drzewa obsługującego
zapytania odnośnie rangi mężczyzn względem kobiet.
Params.h - plik zawierający klasę z parametrami losowego generowania danych

Konwencja zapisu danych w pliki
W pierwszym trybie wykonania program odczytuje dane z plików "males.txt" i "females.txt", które znajdują
się w tym samym folderze co AAL.cpp. Każda osoba jest reprezentowana w pliku zgodnie z poniższą konwencją:

wzrost1 obwod1
wzrost2 obwod2

Inne informacje
 - wzrost i obwód głowy są uznawane za liczby naturalne
 - wzrosty i obwody głów w 2. i 3. trybie wykonania są losowane zgodnie z rozkładem normalnym.
 - graf dwudzielny jest reprezentowany poprzez macierz nXn int-ów, gdzie n to liczba osób jednej płci.
   Ten fakt powoduje, że dla n>15000 może zabraknąć pamięci w zależności od możliwości maszyny, na której
   jest uruchamiany program.
 


