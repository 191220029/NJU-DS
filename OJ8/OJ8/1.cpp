/*
题目描述

虽然 5G 在中国大陆已经普及，但是蓝鲸大学才刚刚通网。现在需要将 n 台计算机连接起来，一台计算机可以间接地通过其他计算机来和另一台计算机连接。由于网线的价格取决于长度，不同的两台计算机之间的连接费用可能是不同的。

由于蓝鲸大学非常穷，小蓝鲸们不得不靠嚼菜根过日子（有时候还会吃出虫子），而昂贵的布线费用无疑会成为压垮蓝鲸大学财务处的最后一根稻草。因此，校领导希望总的连接费用最省，并且任意两台计算机之间都是连通的（不管是直接还是间接的）。请你编程计算这个最小的费用。

输入描述

输入第一行为两个整数 n, m（2 <= n <= 1e5，2 <= m <= 3e5）。其中，n 表示计算机总数，m 表示可以建立的连接数。

接下来 m 行，每行三个整数 a, b, c，表示在机器 a 和机器 b 之间建立连接的费用是 c。

题目保证：
•一定存在可行的连通方案
•不存在自环（即 a = b 的情况）

友情提示：
•可能存在重边（即 a 和 b 之间可能可以建立多个连接，你应该只关注费用最小的连接）
•long long 你懂的

样例输入
3 3
1 2 1
1 3 2
2 3 1

样例输出
2
*/

/*

#include<iostream>
using namespace std;

const long long  DefaultSize = 300000;

struct Node {		//树边结点的类定义
    long long tail;
    long long head;			//两顶点位置
    long long cost;				//边上的权值
    Node() { tail = head = -1; cost = 0; }						//构造函数
};
Node heap[300000];
long long currentSize;		//最小堆当前元素个数
long long maxHeapSize;	//最小堆最大容量


void swap(Node& a, Node& b) {
    Node temp = a;
    a = b;
    b = temp;
}

void quick_sort(Node* a, int left, int right) {
    Node mid = a[(left + right) / 2];
    int i = left, j = right;
    do {
        while (a[i].cost < mid.cost) i++;
        while (a[j].cost > mid.cost) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (left < j) quick_sort(a, left, j);
    if (i < right) quick_sort(a, i, right);
}
/*

void init_MinHeap(long long sz) {
    maxHeapSize = (DefaultSize < sz) ?
        sz : DefaultSize;
    currentSize = 0;				//建立当前大小
};


void siftDown(long long start, long long m) {

    long long i = start, j = 2 * i + 1;  	//j是i的左子女位置
    Node temp = heap[i];
    while (j <= m) {			//检查是否到最后位置
        if (j < m && heap[j].cost > heap[j + 1].cost) j++;
        //让j指向两子女中的小者
        if (temp.cost <= heap[j].cost) break;	//小则不做调整
        else { heap[i] = heap[j];  i = j; j = 2 * j + 1; }
        //否则小者上移, i, j下降
    }
    heap[i] = temp;	      	//回放temp中暂存的元素
};

void siftUp(long long start) {
    //私有函数: 从结点start开始到结点0为止, 自下向上
    //比较, 如果子女的值小于父结点的值, 则相互交换,
    //这样将集合重新调整为最小堆。关键码比较符<=
    //在E中定义。
    long long j = start, i = (j - 1) / 2;   Node temp = heap[j];
    while (j > 0) {		//沿父结点路径向上直达根
        if (heap[i].cost <= temp.cost) break;							//父结点值小, 不调整
        else { heap[j] = heap[i];  j = i;  i = (i - 1) / 2; }
        //父结点结点值大, 调整
    }
    heap[j] = temp;				//回送
};




bool Insert(Node& x) {
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


bool Remove(Node& x) {
    if (!currentSize) {		//堆空, 返回false
        cout << "Heap empty" << endl;  return false;
    }
    x = heap[0];
    heap[0] = heap[currentSize - 1];
    currentSize--;
    siftDown(0, currentSize - 1);    	//自上向下调整为堆
    return true;			//返回最小元素
};

class UFSets {	//集合中的各个子集合互不相交
public:
    UFSets(long long sz = DefaultSize);	//构造函数
    //～UFSets() { delete[]parent; }	//析构函数
    UFSets& operator = (UFSets& R);    //集合赋值
    void Union(long long Root1, long long Root2);	     //子集合并
    long long Find(long long x);				//查找x的根
    void WeightedUnion(long long Root1, long long Root2);
    //改进例程:加权的合并算法
private:long long* parent;		  //集合元素数组(双亲表示)
       long long size;			  //集合元素的数目
};

UFSets::UFSets(long long sz) {
    //构造函数：sz 是集合元素个数，双亲数组的范围
    //为parent[0]～parent[size-1]。
    size = sz;			  //集合元素个数
    parent = new long long[size + 1];  //创建双亲数组
    for (long long i = 0; i < size + 1; i++) parent[i] = i;
    //每个自成单元素集合
};

long long UFSets::Find(long long x) {
    //函数搜索并返回包含元素x的树的根。
    //if (parent[x] == x) return x;   //根的parent[]值小于0
    while (x != parent[x]) {
        parent[x] = Find(parent[x]);
        x = parent[x];
    }
    //else return (Find(parent[x]));
    return x;
};


void UFSets::Union(long long Root1, long long Root2) {
    //求两个不相交集合Root1与Root2的并
    //parent[Root1] += parent[Root2];
    parent[Root2] = Root1;
    //将Root2连接到Root1下面
};


void UFSets::WeightedUnion(long long Root1, long long Root2) {
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



const int maxValue = 0x7fffffff;


long long Kruskal() {
    long long sum = 0;
    Node edge;
    long long n, m;
    //scanf("%d%d", &n, &m);
    cin >> n >> m;
    //init_MinHeap(m);
    UFSets F(n);

    for (long long i = 0; i < m; i++) {
        long long a, b, w; cin >> a >> b >> w;
        heap[i].head = a, heap[i].tail = b, heap[i].cost = w;
    }
    quick_sort(heap, 0, m - 1);
    long long count = 0;
    for (int i = 0; i < m; i++) {
        edge = heap[i];
        long long u = F.Find(edge.tail), v = F.Find(edge.head);
        if (u != v) {
            F.Union(u, v);
            sum += edge.cost;
            count++;
            if (count == n - 1)break;
        }
    }
    
    while (count < n) {
        //Remove(edge);
        long long u = F.Find(edge.tail), v = F.Find(edge.head);
        if (u != v) {
            F.Union(u, v);
            sum += edge.cost;
            count++;
        }
        //if (count == n - 1)break;
    }
    
    return sum;
}

int main()
{
    long long sum = Kruskal();
    cout << sum << endl;

    return 0;
}
*/