
/*
*	Copyright (c) 2020,华工电信
*	All rights reserved.

*	文件名称：cursor.h
*	版本：1.0
*	作 者：杨杰尧

*	Creation Date:     20200518
*	Last Modified:     20200523

*	摘 要：
*	本程序模拟了飞机值机系统的显示例程。

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