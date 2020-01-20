//Autor: Przemys³aw Bede³ek

//Nazwa projektu: AAL-6-LS vururuk
#pragma once
#include <vector>
#include <list>
#include "Person.h"
#include "RankingTree.h"

using namespace std;
class Graph
{
	public:
		vector<list<int>> adjacencyList;		
		int *fMatch, *mMatch, *distance;
		int gSize;
		RankingTree rankingTree;

		void createGraph(vector<Person>, vector<Person>);
		int hopcroftKarp();
	private:
		bool bfs();
		bool dfs(int);

		void setSource(int);
		//void setEdges(vector<int>, vector<int>);
		void setFemaleEdges(vector<Person>, vector<Person>);
		void setFemaleEdges2(vector<Person> females, vector<Person> males);
		void setMaleEdges(int);

		
};

