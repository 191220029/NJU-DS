/*
С����վλ

������ N ��С������Ҫ��������ѧ�Ĳٳ���վλ��������ѧ�Ĳٳ���һ�� NxN �ķ��󣬷����е�ÿһ���������ֻ������һ��С���������ң������������ѩ�������еĸ����ǲ���վ�˵ģ���Ϊ��ˮ����

���⣬������ѧѧ��뺷��С������Ҳ���ǳ� aggressive�����������С����λ��ͬһ���С����С�����б�ߣ����ǽ����������������ⲻ�á�

��ΪУ�쵼���㣬�϶�ϣ�������С������Ҫ�Ժ�Ϊ��Ҫ����£���Ҫ�����ﶷ������������ж�����վλ������ȷ��ÿ��С��������λ�ã��������ǲ����������

�����ʽ

����ĵ�һ�а������� N �� M�����У�N ������ʾ�ٳ��Ĵ�С��NxN����Ҳ��ʾС������������M ��ʾ�ٳ����ж��ٸ�������Ϊ��ˮԭ���޷�վ�ˡ�

��������M�У�ÿ�а������������� X Y���ֱ��ʾ��ˮ���ӵĺ������꣨����� 1 ��ʼ�����Ͻ��� 1 1�����½��� N N����

���ݷ�Χ��N ������ 12��M ������ $N^2$��

�����ʽ

һ����Ȼ������ʾ�ж�����վλ������

�������� 1
10 3
4 7
2 6
8 1

������� 1
532

�������� 2
6 6
1 6
2 6
3 6
4 6
5 6
6 6

������� 2
0

���� 2 ���ͣ��� 6x6 �Ĳٳ��У��� 6 �еĸ���ȫ������Ϊ��ˮ�޷�վ�ˡ����ݳ���ԭ������� 6 ��С���������ڽ��� 5 �еĲٳ��У���ô��������С����λ��ͬһ�У��Ӷ�������������޽⣬��� 0��

*/

/*
#include<iostream>

using namespace std;

int m, n;

const int N = 13;

int water[N][N];
int queen[N][N];
int isSafe(int row, int col, int n) { // if [row][col] is in water or in confict with others
	if (water[row][col]) return 0;
	int i, j;
	for (i = 0; i < n; i++) { //judge same column
		if (queen[i][col] == 1)
			return 0;
	}
	for (j = 0; j < n; j++) { //judge same row
		if (queen[row][i] == 1)
			return 0;
	}
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--) { //judge left up
		if (queen[i][j] == 1)
			return 0;
	}
	for (i = row, j = col; i >= 0 && j < n; i--, j++) {//judge right up
		if (queen[i][j] == 1)
			return 0;
	}
	return 1;
}
void eightqueen(int row, int& count, int n) {
	if (row >= n) { //one valid anwser
		count++;
		return;
	}
	for (int j = 0; j < n; j++) {
		if (isSafe(row, j, n)) {
			queen[row][j] = 1;
			//goto next row to see if there is valid position to stand
			eightqueen(row + 1, count, n);

			//reset cur position to see if there are other valid answers
			queen[row][j] = 0;
		}
	}
}

void solution_3() {
	int cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		water[x - 1][y - 1] = 1;
	}
	eightqueen(0, cnt, n);
	cout << cnt;
	return;
}

int main() {
	solution_3();
	return 0;
}
*/