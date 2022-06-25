
#include <iostream>
#include "AVLTree.h"
using namespace std;

void main()
{
	int Arr[9] = { 6,2,8,4,10,0,12,16,14 };
	AVLTree<int> Tr(Arr, 9);
	Tr.traverse(Tr.getRoot());
	Tr.traverseByLevel(Tr.getRoot());

	Tr.erase(14, Tr.getRoot());
	Tr.traverse(Tr.getRoot());
	Tr.traverseByLevel(Tr.getRoot());
	cout << "Tree's length is:" << Tr.getLength() << endl;
	Tr.clear();
	cout << "Tree's length is:" << Tr.getLength() << endl;

}