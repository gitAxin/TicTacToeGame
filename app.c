#define _CRT_SECURE_NO_DEPRECATE 1
#include "game.h";
void menu() {

	printf("****************************\n");
	printf("****  1. play 0. exit   ****\n");
	printf("****************************\n");

}
void game() {
	system("cls");
	printf("��ʼ��Ϸ\n");

	Sleep(1000);
	

	char board[ROW][COL] = { '0' };
	//��ʼ������
	initBoard(board, ROW, COL);
	char r = '0';
	while (1) {
		system("cls");
		//��ӡ����
		printBoard(board, ROW, COL);
		//���
		playerMove(board, ROW, COL);
		
		r = isWin(board, ROW, COL);
		if (r != 'C') {
			break;
		}
		//����
		computerMove(board, ROW, COL);
		
		r = isWin(board, ROW, COL);
		if (r != 'C') {
			break;
		}
		
	}
	//��ӡ����
	system("cls");
	printBoard(board, ROW, COL);
	if (r == '*') {
		printf("��Ӯ�ˣ�\n");
	}
	else if (r == '#') {
		printf("�����ˣ�\n");
	}
	else {
		printf("ƽ�֣�\n");
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
				printf("�˳���Ϸ!\n");
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