/*
��ǿ����

С���������μ���ǿ���Խ�Ŀ����ε���Ŀ�Ǹ���һ�Ż�ľ��ÿ���ľ�Ͽ���һ���ַ��������˸���һ���̶����ַ�������С���������Ż�ľ���ҵ����а��ַ���˳����������еĻ�ľ��

�����ʽ

�������룬��һ��Ϊ���Ż�ľ�������ҵ�����˳�򣬵ڶ�������Ϊ�����˸������ַ�����

�����ʽ

һ����������������г�����Ҫ���������ľ�����еĵ�һ����ľ���ڵ�λ�ã��±��0��ʼ������δ�ҵ����ϵĽ�������-1���������������Ŀո��س���

����Լ��

������Ϊ��ľ�������ַ������ȶ���Ϊ0���һ�ľ������С���ַ������ȣ���ͬ��ĸ�Ĵ�Сд����Ϊ��ͬһ�ַ���

��������
0110110
11

�������
1 4

*/

/*
#include<iostream>
#include<string>
using namespace std;

void getNext(string s, int next[]) {
	int j = 0, k = -1;
	int length = s.length();
	next[0] = -1; j = 1;
	while (j <= length) {
		k = next[j - 1];
		while (1) {
			if (k == -1 || s[j - 1] == s[k]) {
				k++;
				next[j] = k;
				j++;
				break;
			}
			else k = next[k];
		}
	}
}

int kmpFind(string target, string pat, int start, int next[]) {
	int posP = 0, posT = start;
	int lengthP = pat.length();
	int lengthT = target.length();

	bool kmp_succeed = false;

	//while (posP < lengthP && posT < lengthT) {
	while (posT < lengthT) {
		if (posP == -1 || pat[posP] == target[posT]) {
			posP++; posT++;
		}
		else posP = next[posP];

		if (posP == lengthP) {
			if (kmp_succeed) cout << ' ';
			cout << posT - lengthP;
			kmp_succeed = true;
			posP = next[posP];
		}
	}

	if (!kmp_succeed) cout << -1;
	cout << endl;
	//if (posP < lengthP) cout <<  -1;
	//else cout <<  posT - lengthP;
	return 0;
}

void solution_2() {
	string target, pat;
	cin >> target >> pat;
	int* nxt = new int[pat.length()+1];
	getNext(pat, nxt);
	kmpFind(target, pat, 0, nxt);
}
*/