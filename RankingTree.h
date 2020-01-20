
//Autor: Przemys³aw Bede³ek

//Nazwa projektu: AAL-6-LS vururuk#pragma once
#include <vector>
#include "Person.h"
#include "Node.h"
#include <list>

using namespace std;
class RankingTree {
	public:
		RankingTree() { head = NULL; }
		void createRankTree(vector<Person>);
		
		list<int> findMales(Person,Node*);
		list<int> checkLeftMales(Person female, Node* leftNode);
		Node* head;
		
	private:
		
		

};