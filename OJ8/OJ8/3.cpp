/*
小蓝鲸找朋友

有一群小蓝鲸，每个小蓝鲸有个编号（编号为正整数），且任何两个小蓝鲸的编号互不相同。

两个小蓝鲸的编号有相同的公因数（公因数需大于 1 ）时，这两个小蓝鲸成为朋友。

若小蓝鲸 a 和 b 是朋友，形成一个小蓝鲸朋友圈，之后发现 b 和 c 也为朋友，那么此时这个朋友圈扩充为 3 个小蓝鲸，即 a, b, c.

请问拥有最多小蓝鲸数的朋友圈，到底有多少小蓝鲸呢？

输入
第一行为小蓝鲸个数
第二行依次为每个小蓝鲸编号

输出
最多人数朋友圈的人数

示例 1：

输入
4
9 15 4 64

输出
2



每个圈表示一个小蓝鲸，数字为小蓝鲸的编号。圈之间有连线，则表示这两个编号有大于 1 的公因数。

这个例子中，形成了两个朋友圈，分别有 2 个小蓝鲸。因此输出 2.

示例 2：

输入
4
9 15 40 64

输出
4



此例一个朋友圈，4 个小蓝鲸，输出 4.

示例 3：

输入
7
35 14 9 15 4 64 48

输出
7



此例一个朋友圈，7 个小蓝鲸，输出 7.

*/

/*
#include<iostream>
using namespace std;

const int N = 1000000;

int prime[N];
int parent[N];
int is_prime[N];
int ans[N];
int input[N];


int Find(int x) {
    //函数搜索并返回包含元素x的树的根。
    while (x != parent[x]) {
        parent[x] = Find(parent[x]);
        x = parent[x];
    }
    return x;
};

void Union(int Root1, int Root2) {
    parent[Find(Root2)] = Find(Root1);
};

void solution_3() {
    int n; scanf("%d", &n);
    for (int i = 1; i < N; i++) {
        parent[i] = i;
        is_prime[i] = 1;
    }
    int cnt = 0;
    for (int i = 2; i < N; i++) {
        if (is_prime[i]) prime[cnt++] = i;
        for (int j = 0; j < cnt && i * prime[j] < N; j++) {
            is_prime[i * prime[j]] = 0;
            if (i % prime[j] == 0) break;
        }
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
        for (int j = 2; j * j <= input[i]; j++) {
            if (input[i] % j == 0) {
                if (is_prime[j]) {
                    Union(input[i], j);
                }
                if (is_prime[input[i] / j]) {
                    Union(input[i], input[i] / j);
                }
            }

        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        ans[Find(input[i])]++;
        if (ans[parent[input[i]]] > sum)
            sum = ans[parent[input[i]]];
    }
    cout << sum << endl;
    return;
}

int main()
{

    solution_3();

    return 0;
}
*/