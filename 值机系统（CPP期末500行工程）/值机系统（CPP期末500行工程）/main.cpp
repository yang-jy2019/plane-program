
/*
*	Copyright (c) 2020,��������
*	All rights reserved.

*	�ļ����ƣ�main.cpp ��main��
*	�汾��1.0
*	�� �ߣ����Ң

*	Creation Date:     20200518
*	Last Modified:     20200523

*	ժ Ҫ��
*	����̨UI������̡�������ģ���˷ɻ�ֵ��ϵͳ����ʾ���̡�

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
		cout << "wsad������������ѡ�񣬿ո��ȷ��";
		white_back(hout);
		face(hout);
		char i;
		i = facecontrol(hout);
		system("cls");
		switch (i) {
		case '1': {
			//ֵ���������Ϣ¼�뼰���洴��
			string m, n, k;
			pos(27, 2, hout);
			important(hout);
			cout << "��Ϣ¼��";
			white_back(hout);
			pos(0, 4, hout);
			cout << "����������:";
			cin >> m;
			cout << endl;
			cout << "�Ա�:";
			cin >> n;
			cout << endl;
			cout << "���֤����:";
			cin >> k;
			cout << endl;
			SetConsoleTitle("ֵ��ϵͳ");
			SMALL_RECT rc = { 0,0,100 - 1,50 - 1 };
			SetConsoleWindowInfo(hout, true, &rc);
			pos(0, 0, hout);
			WORD cyan = FOREGROUND_BLUE | FOREGROUND_GREEN;
			SetConsoleTextAttribute(hout, cyan);
			cout << "wsad������������ѡ�񣬿ո��ȷ��";
			white_back(hout);
			for (int j = 7; j < 35; j++) {
				pos(18, j, hout);
				cout << "��";
				pos(42, j, hout);
				cout << "��" << endl;
			}
			pos(18, 5, hout);
			chose_block(hout);
			cout << "��ɫ";
			white_back(hout);
			cout << " ��λΪ��ѡ��";
			green_block(hout);
			cout<<"��ɫ";
			white_back(hout); 
			cout<<"��λΪ��ѡ";
			pos(23, 10, hout);
			cout << "A    " << "B    " << "C    " << "D";
			for (int k = 12; k < 32; k++) {
				if ((k - 11) < 10)
				{
					pos(14, k, hout);
					cout << k - 11 << "��";
				}
				else {
					if (k < 30)
					{
						pos(13, k, hout);
						cout << k - 11 << "��";
					}
					else {
						pos(7, k, hout);
						cout << "������" << k - 11 << "��";
					}
				}
			}
			start(hout);
			int x = 22; int y = 12;
			char inputketboard;
			inputketboard = _getch();
			//ͨ��������ƹ�����ѡ��
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
			cout << "ѡ��ɹ�!" << endl;
			cout << "λ��:" << b << l << endl;
			o += to_string(b);
			o += l;
			string g[] = { m,n,k,o };
			if (deter_seat(T, o)) {
				add_data(T, g);
				cout << endl << "ֵ���ɹ��������������������..." << endl;
			}
			else cout << "ֵ��ʧ�ܣ�λ���ѱ�ѡ�񣬰����������������..." << endl;
			_getch();
			system("cls");
			ofstream outstuf;
			writein(T, outstuf);
			break;
		}
		case '2': {
			//����Ա��ݲ�ѯ��Ϣ������Ϊ00000000
			string a;
			pos(27, 2, hout);
			important(hout);
			cout << "����Ա�����Ϣͳ��";
			white_back(hout);
			pos(0, 4, hout);
			cout << "���������Ա����:";
			cin >> a;
			if (a == "00000000") {
			traverse_linklist(T);
			cout <<endl<< "��ѯ�ɹ��������������������..." << endl;
			_getch();
			system("cls"); break; }
			else { cout << "����Ա�����������,"; 		
			cout << "�����������������..." << endl;
			_getch();
			system("cls"); 
			break;
			}
		}
		case'3': {
			//������λȡ��
			string a, b;
			pos(27, 2, hout);
			important(hout);
			cout << "ȡ����λ";
			white_back(hout);
			pos(0, 4, hout);
			cout << "������ȡ���˿�����:" << endl;
			cin >> a;
			cout << "������ȡ���˿����֤:" << endl;
			cin >> b;
			if (!delete_lnode(T, a, b))
			{
				cout << "�޴˳˿ͣ������������������..." << endl;
				_getch();
				system("cls");
				break;
			}
			else
			{
				cout << '\n' << "ȡ���ɹ��������������������..." << endl;
				_getch();
				system("cls");
				break;
			}
		}
		case'4':{
			//������λ��ѯ
			string a, b;
			pos(27, 2, hout);
			important(hout);
			cout << "��λ��ѯ";
			white_back(hout);
			pos(0, 4, hout);
			cout << "�������ѯ����:" << endl;
			cin >> a;
			cout << "�������ѯ�����֤:" << endl;
			cin >> b;
			if (!check_seat(T, a, b))
			{
				cout << "�޴˲�ѯ����������������������..." << endl;
				_getch();
				system("cls");
				break;
			}
			else
			{
				cout <<'\n'<< "��ѯ�ɹ��������������������..." << endl;
				_getch();
				system("cls");
				break;
			} 
		}
		}
		
	}	
	CloseHandle(hout);
}
