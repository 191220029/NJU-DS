#pragma once
template<class T>
class LinearList {
public:
	LinearList();//����
	~LinearList();//����
	virtual int Size()const = 0;//���������
	virtual int length()const = 0;//�����
	virtual int Search(T& x)const = 0;//�ڱ�������x
	virtual int Locate(int i)const = 0;//�ڱ��ж�λ��i��Ԫ�ص�λ��
	virtual bool getData(int i, T& x)const = 0;//ȡ��i�������ֵ
	virtual void setData(int i, T& x)const = 0;//�޸ĵ�i�������ֵΪx
	virtual bool Insert(int i, T& x)const = 0;//�ڵ�i����������x
	virtual int Remove(int i, T& x)const = 0;//ɾ����i������,ͨ��x����
	virtual bool IsEmpty()const = 0;//�жϱ��
	virtual bool IsFull()const = 0;//�жϱ���
	virtual void sort()const = 0;//����
	virtual void input()const = 0;//����
	virtual void output()const = 0;//���
	virtual LinearList<T> opearator = (LinearList<T> & L) = 0;//����
};