#define ROW 3
#define COL 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <process.h>
#include <windows.h>



/*��ʼ������*/
void initBoard(char board[ROW][COL], int row, int col);
/*��ӡ����*/
void printBoard(char board[ROW][COL], int row, int col);
/*�������*/
void playerMove(char board[ROW][COL], int row, int col);
/*��������*/
void computerMove(char board[ROW][COL], int row, int col);
//�ж��Ƿ�Ӯ
char isWin(char board[ROW][COL], int row, int col);