/*
��Ŀ����

С������ѧУΪ�˷���ѧ��У�ڽ�ͨ����ͨ�˹����� ������m
m��ͬѧ������ͬѧi��i����aվ�ϳ���bվ�³���b>a), ��ô���������й���������ж����˳�������������ѭ���º���ԭ��

�����ʽ

��һ������M
M
����

����M
M
�����룬a
a
,b
b
��ʾͬѧi
i
��a
a
վ�ϳ���b
b
վ�³���

�����ʽ

һ�У�һ������������ʾ��������������

��������

input
3
1 2
1 3
2 3

output
2

���ݹ�ģ��Լ��

M��10 6
M��106


0<a<b��10 6
0<a<b��106


ʱ�����ƣ�1s
1s


�ռ����ƣ�64MB
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

    //��ʼ����¼����
    for (int i = 0; i < N; i++) {
        bus[i][0] = 0;
        bus[i][1] = 0;
    }
    //ͳ��ÿվ����
    for (int i = 0; i < num; i++) {
        cin >> a >> b;
        bus[a][0]++;
        bus[b][1]++;
        if (b > last) {
            last = b;//ͳ�����һվ
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
