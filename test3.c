#include<stdio.h>
#include"game2.h"
void menu(){
printf("****************************\n");
printf("************扫雷************\n");
printf("****1.play********2.exit****\n");
printf("注：'#'代表地雷\n");
}
void game(){
	int unshow[ROWS][COLS];
	char show[ROWS][COLS];
	Initboard(unshow,show);
	Stickmine(unshow);
	Displayboard(unshow,show);
	int k=0;
	do{
	int i=0;
	i=Checkmine(unshow,show);
	if(i==1){
	break;	
	}
	else{
		k+=1;
	}
}while(k<ROW*COL-MODERN);
}


int main(){
	int input=0;
		do{
		srand((unsigned int)time(NULL));	
		menu();
		printf("请选择:>");
		scanf("%d",&input);
		switch(input){
				case 0:printf("退出游戏\n");
				break;
				case 1:printf("开始游戏\n");
					game(); 
					break;
			default:
			printf("选择错误，请重新选择\n");		
		}
}while(input);
}

