#include <iostream>
#include<cmath>
using namespace std;

const int MAX_SIZE = 3000000;
double dis[MAX_SIZE];
int rear;
void insert(double distance) {
	dis[++rear] = x;
	int t = rear;
	while (t > 1) {
		if (heap[t] < heap[t / 2]) {
			double y = heap[t];
			heap[t] = heap[t / 2];
			heap[t / 2] = y;
		}
		t /= 2;
	}
}

void del() {
	double ret = dis[1];
	if (rear == 0)return ;
	dis[1] = dis[rear];
	rear--;
	int pos = 1;
	int dpos = 2 * pos;
	while (dpos <= rear) {
		if (dpos + 1 <= rear && dis[dpos] > dis[dpos + 1]) {
			dpos++;
		}
		if (dis[pos] > dis[dpos]) {
			double temp = dis[pos];
			dis[pos] = dis[dpos];
			dis[dpos] = temp;
			pos = dpos;
		}
		else break;
	}
	return ;
}

void solution_3() {
	int N; cin >> N;
	//scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		char c; 
		scanf("\n");
		scanf("%c", &c);
		//cin >> c;
		if (c == 'A') {//insert
			double a, b, c;
			scanf("%lf%lf%lf", &a, &b, &c);
			//cin >> a >> b >> c;
			double distance = sqrt(a * a + b * b + c * c);
			insert(distance);
		}
		else if (c == 'Q') {//search
			int s; 
			scanf("%d", &s);
			//cin >> s;
			double sum = 0;
			for (int i = 0; i < s; i++) {
				sum += del();
			}
			sum /= (double)s;
			printf("%.5f\n", sum);
		}
	}
	return;
}

int main() {
	solution_3();
	return 0;
}
