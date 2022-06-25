#pragma once
template <class Name, class Attribute>
class Dictionary {
    //对象: 一组<名字-属性>对, 其中, 名字是唯一的
public:
    Dictionary(int size = DefaultSize);      //构造函数
    bool Member(Name name);
    //判name是否在字典中
    Attribute* Search(Name name);
    //在字典中搜索关键码与name匹配的表项 
    void Insert(Name name, Attribute attr);
    //若name在字典中, 则修改相应<name, attr>对
    //的attr项; 否则插入<name, attr>到字典中
    void Remove(Name name);
    //若name在字典中, 则在字典中删除相应的
    //<name, attr>对
};

const int defaultSize = 50;
template <class K, class E>
class SortedList : public SeqList {
public:
    int Search(K k1) const;			     //搜索
    void Insert(const K k1, E& e1);	     //插入，
    bool Remove(const K k1, E& e1);	     //删除
    int BinarySearch(K k1) const;
    int BinarySearch(K k1, const int low, const int high) const;

};

template <class K, class E>
int SortedList<K, E>::Search(K k1) const {
    //顺序搜索关键码为k1的数据对象
    int n = last + 1;
    for (int i = 1; i <= n; i++)
        if (data[i - 1] == k1) return i;         //成功
        else if (data[i - 1] > k1) break;
    return 0;       //顺序搜索失败, 返回失败信息
};

template<class K, class E>
int SortedList<K, E>::BinarySearch
(K k1, const int low, const int high) const {
    //折半搜索的递归算法，用到E的重载操作“<”和“>”
    int mid = 0;		        //元素序号从0开始
    if (low <= high) {
        mid = (low + high) / 2;
        if (data[mid] < k1)
            mid = BinarySearch(k1, mid + 1, high);
        else if (data[mid] > k1)
            mid = BinarySearch(k1, low, mid - 1);
        else return mid;
    }
    return 0;
};

template<class K, class E>
int SortedList <K, E>::BinarySearch(K k1) const {
    //折半搜索的迭代算法，用到K的重载操作“<”和“>” 
    int high = n - 1, low = 0, mid;    //元素序号从0开始	      
    while (low <= high) {
        mid = (low + high) / 2;
        if (data[mid] < k1) low = mid + 1;
        //右缩搜索区间	 
        else if (data[mid] > k1) high = mid - 1;
        //左缩搜索区间
        else return mid;                 //搜索成功
    }
    return 0;                                  //搜索失败
}

