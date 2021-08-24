
#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
void AI1(char board[3][3]){
	board[1][1]='#';
		Printform(board);
}
void AI2(char board[3][3]){
	if(board[0][0]=='*'){
		board[2][2]='#';
		Printform(board);
	}
	if(board[0][2]=='*'){
		board[2][0]='#';
		Printform(board);
	}
	if(board[2][2]=='*'){
		board[0][0]='#';
		Printform(board);
	}
}
void AI3(char board[3][3]){
	if(board[0][1]=='*'&&board[0][0]=='*'){
		board[0][2]='#';
		Printform(board);
	}
	if(board[1][0]=='*'&&board[0][0]=='*'){
		board[2][0]='#';
		Printform(board);
	}
	if(board[0][1]=='*'&&board[0][2]=='*'){
		board[0][0]='#';
		Printform(board);
	}
	if(board[1][2]=='*'&&board[0][2]=='*'){
		board[2][2]='#';
		Printform(board);
	}
	if(board[2][0]=='*'&&board[1][0]=='*'){
		board[0][0]='#';
		Printform(board);
	}
	if(board[2][1]=='*'&&board[2][0]=='*'){
		board[2][2]='#';
		Printform(board);
	}
}
void AI4(char board[3][3]){
	if(board[1][2]=='*'&&board[0][0]=='*'&&board[0][1]=='*'){
		board[2][0]='#';
		Printform(board);
	}
	if(board[2][0]=='*'&&board[0][0]=='*'&&board[0][1]=='*'){
		board[1][2]='#';
		Printform(board);
	}
	if(board[0][0]=='*'&&board[1][0]=='*'&&board[0][2]=='*'){
		board[2][1]='#';
		Printform(board);
	}
	if(board[0][0]=='*'&&board[1][0]=='*'&&board[2][1]=='*'){
		board[0][2]='#';
		Printform(board);
	}
	if(board[0][1]=='*'&&board[0][2]=='*'&&board[2][2]=='*'){
		board[1][0]='#';
		Printform(board);
	}
	if(board[0][1]=='*'&&board[0][2]=='*'&&board[1][0]=='*'){
		board[2][2]='#';
		Printform(board);
	}
	if(board[1][2]=='*'&&board[0][2]=='*'&&board[0][0]=='*'){
		board[2][1]='#';
		Printform(board);
	}
	if(board[1][2]=='*'&&board[0][2]=='*'&&board[2][1]=='*'){
		board[0][0]='#';
		Printform(board);
	}
	else{
		board[0][0]=
	}
	 if(board[0][1]=='*'&&board[0][2]=='*'&&board[1][0]=='*'){
		board[2][2]='#';
		Printform(board);
	}
	else{
		board[2][2]='#';
	}
	if(board[2][0]=='*'&&board[][2]=='*'&&board[1][0]=='*'){
		board[2][2]='#';
		Printform(board);
	}
	else{
		board[2][2]='#';
	}
}
void Playermove(char board[3][3]){
 printf("玩家选择落棋的位置坐标(行列)，并以空格隔开:>");
 int a,b;
 scanf("%d%d",&a,&b);
 while(a<=0||a>3||b<=0||b>3||board[a-1][b-1]!=0){
 	printf("错误坐标，请重新输入:>");
 	scanf("%d%d",&a,&b);
 }
 	board[a-1][b-1]='*';
 	Printform(board);
}//玩家下棋 
void Computermove(char board[3][3]){
int x,y;
printf("电脑下棋:>\n");
do{
	x=rand()%3;
	y=rand()%3;
	if(board[x][y]==' '){
		board[x][y]='#';
		Printform(board);
		break;
	}
	else{
		continue;
	}
}while(1);
}//电脑下棋 
int Checkrow(char board[3][3]){
	int i=0;
for(i;i<3;i++){
	if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][2]=='*'){
		printf("恭喜你，你赢了！\n");
		return 0;
		break;
		}//玩家赢 
	if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][2]=='#'){
		printf("很遗憾，电脑获胜\n");
		return 0;
		break;
	}//电脑赢
	}		
}//检查行 
int Checkcol(char board[3][3]){
	int j=0;
	for(j;j<3;j++){
	if(board[0][j]==board[1][j]&&board[1][j]==board[2][j]&&board[2][j]=='*'){
		printf("恭喜你，你赢了!\n");
		return 0;
		break; 
		}//玩家赢 
	if(board[0][j]==board[1][j]&&board[1][j]==board[2][j]&&board[2][j]=='#'){
		printf("很遗憾，电脑获胜\n");
		return 0;
		break;
	}//电脑赢
}	
}//检查列
int Checkslash(char board[3][3]){	
	if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[2][2]=='*'){
		printf("恭喜你，你赢了！\n");
		return 0;
	}
	if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[2][0]=='*'){
		printf("恭喜你，你赢了！\n");
		return 0;
	}
	if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[2][2]=='#'){
		printf("很遗憾，电脑获胜\n");
		return 0;
	}
	if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[2][0]=='#'){
		printf("很遗憾，电脑获胜\n");
		return 0;		
	}
	}//检查斜线 
