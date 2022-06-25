/*
�򵥼�����
ʵ��һ�������ļ�����������һ���򵥵��ַ������ʽ��ֵ���ַ������ʽ���԰��������� ( �������� )���Ӻ� + ������ -���˺�x���Ǹ�������
����Լ����������ı��ʽ������Ч�ġ�

�����ʽ
һ���ַ������ʽ�����У�����ΪӢ���ַ����˺�ΪСд��ĸx���Ǹ�����n(0 �� n �� 9)��

�����ʽ
����һ�����룬���һ�У���ʾ�ַ������ʽ�ļ�����res(|res| �� 1e16)

��������
(1+(4+5x2)-3)-(6+((8)))
�������
-2
����
*/

#include<iostream>
#include<string>
using namespace std;

#define MAX_NUM 1e5

template <class E>
class stack {
public:
	stack() { T = new E[100000];	top = -1; }
	//~stack() { delete []T; top = -1; }
	bool isEmpty() { return (top == -1); }
	bool push(const E& x);
	E pop();
	E peek();
private:
	E* T;
	int top;
};

template<class E>
bool stack<E>::push(const E& x) {
	if (top < MAX_NUM - 2) {
		T[++top] = x;
		return true;
	}
	else return false;
}

template<class E>
E stack<E>::pop() {
	if (top > -1) {
		return T[top--];
	}
}

template<class E>
E stack<E>::peek() {
	if (top > -1) {
		return T[top];
	}
}

void printStack(stack<char> s) {
	stack<char> t = s;
	while (!s.isEmpty()) {
		cout << s.pop();
	}
	cout << endl;
}

//�����������ȼ�
int order[1000] = { 0 };
void init_order() {
	order['+'] = 1;
	order['-'] = 1;
	order['x'] = 2;
	order['('] = 0;
	order[')'] = 3;
	return;
}

//��������
int scal(char op, int a, int b) {
	switch (op)
	{
	case '+':return b + a;
	case '-':return b - a;
	case 'x':return b * a;
	default:
		break;
	}
}

int Poly_setup(string s, stack<int>& rpn, stack<char>& opn) {

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			opn.push(s[i]);
		}
		else if (s[i] == '+' || s[i] == '-' || s[i] == 'x') {
			if (opn.isEmpty()) opn.push(s[i]);
			else {
				while (order[s[i]] <= order[opn.peek()]) {
					int a = rpn.pop();
					int b = rpn.pop();
					int res = scal(opn.pop(), a, b);
					rpn.push(res);
				}
				opn.push(s[i]);
			}
		}
		else if (s[i] == ')') {
			while (!opn.isEmpty() && opn.peek() != '(') {
				int a = rpn.pop();
				int b = rpn.pop();
				int res = scal(opn.pop(), a, b);
				rpn.push(res);
			}
			opn.pop();
		}
		else if (s[i] <= '9' && s[i] >= '0') {
			rpn.push(s[i] - '0');
		}
	}//end for

	//�������Ĳ������Ͷ���ʽ��
	while (!opn.isEmpty()) {
		int a = rpn.pop();
		int b = rpn.pop();
		int res = scal(opn.pop(), a, b);
		rpn.push(res);
	}
	return rpn.peek();
}


void solution_1() {
	//������ʽ
	string s; cin >> s;

	stack<int> rpn;//������ջ
	stack<char>opn;//����ջ
	init_order();//��ʼ����������ȼ�����
	//�����沨�����ʽ������
	int res = Poly_setup(s, rpn, opn);

	//printStack(rpn);


	cout << res << endl;
	return;
}


int main() {
	solution_1();
	return 0;
}
