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