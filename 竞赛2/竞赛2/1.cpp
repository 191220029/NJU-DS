/*
˫��������

���һ�������� n �ڶ�������ʮ�����¶��ǻ���������� n ��˫����������ע�⣺������������ǰ�� 0 �������������� S<10e6 (ʮ����), ����� S �����С˫����������

�������룺
20

���������
33

��ʾ��

33 ʮ�������ǻ��ģ�������Ϊ 100001��Ҳ�ǻ��ġ�

*/

/*
#include <iostream>
#include <string>
using namespace std;


int lengthB(int x) {
	int l = 0;
	while (x != 0) {
		x >>= 1;
		l++;
	}
	return l;
}

int getbyte(int x, int pos) {
	return (x >> pos) & 0x1;
}

bool isDh(int x) {
	string s = to_string(x);
	int front = 0; int rear = s.length() - 1;
	while (front < rear) {
		if (s[front] != s[rear]) return false;
		front++;
		rear--;
	}
	return true;
}

bool isBh(int x, const int& length) {
	int front = 0, rear = length - 1;
	while (front < rear) {
		if (getbyte(x, front) != getbyte(x, rear)) return false;
		front++;
		rear--;
	}
	return true;
}

void solution_1() {
	int x; cin >> x;
	x++;
	int lb = lengthB(x);
	//cout << ld << endl;
	//cout << lb << endl;
	while (!(isDh(x) && isBh(x, lb))) {
		x++;
		lb = lengthB(x);
	}
	cout << x << endl;
	return;
}

int main() {
	solution_1();
	return 0;
}

*/