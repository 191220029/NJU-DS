/*
��Ŀ����
���������Ǹ���������һ��Ϊ���������ڶ���Ϊ������ʵ�ֳ��������������Ľ����

���ܳ�����ֵ�ϴ�����֣���ʹ���ʵ������ݽṹ�洢���ֲ����㡣

�����ʽ
���У���һ��Ϊ���������ڶ���Ϊ������

�����ʽ
һ�У������ļ�������Ľ����
*/

#include <iostream>
#include<string>
using namespace std;

bool greaterNum(string a, string b) {//�Ƚ���a,b��С
	if (a.size() > b.size())return true;//λ���Ƚ�
	else if (a.size() < b.size())return false;
	else {//λ�����ʱ�Ӹ�λ���λ�Ƚϸ�λ��ֵ
		for (int i = 0; i < a.size(); i++) {
			if (a[i] > b[i])return true;
			else if (a[i] < b[i])return false;
			//����ǰλ��ͬ�򿴵�λ�����Ƚ�
		}
	}
	return false;
}


string calculate_minus(string a, string b) {//���м�������
	string c;//���ڴ洢������
	int CF = 0;//��λ���Ƿ�
	//��λ���λ���м�������
	int i, j;
	for (i = a.size() - 1, j = b.size() - 1; i >= 0 && j >= 0; i--, j--) {
		int t = (a[i] - b[j]) - CF;
		if (t >= 0) {//��ǰλ�������>=0����λ���Ƿ����㣬����Ϊ1
			c = to_string(t) + c; CF = 0;
		}
		else {
			t += 10;//��λ
			c = to_string(t) + c; CF = 1;
		}
	}
	while (i >= 0) {//����a,b���Ȳ����ʱ����λ�Ĵ��� ***��Ҫע���λ���Ƿ���Ӱ����Ȼ����
		int t = a[i] - '0' - CF;
		if (t < 0) {
			t += 10; CF = 1;
		}
		else {
			CF = 0;
		}
		c = to_string(t) + c;
		i--;
	}
	//ɾȥ��������λ�����0
	for (int i = 0; i < c.size(); i++) {
		if (c[i] == '0') {
			c = c.substr(i + 1, c.size());
			i--;
		}
		else break;
	}
	return c;
}
int solution_3() {
	string a, b;
	cin >> a >> b;
	string c;
	if (a == b)c = '0';
	else if (greaterNum(a, b)) {
		c = calculate_minus(a, b);
	}
	else {
		c = '-' + calculate_minus(b, a);
	}
	cout << c << endl;
	return 0;
}