#define _CRT_SECURE_NO_DEPRECATE 1

#include "game.h"
/*初始化棋盘*/
void initBoard(char board[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}
}
/*打印棋盘*/
void printBoard(char board[ROW][COL], int row, int col) {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf(" %c ",board[i][j]);
			if (j < col - 1) {
				printf("|");
			}
			
		}
		printf("\n");
		if (i < row - 1) {
			for (int j = 0; j < col; j++) {
				printf("---");
				if (j < col - 1) {
					printf("|");
				}

			}
			printf("\n");
		}
		
		
	}
}

/*玩家移动*/
void playerMove(char board[ROW][COL], int row, int col) {
	

	while (1) {
		printf("玩家->:");
		int x = 0;
		int y = 0;
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col) {
			if (board[x - 1][y - 1] != ' ') {
				printf("坐标已放置棋子\n");
			}
			else {
				board[x - 1][y - 1] = '*';
				break;
			}
		}
		else {
			printf("超出棋盘范围\n");
		}
	}


}
/*电脑*/
void computerMove(char board[ROW][COL], int row, int col) {

	while (1) {
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ') {
			board[x][y] = '#';
			break;
		}
	}

}
/*
玩家赢：‘*’
电脑赢：‘#’
平局：‘D’
继续：‘C’
*/
char isWin(char board[ROW][COL], int row, int col) {
	//判断三行
	for (int i = 0; i < row; i++) {
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ') {
			return board[i][0];
		}
	}
	//判断三列
	for (int i = 0; i < col; i++) {
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ') {
			return board[0][i];
		}
	}
	
	//判断对角线
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ') {
		return board[0][0];
	}
	if (board[2][0] == board[1][1] && board[2][0] == board[0][2] && board[2][0] != ' ') {
		return board[2][0];
	}
	//判断是否棋盘已下满
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (board[i][j] == ' ') {
				return 'C';
			}
		}
	}
	//平局
	return 'D';


}