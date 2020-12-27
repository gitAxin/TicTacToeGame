#define _CRT_SECURE_NO_DEPRECATE 1
#include "game.h";
void menu() {

	printf("****************************\n");
	printf("****  1. play 0. exit   ****\n");
	printf("****************************\n");

}
void game() {
	system("cls");
	printf("开始游戏\n");

	Sleep(1000);
	

	char board[ROW][COL] = { '0' };
	//初始化棋牌
	initBoard(board, ROW, COL);
	char r = '0';
	while (1) {
		system("cls");
		//打印棋盘
		printBoard(board, ROW, COL);
		//玩家
		playerMove(board, ROW, COL);
		
		r = isWin(board, ROW, COL);
		if (r != 'C') {
			break;
		}
		//电脑
		computerMove(board, ROW, COL);
		
		r = isWin(board, ROW, COL);
		if (r != 'C') {
			break;
		}
		
	}
	//打印棋盘
	system("cls");
	printBoard(board, ROW, COL);
	if (r == '*') {
		printf("你赢了！\n");
	}
	else if (r == '#') {
		printf("你输了！\n");
	}
	else {
		printf("平局！\n");
	}
}
void start() {

	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("->:");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("退出游戏!\n");
				break;
			default:
				break;
		}
	} while (input);


}


int main() {
	start();
	return 0;
}