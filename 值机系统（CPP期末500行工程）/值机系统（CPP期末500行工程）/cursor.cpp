
/*
*	Copyright (c) 2020,华工电信
*	All rights reserved.

*	文件名称：cursor.cpp
*	版本：1.0
*	作 者：杨杰尧

*	Creation Date:     20200518
*	Last Modified:     20200523

*	摘 要：
*	本程序模拟了飞机值机系统的显示例程。

*/
#include"cursor.h"
HANDLE initiate()
{

	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	return hout;
}
//设计初始界面
void face(HANDLE hout) {
	pos(40, 1, hout);
	important(hout);
	cout << "飞机值机系统(请选择功能)"<<endl;
	white_back(hout);
	pos(20, 5, hout);
	cout << "1、值机";
	pos(40, 5, hout);
	cout << "2、统计信息";
	pos(60, 5, hout);
	cout << "3、取消座位";
	pos(80, 5, hout);
	cout << "4、查询座位";
}
//设计变化界面
void faceexcept(HANDLE hout,int x) {
	pos(40, 1, hout);
	important(hout);
	cout << "飞机值机系统(请选择功能)" << endl;
	white_back(hout);
	if (x != 20)
	{
		pos(20, 5, hout);
		cout << "1、值机";
	}
	if (x != 40) {
		pos(40, 5, hout);
		cout << "2、统计信息";
	}
	if (x != 60){
		pos(60, 5, hout);
		cout << "3、取消座位";
	}
	if (x != 80) {
		pos(80, 5, hout);
		cout << "4、查询座位";
	}
}
char facecontrol(HANDLE hout) {
	int x = 20; int y = 5;
	char inputketboard;
	inputketboard = _getch();
	char b='1';
	while (inputketboard != ' ') {
		face(hout);
		switch (inputketboard) {
		case 'a':
		{x = x - 20;
		break; }
		case 'd':
		{x = x + 20;
		break; }
		}
		if (x >= 80)
		{
			x = 80;
		}
		if (x <= 20)
		{
			x = 20;
		}
		switch (x) {
		case 20: {
			red_block(hout);
			pos(20, 5, hout);
			cout << "1、值机"; 
			b = '1'; 
			white_back(hout);
			break; }
		case 40: {
			red_block(hout);
			pos(40, 5, hout);
			cout << "2、统计信息"; 
			b = '2'; 
			white_back(hout);
			break; }
		case 60: {
			red_block(hout);
			pos(60, 5, hout);
			cout << "3、取消座位";
			b = '3'; 
			white_back(hout);
			break; }
		case 80: {
			red_block(hout);
			pos(80, 5, hout);
			cout << "4、查询座位";
			b = '4'; 
			white_back(hout);
			break; }
		}
		faceexcept(hout, x);
		inputketboard = _getch();
		white_back(hout);
	}
	return b;
}
//光标位置设置
void pos(int x, int y,HANDLE hout) {
	COORD pospoint = { x,y };
	SetConsoleCursorPosition(hout, pospoint);
}
//字体颜色设置
void green_block(HANDLE hout) {
	WORD green = FOREGROUND_GREEN | BACKGROUND_BLUE;
	SetConsoleTextAttribute(hout, green);
}
void white_back(HANDLE hout) {
	WORD white = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY;
	SetConsoleTextAttribute(hout, white);
}
void red_block(HANDLE hout) {
	WORD red = FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN;
	SetConsoleTextAttribute(hout, red);
}
//设计值机初始界面
void start(HANDLE hout) {
	green_block(hout);
	for (int i = 22; i < 39; i += 5) {
		for (int j = 12; j < 32; j++) {
			pos(i, j,hout);
			switch (i) {
			case 22:cout << j - 11 << "A"; break;
			case 27:cout << j - 11 << "B"; break;
			case 32:cout << j - 11 << "C"; break;
			case 37:cout << j - 11 << "D";
			}
		}
	}
}
void important(HANDLE hout) {
	WORD important = FOREGROUND_RED | FOREGROUND_INTENSITY;
	SetConsoleTextAttribute(hout, important);
};
void chose_block(HANDLE hout) {
	WORD important = FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_RED;
	SetConsoleTextAttribute(hout, important);
};
//设计值机按键被选择界面
void onChoose(int x, int y,HANDLE hout) {
	for (int i = 22; i < 39; i += 5) {
		for (int j = 12; j < 32; j++) {
			if (x == i && y == j) {
				red_block( hout);
				pos(i, j,hout);
				switch (i) {
				case 22:cout << j - 11 << "A"; break;
				case 27:cout << j - 11 << "B"; break;
				case 32:cout << j - 11 << "C"; break;
				case 37:cout << j - 11 << "D";
				}
			}
		}
	}
	for (int i = 22; i < 39; i += 5) {
		for (int j = 12; j < 32; j++) {
			if (x != i && y != j) {
				green_block(hout);
				pos(i, j,hout);
				switch (i) {
				case 22:cout << j - 11 << "A"; break;
				case 27:cout << j - 11 << "B"; break;
				case 32:cout << j - 11 << "C"; break;
				case 37:cout << j - 11 << "D";
				}
			}
		}
	}
}
//设计值机座位已被选择座位显示
void chose(LinkList L, HANDLE hout) {
	if (!L->next) return;
	LinkList q;
	q = L->next;
	for (; q; q = q->next) {
		string a = q->data[3];
		int x = 0;
		int y= 0;
		int i = 0;
		while (i < a.length()) {
			if ('0' <= a.at(i) && a.at(i) <= '9') {
				y = y * 10 + (a.at(i) - '0');
			}
			else {
				switch (a.at(i)) {
				case 'A':x = 22; break;
				case 'B':x = 27; break;
				case 'C':x = 32; break;
				case 'D':x = 37; break;
				}
			}
			i++;
		}
		y = y + 11;
		for (int i = 22; i < 39; i += 5) {
			for (int j = 12; j < 32; j++) {
				if (x == i && y == j) {
					chose_block(hout);
					pos(i, j, hout);
					switch (i) {
					case 22:cout << j - 11 << "A"; break;
					case 27:cout << j - 11 << "B"; break;
					case 32:cout << j - 11 << "C"; break;
					case 37:cout << j - 11 << "D"; break;
					}
				}
			}
		}
	}
	pos(0, 0,hout);
}

