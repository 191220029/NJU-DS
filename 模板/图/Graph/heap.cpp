#include"heap.h"
#include<iostream>
using namespace std;

static const int DefaultSize = 10000;

template <class E>
MinHeap<E>::MinHeap(int sz) {
    maxHeapSize = (DefaultSize < sz) ?
        sz : DefaultSize;
    heap = new E[maxHeapSize];  	//�����ѿռ�
    if (heap == NULL) {
        cerr << "�Ѵ洢����ʧ�ܣ�" << endl;  exit(1);
    }
    currentSize = 0;				//������ǰ��С
};

template <class E>
MinHeap<E>::MinHeap(E arr[], int n) {
    maxHeapSize = (DefaultSize < n) ? n : DefaultSize;
    heap = new E[maxHeapSize];
    if (heap == NULL) {
        cerr << "�Ѵ洢����ʧ�ܣ�" << endl;  exit(1);
    }
    for (int i = 0; i < n; i++) heap[i] = arr[i];
    currentSize = n;	       //���ƶ�����, ������ǰ��С
    int currentPos = (currentSize - 2) / 2;
    //���������λ��:����֧���
    while (currentPos >= 0) {	    //�����������
        siftDown(currentPos, currentSize - 1);
        //�ֲ����������»�����
        currentPos--;
    }
};

template <class E>
void MinHeap<E>::siftDown(int start, int m) {
    //˽�к���: �ӽ��start��ʼ��mΪֹ, �������±Ƚ�, 
    //�����Ů��ֵС�ڸ�����ֵ,  ��ؼ���С���ϸ�, 
    //�������²�Ƚ�, ��һ�����Ͼֲ�����Ϊ��С�ѡ�
    int i = start, j = 2 * i + 1;  	//j��i������Ůλ��
    E temp = heap[i];
    while (j <= m) {			//����Ƿ����λ��
        if (j < m && heap[j] > heap[j + 1]) j++;
        //��jָ������Ů�е�С��
        if (temp <= heap[j]) break;	//С��������
        else { heap[i] = heap[j];  i = j; j = 2 * j + 1; }
        //����С������, i, j�½�
    }
    heap[i] = temp;	      	//�ط�temp���ݴ��Ԫ��
};

//ÿ�β��붼���ڶѵ��������������ִ�е�����ʹ֮�����γɶѣ�ʱ�临����O(log2n)��
template <class E>
bool MinHeap<E>::Insert(const E& x) {
    //��������: ��x���뵽��С����
    if (currentSize == maxHeapSize) 	//����
    {
        cerr << "Heap Full" << endl;  return false;
    }
    heap[currentSize] = x;  		//����
    siftUp(currentSize);			//���ϵ���
    currentSize++;				//�Ѽ�����1
    return true;
};


template <class E>
void MinHeap<E>::siftUp(int start) {
    //˽�к���: �ӽ��start��ʼ�����0Ϊֹ, ��������
    //�Ƚ�, �����Ů��ֵС�ڸ�����ֵ, ���໥����, 
    //�������������µ���Ϊ��С�ѡ��ؼ���ȽϷ�<=
    //��E�ж��塣
    int j = start, i = (j - 1) / 2;   E temp = heap[j];
    while (j > 0) {		//�ظ����·������ֱ���
        if (heap[i] <= temp) break;							//�����ֵС, ������
        else { heap[j] = heap[i];  j = i;  i = (i - 1) / 2; }
        //�������ֵ��, ����
    }
    heap[j] = temp;				//����
};

template <class E>
bool MinHeap<E>::Remove(E& x) {
    if (!currentSize) {		//�ѿ�, ����false
        cout << "Heap empty" << endl;  return false;
    }
    x = heap[0];
    heap[0] = heap[currentSize - 1];
    currentSize--;
    siftDown(0, currentSize - 1);    	//�������µ���Ϊ��
    return true;			//������СԪ��
};
