/*
��Ŀ����
ÿ�궼���кܶ�����С���������Ͼ���ѧ��С�����ڱ�����ʱ�������ܳ��Ķ��飬ÿ��ͬѧֻ�ܿ����Լ�ǰ��һλͬѧ��id�������æ��ԭ������С�

�����ʽ
��һ��һ������n��n<=100000������ʾ��n��������Id�ӣ�1-n����ʾ

������n�У�ÿ��������i��j����ʾ��������iǰ����Ǹ�����j��

�����ʽ
1�У�n��������ʾ�����Ķ��С�
*/

#include <iostream>
using namespace std;
#define MAX_NUMBER 100000
int queue[MAX_NUMBER] = { -1 };
//����ģ������
void setupQueue(int curId, int nxtId) {
	queue[nxtId] = curId;
	return;
}

void printQueue(int n) {
	int i = 0;
	for (int cnt = 0; cnt < n; cnt++) {
		cout << queue[i] << ' ';
		i = queue[i];
	}
	cout << endl;
	return;
}

int solution_2() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int curId, nxtId;
		cin >> curId >> nxtId;
		setupQueue(curId, nxtId);
	}
	printQueue(n);
	return 0;
}