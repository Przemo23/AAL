//Autor: Przemys³aw Bede³ek

//Nazwa projektu: AAL-6-LS vururuk
#pragma once
#include "Person.h"
#include <vector>
#include "Node.h"
#include <algorithm>

using namespace std;

float Node::calcMedian(vector<Person> males)
{
	vector<float> maleHeights;
	for (auto male : males)
		maleHeights.push_back(male.height);
	sort(maleHeights.begin(),maleHeights.end());
	if (maleHeights.size() % 2 == 1)
		return maleHeights[maleHeights.size()/ 2];
	else
		return (maleHeights[(maleHeights.size()-1) / 2 + 1] + maleHeights[(maleHeights.size()-1) / 2]) / 2;

}

void Node::createSortY(vector<Person> leftCollection)
{
	if (leftCollection.empty())
		return;
	for (Person male : leftCollection) {
		if (sortedLeftHalf.empty())
			sortedLeftHalf.push_back(male);
		else {
			insertBinarySort(male, 0, sortedLeftHalf.size() - 1);
		}
	}
}
void Node::insertBinarySort(Person male, int l, int r) {
	if (r >= l) {
		int mid = l + ((r -l) / 2);
		if (sortedLeftHalf[mid].width == male.width) {
			sortedLeftHalf.insert(sortedLeftHalf.begin() + mid, male);
			return;
		}
		if (r == l) {
			if(sortedLeftHalf[mid].width > male.width)
				sortedLeftHalf.insert(sortedLeftHalf.begin() + r+1, male);
			else
				sortedLeftHalf.insert(sortedLeftHalf.begin() + r, male);
			return;
		}
		if (sortedLeftHalf[mid].width > male.width)
			return insertBinarySort(male,mid == l? mid +1:mid,r);
		return insertBinarySort(male, l, mid);
	}
	sortedLeftHalf.insert(sortedLeftHalf.begin() + r, male);
}



void Node::splitMales(vector<Person> males, vector<Person> &leftCollection, vector<Person> &rightCollection)
{
	int equalToMedian = 0;
	for (Person male : males) {
		if (male.height == median) {
			equalToMedian % 2 == 0 ? rightCollection.push_back(male) : leftCollection.push_back(male);
			equalToMedian++;
		}
		else if (male.height < median)
			rightCollection.push_back(male);
		else
			leftCollection.push_back(male);
	}
}
void Node::copyVectorToList() {
	for (Person male : sortedLeftHalf) {
		sortedLeftHalfList.push_back(male);
	}
}

Node* Node::createNode(vector<Person> males) {
	Node* newNode = new Node();
	newNode->median = calcMedian(males);
	vector<Person> leftCollection, rightCollection;
	newNode->splitMales(males, leftCollection, rightCollection);
	newNode->createSortY(leftCollection);
	if (males.size() == 1)
		return newNode;
	if (!leftCollection.empty())
		newNode->leftChild = newNode->createNode(leftCollection);
	if (!rightCollection.empty())
		newNode->rightChild = newNode->createNode(rightCollection);

	vector<Person>().swap(leftCollection);
	vector<Person>().swap(rightCollection);
	return newNode;
};


