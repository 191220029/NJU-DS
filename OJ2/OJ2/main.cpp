#include<iostream>
using namespace std;

const int MAX_NUM = 1e5;//栈的最大容量

//单调栈

class stack {
public:
	stack() { top = -1; }
	bool isEmpty() { return (top == -1); }
	bool push(long long x);
	long long pop();
	long long peek();
private:
	long long T[MAX_NUM];
	int top;
};

bool stack::push(long long x) {
	if (top < MAX_NUM - 2) {
		T[++top] = x;
		return true;
	}
	else return false;
}

long long stack::pop() {
	if (top > -1) {
		return T[top--];
	}
}

long long stack::peek() {
	if (top > -1) {
		return T[top];
	}
}

long long solution_3(long long *height, int N) {
	height[N] = -1; //边界
	stack s;
	long long res = 0, top;
	for (int i = 0; i < N + 1; i++) {
		//构建单调栈
		if (s.isEmpty() || height[s.peek()] <= height[i]) {//如果是空栈或者下一个高度大于栈顶元素则入栈
			s.push(i);
		}
		else {
			while (!s.isEmpty() && height[s.peek()] > height[i]) {//出现了比栈顶元素小的元素
				top = s.peek();
				s.pop();//栈顶元素出栈
				//i-top是当前矩形的宽度，height[top]是当前的高度
				long long tmp = (long long)(i - top) * (long long)height[top];
				if (tmp > res) res = tmp;
			}
			s.push(top);
			height[top] = height[i];
		}
	}
	return res;
}

int main() {
	//读入数据
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int N; cin >> N;
		long long* height = new long long[N + 1];
		for (int j = 0; j < N; j++) {
			cin >> height[j];
		}
		long long res = solution_3(height, N);
		cout << res << endl;
	}
	return 0;
}