
/*
*	Copyright (c) 2020,��������
*	All rights reserved.

*	�ļ����ƣ�cursor.cpp
*	�汾��1.0
*	�� �ߣ����Ң

*	Creation Date:     20200518
*	Last Modified:     20200523

*	ժ Ҫ��
*	������ģ���˷ɻ�ֵ��ϵͳ����ʾ���̡�

*/
#include"cursor.h"
HANDLE initiate()
{

	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	return hout;
}
//��Ƴ�ʼ����
void face(HANDLE hout) {
	pos(40, 1, hout);
	important(hout);
	cout << "�ɻ�ֵ��ϵͳ(��ѡ����)"<<endl;
	white_back(hout);
	pos(20, 5, hout);
	cout << "1��ֵ��";
	pos(40, 5, hout);
	cout << "2��ͳ����Ϣ";
	pos(60, 5, hout);
	cout << "3��ȡ����λ";
	pos(80, 5, hout);
	cout << "4����ѯ��λ";
}
//��Ʊ仯����
void faceexcept(HANDLE hout,int x) {
	pos(40, 1, hout);
	important(hout);
	cout << "�ɻ�ֵ��ϵͳ(��ѡ����)" << endl;
	white_back(hout);
	if (x != 20)
	{
		pos(20, 5, hout);
		cout << "1��ֵ��";
	}
	if (x != 40) {
		pos(40, 5, hout);
		cout << "2��ͳ����Ϣ";
	}
	if (x != 60){
		pos(60, 5, hout);
		cout << "3��ȡ����λ";
	}
	if (x != 80) {
		pos(80, 5, hout);
		cout << "4����ѯ��λ";
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
			cout << "1��ֵ��"; 
			b = '1'; 
			white_back(hout);
			break; }
		case 40: {
			red_block(hout);
			pos(40, 5, hout);
			cout << "2��ͳ����Ϣ"; 
			b = '2'; 
			white_back(hout);
			break; }
		case 60: {
			red_block(hout);
			pos(60, 5, hout);
			cout << "3��ȡ����λ";
			b = '3'; 
			white_back(hout);
			break; }
		case 80: {
			red_block(hout);
			pos(80, 5, hout);
			cout << "4����ѯ��λ";
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
//���λ������
void pos(int x, int y,HANDLE hout) {
	COORD pospoint = { x,y };
	SetConsoleCursorPosition(hout, pospoint);
}
//������ɫ����
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
//���ֵ����ʼ����
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
//���ֵ��������ѡ�����
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
//���ֵ����λ�ѱ�ѡ����λ��ʾ
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

