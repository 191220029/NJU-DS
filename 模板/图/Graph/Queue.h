#pragma once
#include <assert.h>
#include <iostream>

template <class E>
class Queue {
public:
    Queue() { };	      //���캯��
    ~Queue() { };	      //��������
    virtual bool EnQueue(E x) = 0;           //������
    virtual bool DeQueue(E& x) = 0;	      //������
    virtual bool getFront(E& x) = 0;	      //ȡ��ͷ  
    virtual bool IsEmpty() const = 0;	      //�ж��п�
    virtual bool IsFull() const = 0;	      //�ж�����
};


template <class E>
class SeqQueue : public Queue<E> {	   //�����ඨ��
protected:
    int rear, front;		       //��β���ͷָ��
    E* elements;		       //���д������
    int maxSize;		       //�����������
public:
    SeqQueue(int sz = 10);    //���캯��    
    ~SeqQueue() { delete[] elements; }  //��������
    bool EnQueue(E x);         //��Ԫ�ؽ�����
    bool DeQueue(E& x);      //�˳���ͷԪ��
    bool getFront(E& x);	      //ȡ��ͷԪ��ֵ
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


