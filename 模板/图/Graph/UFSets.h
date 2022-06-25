#pragma once
static const int DefaultSizeU = 10000;
class UFSets {	//集合中的各个子集合互不相交
public:
    UFSets(int sz = DefaultSizeU);	//构造函数
    ~UFSets() { delete[]parent; }	//析构函数
    UFSets& operator = (UFSets& R);    //集合赋值
    void Union(int Root1, int Root2);	     //子集合并
    int Find(int x);				//查找x的根
    void WeightedUnion(int Root1, int Root2);
    //改进例程:加权的合并算法
private:
    int* parent;		  //集合元素数组(双亲表示)
    int size;			  //集合元素的数目
};


