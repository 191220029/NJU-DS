#include <iostream>
#include<cmath>
using namespace std;

const int MAX_SIZE = 1000000;

struct Node {
	double x;
	double y;
	double z;
	double distance;
	Node() {};
	Node(double inx, double iny, double inz) {
		x = inx, y = iny, z = inz;
		distance = sqrt(x * x + y * y + z * z);
	}
};


class Nodes {
public:
	Nodes();
	bool insert(Node n);
	double search_O(int k);
private:
	Node nodes[MAX_SIZE];
	int dis_smaller[MAX_SIZE]; //存放比当前结点更小的一个结点的位置
	int closest_index; //存放距离原点最近元素的下标
	int rear;
}n;

Nodes::Nodes() {
	for (int i = 0; i < MAX_SIZE; i++) {
		dis_smaller[i] = -1;
	}
	closest_index = -1;
	rear = 0;
}

bool Nodes::insert(Node n) {
	nodes[rear] = n;
	rear++;
	int index = closest_index;
	int last_index = closest_index;
	if (index == -1) closest_index = rear - 1;
	else {
		//find the one smaller than cur
		while (n.distance > nodes[index].distance && index != -1) {
			last_index = index;
			index = dis_smaller[index];
		}
		if (index == -1) {
			dis_smaller[rear - 1] = -1;
			dis_smaller[last_index] = rear - 1;
		}
		else if (index == closest_index) {
			closest_index = rear - 1;
			dis_smaller[rear - 1] = index;
		}
		else {
			dis_smaller[last_index] = rear - 1;
			dis_smaller[rear - 1] = index;
		}
	}
	return true;
}

double Nodes::search_O(int k) {
	double sum = 0;
	int index = closest_index;
	for (int i = 0; i < k; i++) {
		sum += nodes[index].distance;

		//进行删除操作
		index = dis_smaller[index];
		closest_index = index;
	}
	return sum / k;
}



void solution_3() {
	int N; scanf("%d\n", &N);
	for (int i = 0; i < N; i++) {
		char c; scanf("%c", &c);
		if (c == 'A') {//insert
			double a, b, c;
			scanf("%lf %lf %lf\n", &a, &b, &c);
			Node p(a, b, c);
			n.insert(p);
		}
		else if (c == 'Q') {//search
			int k; scanf("%d\n", &k);
			double d = n.search_O(k);
			printf("%.5f\n", d);
		}
		//读取换行符
		//getchar();
	}
	return;
}

int main() {
	solution_3();
	return 0;
}

