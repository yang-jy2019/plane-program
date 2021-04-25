
/*
*	Copyright (c) 2020,华工电信
*	All rights reserved.

*	文件名称：main.cpp （main）
*	版本：1.0
*	作 者：杨杰尧

*	Creation Date:     20200518
*	Last Modified:     20200523

*	摘 要：
*	控制台UI编程例程。本程序模拟了飞机值机系统的显示例程。

*/
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
#include<windows.h>
#include"cursor.h"
#include"data.h"
#include<string>
#include<iomanip>
#include<vector>
using namespace std;
int main() {
	LinkList T;
	init_linklist(T);
	ifstream instuf;
	load(T, instuf);
	HANDLE hout;
	hout = initiate();
	while (1) {
		int a = 0;
		int	b = 0;
		pos(0, 0, hout);
		WORD cyan = FOREGROUND_BLUE | FOREGROUND_GREEN;
		SetConsoleTextAttribute(hout, cyan);
		cout << "wsad控制上下左右选择，空格键确认";
		white_back(hout);
		face(hout);
		char i;
		i = facecontrol(hout);
		system("cls");
		switch (i) {
		case '1': {
			//值机界面的信息录入及界面创建
			string m, n, k;
			pos(27, 2, hout);
			important(hout);
			cout << "信息录入";
			white_back(hout);
			pos(0, 4, hout);
			cout << "请输入名字:";
			cin >> m;
			cout << endl;
			cout << "性别:";
			cin >> n;
			cout << endl;
			cout << "身份证号码:";
			cin >> k;
			cout << endl;
			SetConsoleTitle("值机系统");
			SMALL_RECT rc = { 0,0,100 - 1,50 - 1 };
			SetConsoleWindowInfo(hout, true, &rc);
			pos(0, 0, hout);
			WORD cyan = FOREGROUND_BLUE | FOREGROUND_GREEN;
			SetConsoleTextAttribute(hout, cyan);
			cout << "wsad控制上下左右选择，空格键确认";
			white_back(hout);
			for (int j = 7; j < 35; j++) {
				pos(18, j, hout);
				cout << "╂";
				pos(42, j, hout);
				cout << "╂" << endl;
			}
			pos(18, 5, hout);
			chose_block(hout);
			cout << "红色";
			white_back(hout);
			cout << " 座位为已选，";
			green_block(hout);
			cout<<"绿色";
			white_back(hout); 
			cout<<"座位为可选";
			pos(23, 10, hout);
			cout << "A    " << "B    " << "C    " << "D";
			for (int k = 12; k < 32; k++) {
				if ((k - 11) < 10)
				{
					pos(14, k, hout);
					cout << k - 11 << "排";
				}
				else {
					if (k < 30)
					{
						pos(13, k, hout);
						cout << k - 11 << "排";
					}
					else {
						pos(7, k, hout);
						cout << "吸烟区" << k - 11 << "排";
					}
				}
			}
			start(hout);
			int x = 22; int y = 12;
			char inputketboard;
			inputketboard = _getch();
			//通过输入控制光标进行选择
			while (inputketboard != ' ') {
				start(hout);
				switch (inputketboard) {
				case 'w':
					y = y - 1;
					break;
				case 's':
					y = y + 1;
					break;
				case 'a':
					x = x - 5;
					break;
				case 'd':
					x = x + 5;
					break;
				}
				if (x >= 37)
				{
					x = 37;
				}
				if (y >= 32)
				{
					y = 32;
				}
				if (x <= 22)
				{
					x = 22;
				}
				if (y <= 12)
				{
					y = 12;
				}
				pos(x, y, hout);
				a = x;
				b = y;
				onChoose(x, y, hout);
				chose(T, hout);
				inputketboard = _getch();
			}
			string l;
			string o = "";
			switch (a) {
			case 22:l = "A"; break;
			case 27:l = "B"; break;
			case 32:l = "C"; break;
			case 37:l = "D";
			}
			b = b - 11;
			start(hout);
			pos(0, 35, hout);
			white_back(hout);
			cout << "选择成功!" << endl;
			cout << "位置:" << b << l << endl;
			o += to_string(b);
			o += l;
			string g[] = { m,n,k,o };
			if (deter_seat(T, o)) {
				add_data(T, g);
				cout << endl << "值机成功，按任意键返回主界面..." << endl;
			}
			else cout << "值机失败，位置已被选择，按任意键返回主界面..." << endl;
			_getch();
			system("cls");
			ofstream outstuf;
			writein(T, outstuf);
			break;
		}
		case '2': {
			//管理员身份查询信息，密码为00000000
			string a;
			pos(27, 2, hout);
			important(hout);
			cout << "管理员身份信息统计";
			white_back(hout);
			pos(0, 4, hout);
			cout << "请输入管理员密码:";
			cin >> a;
			if (a == "00000000") {
			traverse_linklist(T);
			cout <<endl<< "查询成功，按任意键返回主界面..." << endl;
			_getch();
			system("cls"); break; }
			else { cout << "管理员密码输入错误,"; 		
			cout << "按任意键返回主界面..." << endl;
			_getch();
			system("cls"); 
			break;
			}
		}
		case'3': {
			//进行座位取消
			string a, b;
			pos(27, 2, hout);
			important(hout);
			cout << "取消座位";
			white_back(hout);
			pos(0, 4, hout);
			cout << "请输入取消乘客名字:" << endl;
			cin >> a;
			cout << "请输入取消乘客身份证:" << endl;
			cin >> b;
			if (!delete_lnode(T, a, b))
			{
				cout << "无此乘客，按任意键返回主界面..." << endl;
				_getch();
				system("cls");
				break;
			}
			else
			{
				cout << '\n' << "取消成功，按任意键返回主界面..." << endl;
				_getch();
				system("cls");
				break;
			}
		}
		case'4':{
			//进行座位查询
			string a, b;
			pos(27, 2, hout);
			important(hout);
			cout << "座位查询";
			white_back(hout);
			pos(0, 4, hout);
			cout << "请输入查询名字:" << endl;
			cin >> a;
			cout << "请输入查询人身份证:" << endl;
			cin >> b;
			if (!check_seat(T, a, b))
			{
				cout << "无此查询结果，按任意键返回主界面..." << endl;
				_getch();
				system("cls");
				break;
			}
			else
			{
				cout <<'\n'<< "查询成功，按任意键返回主界面..." << endl;
				_getch();
				system("cls");
				break;
			} 
		}
		}
		
	}	
	CloseHandle(hout);
}
