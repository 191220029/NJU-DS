#include"heap.h"
#include<iostream>
using namespace std;

static const int DefaultSize = 10000;

template <class E>
MinHeap<E>::MinHeap(int sz) {
    maxHeapSize = (DefaultSize < sz) ?
        sz : DefaultSize;
    heap = new E[maxHeapSize];  	//创建堆空间
    if (heap == NULL) {
        cerr << "堆存储分配失败！" << endl;  exit(1);
    }
    currentSize = 0;				//建立当前大小
};

template <class E>
MinHeap<E>::MinHeap(E arr[], int n) {
    maxHeapSize = (DefaultSize < n) ? n : DefaultSize;
    heap = new E[maxHeapSize];
    if (heap == NULL) {
        cerr << "堆存储分配失败！" << endl;  exit(1);
    }
    for (int i = 0; i < n; i++) heap[i] = arr[i];
    currentSize = n;	       //复制堆数组, 建立当前大小
    int currentPos = (currentSize - 2) / 2;
    //找最初调整位置:最后分支结点
    while (currentPos >= 0) {	    //逐步向上扩大堆
        siftDown(currentPos, currentSize - 1);
        //局部自上向下下滑调整
        currentPos--;
    }
};

template <class E>
void MinHeap<E>::siftDown(int start, int m) {
    //私有函数: 从结点start开始到m为止, 自上向下比较, 
    //如果子女的值小于父结点的值,  则关键码小的上浮, 
    //继续向下层比较, 将一个集合局部调整为最小堆。
    int i = start, j = 2 * i + 1;  	//j是i的左子女位置
    E temp = heap[i];
    while (j <= m) {			//检查是否到最后位置
        if (j < m && heap[j] > heap[j + 1]) j++;
        //让j指向两子女中的小者
        if (temp <= heap[j]) break;	//小则不做调整
        else { heap[i] = heap[j];  i = j; j = 2 * j + 1; }
        //否则小者上移, i, j下降
    }
    heap[i] = temp;	      	//回放temp中暂存的元素
};

//每次插入都加在堆的最后，再自下向上执行调整，使之重新形成堆，时间复杂性O(log2n)。
template <class E>
bool MinHeap<E>::Insert(const E& x) {
    //公共函数: 将x插入到最小堆中
    if (currentSize == maxHeapSize) 	//堆满
    {
        cerr << "Heap Full" << endl;  return false;
    }
    heap[currentSize] = x;  		//插入
    siftUp(currentSize);			//向上调整
    currentSize++;				//堆计数加1
    return true;
};


template <class E>
void MinHeap<E>::siftUp(int start) {
    //私有函数: 从结点start开始到结点0为止, 自下向上
    //比较, 如果子女的值小于父结点的值, 则相互交换, 
    //这样将集合重新调整为最小堆。关键码比较符<=
    //在E中定义。
    int j = start, i = (j - 1) / 2;   E temp = heap[j];
    while (j > 0) {		//沿父结点路径向上直达根
        if (heap[i] <= temp) break;							//父结点值小, 不调整
        else { heap[j] = heap[i];  j = i;  i = (i - 1) / 2; }
        //父结点结点值大, 调整
    }
    heap[j] = temp;				//回送
};

template <class E>
bool MinHeap<E>::Remove(E& x) {
    if (!currentSize) {		//堆空, 返回false
        cout << "Heap empty" << endl;  return false;
    }
    x = heap[0];
    heap[0] = heap[currentSize - 1];
    currentSize--;
    siftDown(0, currentSize - 1);    	//自上向下调整为堆
    return true;			//返回最小元素
};
