#define _CRT_SECURE_NO_DEPRECATE 

#include "game.h"




void menu()
{
	printf("-----------------------------------\n");
	printf("|      ��ѡ��                   |\n");
	printf("|             1.��ʼ��Ϸ          |\n");
	printf("|             0.�˳���Ϸ          |\n");
	printf("-----------------------------------\n");
}


void mine_menu()
{
	printf("------------------------------------\n");
	printf("|   ��ѡ��ȼ���                   |\n");
	printf("|             1.����               |\n");
	printf("|             2.�м�               |\n");
	printf("|             3.�߼�               |\n");
	printf("------------------------------------\n");

}


void game ()
{
	//int input= 0;
 //   do 
 //   {
	//	mine_menu();
	//	printf("��ѡ��ȼ�>: ");
	//	scanf("%d",&input);
	//	switch(input)
	//	{
	//	case 1:
	//		{
	//			char mine[ROWS+2][COLS+2];
	//			char show[ROWS+2][COLS+2];
	//			srand( (unsigned)time( NULL ) );
	//			memset(mine,'0',(ROWS+2)*(COLS+2)*sizeof(char));
	//			memset(show,'*',(ROWS+2)*(COLS+2)*sizeof(char));
	//			display(show,ROWS+2,COLS+2);
	//			set_mine_one(mine,ROWS+2,COLS+2);
	//			display(mine,ROWS+2,COLS+2);
	//			play_game(mine,show);
	//			break;

	//		}
	//
	//	case 2:
	//		{
	//			char mine[ROWS+2][COLS+2];
	//			char show[ROWS+2][COLS+2];
	//			srand( (unsigned)time( NULL ) );
	//			memset(mine,'0',(ROWS+2)*(COLS+2)*sizeof(char));
	//			memset(show,'*',(ROWS+2)*(COLS+2)*sizeof(char));
	//			display(show,ROWS+2,COLS+2);
	//			set_mine_two(mine,ROWS+2,COLS+2);
	//			display(mine,ROWS+2,COLS+2);
	//			play_game(mine,show);
	//			break;

	//		}
	//	case 3:
	//		{
	//			char mine[ROWS+2][COLS+2];
	//			char show[ROWS+2][COLS+2];
	//			srand( (unsigned)time( NULL ) );
	//			memset(mine,'0',(ROWS+2)*(COLS+2)*sizeof(char));
	//			memset(show,'*',(ROWS+2)*(COLS+2)*sizeof(char));
	//			display(show,ROWS+2,COLS+2);
	//			set_mine_three(mine,ROWS+2,COLS+2);
	//			display(mine,ROWS+2,COLS+2);
	//			play_game(mine,show);
	//			break;
	//		}
	//		
	//	default:
	//		printf("����������������룡\n");
	//		break;
	//} while (input);
	//	


	//}
	
	char mine[ROWS+2][COLS+2];
	char show[ROWS+2][COLS+2];
	srand( (unsigned)time( NULL ) );
	memset(mine,'0',(ROWS+2)*(COLS+2)*sizeof(char));
	memset(show,'*',(ROWS+2)*(COLS+2)*sizeof(char));
	display(show,ROWS+2,COLS+2);
	set_mine(mine,ROWS+2,COLS+2);
	display(mine,ROWS+2,COLS+2);
	play_game(mine,show);
}



int main()
{
	
	int input = 0;
	system("color 30");
	do 
	{
		menu();
		printf("���������ѡ��> ");
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("����������������룡\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}