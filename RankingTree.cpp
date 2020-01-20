//Autor: Przemys³aw Bede³ek

//Nazwa projektu: AAL-6-LS vururuk
#include "RankingTree.h"
#include <iostream>
#include <vector>

using namespace std;
void RankingTree::createRankTree(vector<Person> males)
{
	if (!males.empty())
	{
		head = new Node();
		head = head->createNode(males);
		std::cout << "Finished";
	}
}

list<int> RankingTree::findMales(Person female,Node* node)
{
	if (node == NULL)
		return	list<int>();
	if (female.height > node->median)
		return findMales(female, node->leftChild);
	else
	{
		list<int> males = findMales(female, node->rightChild);
		if (males.empty()) {
			males.merge(checkLeftMales(female, node));
			return males;
		}
		else
			return checkLeftMales(female, node);
	}
	
}
list<int> RankingTree::checkLeftMales(Person female, Node* leftNode) {
	list<int> fittingMales;
	if (leftNode->sortedLeftHalf.empty())
		return fittingMales;
	for (int i = 0; i <leftNode->sortedLeftHalf.size() ; i++)
	{
		if (leftNode->sortedLeftHalf[i].width > female.width)
			fittingMales.push_back(leftNode->sortedLeftHalf[i].index);
		else
			return fittingMales;
	}
}

