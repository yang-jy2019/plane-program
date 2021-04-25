
/*
*	Copyright (c) 2020,��������
*	All rights reserved.

*	�ļ����ƣ�data.h
*	�汾��1.0
*	�� �ߣ����Ң

*	Creation Date:     20200518
*	Last Modified:     20200523

*	ժ Ҫ��
*	������ģ���˷ɻ�ֵ��ϵͳ����ʾ���̡�

*/
#pragma once
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<fstream>
#define OK 1
#define ERROR 0
using namespace std;
typedef struct Lnode {
	string data[4];
	struct Lnode* next;
}Lnode, * LinkList;
int writein(LinkList& L,ofstream &outstuf);
int load(LinkList& L,ifstream &instuf);
void init_linklist(LinkList& L);
int add_data(LinkList& L, const string *a);
int traverse_linklist(LinkList L);
int delete_lnode(LinkList& L, string a, string b);
int check_seat(LinkList L, string a, string b);
int deter_seat(LinkList L, string a);