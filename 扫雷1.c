#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#include<stdlib.h>
#include<time.h>
#define MODERN 10
#include<stdio.h>
void Initboard(char unshow[ROWS][COLS],char show[ROWS][COLS]);
void Displayboard(char unshow[ROWS][COLS],char show[ROWS][COLS]);
void Stickmine(char unshow[ROWS][COLS]);
int  Checkmine1(char unshow[ROWS][COLS],char show[ROWS][COLS],int a,int b);
void Inputmine(int* a,int* b);
void Count(char unshow[ROWS][COLS],char show[ROWS][COLS],int a,int b);
int  Checkmine2(char unshow[ROWS][COLS],char show[ROWS][COLS],int a,int b);
int  Checkmine3(char unshow[ROWS][COLS],char show[ROWS][COLS],int a,int b);
int  Checkmine4(char unshow[ROWS][COLS],char show[ROWS][COLS],int a,int b);
int  Checkmine5(char unshow[ROWS][COLS],char show[ROWS][COLS],int a,int b);
int  Checkmine6(char unshow[ROWS][COLS],char show[ROWS][COLS],int a,int b);
int  Checkmine7(char unshow[ROWS][COLS],char show[ROWS][COLS],int a,int b);
int  Checkmine8(char unshow[ROWS][COLS],char show[ROWS][COLS],int a,int b);
int  Checkmine9(char unshow[ROWS][COLS],char show[ROWS][COLS],int a,int b);

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
void Inputmine(int *pa,int *pb){
	int i=0;
	printf("请选择想要排查的坐标:>");
	scanf("%d %d",&*pb,&*pa);
	while(*pa<1||*pa>9||*pb<1||*pb>9){
		printf("坐标非法，请重新输入:>");
		scanf("%d %d",&*pb,&*pa);
	}
}
void Count(char unshow[ROWS][COLS],char show[ROWS][COLS],int a,int b){
		int count;
	count=
	unshow[a-1][b-1]+unshow[a][b-1]+
	unshow[a+1][b-1]+unshow[a-1][b]+
	unshow[a+1][b]+unshow[a-1][b+1]+
	unshow[a][b+1]+unshow[a+1][b+1]-8*'0';
	show[a][b]=count+'0';
} 
int Checkmine1(char unshow[ROWS][COLS],char show[ROWS][COLS],int a,int b){
	if(unshow[a][b]=='1'){
		int i,j;
		for(i=1;i<=ROW;i++){
			for(j=1;j<=COL;j++){
				if(unshow[i][j]=='1'){
				show[i][j]='#';
			}
			}
		}
		Displayboard(unshow,show);
		printf("很遗憾，你被炸死了!\n");
		return 1;
	}
}
int  Checkmine2(char unshow[ROWS][COLS],char show[ROWS][COLS],int a,int b){
		Count(unshow,show,a,b);
	if(show[a][b]=='0'&&a-1>=0&&b-1>=0){
		Count(unshow,show,a-1,b-1);
		Count(unshow,show,a,b-1);
		Count(unshow,show,a+1,b-1);
		Count(unshow,show,a-1,b);
		Count(unshow,show,a+1,b);
		Count(unshow,show,a-1,b+1);
		Count(unshow,show,a,b+1);
		Count(unshow,show,a+1,b+1);
		if(a-1>0&&b-1>0){
		Checkmine2(unshow,show,a-1,b-1);
	}
	}
}

