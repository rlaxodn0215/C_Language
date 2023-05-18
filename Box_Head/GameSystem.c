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
void DrawMap(int mapNum)
{
	switch (mapNum)
	{
	case 0: // 일반 사각형 맵
	{
		for (int i = 0; i <= MAP_COLS; i++) //가로 그리기
		{
			GotoXY(i, 0);
			printf("#");
			GotoXY(i, MAP_LINES);
			printf("#");
		}

		for (int i = 1; i < MAP_LINES; i++) //세로 그리기
		{
			GotoXY(0, i);
			printf("#");
			GotoXY(MAP_COLS, i);
			printf("#");
		}

	}
		break;
	default:
		printf("잘못된 맵 번호를 입력하였습니다.\n");
		break;
	}
}
void Rank()
{

}
void GameOver()
{

}