
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
 printf("���ѡ�������λ������(����)�����Կո����:>");
 int a,b;
 scanf("%d%d",&a,&b);
 while(a<=0||a>3||b<=0||b>3||board[a-1][b-1]!=0){
 	printf("�������꣬����������:>");
 	scanf("%d%d",&a,&b);
 }
 	board[a-1][b-1]='*';
 	Printform(board);
}//������� 
void Computermove(char board[3][3]){
int x,y;
printf("��������:>\n");
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
}//�������� 
int Checkrow(char board[3][3]){
	int i=0;
for(i;i<3;i++){
	if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][2]=='*'){
		printf("��ϲ�㣬��Ӯ�ˣ�\n");
		return 0;
		break;
		}//���Ӯ 
	if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][2]=='#'){
		printf("���ź������Ի�ʤ\n");
		return 0;
		break;
	}//����Ӯ
	}		
}//����� 
int Checkcol(char board[3][3]){
	int j=0;
	for(j;j<3;j++){
	if(board[0][j]==board[1][j]&&board[1][j]==board[2][j]&&board[2][j]=='*'){
		printf("��ϲ�㣬��Ӯ��!\n");
		return 0;
		break; 
		}//���Ӯ 
	if(board[0][j]==board[1][j]&&board[1][j]==board[2][j]&&board[2][j]=='#'){
		printf("���ź������Ի�ʤ\n");
		return 0;
		break;
	}//����Ӯ
}	
}//�����
int Checkslash(char board[3][3]){	
	if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[2][2]=='*'){
		printf("��ϲ�㣬��Ӯ�ˣ�\n");
		return 0;
	}
	if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[2][0]=='*'){
		printf("��ϲ�㣬��Ӯ�ˣ�\n");
		return 0;
	}
	if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[2][2]=='#'){
		printf("���ź������Ի�ʤ\n");
		return 0;
	}
	if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[2][0]=='#'){
		printf("���ź������Ի�ʤ\n");
		return 0;		
	}
	}//���б�� 
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
printf("ƽ�֣�\n");
return 0;	
}
}//���ƽ�� 
void Initboard(char board[3][3]){
		int i=0,j=0;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			board[i][j]=' ';
		}
	}
}//��ʼ������ 
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
}//��ӡ��� 

void menu(){
	printf("********************************\n");
	printf("*************������*************\n");
	printf("***1.play**************0.exit***\n");
	printf("********************************\n");//��ʼ�˵� 
}
void game(){
	char board[3][3]={0};
		Initboard(board);//��ʼ����� 
		Printform(board);//��ӡ��� 
	int l=0;
	l=rand()%10;
	if(l>4){
	do{int t=1;
	Playermove(board);//������� 
		//�ж���
		t=Checkrow(board);
		if(t==0){
		break;	
		}
		t=Checkcol(board);
		if(t==0){
		break;	
		}//�ж���		
		t=Checkslash(board);
		if(t==0){
		break;	
		}//�ж�б�� 		
		t=Checkequal(board);
		if(t==0){
		break;	
		}
	Computermove(board); //�������� 		
		t=Checkrow(board);
		if(t==0){
		break;	
		}//�ж���		
		t=Checkcol(board);
		if(t==0){
		break;	
		}//�ж���		
		t=Checkslash(board);
		if(t==0){
		break;	
		}//�ж�б�� 
		t=Checkequal(board);
		if(t==0){
		break;	
		}
				}while(1);
}
else{
	do{int t=1;
	Computermove(board);//�������� 
		//�ж���
		t=Checkrow(board);
		if(t==0){
		break;	
		}
		t=Checkcol(board);
		if(t==0){
		break;	
		}//�ж���		
		t=Checkslash(board);
		if(t==0){
		break;	
		}//�ж�б�� 		
		t=Checkequal(board);
		if(t==0){
		break;	
		}
	Playermove(board); //������� 		
		t=Checkrow(board);
		if(t==0){
		break;	
		}//�ж���		
		t=Checkcol(board);
		if(t==0){
		break;	
		}//�ж���		
		t=Checkslash(board);
		if(t==0){
		break;	
		}//�ж�б�� 
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