int  Checkmine3(char unshow[ROWS][COLS],char show[ROWS][COLS],int a,int b){
		Count(unshow,show,a,b);
	if(show[a][b]=='0'&&a-1>=0&&b>=0){
		Count(unshow,show,a-1,b-1);
		Count(unshow,show,a,b-1);
		Count(unshow,show,a+1,b-1);
		Count(unshow,show,a-1,b);
		Count(unshow,show,a+1,b);
		Count(unshow,show,a-1,b+1);
		Count(unshow,show,a,b+1);
		Count(unshow,show,a+1,b+1);
		if(a-1>0&&b>0){
		Checkmine3(unshow,show,a-1,b);
	}
	}
}
int  Checkmine4(char unshow[ROWS][COLS],char show[ROWS][COLS],int a,int b){
		Count(unshow,show,a,b);
	if(show[a][b]=='0'&&a-1>=0&&b+1>=0){
		Count(unshow,show,a-1,b-1);
		Count(unshow,show,a,b-1);
		Count(unshow,show,a+1,b-1);
		Count(unshow,show,a-1,b);
		Count(unshow,show,a+1,b);
		Count(unshow,show,a-1,b+1);
		Count(unshow,show,a,b+1);
		Count(unshow,show,a+1,b+1);
		if(a-1>0&&b+1>0){
		Checkmine4(unshow,show,a-1,b+1);
	}
	}
}
int  Checkmine5(char unshow[ROWS][COLS],char show[ROWS][COLS],int a,int b){
		Count(unshow,show,a,b);
	if(show[a][b]=='0'&&a>=0&&b-1>=0){
		Count(unshow,show,a-1,b-1);
		Count(unshow,show,a,b-1);
		Count(unshow,show,a+1,b-1);
		Count(unshow,show,a-1,b);
		Count(unshow,show,a+1,b);
		Count(unshow,show,a-1,b+1);
		Count(unshow,show,a,b+1);
		Count(unshow,show,a+1,b+1);
		if(a>0&&b-1>0){
		Checkmine5(unshow,show,a,b-1);
	}
	}
}
int  Checkmine6(char unshow[ROWS][COLS],char show[ROWS][COLS],int a,int b){
		Count(unshow,show,a,b);
	if(show[a][b]=='0'&&a>=0&&b+1>=0){
		Count(unshow,show,a-1,b-1);
		Count(unshow,show,a,b-1);
		Count(unshow,show,a+1,b-1);
		Count(unshow,show,a-1,b);
		Count(unshow,show,a+1,b);
		Count(unshow,show,a-1,b+1);
		Count(unshow,show,a,b+1);
		Count(unshow,show,a+1,b+1);
		if(a>0&&b+1>0){
		Checkmine6(unshow,show,a,b+1);
	}
	}
}
int  Checkmine7(char unshow[ROWS][COLS],char show[ROWS][COLS],int a,int b){
		Count(unshow,show,a,b);
	if(show[a][b]=='0'&&a+1>=0&&b-1>=0){
		Count(unshow,show,a-1,b-1);
		Count(unshow,show,a,b-1);
		Count(unshow,show,a+1,b-1);
		Count(unshow,show,a-1,b);
		Count(unshow,show,a+1,b);
		Count(unshow,show,a-1,b+1);
		Count(unshow,show,a,b+1);
		Count(unshow,show,a+1,b+1);
		if(a+1>0&&b-1>0){
		Checkmine7(unshow,show,a+1,b-1);
	}
	}
}
int  Checkmine8(char unshow[ROWS][COLS],char show[ROWS][COLS],int a,int b){
		Count(unshow,show,a,b);
	if(show[a][b]=='0'&&a+1>=0&&b>=0){
		Count(unshow,show,a-1,b-1);
		Count(unshow,show,a,b-1);
		Count(unshow,show,a+1,b-1);
		Count(unshow,show,a-1,b);
		Count(unshow,show,a+1,b);
		Count(unshow,show,a-1,b+1);
		Count(unshow,show,a,b+1);
		Count(unshow,show,a+1,b+1);
		if(a+1>0&&b>0){
		Checkmine8(unshow,show,a+1,b);
	}
	}
}
int  Checkmine9(char unshow[ROWS][COLS],char show[ROWS][COLS],int a,int b){
		Count(unshow,show,a,b);
	if(show[a][b]=='0'&&a+1>=0&&b+1>=0){
		Count(unshow,show,a-1,b-1);
		Count(unshow,show,a,b-1);
		Count(unshow,show,a+1,b-1);
		Count(unshow,show,a-1,b);
		Count(unshow,show,a+1,b);
		Count(unshow,show,a-1,b+1);
		Count(unshow,show,a,b+1);
		Count(unshow,show,a+1,b+1);
		if(a+1>0&&b+1>0){
		Checkmine9(unshow,show,a+1,b+1);
	}
	}
}
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
	int a=1;
	int b=1;
	Inputmine(&a,&b);
	i=Checkmine1(unshow,show,a,b);
	if(i==1){
		break;
	}
	Checkmine2(unshow,show,a,b);
	Checkmine3(unshow,show,a,b);
	Checkmine4(unshow,show,a,b);
	Checkmine5(unshow,show,a,b);
	Checkmine6(unshow,show,a,b);
	Checkmine7(unshow,show,a,b);
	Checkmine8(unshow,show,a,b);
	Checkmine9(unshow,show,a,b);
	int x,y;
	for(x=1,k=0;x<=ROW;x++){
		for(y=1;y<=COL;y++){
			if(show[x][y]=='*'){
				k++;
			}
		}
	}
	if(k==MODERN){
	int r,t;
	for(r=1;r<=ROW;r++){
		for(t=1;t<=COL;t++){
			if(show[r][t]=='*'){
				show[r][t]='X'; 
			}
		}
	}
}
	Displayboard(unshow,show);
	if(k==MODERN){
		printf("恭喜你，你赢了！");
	}
}while(k!=MODERN);
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

