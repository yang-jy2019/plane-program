
/*
*	Copyright (c) 2020,��������
*	All rights reserved.

*	�ļ����ƣ�cursor.h
*	�汾��1.0
*	�� �ߣ����Ң

*	Creation Date:     20200518
*	Last Modified:     20200523

*	ժ Ҫ��
*	������ģ���˷ɻ�ֵ��ϵͳ����ʾ���̡�

*/
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include<conio.h>
#include<stdlib.h>
#include<vector>
#include"data.h"
using namespace std;
void face(HANDLE hout);
void faceexcept(HANDLE hout, int x);
char facecontrol(HANDLE hout);
void pos(int x, int y,HANDLE hout);
void green_block(HANDLE hout);
void white_back(HANDLE hout);
void red_block(HANDLE hout);
void start(HANDLE hout);
void onChoose(int x, int y,HANDLE hout);
void important(HANDLE hout);
void chose(LinkList L, HANDLE hout);
void chose_block(HANDLE hout);
HANDLE initiate();