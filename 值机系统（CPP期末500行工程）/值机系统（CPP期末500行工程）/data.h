
/*
*	Copyright (c) 2020,华工电信
*	All rights reserved.

*	文件名称：data.h
*	版本：1.0
*	作 者：杨杰尧

*	Creation Date:     20200518
*	Last Modified:     20200523

*	摘 要：
*	本程序模拟了飞机值机系统的显示例程。

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