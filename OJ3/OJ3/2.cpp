/*
�������
С��ͬѧ��1��n��n�����ְ���һ����˳�������һ������Q�С��������Զ���Qִ�������³���

while(!Q.empty())       //���в��գ�ִ��ѭ��
{
 int x=Q.front();      //ȡ����ǰ��ͷ��ֵx
 Q.pop();         //������ǰ��ͷ
 Q.push(x);        //��x�����β
 x = Q.front();       //ȡ����ʱ���ͷ��ֵ
 printf("%d\n",x);     //���x
 Q.pop();         //������ʱ��Ķ�ͷ
}
��ȡ����ͷ��ֵ������ʱ�򣬲���������ǰ��ͷ�� С��ͬѧ���֣���γ���ǡ�ð�˳�������1,2,3,...,n������С�������㹹���ԭʼ�Ķ��У�����������

�����ʽ
��һ��һ������T��T �� 100����ʾ����������ÿ����������һ����n��1 �� n �� 100000��

�����ʽ
����ÿ�����ݣ����һ�У���ʾԭʼ�Ķ��С�����֮����һ���ո��������Ҫ����ĩ�������Ŀո�.

��������
4
1
2
3
10
�������
1
2 1
2 1 3
8 1 6 2 10 3 7 4 9 5
*/


#include<iostream>
#include<string>
using namespace std;

void solution_2(int n) {
	//С�������
	int* a = new int[n];
	//��ԭ����
	//һ����һ��������

	int k = 1, pos = 1, cnt = 1;
	if (n == 1)a[0] = 1;
	else {
		while (k <= n) {
			if (cnt == 1) {
				while (a[pos] != 0) {
					pos = (pos + 1) % n;
				}
				a[pos] = k;
				k++;
				cnt = 0;
			}
			else {
				if (a[pos] == 0)cnt++;
			}
			pos = (pos + 1) % n;
		}
	}


	//���
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
	return;
}


int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		solution_2(n);
	}
	return 0;
}