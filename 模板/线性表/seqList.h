#pragma once
#include <iostream>	       //定义在“seqList.h”中
#include <stdlib.h>
#include  "linearList.h"
const int defaultSize = 100;
template < class E>
class SeqList : public LinearList<E> {
protected:
	E* data;		     //存放数组
	int maxSize;	     //最大可容纳表项的项数
	int last;		     //当前已存表项的最后位置
	void reSize(int newSize);	//改变数组空间大小
public:
	SeqList(int sz = defaultSize);          //构造函数
	SeqList(SeqList<E>& L);	           //复制构造函数
	～SeqList() { delete[] data; }	           //析构函数
	int Size() const { return maxSize; }	 //求表最大容量
	int Length() const { return last + 1; }  //计算表长度
	int Search(E& x) const;
	//搜索x在表中位置，函数返回表项序号
	int Locate(int i) const;
	//定位第 i 个表项，函数返回表项序号
	bool getData(int i, E& x) const;  //取第i个表项的值
	bool Insert(int i, E x);			//插入
	bool Remove(int i, E& x);		//删除
};
