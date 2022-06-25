#include<iostream>
using namespace std;

int a[10000];

void solution_2() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] < a[j]) {//寻找第三个合适的数
				for (int k = j + 1; k < n; k++) {
					if (a[i] < a[k] && a[j] > a[k]) {
						cout << "True" << endl;
						return;
					}
				}
			}
		}
	}
	cout << "False" << endl;
}

int main() {
	solution_2();
	return 0;
}