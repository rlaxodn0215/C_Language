#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>


char map1[25][40] = {
	{"1111111111111111111111111111111111111111"},
	{"1000000000000000000000000000000000000001"},
	{"1000000000000000000000000000000000000001"},
	{"1000000000000000000000000000000000000001"},
	{"1000000000000000000000000000000000000001"},
	{"1000000000000000000000000000000000000001"},
	{"1000000000000000000000000000000000000001"},
	{"1000000000000000000000000000000000000001"},
	{"1000000000000000000000000000000000000001"},
	{"1000000000000000000000000000000000000001"},
	{"1000000000000000000000000000000000000001"},
	{"1000000000000000000000000000000000000001"},
	{"1000000000000000000000000000000000000001"},
	{"1000000000000000000000000000000000000001"},
	{"1000000000000000000000000000000000000001"},
	{"1000000000000000000000000000000000000001"},
	{"1000000000000000000000000000000000000001"},
	{"1000000000000000000000000000000000000001"},
	{"1000000000000000000000000000000000000001"},
	{"1000000000000000000000000000000000000001"},
	{"1000000000000000000000000000000000000001"},
	{"1000000000000000000000000000000000000001"},
	{"1000000000000000000000000000000000000001"},
	{"1000000000000000000000000000000000000001"},
	{"1111111111111111111111111111111111111111"},
};

struct Player
{
	char name[20];
	int Hp;
	int posX;
	int posY;
	int way; //시계방향으로 12,3,6,9
	int points;
};

struct Zombie
{
	int posX;
	int posY;
	int Hp;
	int attackDamage;
};

void DrawMap(char(*map)[40], int row, int col);

void PlayerBeacon(char(*map)[40], int posX, int posY);
void PlayerMove(char(*map)[40], struct player *ply);
void PlayerDamage();

void MonsterBeacon(char(*map)[40], int posX, int posY);
void MonsterBorn(char(*map)[40], int posX, int posY);
void MonsterMove(struct Zombie* zom, struct Player* ply, int zombieNum, char(*map)[40]);
void MonsterAttack();

void GetPoints();
void PlayerShoot();

int main()
{

	//플레이어의 처음 위치
	int PlayerPosX=22;
	int PlayerPosY=36;

	//몬스터 소환 위치
	int MonsterPosX = 2;
	int MonsterPosY = 2;

	struct Player player = { "player", 10,PlayerPosX,PlayerPosY,12,0 };
	struct Player *you = &player;
	struct Zombie zombie[30]; //최대 좀비수 : 30마리


	PlayerBeacon(map1, PlayerPosX, PlayerPosY);
	MonsterBeacon(map1, MonsterPosX, MonsterPosY);
	
	zombie[0].posX = MonsterPosX;
	zombie[0].posY = MonsterPosY;
	zombie[0].Hp = 4;
	zombie[0].attackDamage = 0;

	while (you->Hp>0)
	{
		DrawMap(map1, 25, 40);
		//MonsterBorn();
		PlayerMove(map1, you);
		MonsterMove(zombie,you,0,map1);
	}
	/*printf("zombie.posX : %d, zombie.posY : %d\n", zombie[0].posX, zombie[0].posY);
	printf("player.posX : %d, player.posY : %d\n", player.posX, player.posY);
	system("pause");*/


	return 0;
}

