/*
��Ŀ����

С�������Ѿ��ų���һ�ţ�ÿ��С������������һ��СдӢ����ĸ�������һ���ַ��� s ������ȥ������ַ����������ظ���ĸ��С������ʹ��s�����в�ͬ����ĸ������ֻ����һ�Ρ����ң�Ҫʹ�÷��ؽ�����ַ������ֵ�����С��Ҫ���ܴ���С�����ǵ����λ��Ӵ����

�����ʽ

һ���ַ���s

�����ʽ

�ֵ�����С�Ľ���ַ���

��������

����1

����
abae

���
abe

����2

����
ecbaadaccc

���
ebadc

���ݹ�ģ

1<=len(s)<=5000000
1<=len(s)<=5000000

*/

/*
#include<iostream>
#include<string.h>
using namespace std;

int cnt[26] = { 0 };
int vflag[26] = { 0 };//�Ƿ���ʹ�

void solution_4() {
	string s; cin >> s;
	string res = "";
	for (int i = 0; i < s.length(); i++) {
		cnt[s[i] - 'a']++;
	}//ͳ�Ƹ���ĸ���ִ���
	for (int i = 0; i < s.length(); i++) {
		cnt[s[i] - 'a']--;
		if (vflag[s[i] - 'a'])continue;//����Ѿ����ʹ���λ�õ��ַ������
		while (res.length() && cnt[res.back() - 'a'] > 0 && res.back() > s[i]) {
			vflag[res.back() - 'a'] = 0;
			res.pop_back(); //ɾȥ���ַ�
		}
		res += s[i];
		vflag[s[i] - 'a'] = 1;
	}
	cout << res << endl;
}

int main() {
	solution_4();
	return 0;
}
*/