int Checkequal(char board[3][3]){
int m=0;
int i=0;
int j=0;
for(i=0;i<3;i++){
	for(j=0;j<3;j++){
		if(board[i][j]!=' '){
			m+=1;
		}
	}
}
if(m==9){
printf("平局！\n");
return 0;	
}
}//检查平局 
void Initboard(char board[3][3]){
		int i=0,j=0;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			board[i][j]=' ';
		}
	}
}//初始化棋盘 
void Printform(char board[3][3]){
		int i=0,j=0;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf(" %c ",board[i][j]);
			if(j<2){
				printf("|");}
			else{printf("\n");
			                  
			}
		}
	if(i<2){
	for(j=0;j<3;j++){
		if(j<3){printf("---");}
		if(j<2){
			printf("|");
		}
		else{
			printf("\n");
		}
	}
	}
	}
}//打印表格 

void menu(){
	printf("********************************\n");
	printf("*************井字棋*************\n");
	printf("***1.play**************0.exit***\n");
	printf("********************************\n");//开始菜单 
}
void game(){
	char board[3][3]={0};
		Initboard(board);//初始化表格 
		Printform(board);//打印表格 
	int l=0;
	l=rand()%10;
	if(l>4){
	do{int t=1;
	Playermove(board);//玩家下棋 
		//判断行
		t=Checkrow(board);
		if(t==0){
		break;	
		}
		t=Checkcol(board);
		if(t==0){
		break;	
		}//判断列		
		t=Checkslash(board);
		if(t==0){
		break;	
		}//判断斜线 		
		t=Checkequal(board);
		if(t==0){
		break;	
		}
	Computermove(board); //电脑下棋 		
		t=Checkrow(board);
		if(t==0){
		break;	
		}//判断行		
		t=Checkcol(board);
		if(t==0){
		break;	
		}//判断列		
		t=Checkslash(board);
		if(t==0){
		break;	
		}//判断斜线 
		t=Checkequal(board);
		if(t==0){
		break;	
		}
				}while(1);
}
else{
	do{int t=1;
	Computermove(board);//电脑下棋 
		//判断行
		t=Checkrow(board);
		if(t==0){
		break;	
		}
		t=Checkcol(board);
		if(t==0){
		break;	
		}//判断列		
		t=Checkslash(board);
		if(t==0){
		break;	
		}//判断斜线 		
		t=Checkequal(board);
		if(t==0){
		break;	
		}
	Playermove(board); //玩家下棋 		
		t=Checkrow(board);
		if(t==0){
		break;	
		}//判断行		
		t=Checkcol(board);
		if(t==0){
		break;	
		}//判断列		
		t=Checkslash(board);
		if(t==0){
		break;	
		}//判断斜线 
		t=Checkequal(board);
		if(t==0){
		break;	
		}
				}while(1);
}
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

