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
void DrawMap(int mapNum)
{
	switch (mapNum)
	{
	case 0: // �Ϲ� �簢�� ��
	{
		for (int i = 0; i <= MAP_COLS; i++) //���� �׸���
		{
			GotoXY(i, 0);
			printf("#");
			GotoXY(i, MAP_LINES);
			printf("#");
		}

		for (int i = 1; i < MAP_LINES; i++) //���� �׸���
		{
			GotoXY(0, i);
			printf("#");
			GotoXY(MAP_COLS, i);
			printf("#");
		}

	}
		break;
	default:
		printf("�߸��� �� ��ȣ�� �Է��Ͽ����ϴ�.\n");
		break;
	}
}
void Rank()
{

}
void GameOver()
{

}