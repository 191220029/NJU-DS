#pragma once
#include <iostream>	       //�����ڡ�seqList.h����
#include <stdlib.h>
#include  "linearList.h"
const int defaultSize = 100;
template < class E>
class SeqList : public LinearList<E> {
protected:
	E* data;		     //�������
	int maxSize;	     //�������ɱ��������
	int last;		     //��ǰ�Ѵ��������λ��
	void reSize(int newSize);	//�ı�����ռ��С
public:
	SeqList(int sz = defaultSize);          //���캯��
	SeqList(SeqList<E>& L);	           //���ƹ��캯��
	��SeqList() { delete[] data; }	           //��������
	int Size() const { return maxSize; }	 //����������
	int Length() const { return last + 1; }  //�������
	int Search(E& x) const;
	//����x�ڱ���λ�ã��������ر������
	int Locate(int i) const;
	//��λ�� i ������������ر������
	bool getData(int i, E& x) const;  //ȡ��i�������ֵ
	bool Insert(int i, E x);			//����
	bool Remove(int i, E& x);		//ɾ��
};
