#include"GameSystem.h"
#include"Weapon.h"
#include"Player.h"
#include"Zombie.h"

int main()
{
	StartScene();

	Weapon weap = { "pistol",1,5,100,9 };
	Weapon* weapon = &weap;
	Player ply = {"player",100,PLAYER_BORN_X ,PLAYER_BORN_Y,0,NULL};
	Player* player = &ply;
	player->weapon = weapon;
	Zombie zombie[30]; //좀비 최대 30마리 소환

	// 맵 UI
	DrawMap(0);
	ShowHP(60, 3, player);
	Score(60, 5, player);
	WeaponName(60, 7, player->weapon);

	PlayerBeacon(PLAYER_BORN_X, PLAYER_BORN_Y);
	ZombieBeacon(ZOMBIE_BORN_X, ZOMBIE_BORN_Y);

	while (1)
	{
		PlayerMove(player,player->weapon,0);
		ZombieMove(player);
	}

	return 0;
}
