#include"GameSystem.h"

void GotoXY(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void StartScene()
{
	system("title Box Head"); //�ܼ�â ����
	system("mode con cols=100 lines=25"); //�ܼ� â ũ�� ���� :100, ���� : 25

	CONSOLE_CURSOR_INFO consoleCursorInfo;

	consoleCursorInfo.bVisible = 0; //�ܼ� â�� Ŀ�� �Ⱥ��̰� �ϱ�
	consoleCursorInfo.dwSize = 1;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleCursorInfo);

	/*while ()
	{

	}*/


}

void DrawMap(char (*map)[60])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			if (map[i][j] == '1')
			{
				GotoXY(j, i);
				printf("#");
			}
		}
	}
	
}
void GameOver()
{
	FILE* rank;
	rank = fopen("Rank.txt", "w");
	if (rank == NULL) return 1;
	
	GotoXY(70, 11);
	printf("G A M E  O V E R");

	GotoXY(61, 14);
	// �÷��̾� �̸� �Է�




	fclose(rank);
}