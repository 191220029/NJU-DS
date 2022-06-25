/*
题目描述

小蓝鲸的学校为了方便学生校内交通，开通了公交， 现在有m
m个同学，对于同学i，i想在a站上车，b站下车（b>a), 那么公交车运行过程中最多有多少人乘坐？公交车遵循先下后上原则。

输入格式

第一行输入M
M
个人

后面M
M
行输入，a
a
,b
b
表示同学i
i
在a
a
站上车，b
b
站下车。

输出格式

一行，一个正整数，表示最多乘坐的人数。

样例数据

input
3
1 2
1 3
2 3

output
2

数据规模与约定

M≤10 6
M≤106


0<a<b≤10 6
0<a<b≤106


时间限制：1s
1s


空间限制：64MB
64MB

*/
/*
#include<iostream>
using namespace std;
#define N 1000000
int bus[N][2];
int last = 0;
int tmp_res = 0;
int max_res = 0;

void solution_2() {
    int num;
    cin >> num;
    int a, b;

    //初始化记录数组
    for (int i = 0; i < N; i++) {
        bus[i][0] = 0;
        bus[i][1] = 0;
    }
    //统计每站人数
    for (int i = 0; i < num; i++) {
        cin >> a >> b;
        bus[a][0]++;
        bus[b][1]++;
        if (b > last) {
            last = b;//统计最后一站
        }
    }
    for (int i = 0; i <= last; i++) {
        tmp_res = tmp_res + bus[i][0] - bus[i][1];
        if (tmp_res > max_res) {
            max_res = tmp_res;
        }
    }
    cout << max_res << endl;

}

int main() {
    solution_2();
    return 0;
}
*/
