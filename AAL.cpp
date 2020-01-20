// AAL.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <chrono>
#include "Person.h"
#include "Graph.h"
#include "Params.h"

using namespace std::chrono;

int main()
{
	int peopleCount;
	/*cout << "Program AAL - plemienie Vururuk, Autor - Przemysław Bedełek" << endl;
	
	cout << "Wprowadź liczbę kobiet i mężczyzn: ";
	cin >> peopleCount;*/

	int runs[] = { 50000,100000 };
	for (int i = 0;i < 1;i++) {
		peopleCount = runs[i];
		for (int j = 0;j < 1;j++) {
			auto start = chrono::high_resolution_clock::now();
			vector<Person> males, females;
			Params params = Params(peopleCount);
			unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
			default_random_engine generator(seed);
			normal_distribution<float> maleHeightDistr(params.maleHeight, params.heightStandDiviation);
			normal_distribution<float> maleWidthDistr(params.maleWidth, params.widthStandDiviation);
			normal_distribution<float> femaleHeightDistr(params.femaleHeight, params.heightStandDiviation);
			normal_distribution<float> femaleWidthDistr(params.femaleWidth, params.widthStandDiviation);

			auto rngStop = chrono::high_resolution_clock::now();

			for (int i = 0; i < params.peopleCount; i++)
			{
				int mHeight = static_cast<int>(maleHeightDistr(generator));
				int mWidth = static_cast<int>(maleWidthDistr(generator));
				int fHeight = static_cast<int>(femaleHeightDistr(generator));
				int fWidth = static_cast<int>(femaleWidthDistr(generator));

				males.push_back(Person(mHeight, mWidth, i + 1));
				females.push_back(Person(fHeight, fWidth, i + 1));

			}

			Graph graph = Graph();
			graph.createGraph(females, males);

			auto graphStop = chrono::high_resolution_clock::now();
			//cout << males.size() << " " << females.size();
			/*for (int i = 0;i < graph.adjacencyList.size(); i++)
			{
				cout << "Vertex: " << i << " has an edge to :";
				for (list<int>::iterator j = graph.adjacencyList.at(i).begin(); j != graph.adjacencyList.at(i).end();j++)
				{
					cout << " " << *j;
				}
				cout << endl;

			}*/

			int diffA, diffB;
			diffA = diffB = 0;
			cout << "Result is" << graph.hopcroftKarp() << endl;
			auto hopcroftKarpStop = chrono::high_resolution_clock::now();
			/*for (int i = 1; i <= graph.gSize;i++)
			{
				cout << "female nr. " << i << " is connected to male nr. " << graph.fMatch[i] << endl;
				if(graph.fMatch[i] !=0)
					cout << "dH: " << males[graph.fMatch[i] -1].height - females[i-1].height << " dW: " << males[graph.fMatch[i] - 1].width - females[i-1].width <<
					" fH: "<< females[i - 1].height << " mH: "<< males[graph.fMatch[i] - 1].height << " fW:"<< females[i - 1].width <<" mW: " << males[graph.fMatch[i] - 1].width <<endl<<endl;
			}*/
			auto rngDuration = duration_cast<microseconds>(rngStop - start);
			auto graphDuration = duration_cast<microseconds>(graphStop - start);
			auto algDuration = duration_cast<microseconds>(hopcroftKarpStop - start);
			cout << "RNG time: " << rngDuration.count() << endl;
			cout << "Graph time: " << graphDuration.count() << endl;
			cout << "RNG time: " << algDuration.count() << endl;
		}
	}
	
}
int chooseMode() {
	cout << "Wybierz tryb wykonania:" << endl;

}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
