#include"Player.h"

void PlayerBeacon(int posX, int posY, char(*map)[60])
{
	GotoXY(posX, posY);
	map[posY][posX] = 'P';
	printf("P");
}
void PlayerMove(Player* player, Weapon* weapon, char (*map)[60]) // ȭ��ǥ �̵�, �����̽��� ����
{
	int key;

	if (_kbhit())
	{
		key = _getch();
		if (key == 224)
		{
			key = _getch();

			switch (key)
			{
			case 72: //����
			{
				if (map[(player->posY)-1][player->posX] !='1')
				{
					GotoXY(player->posX, player->posY);
					printf(" ");
					map[player->posY][player->posX] = '0';
					(player->posY)--;
					GotoXY(player->posX, player->posY);
					printf("P");
					map[player->posY][player->posX] = 'P';
					weapon->way = 12;
				}
			}
			break;
			case 75: //����
			{
				if (map[player->posY][(player->posX)-1] != '1')
				{
					GotoXY(player->posX, player->posY);
					printf(" ");
					map[player->posY][player->posX] = '0';
					(player->posX)--;
					GotoXY(player->posX, player->posY);
					printf("P");
					map[player->posY][player->posX] = 'P';
					weapon->way = 9;
				}

			}
			break;
			case 77: //������
			{
				if (map[player->posY][(player->posX)+1] != '1')
				{
					GotoXY(player->posX, player->posY);
					printf(" ");
					map[player->posY][player->posX] = '0';
					(player->posX)++;
					GotoXY(player->posX, player->posY);
					printf("P");
					map[player->posY][player->posX] = 'P';
					weapon->way = 3;
				}
			}
			break;
			case 80: //�Ʒ���
			{
				if (map[(player->posY)+1][player->posX] != '1')
				{
					GotoXY(player->posX, player->posY);
					printf(" ");
					map[player->posY][player->posX] = '0';
					(player->posY)++;
					GotoXY(player->posX, player->posY);
					printf("P");
					map[player->posY][player->posX] = 'P';
					weapon->way = 6;
				}
			}
			break;
			default:
				break;
			}
		}

		else if (key == 32) //�����̽��� �Է�
		{
			weapon->isShoot = 1;
			weapon->ammo--;
			PlayerAttack(player, weapon, map);
		}
	}
}
void PlayerAttack(Player* player, Weapon* weapon, char (*map)[60])
{
	if (weapon->ammo >= 0)
	{
		int posX = player->posX;
		int posY = player->posY;
		int i = 1;
		if (weapon->way == 12)// ���� ��� 
		{
			while (i < weapon->range && map[posY - i][posX] == '0')
			{
				GotoXY(posX, posY - i);
				printf("o");
				Sleep(50);
				GotoXY(posX, posY - i);
				printf(" ");
				i++;
			}
		}

		else if (weapon->way == 3)// ������ ���
		{
			while (i < weapon->range * 2 && map[posY][posX + i] == '0')
			{
				GotoXY(posX + i, posY);
				printf("o");
				Sleep(25);
				GotoXY(posX + i, posY);
				printf(" ");
				i++;
			}
		}

		else if (weapon->way == 6)// �Ʒ� ���
		{
			while (i < weapon->range && map[posY + i][posX] == '0')
			{
				GotoXY(posX, posY + i);
				printf("o");
				Sleep(50);
				GotoXY(posX, posY + i);
				printf(" ");
				i++;
			}
		}

		else //���� ���
		{
			while (i < weapon->range * 2 && map[posY][posX - i] == '0')
			{
				GotoXY(posX - i, posY);
				printf("o");
				Sleep(25);
				GotoXY(posX - i, posY);
				printf(" ");
				i++;
			}
		}
	}
	
}
void ShowHP(int posX, int posY, Player* player)
{
	if (player->Hp < 0)
	{
		player->Hp = 0;
		return;
	}
	GotoXY(posX, posY);
	printf("HP : %3d", player->Hp);
}
void ShowAmmo(int posX, int posY, Weapon* weapon)
{
	if (weapon->ammo < 0)
	{
		GotoXY(posX, posY);
		printf("Ammo :   0");
	}
	else
	{
		GotoXY(posX, posY);
		printf("Ammo : %3d", weapon->ammo);
	}
}
void Score(int posX, int posY, Player *player)
{
	GotoXY(posX, posY);
	printf("Score : %4d", player->points);
}