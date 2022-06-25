#pragma once
template<class T>
class LinearList {
public:
	LinearList();//构造
	~LinearList();//析构
	virtual int Size()const = 0;//求表最大体积
	virtual int length()const = 0;//求表长度
	virtual int Search(T& x)const = 0;//在表中搜索x
	virtual int Locate(int i)const = 0;//在表中定位第i个元素的位置
	virtual bool getData(int i, T& x)const = 0;//取第i个表项的值
	virtual void setData(int i, T& x)const = 0;//修改第i个表项的值为x
	virtual bool Insert(int i, T& x)const = 0;//在第i个表项后插入x
	virtual int Remove(int i, T& x)const = 0;//删除第i个表项,通过x返回
	virtual bool IsEmpty()const = 0;//判断表空
	virtual bool IsFull()const = 0;//判断表满
	virtual void sort()const = 0;//排序
	virtual void input()const = 0;//输入
	virtual void output()const = 0;//输出
	virtual LinearList<T> opearator = (LinearList<T> & L) = 0;//复制
};