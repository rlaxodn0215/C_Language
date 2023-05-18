#pragma once
#include"GameSystem.h"
#include "Player.h"

typedef struct
{
	int Hp;
	int posX;
	int posY;
	int damage;
	int points;

}Zombie;

void ZombieBeacon(int posX,int posY);
void ZombeSpawn();
void ZombieMove(Player *player);
void ZombieAttack();
void ZombieDamaged();
void ZombieDead();