void DrawMap(char(*map)[40], int row, int col)
{
	//0. 이동 가능 구간
	//1. 벽 (#)
	//2. 몬스터 비콘 ($)
	//3. 플레이어 비콘 (@)
	//4. 몬스터 (Z)
	//5. 플레이어 (P)
	//6. 총알 (o)

	system("cls");

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			int temp = map[i][j] - 48;
			switch (temp)
			{
			case 0:
			{
				printf(" ");
			}
			break;
			case 1:
			{
				printf("#");
			}
			break;
			case 2:
			{
				printf("$");
			}
			break;
			case 3:
			{
				printf("@");
			}
			break;
			case 4:
			{
				printf("Z");
			}
			break;
			case 5:
			{
				printf("P");
			}
			break;
			case 6:
			{
				printf("o");
			}
			break;
			default:
			{
				printf("잘못된 숫자 입력.\n");
			}
			break;
			}
		}

		printf("\n");
	}

	GetPoints();

}
void PlayerMove(char(*map)[40], struct Player *ply) //이동 : w,a,s,d 
{
	char temp = getch();

	if (temp == 'w') //위로 이동
	{
		if (map[(ply->posX)-1][(ply->posY)] != '1')
		{
			
			map[(ply->posX)][(ply->posY)] = '0';
			(ply->posX)--;
			map[(ply->posX)][(ply->posY)] = '5';
			(ply->way) = 12; // 총구방향 설정
			
		}
	}

	else if (temp == 'a') //왼쪽 이동
	{
		if (map[(ply->posX)][(ply->posY) -1] != '1')
		{
			map[(ply->posX)][(ply->posY)] = '0';
			(ply->posY)--;
			map[(ply->posX)][(ply->posY)] = '5';
			(ply->way) = 9;
		}
	}

	else if (temp == 's') //아래 이동
	{
		if (map[(ply->posX) +1][(ply->posY)] != '1')
		{
			map[(ply->posX)][(ply->posY)] = '0';
			(ply->posX)++;
			map[(ply->posX)][(ply->posY)] = '5';
			(ply->way) = 6;
			
		}
	}

	else if (temp == 'd') //오른쪽 이동
	{
		if (map[(ply->posX)][(ply->posY) + 1] != '1')
		{
			map[(ply->posX)][ply->posY] = '0';
			(ply->posY)++;
			map[(ply->posX)][ply->posY] = '5';
			(ply->way) = 3;
		}
	}
}
void MonsterMove(struct Zombie* zom,struct Player *ply, int zombieNum, char(*map)[40]) //좀비 위치로 구분하기
{

	if ((zom[zombieNum].posX - (ply->posX)) <= 0) //오른쪽으로 떨어져 있을 때
	{
		if (map[zom[zombieNum].posX][zom[zombieNum].posY + 1] != '1') //벽이 없으면
		{
			if ((zom[zombieNum].posY - (ply->posY)) < 0) //아래 방향으로 떨어져 있을 때
			{
				if (map[zom[zombieNum].posX + 1][zom[zombieNum].posY] != '1')
				{
					map[zom[zombieNum].posX][zom[zombieNum].posY] = '0';
					zom[zombieNum].posX++;
					zom[zombieNum].posY++;
					map[zom[zombieNum].posX][zom[zombieNum].posY] = '4';

				}
			}

			else if ((zom[zombieNum].posY - (ply->posY)) > 0) //위 방향으로 떨어져 있을 때
			{
				if (map[zom[zombieNum].posX - 1][zom[zombieNum].posY] != '1')
				{
					map[zom[zombieNum].posX][zom[zombieNum].posY] = '0';
					zom[zombieNum].posX++;
					zom[zombieNum].posY--;
					map[zom[zombieNum].posX][zom[zombieNum].posY] = '4';
				}
			}

			else //같을 때
			{
				map[zom[zombieNum].posX][zom[zombieNum].posY] = '0';
				zom[zombieNum].posY++;
				map[zom[zombieNum].posX][zom[zombieNum].posY] = '4';
			}
		}
	}

	else if ((zom[zombieNum].posX - (ply->posX)) >= 0) //왼쪽으로 떨어져 있을 때
	{
		if (map[zom[zombieNum].posX][zom[zombieNum].posY - 1] != '1')
		{
			if ((zom[zombieNum].posY - (ply->posY)) < 0) //아래 방향으로 떨어져 있을 때
			{
				if (map[zom[zombieNum].posX + 1][zom[zombieNum].posY] != '1')
				{
					map[zom[zombieNum].posX][zom[zombieNum].posY] = '0';
					zom[zombieNum].posX--;
					zom[zombieNum].posY++;
					map[zom[zombieNum].posX][zom[zombieNum].posY] = '4';

				}
			}

			else if ((zom[zombieNum].posY - (ply->posY)) > 0) //위 방향으로 떨어져 있을 때
			{
				if (map[zom[zombieNum].posX - 1][zom[zombieNum].posY] != '1')
				{
					map[zom[zombieNum].posX][zom[zombieNum].posY] = '0';
					zom[zombieNum].posX--;
					zom[zombieNum].posY--;
					map[zom[zombieNum].posX][zom[zombieNum].posY] = '4';
				}
			}

			else  //같을때
			{
				map[zom[zombieNum].posX][zom[zombieNum].posY] = '0';
				zom[zombieNum].posY--;
				map[zom[zombieNum].posX][zom[zombieNum].posY] = '4';
			}
		}
	}

	else if ((zom[zombieNum].posY - (ply->posY)) < 0) //아래 방향으로 떨어져 있을 때
	{
		if (map[zom[zombieNum].posX+1][zom[zombieNum].posY] != '1')
		{
			map[zom[zombieNum].posX][zom[zombieNum].posY] = '0';
			zom[zombieNum].posX++;
			map[zom[zombieNum].posX][zom[zombieNum].posY] = '4';
		}
	}

	else if ((zom[zombieNum].posY - (ply->posY)) > 0) //위 방향으로 떨어져 있을 때
	{
		if (map[zom[zombieNum].posX - 1][zom[zombieNum].posY] != '1')
		{
			map[zom[zombieNum].posX][zom[zombieNum].posY] = '0';
			zom[zombieNum].posX--;
			map[zom[zombieNum].posX][zom[zombieNum].posY] = '4';
		}
	}
}
void MonsterBeacon(char(*map)[40], int posX, int posY)
{
	map[posX][posY] = '4';
}
void PlayerBeacon(char(*map)[40], int posX, int posY)
{
	map[posX][posY] = '5';
}

void MonsterBorn(char(*map)[40], int posX, int posY)
{

}

void GetPoints()
{

}

void PlayerShoot()
{

}

void PlayerDamage()
{

}

void MonsterAttack()
{

}

