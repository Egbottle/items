#include<stdio.h>
#include"game2.h"
void menu(){
printf("****************************\n");
printf("************ɨ��************\n");
printf("****1.play********2.exit****\n");
printf("ע��'#'�������\n");
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
		printf("��ѡ��:>");
		scanf("%d",&input);
		switch(input){
				case 0:printf("�˳���Ϸ\n");
				break;
				case 1:printf("��ʼ��Ϸ\n");
					game(); 
					break;
			default:
			printf("ѡ�����������ѡ��\n");		
		}
}while(input);
}

