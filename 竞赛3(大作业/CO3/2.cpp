/*
寻找相同二叉搜索树

给定一个不包含相同元素的整数序列， B：请问一共有几种能够生成该二叉搜索树T的整数序列？

输入

两行输入，第一行为整数序列的元素的个数 第二行为整数序列，以空格隔开

输出

一行输出，输出可能性的数量（可能会超过整型范围，建议取模(2^32)-1）

样例
*/
/*
1                   1
1.

1 2                 2
1,2

1 2 3               2
2,1,3 2,3,1

1 2 3 4             3
        2
    1       3
                4
2,3,1,4; 2,1,3,4; 2,3,4,1
1 2 3 4 5                       6
        3
    2       4
1               5
3,2,1,4,5; 3,2,4,1,5; 3,2,4,5,1;
3,4,5,2,1; 3,4,2,5,1; 3,4,2,1,5;


1 2 3 4 5 6
            3
     2              4
1                           5
                                    6
3,2,1,4,5,6; 3,2,4,1,5,6; 3,2,4,5,1,6; 3,2,4,5,6,1
3,4,2,1,5,6; 3,4,2,5,1,6; 3,4,2,5,6,1; 3,4,5,2,1,6; 3,4,5,2,6,1; 3,4,5,6,2,1

1 2 3 4 5 6 7
            4
        3       5
    2               6
1                       7
4,3,2,1,5,6,7; 4,5,6,7,3,2,1; 4,3,5,2,6,1,7
4,3,5,2,6,7,1; 4

*/


/*
#include<iostream>

using namespace std;

#define MAX_N 50000
int ele[MAX_N];
int bs_index[MAX_N][2]; //
int bs_cnt[MAX_N];
int n;

int max_num = 1;
//always find the mid one to be the root

void set_bs(int cur, int index) {
    if (ele[index] > ele[cur]) {
        bs_cnt[cur]++;
        if (bs_index[cur][1] == 0)
            bs_index[cur][1] = index;
        else set_bs(bs_index[cur][1], index);
    }
    else {
        bs_cnt[cur]++;
        if (bs_index[cur][0] == 0)
            bs_index[cur][0] = index;
        else set_bs(bs_index[cur][0], index);
    }
}

void solution_2() {
    int i;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> ele[i];
        bs_cnt[i] = 1;
        set_bs(0, i);
    }
    int k = 1;

    //Cbs_cnt[] i...
    for (i = n - 1; i >= 1; i--) {
        max_num *= i;
        while (k < n && (max_num % bs_cnt[k] == 0) ) {
            max_num /= bs_cnt[k];
            k++;
        }
    }

    for (i = k; i < n; i ++) {
        max_num /= bs_cnt[i];
    }
    cout << max_num << endl;
    return;
}

int main() {
    solution_2();
    return 0;
}


*/