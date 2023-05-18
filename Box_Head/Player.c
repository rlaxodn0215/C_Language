#include"Player.h"

void PlayerBeacon(int posX, int posY)
{
	GotoXY(posX, posY);
	printf("P");
}
void PlayerMove(Player *player, Weapon* weapon, int mapNum) // ȭ��ǥ �̵�, �����̽��� ����
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
				if (mapNum == 0 && (player->posY != 1))
				{
					GotoXY(player->posX, player->posY);
					printf(" ");
					(player->posY)--;
					GotoXY(player->posX, player->posY);
					printf("P");
					weapon->way = 12;
				}
			}
				break;
			case 75: //����
			{
				if (mapNum == 0 && (player->posX != 1))
				{
					GotoXY(player->posX, player->posY);
					printf(" ");
					(player->posX)--;
					GotoXY(player->posX, player->posY);
					printf("P");
					weapon->way = 9;
				}

			}
				break;
			case 77: //������
			{
				if (mapNum == 0 && (player->posX != MAP_COLS-1))
				{
					GotoXY(player->posX, player->posY);
					printf(" ");
					(player->posX)++;
					GotoXY(player->posX, player->posY);
					printf("P");
					weapon->way = 3;
				}
			}
				break;
			case 80: //�Ʒ���
			{
				if (mapNum == 0 && (player->posY != MAP_LINES-1))
				{
					GotoXY(player->posX, player->posY);
					printf(" ");
					(player->posY)++;
					GotoXY(player->posX, player->posY);
					printf("P");
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
			PlayerAttack(player, weapon, MAP_COLS,MAP_LINES);
		}
	}
}
void PlayerAttack(Player* player, Weapon* weapon, int max_cols, int max_lines)
{
	int posX = player->posX;
	int posY = player->posY;

	if (weapon->way == 12)// ���� ���
	{
		if (posY > weapon->range+1) // ������ �Ÿ��� ��Ÿ����� �� ���
		{
			GotoXY(posX, posY - 1);
			printf("o");

			for (int i = 1; i < weapon->range; i++)
			{
				GotoXY(posX, posY - i - 1);
				printf("o");
				GotoXY(posX, posY - i);
				printf(" ");
				Sleep(50);
			}

			GotoXY(posX, posY - weapon->range);
			printf(" ");

		}

		else // ������ �Ÿ��� ��Ÿ����� ª�� ���
		{

			if (posY == 2) //���� �� ĭ �������� ��
			{
				GotoXY(posX, posY - 1);
				printf("o");
				Sleep(50);
				GotoXY(posX, posY - 1);
				printf(" ");
			}

			else if(posY>2) //���� 2ĭ �̻� �������� ��
			{

				GotoXY(posX, posY - 1);
				printf("o");

				for (int i = 1; i < posY-1; i++)
				{
					GotoXY(posX, posY - i - 1);
					printf("o");
					GotoXY(posX, posY - i);
					printf(" ");
					Sleep(50);
				}

				GotoXY(posX, 1);
				printf(" ");

			}
		}
	}

	else if (weapon->way == 3)// ������ ���
	{
		if (max_cols - posX > weapon->range*2 + 1) // ������ �Ÿ��� ��Ÿ����� �� ���
		{
			GotoXY(posX + 1, posY);
			printf("o");

			for (int i = 1; i < weapon->range * 2; i++)
			{
				GotoXY(posX + i + 1, posY);
				printf("o");
				GotoXY(posX + i, posY);
				printf(" ");
				Sleep(25);
			}

			GotoXY(posX + weapon->range * 2, posY);
			printf(" ");
		}

		else
		{
			if (posX == max_cols-2) //���� �� ĭ �������� ��
			{
				GotoXY(posX+1, posY);
				printf("o");
				Sleep(25);
				GotoXY(posX+1, posY);
				printf(" ");
			}

			else if (posX < max_cols - 2) //���� 2ĭ �̻� �������� ��
			{

				GotoXY(posX+1, posY);
				printf("o");

				for (int i = 1; i < max_cols - (posX+1); i++)
				{
					GotoXY(posX+i+1, posY);
					printf("o");
					GotoXY(posX+i, posY);
					printf(" ");
					Sleep(25);
				}

				GotoXY(max_cols-1, posY);
				printf(" ");

			}
		}
	}

	else if (weapon->way == 6)// �Ʒ� ���
	{

		if (max_lines - posY > weapon->range + 1) // ������ �Ÿ��� ��Ÿ����� �� ���
		{
			GotoXY(posX, posY + 1);
			printf("o");

			for (int i = 1; i < weapon->range; i++)
			{
				GotoXY(posX, posY + i + 1);
				printf("o");
				GotoXY(posX, posY + i);
				printf(" ");
				Sleep(50);
			}

			GotoXY(posX, posY + weapon->range);
			printf(" ");
		}

		else
		{
			if (posY == max_lines-2) //���� �� ĭ �������� ��
			{
				GotoXY(posX, posY + 1);
				printf("o");
				Sleep(50);
				GotoXY(posX, posY + 1);
				printf(" ");
			}

			else if (posY < max_lines - 2)//���� 2ĭ �̻� �������� ��
			{

				GotoXY(posX, posY +1);
				printf("o");

				for (int i = 1; i < max_lines-(posY + 1); i++)
				{
					GotoXY(posX, posY + i + 1);
					printf("o");
					GotoXY(posX, posY + i);
					printf(" ");
					Sleep(50);
				}

				GotoXY(posX, max_lines-1);
				printf(" ");

			}
		}
	}

	else //���� ���
	{

		if (posX > weapon->range*2 + 1) // ������ �Ÿ��� ��Ÿ����� �� ���
		{
			GotoXY(posX - 1, posY);
			printf("o");

			for (int i = 1; i < weapon->range * 2; i++)
			{
				GotoXY(posX - i - 1, posY);
				printf("o");
				GotoXY(posX - i, posY);
				printf(" ");
				Sleep(25);
			}

			GotoXY(posX - weapon->range * 2, posY);
			printf(" ");

		}

		else
		{
			if (posX == 2) //���� �� ĭ �������� ��
			{
				GotoXY(posX-1, posY);
				printf("o");
				Sleep(25);
				GotoXY(posX-1, posY);
				printf(" ");
			}

			else if(posX > 2)//���� 2ĭ �̻� �������� ��
			{

				GotoXY(posX-1, posY);
				printf("o");

				for (int i = 1; i < posX - 1; i++)
				{
					GotoXY(posX-i-1, posY);
					printf("o");
					GotoXY(posX-i, posY);
					printf(" ");
					Sleep(25);
				}

				GotoXY(1, posY);
				printf(" ");

			}
		}
	}
}
void ShowHP(int posX, int posY, Player* player)
{
	GotoXY(posX, posY);
	printf("HP : %3d", player->Hp);
}
void Score(int posX, int posY, Player *player)
{
	GotoXY(posX, posY);
	printf("Score : %4d", player->points);
}
void PlayerDamaged()
{

}
void PlayerDead()
{

}