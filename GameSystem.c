#include"GameSystem.h"

void GotoXY(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void StartScene()
{
	system("title Box Head"); //콘솔창 제목
	system("mode con cols=100 lines=25"); //콘솔 창 크기 가로 :100, 세로 : 25

	CONSOLE_CURSOR_INFO consoleCursorInfo;

	consoleCursorInfo.bVisible = 0; //콘솔 창에 커서 안보이게 하기
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
	// 플레이어 이름 입력




	fclose(rank);
}