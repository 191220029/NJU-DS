#pragma once

template <class E>
class MinHeap {
public:
    MinHeap(int sz = DefaultSize);	//���캯��
    MinHeap(E arr[], int n);		//���캯��
    ~MinHeap() { delete[] heap; }	//��������
    bool Insert(const E& x);			//����
    bool Remove(E& x);			//ɾ��
    bool IsEmpty() const		//�жѿշ�
    {
        return  currentSize == 0;
    }
    bool IsFull() const		//�ж�����
    {
        return currentSize == maxHeapSize;
    }
    void MakeEmpty() { currentSize = 0; }	//�ÿն�
private:
    E* heap;			//��С��Ԫ�ش洢����
    int currentSize;		//��С�ѵ�ǰԪ�ظ���
    int maxHeapSize;	//��С���������
    void siftDown(int start, int m);	//�����㷨
    void siftUp(int start);		          //�����㷨
};

