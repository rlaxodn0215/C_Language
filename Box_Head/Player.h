#pragma once
#include"GameSystem.h"
#include"Weapon.h"

typedef struct 
{
	char name[20];
	int Hp;
	int posX;
	int posY;
	int points;
	struct Weapon *weapon;

}Player;

void PlayerBeacon(int posX, int posY);
void ShowHP(int posX, int posY, Player* player);
void Score(int posX, int posY, Player* player);
void PlayerMove(Player* player,Weapon *weapon, int mapNum);
void PlayerAttack(Player* player, Weapon* weapon,int max_cols, int max_lines);
void PlayerDamaged();
void PlayerDead();

