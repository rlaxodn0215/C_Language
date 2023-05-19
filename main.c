#include"Map.h"
#include"GameSystem.h"
#include"Weapon.h"
#include"Player.h"
#include"Zombie.h"

int main()
{
	srand(time(NULL));
	StartScene();

	Weapon weap = { "pistol",1,5,200,9,0 };
	Weapon* weapon = &weap;
	Player ply = {"player",100,PLAYER_BORN_X ,PLAYER_BORN_Y,0,NULL};
	Player* player = &ply;
	player->weapon = weapon;
	Zombie zombie[10]; //좀비 최대 10마리 소환, 죽으면 일정 시간이 지난 후 부활

	// 맵 UI
	DrawMap(map_0);

	PlayerBeacon(PLAYER_BORN_X, PLAYER_BORN_Y,map_0);

	int zombieMoveTimer = 0;
	int zombieSpawnTimer = 0;
	int zombieNum = 1;
	
	for (int i = 0; i < 10; i++)
	{
		zombie[i].posX = ZOMBIE_BORN_X;
		zombie[i].posY = ZOMBIE_BORN_Y;
		zombie[i].Hp = 4;
		zombie[i].damage = 10;
		zombie[i].zombieDead = 0;
		zombie[i].points = 50;	
		zombie[i].sight = 6;	
	}

	ZombieBeacon(ZOMBIE_BORN_X, ZOMBIE_BORN_Y,map_0,zombie,0);

	while ((player->Hp)>0)
	{
		PlayerMove(player,player->weapon,map_0);

		//플레이어 정보 UI
		ShowHP(61, 1, player);
		ShowAmmo(61, 3, weapon);
		WeaponName(61, 5, player->weapon);
		Score(61, 7, player);

		ControlZombieHP(player, weapon, zombie, zombieNum, map_0);
		if (zombieMoveTimer > 6000)
		{
			for (int i = 0; i < zombieNum; i++)
			{
				ZombieMove(player, zombie, i, map_0);
			}
			zombieMoveTimer = 0;
		}
		zombieMoveTimer++;

		if (zombieSpawnTimer > 100000 && zombieNum<3)
		{
			ZombieBeacon(ZOMBIE_BORN_X, ZOMBIE_BORN_Y, map_0,zombie,zombieNum);
			zombieNum++;
			zombieSpawnTimer = 0;
		}
		zombieSpawnTimer++;

	}

	ShowHP(61, 1, player);
	GameOver();

	return 0;
}
