#ifndef DDXX_AVLTREE_H
#define DDXX_AVLTREE_H
#include <iostream>
#include <queue>
using namespace std;
template<typename Type>
class AVLTree
{
	struct Node
	{
		Type e;
		Node* left;
		Node* right;
		int h;
		Node(Type _e) :e(_e), left(NULL), right(NULL), h(0) {}
		Node(Type _e, Node* _left, Node* _right, int _h) :e(e), left(_left), right(_right), h(_h) {}
	};
public:
	AVLTree();
	AVLTree(Type arr[], int nLength);
	//AVLTree(const AVLTree& right);
	//AVLTree& operator=(const AVLTree& right);
	~AVLTree();
public:
	bool	insert(Type e, Node*& p);
	void	erase(Type e, Node*& p);
	Node*& find(Type e)const;
	void	traverse(Node* p)const;
	void	traverseByLevel(Node* p)const;
	int		getLength() { return mLength; }
	Node*& getParent(Node* p);
	Node*& getRoot() { return mRoot; } //notice the return type
	bool	empty() { return mRoot == NULL; };
	void	clear();
	void	clears(Node*& p);
private:
	void	rotateLeft(Node*& k2);
	void	rotateRight(Node*& k2);
	void	rotateLeftDouble(Node*& p);
	void	rotateRightDouble(Node*& p);
	int		height(Node* p)const { return p == NULL ? -1 : p->h; }
	int		max(int x, int y) { return x > y ? x : y; }
private:
	Node* mRoot;
	int mLength;

};
template<typename Type> AVLTree<Type>::AVLTree() :mRoot(NULL), mLength(0)
{
}

template<typename Type> AVLTree<Type>::AVLTree(Type arr[], int nLength) : mRoot(NULL), mLength(0)
{
	for (int i = 0; i < nLength; i++)
	{
		insert(arr[i], mRoot);
	}
}

template<typename Type> AVLTree<Type>::~AVLTree()
{
	clears(mRoot);
}
template<typename Type> bool AVLTree<Type>::insert(Type e, Node*& p)
{
	if (p == NULL)
	{
		p = new Node(e);
		mLength++;
	}
	else if (e < p->e)
	{
		insert(e, p->left);
		if (height(p->left) - height(p->right) == 2)
		{
			if (e < p->left->e)
				rotateLeft(p);
			else
				rotateLeftDouble(p);
		}
	}
	else if (e > p->e)
	{
		insert(e, p->right);
		if (height(p->left) - height(p->right) == -2)
		{
			if (e > p->right->e)
				rotateRight(p);
			else
				rotateRightDouble(p);
		}
	}
	else // e ia already exist
	{
		//return false;
	}
	p->h = max(height(p->left), height(p->right)) + 1;
	return true;
}

template<typename Type> void AVLTree<Type>::rotateLeft(Node*& k2)
{
	Node* k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;

	k1->h = max(height(k1->left), height(k1->right)) + 1;
	k2->h = max(height(k2->left), height(k2->right)) + 1;
	k2 = k1;// join the original node
}

template<typename Type> void AVLTree<Type>::rotateRight(Node*& k2)
{
	Node* k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;

	k1->h = max(height(k1->left), height(k1->right)) + 1;
	k2->h = max(height(k2->left), height(k2->right)) + 1;
	//k1=k2，因为在insert函数中传入的是p->left或者p->right的引用，所以这里能把根结点赋给其父结点的子节点
	k2 = k1;
}

template<typename Type> void AVLTree<Type>::rotateLeftDouble(Node*& k3)
{
	rotateRight(k3->left);
	rotateLeft(k3);
}
template<typename Type> void AVLTree<Type>::rotateRightDouble(Node*& k3)
{
	rotateLeft(k3->right);
	rotateRight(k3);
}

template<typename Type> void AVLTree<Type>::traverse(Node* p)const
{
	if (p == NULL)
		return;
	else
	{
		traverse(p->left);
		cout << "element:" << p->e << endl; //traverse by mid
		traverse(p->right);
	}
}

template<typename Type> void AVLTree<Type>::traverseByLevel(Node* root)const
{
	if (root == NULL)
	{
		cout << "The tree is empty" << endl;
		return;
	}
	queue<Node*> que;
	que.push(root);
	while (!que.empty())
	{
		Node* ptr = que.front();
		que.pop();
		cout << "element:" << ptr->e << "	th:" << height(ptr->left) - height(ptr->right) << endl;
		if (ptr->left != NULL)
			que.push(ptr->left);
		if (ptr->right != NULL)
			que.push(ptr->right);
	}
}

template<typename Type> typename AVLTree<Type>::Node*& AVLTree<Type>::getParent(Node* p)
{
	if (p == mRoot)
		return NULL;
	Node* ptr = mRoot;
	Node* ptf = ptr;
	while (ptr != NULL)
	{
		if (ptr->e == p->e)
			return ptf;
		if (ptr->e > p->e)
		{
			ptf = ptr;
			ptr = ptr->leftChild;
		}
		else
		{
			ptf = ptr;
			ptr = ptr->rightChild;
		}
	}
}

template<typename Type> typename AVLTree<Type>::Node*& AVLTree<Type>::find(Type e)const
{
	Node* ptr = mRoot;

	while (ptr != NULL)
	{
		if (ptr->e == e)
			return ptr;
		if (ptr->e > e)
			ptr = ptr->leftChild;
		else
			ptr = ptr->rightChild;
	}
	//if ( ptr == NULL )  
	return NULL;
}

template<typename Type> void AVLTree<Type>::clears(Node*& p)
{
	if (p == NULL)
		return;
	else
	{
		clears(p->left);
		clears(p->right);
		delete p;
		p = NULL;
		mLength--;
	}
}

template<typename Type> void AVLTree<Type>::clear()
{
	clears(mRoot);
}

template<typename Type> void AVLTree<Type>::erase(Type e, Node*& p)
{
	if (p == NULL)
		return;
	if (e > p->e)
	{
		erase(e, p->right);
		if (height(p->left) - height(p->right) == 2)
		{
			if (height(p->left->left) > height(p->left->right))
				rotateLeft(p);
			else
				rotateLeftDouble(p);
		}
	}
	else if (e < p->e)
	{
		erase(e, p->left);
		if (height(p->left) - height(p->right) == -2)
		{
			if (height(p->right->right) > height(p->right->left))
				rotateRight(p);
			else
				rotateRightDouble(p);
		}
	}
	else if (e == p->e && p->left != NULL && p->right != NULL)
	{
		Node* pmax = p->left;
		while (pmax->right != NULL)
		{
			pmax = pmax->right;
		}
		p->e = pmax->e;
		erase(p->e, p->left);
	}
	else //最终的删除会在这里执行
	{
		Node* pNew = p->left == NULL ? p->right : p->left;
		delete p;
		p = pNew;
		mLength--;
	}
	if (p != NULL)
		p->h = max(height(p->left), height(p->right)) + 1;
}
#endif#pragma once
