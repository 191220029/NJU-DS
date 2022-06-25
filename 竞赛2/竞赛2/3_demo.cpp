/*
#include<iostream>
#include<cmath>
using namespace std;
double heap[2000007];
int size = 0;
void push(double x) {
	heap[++size] = x;
	int t = size;
	while (t > 1) {
		if (heap[t] < heap[t / 2]) {
			double y = heap[t];
			heap[t] = heap[t / 2];
			heap[t / 2] = y;
		}
		t /= 2;
	}
}

void pop() {
	if (size == 0) return;
	heap[1] = heap[size--];
	int t = 1;
	while (t * 2 <= size) {
		int m = 2 * t;
		if (m + 1 <= size && heap[m] > heap[m + 1]) m++;
		if (heap[t] > heap[m]) {
			double y = heap[t];
			heap[t] = heap[m];
			heap[m] = y;
			t = m;
		}
		else break;
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char ch;
		scanf("\n");
		scanf("%c", &ch);
		if (ch == 'A') {
			double a, b, c;
			scanf("%lf%lf%lf", &a, &b, &c);
			push(sqrt(a * a + b * b + c * c));
		}
		else
			if (ch == 'Q') {
				int x;
				scanf("%d", &x);
				double sum = 0;
				for (int j = 0; j < x; j++) {
					sum += heap[1];
					pop();
				}
				printf("%.5f\n", sum / (x * 1.0));
			}
	}
	return 0;
}
*/