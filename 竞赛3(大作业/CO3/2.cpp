/*
Ѱ����ͬ����������

����һ����������ͬԪ�ص��������У� B������һ���м����ܹ����ɸö���������T���������У�

����

�������룬��һ��Ϊ�������е�Ԫ�صĸ��� �ڶ���Ϊ�������У��Կո����

���

һ���������������Ե����������ܻᳬ�����ͷ�Χ������ȡģ(2^32)-1��

����
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