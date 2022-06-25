/*
简单计算器
实现一个基本的计算器来计算一个简单的字符串表达式的值。字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，乘号x，非负整数。
你可以假设所给定的表达式都是有效的。

输入格式
一个字符串表达式。其中，括号为英文字符，乘号为小写字母x，非负整数n(0 ≤ n ≤ 9)。

输出格式
对于一个输入，输出一行，表示字符串表达式的计算结果res(|res| ≤ 1e16)

输入样例
(1+(4+5x2)-3)-(6+((8)))
输出样例
-2
限制
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

//操作符的优先级
int order[1000] = { 0 };
void init_order() {
	order['+'] = 1;
	order['-'] = 1;
	order['x'] = 2;
	order['('] = 0;
	order[')'] = 3;
	return;
}

//单次运算
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

	//处理最后的操作符和多项式名
	while (!opn.isEmpty()) {
		int a = rpn.pop();
		int b = rpn.pop();
		int res = scal(opn.pop(), a, b);
		rpn.push(res);
	}
	return rpn.peek();
}


void solution_1() {
	//读入表达式
	string s; cin >> s;

	stack<int> rpn;//运算数栈
	stack<char>opn;//符号栈
	init_order();//初始化运算符优先级数组
	//构建逆波兰表达式并计算
	int res = Poly_setup(s, rpn, opn);

	//printStack(rpn);


	cout << res << endl;
	return;
}


int main() {
	solution_1();
	return 0;
}
