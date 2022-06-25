#include<iostream>

using namespace std;

#define MAX_N 50000
int ele[MAX_N];
int bs_index[MAX_N][2];
int bs_cnt[MAX_N];
int n;

int max_num = 1;

void set_bs(int cur, int index) {
    if (ele[index] > ele[cur]) {
        bs_cnt[cur]++;
        if (!bs_index[cur][1])
            bs_index[cur][1] = index;
        else set_bs(bs_index[cur][1], index);
    }
    else {
        bs_cnt[cur]++;
        if (!bs_index[cur][0])
            bs_index[cur][0] = index;
        else set_bs(bs_index[cur][0], index);
    }
}

void solution_2() {
    int i;
    scanf("%d\n", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &ele[i]);
        bs_cnt[i] = 1;
        set_bs(0, i);
    }
    int k = 1;

    for (i = n - 1; i >= 1; i--) {
        max_num *= i;
        while (k < n && (max_num % bs_cnt[k] == 0)) {
            max_num /= bs_cnt[k];
            k++;
        }
    }

    for (i = k; i < n; i++) {
        max_num /= bs_cnt[i];
    }
    printf("%d\n", max_num);
    return;
}

int main() {
    solution_2();
    return 0;
}
