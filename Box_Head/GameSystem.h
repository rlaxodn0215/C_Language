#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>
#include<conio.h>
#include<process.h>

#define MAP_COLS (50) // map 가로 길이
#define MAP_LINES (20) // map 세로 길이

#define PLAYER_BORN_X (48) //플레이서 생성 X좌표
#define PLAYER_BORN_Y (18) //플레이서 생성 Y좌표

#define ZOMBIE_BORN_X (2) //좀비 생성 X좌표
#define ZOMBIE_BORN_Y (2) //좀비 생성 Y좌표

void GotoXY(int x, int y);
void StartScene();
void DrawMap(int mapNum);
void Rank();
void GameOver();