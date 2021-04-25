
/*
*	Copyright (c) 2020,华工电信
*	All rights reserved.

*	文件名称：data.cpp
*	版本：1.0
*	作 者：杨杰尧

*	Creation Date:     20200518
*	Last Modified:     20200523

*	摘 要：
*	本程序模拟了飞机值机系统的显示例程。

*/
#include"data.h"
//初始化链表
int writein(LinkList& L, ofstream &outstuf) {
	outstuf.open("乘客信息.txt",ios::out|ios::app);
	if (!L->next) { outstuf.close(); return ERROR; }
	LinkList p;
	p = L->next;
	for (int i = 0; i < 4; i++) {
		outstuf << p->data[i] << " ";
	}
	outstuf << '\n';
	outstuf.close();
	return OK;
}
int load(LinkList& L, ifstream &instuf) {
	instuf.open("乘客信息.txt", ios::in);
	string x, y, a, b;
	while (instuf >> x >> y >> a >> b) {
		string data[4] = { x,y,a,b };
		add_data(L, data);
	}
	instuf.close();
	return OK;
}
void init_linklist(LinkList& L) {
	L = (LinkList)malloc(sizeof(Lnode));
	L->next = NULL;
}
//链表增加元素
int add_data(LinkList& L, const string* a) {
	LinkList q;
	q = new Lnode();
	for (int i = 0; i < 4; i++) {
		q->data[i] = a[i];
	}
	q->next = L->next;
	L->next = q;
	return OK;
}
//链表遍历
int traverse_linklist(LinkList L) {
	if (!L->next) return ERROR;
	LinkList p;
	p = L->next;
	cout << setiosflags(ios::left) << setw(10) << "姓名" << setw(10) << "性别" << setw(18) << "身份证号" << setw(10) << "座位" << endl;
	while (p) {
		for (int i = 0; i < 2; i++)
		{
			cout << setiosflags(ios::left) << setw(10) << p->data[i];
		}
		cout << setiosflags(ios::left) << setw(18) << p->data[2];
		cout << setiosflags(ios::left) << setw(10) << p->data[3];
		p = p->next;
		cout << endl;
	}
	return OK;
}
//链表节点删除
int delete_lnode(LinkList& L, string a, string b) {
	if (!L->next) return ERROR;
	LinkList q;
	q = L->next;
	if (!q->next) {
		if (a != q->data[0])return ERROR;
		else {
			if (b == q->data[2]) {
				free(q); L->next = NULL; return OK;
			}
			else return ERROR;
		}
	}
	while (q->next && a != q->next->data[0]) {
		q = q->next;
	}
	if (b == q->next->data[2]) {
		Lnode* p;
		p = q->next;
		q->next = p->next;
		free(p);
	}
	return OK;
}
//座位查询
int check_seat(LinkList L, string a, string b) {
	if (!L->next) return ERROR;
	LinkList q;
	int i = 0;
	q = L->next;
	for (; q; q = q->next) {
		if (a == q->data[0] && b == q->data[2])
		{
			i += 1; break;
		}
	}
	if (!i) { return ERROR; }
	else {
		cout <<endl<< "查询得到座位:" << q->data[3]<<endl;
		return OK;
	}
}
//座位防重复机制
int deter_seat(LinkList L, string a) {
	LinkList q;
	int i = 0;
	q = L->next;
	for (; q; q = q->next) {
		if (a == q->data[3]) {
			return ERROR;
		}
	}
	return OK;
}





