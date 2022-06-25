#include <iostream>
#include<string>
using namespace std;

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
			cur = cur->next;
			cur_cnt++;
		}
	}
	//打印链表
	printList(head);
	//找到第n个结点
	int x = 0; cin >> x;
	while (x != 0) {
		Node* p = getNode(head, x - 1);
		cout << p->val << endl;
		cin >> x;
	}

	return 0;
}
int main() {
	solution_1();
	return 0;
}