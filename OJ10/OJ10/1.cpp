/*
Χ�����

��������

Χ�壬һ�ֲ���������������Ϸ���й���ʱ�ơ��ġ����������ơ�Go���������ڶ��ǹ��ң��С��ա������������������黭����֮һ��Χ����Դ���й�����Ϊ��Ң����������ս��ʱ�ڼ��м��ء�����ʱ�����ʴ����ձ���������ŷ��������Χ���̺����л��Ļ��ķḻ�ں��������й��Ļ������������֡�

Ϊ�˺����й���ͳ�Ļ����ḻ�����ǵ�ҵ�����ĳС�������ٰ�һ��Χ����������С���ľ���ܶ඼��ϲ����Χ�壬����ƽʱҲ����Լ���壬����һ��������˶ԶԷ���Χ�幦�׶����˽⡣Ϊ������Ȥζ�ԣ������Ƿ�ӳ���ܷ�����Ҫ��ƽʱ����һ����������ڵ�һ�ֱ���ʱ��������

���ŵ�������ĸ��ӵ����ѹ�ϵ������췽ͷ���ˣ������ҵ����㣬�������æ���������⡣����췽׼�����������˷�Ϊ���飨�����������Բ�ͬ������һ�ֱ���ʱ�������ڽ��ж��ģ����췽������֪�����ܷ񽫲�����Ա��Ϊ����������˵Ҫ������飨����ƽʱ����һ��������˷��ڲ�ͬ�飩��

�����ʽ

��һ���������������ֱ��ǲ���ѡ������ N���Լ�һ������ M���� 0 < N ��M < INT_MAX ��

������ M �У�ÿ�о����������� x��y�����Ǵ����Ӧ��� x��y �����������������ѣ���ƽʱ����һ��������ˣ���( N �������ߵı�Ŷ�ӦΪ 0 ~ N-1���ʶ���0 <= x��y <= N-1 )

�����ʽ

������԰�Ҫ����飬��� Yes��������� No��

��������

����1

���룺
6 4
3 2
4 0
2 0
0 1

�����
Yes

���ͣ�

�ɷ���Ϊ��{ 0, 3 }��{ 1, 2, 4, 5 }

����2

���룺
5 5
0 1
3 0
2 1
0 2
1 4

�����
No

*/

/*
#include<iostream>

using namespace std;

int N, M;

const int MAX_NUM = 10000;
int group[MAX_NUM]; //[i]'s group is 1 or -1;  0: undefined
int friends[MAX_NUM][MAX_NUM];

int Find_friends(int x, int start) {
	for (int i = start; i < N; i++) {
		if (friends[x][i] == 1) return i;
	}
	return -1;
}

void check_group() {
	//check group[]
	for (int i = 0; i < N; i++) {
		cout << i << ", ";
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << group[i] << ", ";
	}
	cout << endl;
	return;
}

bool set_group(int k, int group_num) {
	if (group[k] == 0) {//undefined
		group[k] = group_num;
		for (int i = 0; i < N; i++) {
			if (friends[k][i]) { //k and i are friends
				if (group[i] == group_num) return false; //i and k in same group
				if (group[i] == 0)  //i's group is undefined
					//set i's group and check
					if (!set_group(i, -group_num)) return false;;
			}
		}
	}
	//check_group();
	return true;
}

void solution_1() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		friends[a][b] = friends[b][a] = 1;
	}

	//set_group();
	bool flag = true;

	for (int i = 0; i < N; i++) {
		flag &= set_group(i, 1);
	}

	if (flag) cout << "Yes" << endl;
	else cout << "No" << endl;
	return;
}

int main() {
	solution_1();
	return 0;
}
*/