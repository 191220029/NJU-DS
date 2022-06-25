#include<iostream>
using namespace std;

int a[900000];
int r[900000];

//*r:
//pos -> val
//*a:
//val -> pos
int normalize(int length) {
	int cnt = 0;
	for (int i = 0; i < length;) {
		if (r[i] % 2 == 0) {
			if (r[i + 1] != r[i] + 1) {
				int temp_val_i1 = r[i + 1];
				int temp_ptr_i1 = a[r[i] + 1];

				r[i + 1] = r[i] + 1;
				r[temp_ptr_i1] = temp_val_i1;

				a[temp_val_i1] = a[r[i + 1]];
				a[r[i + 1]] = i + 1;
				cnt++;
			}
			i += 2;
		}
		else if (r[i] % 2 == 1) {
			if (r[i + 1] != r[i] - 1) {
				int temp_val_i1 = r[i + 1];
				int temp_ptr_i1 = a[r[i] - 1];

				r[i + 1] = r[i] - 1;
				r[temp_ptr_i1] = temp_val_i1;

				a[temp_val_i1] = a[r[i + 1]];
				a[r[i + 1]] = i + 1;
				cnt++;
			}
			i += 2;
		}
	}
	return cnt;
}


void solution_1() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int x; cin >> x;
		a[x] = i;
		r[i] = x;
	}

	int cnt = normalize(N);
	cout << cnt << endl;
	return;
}

int main() {
	solution_1();
	return 0;
}