#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
#include<conio.h>
#include<process.h>

#define MAP_COLS (50) // map ���� ����
#define MAP_LINES (20) // map ���� ����

#define PLAYER_BORN_X (48) //�÷��̼� ���� X��ǥ
#define PLAYER_BORN_Y (18) //�÷��̼� ���� Y��ǥ

#define ZOMBIE_BORN_X (2) //���� ���� X��ǥ
#define ZOMBIE_BORN_Y (2) //���� ���� Y��ǥ

void GotoXY(int x, int y);
void StartScene();
void DrawMap(int mapNum);
void Rank();
void GameOver();