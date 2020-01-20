// AAL.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
//Autor: Przemysław Bedełek

//Nazwa projektu: AAL-6-LS vururuk

#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <chrono>
#include "Person.h"
#include "Graph.h"
#include "Params.h"
#include "AAL.h"
#include <fstream>
#include <cstdio>


using namespace std::chrono;

int main()
{
	vector<Person> males, females;
	Params params;
	int mode;
	for (bool breakLoop = false;!breakLoop;)
	{
		breakLoop = true;
		mode = chooseMode();
		if (mode > 3 || mode < 1)
			breakLoop = false;
	}

		
	switch (mode) 
	{
		case 1:
			execMode1(males, females, params);
			break;
		case 2:
			execMode2(males, females, params);
			break;
		case 3: 
			execMode3(males, females, params);
			break;		
	}
	if (females.size() != males.size())
	{
		cout << "Liczba kobiet i mezczyzn nie jest rowna. Nie da sie polaczyc par.";
		return -1;

	}
	
	auto rngStop = chrono::high_resolution_clock::now();

	Graph graph = Graph();
	graph.createGraph(females, males);

	auto graphStop = chrono::high_resolution_clock::now();
	
	int result = graph.hopcroftKarp();
	if (result == params.peopleCount)
		cout << "Udalo sie polaczyc wszystkie pary" << endl;
	else
		cout << "Nie udalo sie polaczyc wszystkich osob w pary" << endl;
	cout << "Liczba stworzonych par" << result << endl;
	auto hopcroftKarpStop = chrono::high_resolution_clock::now();
	
	
	auto graphDuration = duration_cast<microseconds>(graphStop - rngStop);
	auto algDuration = duration_cast<microseconds>(hopcroftKarpStop - graphStop);
	
	cout << "Graph time: " << graphDuration.count() << endl;
	cout << "Hopcroft-Karp time: " << algDuration.count() << endl;
	}
	
int chooseMode() {
	int mode;
	cout << "Program AAL - plemienie Vururuk, Autor - Przemyslaw Bedelek" << endl;
	cout << "Wybierz sposob uruchomienia:" << endl << endl;
	cout << "1 - odczyt danych z pliku" << endl;
	cout << "2 - dane generowane losowo, parametry wybierane przez uzytkownika" << endl;
	cout << "3 - dane i parametry generowane losowo" << endl;
	cin >> mode;
	if (mode > 3 || mode < 1)
		mode = 3;
	return mode;
}
void execMode1(vector<Person>& males, vector<Person>& females,Params& params) {
	int a, b;
	int i = 0;
	ifstream malesFile,femalesFile;
	malesFile.open("males.txt");
	femalesFile.open("females.txt");
	if(!malesFile || !femalesFile ) {
		cerr << "Unable to open file datafile.txt";
		exit(1);
	}
	while (malesFile >> a >> b)
	{
		males.push_back(Person(a, b, i++));
		
	}
	i = 0;
	malesFile.close();
	while (femalesFile >> a >> b)
	{
		females.push_back(Person(a, b, i++));

	}
	
	femalesFile.close();
	params = Params(females.size());
	

}
void execMode2(vector<Person>& males, vector<Person>& females, Params& params) {
	int peopleCount,mHeight,mWidth,fHeight,fWidth;
	cout << "Wprowadz liczbe kobiet i mezczyzn: ";
	cin >> peopleCount;
	cout << "Wprowadz sredni wzrost mezczyzny: ";
	cin >> mHeight;
	cout << "Wprowadz sredni obwod glowy mezczyzny: ";
	cin >> mWidth;
	cout << "Wprowadz sredni wzrost kobiety: ";
	cin >> fHeight;
	cout << "Wprowadz sredni obwod glowy kobiety: ";
	cin >> fWidth;

	params = Params(peopleCount, mHeight, mWidth, fHeight, fWidth);
	populateVectors(males, females, params);
	
	

}
void execMode3(vector<Person>& males, vector<Person>& females, Params& params) {
	int peopleCount;
	cout << "Wprowadz liczbe kobiet i mezczyzn: ";

	cin >> peopleCount;
	params = Params(peopleCount);
	populateVectors(males, females, params);
	

}

void populateVectors(vector<Person>& males, vector<Person>& females, Params& params)
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);
	normal_distribution<float> maleHeightDistr(params.maleHeight, params.heightStandDiviation);
	normal_distribution<float> maleWidthDistr(params.maleWidth, params.widthStandDiviation);
	normal_distribution<float> femaleHeightDistr(params.femaleHeight, params.heightStandDiviation);
	normal_distribution<float> femaleWidthDistr(params.femaleWidth, params.widthStandDiviation);

	for (int i = 0; i < params.peopleCount; i++)
	{
		int mHeight = static_cast<int>(maleHeightDistr(generator));
		int mWidth = static_cast<int>(maleWidthDistr(generator));
		int fHeight = static_cast<int>(femaleHeightDistr(generator));
		int fWidth = static_cast<int>(femaleWidthDistr(generator));

		males.push_back(Person(mHeight, mWidth, i + 1));
		females.push_back(Person(fHeight, fWidth, i + 1));

	}
}


