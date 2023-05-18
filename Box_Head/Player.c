#include"Player.h"

void PlayerBeacon(int posX, int posY)
{
	GotoXY(posX, posY);
	printf("P");
}
void PlayerMove(Player *player, Weapon* weapon, int mapNum) // 화살표 이동, 스페이스바 공격
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
			case 72: //위쪽
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
			case 75: //왼쪽
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
			case 77: //오른쪽
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
			case 80: //아래쪽
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

		else if (key == 32) //스페이스바 입력
		{
			PlayerAttack(player, weapon, MAP_COLS,MAP_LINES);
		}
	}
}
void PlayerAttack(Player* player, Weapon* weapon, int max_cols, int max_lines)
{
	int posX = player->posX;
	int posY = player->posY;

	if (weapon->way == 12)// 위로 사격
	{
		if (posY > weapon->range+1) // 벽과의 거리가 사거리보다 길 경우
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

		else // 벽과의 거리가 사거리보다 짧을 경우
		{

			if (posY == 2) //벽과 한 칸 떨어졌을 때
			{
				GotoXY(posX, posY - 1);
				printf("o");
				Sleep(50);
				GotoXY(posX, posY - 1);
				printf(" ");
			}

			else if(posY>2) //벽과 2칸 이상 떨어졌을 때
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

	else if (weapon->way == 3)// 오른쪽 사격
	{
		if (max_cols - posX > weapon->range*2 + 1) // 벽과의 거리가 사거리보다 길 경우
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
			if (posX == max_cols-2) //벽과 한 칸 떨어졌을 때
			{
				GotoXY(posX+1, posY);
				printf("o");
				Sleep(25);
				GotoXY(posX+1, posY);
				printf(" ");
			}

			else if (posX < max_cols - 2) //벽과 2칸 이상 떨어졌을 때
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

	else if (weapon->way == 6)// 아래 사격
	{

		if (max_lines - posY > weapon->range + 1) // 벽과의 거리가 사거리보다 길 경우
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
			if (posY == max_lines-2) //벽과 한 칸 떨어졌을 때
			{
				GotoXY(posX, posY + 1);
				printf("o");
				Sleep(50);
				GotoXY(posX, posY + 1);
				printf(" ");
			}

			else if (posY < max_lines - 2)//벽과 2칸 이상 떨어졌을 때
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

	else //왼쪽 사격
	{

		if (posX > weapon->range*2 + 1) // 벽과의 거리가 사거리보다 길 경우
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
			if (posX == 2) //벽과 한 칸 떨어졌을 때
			{
				GotoXY(posX-1, posY);
				printf("o");
				Sleep(25);
				GotoXY(posX-1, posY);
				printf(" ");
			}

			else if(posX > 2)//벽과 2칸 이상 떨어졌을 때
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