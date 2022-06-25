/*
题目描述
给出两个非负整数，第一个为被减数，第二个为减数，实现程序计算两者相减的结果。

可能出现数值较大的数字，请使用适当的数据结构存储数字并计算。

输入格式
两行，第一行为被减数，第二行为减数。

输出格式
一行，完整的减法计算的结果。
*/

#include <iostream>
#include<string>
using namespace std;

bool greaterNum(string a, string b) {//比较数a,b大小
	if (a.size() > b.size())return true;//位数比较
	else if (a.size() < b.size())return false;
	else {//位数相等时从高位向低位比较各位数值
		for (int i = 0; i < a.size(); i++) {
			if (a[i] > b[i])return true;
			else if (a[i] < b[i])return false;
			//若当前位相同则看低位继续比较
		}
	}
	return false;
}


string calculate_minus(string a, string b) {//进行减法运算
	string c;//用于存储运算结果
	int CF = 0;//借位助记符
	//低位向高位进行减法运算
	int i, j;
	for (i = a.size() - 1, j = b.size() - 1; i >= 0 && j >= 0; i--, j--) {
		int t = (a[i] - b[j]) - CF;
		if (t >= 0) {//当前位减法结果>=0，借位助记符清零，否则为1
			c = to_string(t) + c; CF = 0;
		}
		else {
			t += 10;//借位
			c = to_string(t) + c; CF = 1;
		}
	}
	while (i >= 0) {//对于a,b长度不相等时多余位的处理 ***需要注意借位助记符的影响仍然存在
		int t = a[i] - '0' - CF;
		if (t < 0) {
			t += 10; CF = 1;
		}
		else {
			CF = 0;
		}
		c = to_string(t) + c;
		i--;
	}
	//删去运算结果高位多余的0
	for (int i = 0; i < c.size(); i++) {
		if (c[i] == '0') {
			c = c.substr(i + 1, c.size());
			i--;
		}
		else break;
	}
	return c;
}
int solution_3() {
	string a, b;
	cin >> a >> b;
	string c;
	if (a == b)c = '0';
	else if (greaterNum(a, b)) {
		c = calculate_minus(a, b);
	}
	else {
		c = '-' + calculate_minus(b, a);
	}
	cout << c << endl;
	return 0;
}