#include<iostream>
using namespace std;

const int MAX_NUM = 1e5;//ջ���������

//����ջ

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
	height[N] = -1; //�߽�
	stack s;
	long long res = 0, top;
	for (int i = 0; i < N + 1; i++) {
		//��������ջ
		if (s.isEmpty() || height[s.peek()] <= height[i]) {//����ǿ�ջ������һ���߶ȴ���ջ��Ԫ������ջ
			s.push(i);
		}
		else {
			while (!s.isEmpty() && height[s.peek()] > height[i]) {//�����˱�ջ��Ԫ��С��Ԫ��
				top = s.peek();
				s.pop();//ջ��Ԫ�س�ջ
				//i-top�ǵ�ǰ���εĿ�ȣ�height[top]�ǵ�ǰ�ĸ߶�
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
	//��������
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