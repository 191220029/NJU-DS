#include"UFSets.h"

UFSets::UFSets(int sz) {
    //构造函数：sz 是集合元素个数，双亲数组的范围
    //为parent[0]～parent[size-1]。
    size = sz;			  //集合元素个数
    parent = new int[size];  //创建双亲数组
    for (int i = 0; i < size; i++) parent[i] = -1;
    //每个自成单元素集合
};

int UFSets::Find(int x) {
    //函数搜索并返回包含元素x的树的根。
    if (parent[x] < 0) return x;   //根的parent[]值小于0  
    else return (Find(parent[x]));
};

void UFSets ::WeightedUnion(int Root1, int Root2) {
    //按Union的加权规则改进的算法
    int temp = parent[Root1] + parent[Root2];
    if (parent[Root2] < parent[Root1]) {
        parent[Root1] = Root2;     //Root2中结点数多
        parent[Root2] = temp;      //Root1指向Root2
    }
    else {
        parent[Root2] = Root1;    //Root1中结点数多
        parent[Root1] = temp;      //Root2指向Root1
    }
};
