/*
С����������

��һȺС������ÿ��С�����и���ţ����Ϊ�������������κ�����С�����ı�Ż�����ͬ��

����С�����ı������ͬ�Ĺ������������������ 1 ��ʱ��������С������Ϊ���ѡ�

��С���� a �� b �����ѣ��γ�һ��С��������Ȧ��֮���� b �� c ҲΪ���ѣ���ô��ʱ�������Ȧ����Ϊ 3 ��С�������� a, b, c.

����ӵ�����С������������Ȧ�������ж���С�����أ�

����
��һ��ΪС��������
�ڶ�������Ϊÿ��С�������

���
�����������Ȧ������

ʾ�� 1��

����
4
9 15 4 64

���
2



ÿ��Ȧ��ʾһ��С����������ΪС�����ı�š�Ȧ֮�������ߣ����ʾ����������д��� 1 �Ĺ�������

��������У��γ�����������Ȧ���ֱ��� 2 ��С������������ 2.

ʾ�� 2��

����
4
9 15 40 64

���
4



����һ������Ȧ��4 ��С��������� 4.

ʾ�� 3��

����
7
35 14 9 15 4 64 48

���
7



����һ������Ȧ��7 ��С��������� 7.

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
    //�������������ذ���Ԫ��x�����ĸ���
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