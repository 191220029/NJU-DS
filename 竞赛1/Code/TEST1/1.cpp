/*
��Ŀ����
���ǿ�����򵥵�һ���ı�ѹ����������������ͬ���ַ���ɵ�һ��������Ƭ�Σ�������ַ���Ƭ���и��ַ��ĸ�������ʾ��
���� ccccc ���� 5c ����ʾ������ַ�û���ظ�����ԭ����������� aba ѹ������Ȼ�� aba��
������Ҫ�����ѹ����Ҫ�󣬶Ը����ַ������д����������Ǽ򵥵ؼ���ԭʼ�ַ�������ȫ��СдӢ����ĸ��ɵķǿ��ַ�����

�����ʽ
�����һ�и�����Ҫ��ѹ�����ѹ�Ĳ����� 1000 ���ַ����ַ�����
�����ʽ
��һ�������ѹ������ַ�����
���� 1
���룺
bccccccddd
�����
b6c3d
���� 2
���룺
cccbbbcbbddcbccdcdcc
�����
3c3bc2b2dcb2cdcd2c

*/

/*
#include<iostream>
#include<string.h>
using namespace std;


void solution_1() {
	string s; cin >> s;
	string res = "";

	int cnt = 0; char t;
for (int i = 0; i < s.length(); i++) {
	if (res.length() == 0) res = res + s[i];
	else {
		if (s[i] == res[res.length() - 1]) {
			cnt++;
		}
		else {
			if (cnt) {
				char c = res[res.length() - 1];
				cnt++;
				int j = 0;
				while (cnt) {
					if (j == 0) {
						res[res.length() - 1] = (char)((cnt % 10) + '0');
						j++;
					}
					else res = res + (char)((cnt % 10) + '0');
					cnt /= 10;
				}
				//res[res.length() - 1] = (char)(cnt + 1 + '0');
				res = res + c;
				cnt = 0;
			}
			res = res + s[i];
		}
	}
}


//���ַ���ĩβ�Ĵ���
if (cnt) {
	char c = res[res.length() - 1];
	res[res.length() - 1] = (char)(cnt + 1 + '0');
	res = res + c;
	cnt = 0;
}

cout << res << endl;
}

int main() {
	solution_1();
	return 0;
}
*/