#pragma once
#include "Person.h"
#include <vector>
#include <list>

using namespace std;
class Node {
	public:
		Node() {
			leftChild = NULL;
			rightChild = NULL;
			median = 0.0f;
		};
		Node* createNode(vector<Person>);
		float median;
		Node* leftChild;
		Node* rightChild;
		vector<Person> sortedLeftHalf;
		list<Person> sortedLeftHalfList;
	private:
		//Node* parent;
		
		
		float calcMedian(vector<Person>);
		void createSortY(vector<Person>);
		void insertBinarySort(Person male, int l, int r);
		void splitMales(vector<Person>, vector<Person>&, vector<Person>&);

		void copyVectorToList();
		

};