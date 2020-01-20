#include "Graph.h"
#include <vector>
#include <list>
#include <queue>
#include "Person.h"
#include <iostream>
#include "RankingTree.h"
#define NIL 0 
#define INF INT_MAX 

using namespace std;

void Graph::createGraph(vector<Person> females, vector<Person> males)
{
	
	gSize = females.size();
	fMatch = new int[gSize + 1];
	mMatch = new int[gSize + 1];
	distance = new int[gSize + 1];

	adjacencyList.push_back(list<int>());
	setFemaleEdges(females, males);
}
int Graph::hopcroftKarp()
{
	int result = 0;
	for (int f = 0; f <= gSize; f++)
		fMatch[f] = NIL;
	for (int m = 0; m <= gSize; m++)
		mMatch[m] = NIL;

	while (bfs())
	{
		for (int f = 1; f <= gSize; f++)
		{
			if (fMatch[f] == NIL && dfs(f))
				result++;
		}
	}
	return result;
}
bool Graph::bfs()
{
	queue<int> Q;

	for (int f = 1; f <= gSize; f++)
	{
		if (fMatch[f] == NIL)
		{
			distance[f] = 0;
			Q.push(f);
		}
		else
			distance[f] = INF;
	}
	distance[NIL] = INF;
	
	while (!Q.empty())
	{
		int f = Q.front();
		Q.pop();
		if (distance[f] < distance[NIL])
		{
			list<int>::iterator i;
			for (i = adjacencyList.at(f).begin(); i != adjacencyList.at(f).end();i++)
			{
				int m = *i;
				/*for (int i = 0; i <= gSize;i++)
				{
					cout << "distance of " << i << " " << distance[i]<<endl;
				}*/
				if (distance[mMatch[m]] == INF)
				{
					distance[mMatch[m]] = distance[f] + 1;
					Q.push(mMatch[m]);//Check this
				}
			}
		}
	}
	return(distance[NIL] != INF);
}
bool Graph::dfs(int f)
{
	if (f != NIL)
	{
		list<int>::iterator i;
		for (i = adjacencyList.at(f).begin(); i != adjacencyList.at(f).end();i++)
		{
			int m = *i;

			if (distance[mMatch[m]] == distance[f] + 1)
			{
				if (dfs(mMatch[m]) == true)
				{
					fMatch[f] = m;
					mMatch[m] = f;
					return true;
				}
			}
		}
		distance[f] = INF;
		return false;
	}
	return true;
}
void Graph::setSource(int femalesCount)
{
	list<int> sourceEdges;
	for (int i = 0; i < femalesCount; i++)
	{
		sourceEdges.push_back(i + 1);
	}
	adjacencyList.push_back(sourceEdges);
}
void Graph::setFemaleEdges(vector<Person> females, vector<Person> males)// Change it to an nlogn alg
{
	for (int i = 0; i < females.size();i++)
	{
		list<int> femaleEdges;
		for (int j = 0; j < males.size(); j++)
		{
			if (females.at(i).height < males.at(j).height && females.at(i).width < males.at(j).width)
			{
				femaleEdges.push_back(j + 1 /*+ females.size()*/);
			}
		}
		adjacencyList.push_back(femaleEdges);
	}
}
void Graph::setFemaleEdges2(vector<Person> females, vector<Person> males)
{
	rankingTree.createRankTree(males);
	for (Person female : females) {
		adjacencyList.push_back(rankingTree.findMales(female,rankingTree.head));
	}
}
void Graph::setMaleEdges(int maleCount)
{
	for (int i = 0; i < maleCount; i++)
	{
		list<int> maleEdges;
		maleEdges.push_back(1 + 2 * maleCount);
		adjacencyList.push_back(maleEdges);
	}
}
