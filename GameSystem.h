#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
#include<conio.h>
#include<time.h>

#define PLAYER_BORN_X (55) //�÷��̼� ���� X��ǥ // 55
#define PLAYER_BORN_Y (17) //�÷��̼� ���� Y��ǥ // 15

#define ZOMBIE_BORN_X (15) //���� ���� X��ǥ
#define ZOMBIE_BORN_Y (7) //���� ���� Y��ǥ

void GotoXY(int x, int y);
void StartScene();
void DrawMap(char(*map)[60]);
void GameOver();

