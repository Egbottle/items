#include<stdio.h>
#include"game2.h"
void Initboard(char unshow[ROWS][COLS],char show[ROWS][COLS]){
	int i,j;
	for(i=0;i<ROWS;i++){
		for(j=0;j<COLS;j++){
			unshow[i][j]='0';
			show[i][j]='*';
		}
	}
}
void Displayboard(char unshow[ROWS][COLS],char show[ROWS][COLS]){
	int i,j;
	for(i=0;i<=ROW;i++){
		show[i][0]='0'+i;
	}
	for(j=0;j<=COL;j++){
		show[0][j]=j+'0';
	}
	for(i=0;i<=ROW;i++){
		for(j=0;j<=COL;j++){
			printf("%c ",show[i][j]);
			if(j==COL){
				printf("\n");
			}
		}
	}

}
void Stickmine(char unshow[ROWS][COLS]){
	int k=0;
	while(k<MODERN){
	int i=rand()%9+1;
	int j=rand()%9+1;
	if(unshow[i][j]!='1'){
		unshow[i][j]='1';
		k+=1;
		}
	else{
		continue;
	}	
	}
}
int Checkmine(char unshow[ROWS][COLS],char show[ROWS][COLS]){
	int a,b;
	printf("请选择想要排查的坐标:>");
	scanf("%d %d",&b,&a);
	while(a<1||a>9||b<1||b>9){
		printf("坐标非法，请重新输入:>");
		scanf("%d %d",&b,&a);
	}
	if(unshow[a][b]=='1'){
		show[a][b]='#';
		Displayboard(unshow,show);
		printf("很遗憾，你被炸死了!\n");
		return 1;
	}
	else{
	int count;
	count=
	unshow[a-1][b-1]+unshow[a][b-1]+
	unshow[a+1][b-1]+unshow[a-1][b]+
	unshow[a+1][b]+unshow[a-1][b+1]+
	unshow[a][b+1]+unshow[a+1][b+1]-8*'0';
	show[a][b]=count+'0';
	Displayboard(unshow,show);
	//Spreadcheck(unshow,show,a,b);
	}
} 
void Spreadcheck(char unshow[ROWS][COLS],char show[ROWS][COLS],int a,int b){
	if(show[a][b]=='0'){
	a=a-1;
	b=b-1;
	}
}

