/*
С��������ҵ
С��������ʦ����ڿ��Ͻ��˶ԽǾ����������Ǿ��󣬵���С����û������������
�����ڲ��õ���ҵ�������������ܰ��������ҵ�������ģ�
����һ�� NxN �ķ��㷽���ж������͡�����ĵ�һ�������� N��N < 100����
��ʾ�����ά�ȡ�����������һ�� NxN �ķ��󣬷����е�ÿ��Ԫ�ض�����Ȼ����
�Ҳ����� 100��
������ǶԽǾ������Խ��������Ԫ��ȫ��Ϊ 0��������� "diagonal"
������������Ǿ������Խ������µ�Ԫ��ȫ��Ϊ 0��������� "upper"
������������Ǿ������Խ������ϵ�Ԫ��ȫ��Ϊ 0��������� "lower"
����������ֶ����ǣ������ "none"

�����������

3
23 0 10
0 7 9
0 0 0


3
3 0 0
0 7 0
0 0 0


3
1 0 1
0 1 0
1 0 1
upper
diagonal
none
*/

/*
#include<iostream>
using namespace std;

void solution_1() {
	bool diagonal = true, upper = true, lower = true;

	int n; cin >> n; //����ά��
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x; cin >> x;
			if (x != 0) {
				if (i != j) diagonal = false;
				if (i < j) lower = false;
				else if (i > j) upper = false;
			}
		}
	}

	//������
	if (diagonal) printf("diagonal\n");
	else if (upper) printf("upper\n");
	else if (lower) printf("lower\n");
	else printf("none\n");
}
*/