/*
题目描述
开学后小蓝鲸们为了交朋友想要举行聚会。但是由于疫情，聚会需要控制人数，所以组织者提出了一个解决方案来选择能够聚会的小蓝鲸。
所有人排好队，一个接一个。每个人都得到一个号码，第一个2号，第二个3号，第三个4号，依次类推。
第一位小蓝鲸说出他的号码2，不用退出，可以参与聚会，但是在他后面的每2位（号码是4、6、8等）小蓝鲸必须离开聚会。
剩下的队伍中的下一个小蓝鲸说出他的号码3，他可以参与聚会，但在他后面的每3位（号码是9、15、21等）小蓝鲸必须离开聚会。
剩下的队伍中的下一个小蓝鲸说出他的号码5，他可以参与聚会，但是在他后面的每5位(号码是19、35、49等)小蓝鲸必须离开聚会。
下一个号码是7，他可以继续聚会，但在他后面的每隔7位就得离开，如此类推。 按照这个方案，能参与聚会的幸运小蓝鲸的号码是2、3、5、7、11、13、17等。
现在，请你找出第n个幸运数字。

输入格式
输入包含多个测试用例。 每个测试用例由一个整数n组成。 0在最后一个测试用例的输入之后。

输出格式
对于每个测试用例，在一行上输出第n个幸运号码。
*/

#include <iostream>
#include "1.h"
using namespace std;

const int stu_number = 40000;
int queue[stu_number][2];


struct Node {
	int val;
	Node* next;
	Node() { val = 0; next = NULL; }
	Node(int n) { val = n, next = NULL; }
};

Node* initial(int n) {
	Node* head = new Node(2);
	Node* cur = head;
	for (int i = 1; i < n; i++) {
		cur->next = new Node(i + 2);
		cur = cur->next;
	}
	cur->next = NULL;
	return head;
}

Node* getNode(Node* head, int n) {
	Node* cur = head;
	for (int i = 0; i < n && cur != NULL; i++) {
		cur = cur->next;
	}
	return cur;
}

void printList(Node* head) {
	Node* cur = head;
	int i = 1;
	while (cur != NULL) {
		cout << i << " : " << cur->val << endl;
		i++;
		cur = cur->next;
	}
	return;
}

int solution_1() {
	//初始化链表
	int n = 3000;
	Node* head = initial(stu_number);
	//cout << getVal(head, 10) << endl;
	//开始报数
	for (int i = 0; i < n; i++) {	//报n次数
		//获取开始报数的位置和数
		Node* cur = getNode(head, i);
		int cnt = cur->val;
		int cur_cnt = 0;
		while (cur != NULL) {
			if (cnt == cur_cnt + 1) {
				//删除下个节点
				cur_cnt = 0;
				if (cur->next != NULL) {
					Node* p = cur->next;
					cur->next = cur->next->next;
					delete p;
				}
			}
			//报数
			cur = cur->next;
			cur_cnt++;
		}
	}
	//打印链表
	//printList(head);
	//找到第n个结点
	int x = 0; cin >> x;
	while (x != 0) {
		Node* p = getNode(head, x - 1);
		cout << p->val << endl;
		cin >> x;
	}
	
	return 0;
}

