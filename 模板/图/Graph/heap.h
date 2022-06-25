#pragma once

template <class E>
class MinHeap {
public:
    MinHeap(int sz = DefaultSize);	//构造函数
    MinHeap(E arr[], int n);		//构造函数
    ~MinHeap() { delete[] heap; }	//析构函数
    bool Insert(const E& x);			//插入
    bool Remove(E& x);			//删除
    bool IsEmpty() const		//判堆空否
    {
        return  currentSize == 0;
    }
    bool IsFull() const		//判堆满否
    {
        return currentSize == maxHeapSize;
    }
    void MakeEmpty() { currentSize = 0; }	//置空堆
private:
    E* heap;			//最小堆元素存储数组
    int currentSize;		//最小堆当前元素个数
    int maxHeapSize;	//最小堆最大容量
    void siftDown(int start, int m);	//调整算法
    void siftUp(int start);		          //调整算法
};

