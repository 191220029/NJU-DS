#pragma once
#include <assert.h>
#include <iostream>

template <class E>
class Queue {
public:
    Queue() { };	      //构造函数
    ~Queue() { };	      //析构函数
    virtual bool EnQueue(E x) = 0;           //进队列
    virtual bool DeQueue(E& x) = 0;	      //出队列
    virtual bool getFront(E& x) = 0;	      //取队头  
    virtual bool IsEmpty() const = 0;	      //判队列空
    virtual bool IsFull() const = 0;	      //判队列满
};


template <class E>
class SeqQueue : public Queue<E> {	   //队列类定义
protected:
    int rear, front;		       //队尾与队头指针
    E* elements;		       //队列存放数组
    int maxSize;		       //队列最大容量
public:
    SeqQueue(int sz = 10);    //构造函数    
    ~SeqQueue() { delete[] elements; }  //析构函数
    bool EnQueue(E x);         //新元素进队列
    bool DeQueue(E& x);      //退出队头元素
    bool getFront(E& x);	      //取队头元素值
    void MakeEmpty() { front = rear = 0; }
    int IsEmpty() const { return front == rear; }
    int IsFull() const
    {
        return (rear + 1) % maxSize == front;
    }

    int getSize() const
    {
        if (rear >= front)
            return rear - front;
        else return maxSize - (front - rear);
    }
};


