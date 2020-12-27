#define ROW 3
#define COL 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <process.h>
#include <windows.h>



/*初始化棋盘*/
void initBoard(char board[ROW][COL], int row, int col);
/*打印棋盘*/
void printBoard(char board[ROW][COL], int row, int col);
/*玩家下棋*/
void playerMove(char board[ROW][COL], int row, int col);
/*电脑下棋*/
void computerMove(char board[ROW][COL], int row, int col);
//判断是否赢
char isWin(char board[ROW][COL], int row, int col);