/*
构造队列
小明同学把1到n这n个数字按照一定的顺序放入了一个队列Q中。现在他对队列Q执行了如下程序：

while(!Q.empty())       //队列不空，执行循环
{
 int x=Q.front();      //取出当前队头的值x
 Q.pop();         //弹出当前队头
 Q.push(x);        //把x放入队尾
 x = Q.front();       //取出这时候队头的值
 printf("%d\n",x);     //输出x
 Q.pop();         //弹出这时候的队头
}
做取出队头的值操作的时候，并不弹出当前队头。 小明同学发现，这段程序恰好按顺序输出了1,2,3,...,n。现在小明想让你构造出原始的队列，你能做到吗

输入格式
第一行一个整数T（T ≤ 100）表示数据组数，每组数据输入一个数n（1 ≤ n ≤ 100000）

输出格式
对于每组数据，输出一行，表示原始的队列。数字之间用一个空格隔开，不要在行末输出多余的空格.

输入样例
4
1
2
3
10
输出样例
1
2 1
2 1 3
8 1 6 2 10 3 7 4 9 5
*/


#include<iostream>
#include<string>
using namespace std;

void solution_2(int n) {
	//小明的输出
	int* a = new int[n];
	//还原队列
	//一个隔一个放数字

	int k = 1, pos = 1, cnt = 1;
	if (n == 1)a[0] = 1;
	else {
		while (k <= n) {
			if (cnt == 1) {
				while (a[pos] != 0) {
					pos = (pos + 1) % n;
				}
				a[pos] = k;
				k++;
				cnt = 0;
			}
			else {
				if (a[pos] == 0)cnt++;
			}
			pos = (pos + 1) % n;
		}
	}


	//输出
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
	return;
}


int main() {
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		solution_2(n);
	}
	return 0;
}