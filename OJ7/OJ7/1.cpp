/*
С�����ĳ���

С�������ڵ�ѧУ��ʼ�޽�У԰��·��ѧУϣ��ѧУ�������������������໥�������һ����ֱ�ӵĵ�·������ֻҪ������ͨ����·�ɴＴ�ɣ��������ٻ���Ҫ�����������·��

�����ʽ

��1�и����������������ֱ��ǽ�����ĿN ( < 1000 )�͵�·��ĿM������M�ж�ӦM����·��ÿ�и���һ�����������ֱ��Ǹ�����·ֱ����ͨ����������ı�š�Ϊ������������1��N��š� ע��:��������֮������ж�����·��ͨ,Ҳ����˵

3 3

1 2

1 2

2 1

������Ҳ�ǿ��ԺϷ���

�����ʽ

��ÿ��������������1����������ٻ���Ҫ����ĵ�·��Ŀ��

��������1
4 2
1 3
4 3

�������1
1

��������2
3 3
1 2
1 3
2 3

�������2
0

��������3
999 0

�������3
998

*/

/*
#include<iostream>
#include<string>
using namespace std;

#define N 1000
int Tree[N];
//����ĳ������������ĸ����(���̶�д�����μǣ�����)
int findRoot(int x) {
    if (Tree[x] == -1) return x;
    else {
        int tmp = findRoot(Tree[x]);
        Tree[x] = tmp;//·��ѹ���Ż�
        return tmp;
    }
}

void solution_1() {
    int n, m;
    cin >> n >> m;
    //��ʼ��Tree������ÿ��Ԫ��Ϊ-1
    for (int i = 1; i <= n; i++) {
        Tree[i] = -1;
    }
    //�������Ϣ
    while (m > 0) {
        int a, b; cin >> a >> b;
        a = findRoot(a);
        b = findRoot(b); //���ұߵ������������ڼ�����Ϣ
        if (a != b) Tree[a] = b; //���������㲻��ͬһ��������ϲ�����������
        m--;
    }
    int ans = 0;
    //ͳ�����н���и����ĸ���
    for (int i = 1; i <= n; i++) {
        if (Tree[i] == -1) ans++;
    }
    cout << ans - 1; //��ans�����ϼ����޽�ans-1����·����ʹ���н����ͨ
}

int main() {
    solution_1();
    return 0;
}
*/