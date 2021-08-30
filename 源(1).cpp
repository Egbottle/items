#include<bits/stdc++.h> 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<cstdlib>
#include<ctime>
using namespace std;
void Printform(char board[3][3]);
int checkcomputer(char board[3][3]);
int checkplayer(char board[3][3]);
int Checkrow2(char board[3][3], int i);
int Checkcol2(char board[3][3], int i);
int Checkslash2(char board[3][3]);
int Checkslash3(char board[3][3]);
int AI3(char board[3][3]);
int AI4(char board[3][3]);
int AI5(char board[3][3]);
int AI6(char board[3][3], int i);
int AI7(char board[3][3], int i);

int s, t, o, p, s1, t1, o1, p1;
double times = 0;
int computerwin = 0;
double playerwin = 0;
int vsequal = 0;

int diagonal(int a) {
	int c = (a + 2) % 4;
	return c;
}

void Playermove(char board[3][3]) {
	printf("\n玩家选择落棋的位置坐标(行 列)，并以空格隔开:>");
	char ss,tt;
	recin:
	cin >> ss >> tt;
	while (ss-'0' <= 0 || ss -'0'> 3 || tt-'0' <= 0 || tt-'0' > 3) {
		printf("错误坐标，请重新输入:>");
		goto recin;
	}
	s = ss - '0';
	t = tt - '0';
	if( board[s - 1][t - 1] != ' ')
	{
		printf("已经下过，请重新输入:>");
		goto recin;
	}

	board[s - 1][t - 1] = 'X';
	Printform(board);
}//玩家下棋 
void Computermove(char board[3][3]) {
	int x, y;
	printf("\n电脑下棋:>\n");
	do {
		x = rand() % 3;
		y = rand() % 3;
		if (board[x][y] == ' ') {
			board[x][y] = 'O';
			Printform(board);
			break;
		}
		else {
			continue;
		}
	} while (1);
}//电脑下棋随机 

void AI1(char board[3][3]) {
	int x = 1, y = 1;
	printf("\n电脑下棋:>\n");
	board[x][y] = 'O';
	Printform(board);
}

void AI2(char board[3][3]) {
	if ((s * t) % 2 == 0) {
		printf("\n电脑下棋:>\n");
		if (s == 1) {
			board[s - 1][t] = 'O';
			o = s;
			p = t + 1;
		}
		else if (s == 2) {
			board[s][t - 1] = 'O';
			o = s + 1;
			p = t;
		}
		else {
			board[s - 1][t] = 'O';
			o = s;
			p = t + 1;
		}
		s1 = s;
		t1 = t;
		Printform(board);
		Playermove(board);
		printf("\n电脑下棋:>\n");
		if (board[diagonal(o) - 1][diagonal(p) - 1] == ' ') {
			o = diagonal(o);
			p = diagonal(p);
			board[o - 1][p - 1] = 'O';
			Printform(board);
			int t = checkcomputer(board);
		}
		else {
			if (s1 != 2) {
				o = 2;
			}
			else {
				p = 2;
			}
			board[o - 1][p - 1] = 'O';
			Printform(board);
			Playermove(board);
			AI3(board);
			checkcomputer(board);
		}
	}
	else {
		printf("\n电脑下棋:>\n");
		board[diagonal(s) - 1][diagonal(t) - 1] = 'O';
		Printform(board);
		s1 = s;
		t1 = t;
		Playermove(board);
		if ((abs(s - s1) == 2 && abs(t - t1) == 1) || (abs(s - s1) == 1 && abs(t - t1) == 2)) {
			printf("\n电脑下棋:>\n");
			for (int i = 0; i < 3; i = i + 2) {
				int ab = AI6(board, i);
				if (ab == 1) {
					if (board[i][0] == ' ') {
						board[i][0] = 'O';
					}
					else {
						board[i][2] = 'O';
					}
					goto o2;
					break;
				}
			}
			for (int i = 0; i < 3; i = i + 2) {
				int ac = AI7(board, i);
				if (ac == 1) {
					if (board[0][i] == ' ') {
						board[0][i] = 'O';
					}
					else {
						board[2][i] = 'O';
					}
					break;
				}
			}
		o2:
			Printform(board);
			Playermove(board);
			Printform(board);
			checkcomputer(board);
		}
		while (1) {
			int w = 0, q = 0, v = 0;
			w = AI3(board);
			if (w == 1) {
				goto over;
			}
			q = AI4(board);
			if (q == 1) {
				goto over;
			}
			v = AI5(board);
			if (v != 0) {
				goto over;
			}
			Computermove(board);
		over:
			int u = checkcomputer(board);
			if (u == 0) {
				break;
			}
			Playermove(board);
			u = checkcomputer(board);
			if (u == 0) {
				break;
			}
		}
	}
}//电脑先下核心代码

int AI3(char board[3][3]) {
	int k1 = 0, k2 = 0;
	int ab = 0;
	for (int i = 0; i < 3; i++) {
		k1 = Checkcol2(board, i);
		if (k1 == 2) {
			for (int j = 0; j < 3; j++) {
				if (board[j][i] == ' ') {
					printf("\n电脑下棋:>\n");
					board[j][i] = 'O';
					Printform(board);
					return 1;
					ab++;
					break;
				}
			}
			if (ab > 0) {
				break;
			}
		}
		k2 = Checkrow2(board, i);
		if (k2 == 2) {
			for (int j = 0; j < 3; j++) {
				if (board[i][j] == ' ') {
					printf("\n电脑下棋:>\n");
					board[i][j] = 'O';
					Printform(board);
					return 1;
					ab++;
					break;
				}
			}
			if (ab > 0) {
				break;
			}
		}
	}
	if (ab == 0) {
		return 0;
	}
}

int AI4(char board[3][3]) {
	int k1 = 0, k2 = 0;
	int ab = 0;
	for (int i = 0; i < 3; i++) {
		k1 = Checkcol2(board, i);
		if (k1 == 1) {
			for (int j = 0; j < 3; j++) {
				if (board[j][i] == ' ') {
					printf("\n电脑下棋:>\n");
					board[j][i] = 'O';
					Printform(board);
					return 1;
					ab++;
					break;
				}
			}
			if (ab > 0) {
				break;
			}
		}
		k2 = Checkrow2(board, i);
		if (k2 == 1) {
			for (int j = 0; j < 3; j++) {
				if (board[i][j] == ' ') {
					printf("\n电脑下棋:>\n");
					board[i][j] = 'O';
					Printform(board);
					return 1;
					break;
				}
			}
			if (ab > 0) {
				break;
			}
		}
	}
	if (ab == 0) {
		return 0;
	}
}

int AI5(char board[3][3]) {
	int k1 = Checkslash2(board);
	int k2 = Checkslash3(board);
	if (k1 != 0) {
		for (int i = 0; i < 3; i++) {
			if (board[i][i] == ' ') {
				printf("\n电脑下棋:>\n");
				board[i][i] = 'O';
				Printform(board);
				return 1;
				break;
			}
		}
	}
	else if (k2 != 0) {
		for (int i = 0; i < 3; i++) {
			if (board[2 - i][i] == ' ') {
				printf("\n电脑下棋:>\n");
				board[2 - i][i] = 'O';
				Printform(board);
				return 1;
				break;
			}
		}
	}
	else {
		return 0;
	}
}

int AI6(char board[3][3], int i) {
	int j = 0;
	int numnull = 0;
	int n1 = 0, n2 = 0;
	for (j; j < 3; j++) {
		if (board[i][j] == 'X') {
			n1++;
		}
		else if (board[i][j] == ' ') {
			numnull++;
		}
		else {
			n2++;
		}
	}
	if (n1 == 0 && n2 == 1) {
		return 1;
	}
	else {
		return 0;
	}
}//行（AI2特殊情况下）

int AI7(char board[3][3], int i) {
	int j = 0;
	int numnull = 0;
	int n1 = 0, n2 = 0;
	for (j; j < 3; j++) {
		if (board[j][i] == 'X') {
			n1++;
		}
		else if (board[j][i] == ' ') {
			numnull++;
		}
		else {
			n2++;
		}
	}
	if (n1 == 0 && n2 == 1) {
		return 1;
	}
	else {
		return 0;
	}
}//列（AI2特殊情况下）

int Checkrow(char board[3][3]) {
	int i = 0;
	for (i; i < 3; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == 'X') {
			printf("\n恭喜你，你赢了！\n\n\n");
			playerwin++;
			return 0;
			break;
		}//玩家赢 
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == 'O') {
			printf("\n很遗憾，电脑获胜\n\n\n");
			computerwin++;
			return 0;
			break;
		}//电脑赢
	}
}//检查行 
int Checkcol(char board[3][3]) {
	int j = 0;
	for (j; j < 3; j++) {
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j] == 'X') {
			printf("\n恭喜你，你赢了!\n\n\n");
			playerwin++;
			return 0;
			break;
		}//玩家赢 
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j] == 'O') {
			printf("\n很遗憾，电脑获胜\n\n\n");
			computerwin++;
			return 0;
			break;
		}//电脑赢
	}
}//检查列
int Checkslash(char board[3][3]) {
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == 'X') {
		printf("\n恭喜你，你赢了！\n\n\n");
		playerwin++;
		return 0;
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == 'X') {
		printf("\n恭喜你，你赢了！\n\n\n");
		playerwin++;
		return 0;
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == 'O') {
		printf("\n很遗憾，电脑获胜\n\n\n");
		computerwin++;
		return 0;
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == 'O') {
		printf("\n很遗憾，电脑获胜\n\n\n");
		computerwin++;
		return 0;
	}
}//检查斜线 
int Checkequal(char board[3][3]) {
	int m = 0;
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (board[i][j] != ' ') {
				m += 1;
			}
		}
	}
	if (m == 9) {
		printf("\n平局！\n\n\n");
		vsequal++;
		return 0;
	}
}//检查平局 

int checkcomputer(char board[3][3]) {
	int t = 1;
	//判断行
	t = Checkrow(board);
	if (t == 0) {
		goto flag1;
	}
	t = Checkcol(board);
	if (t == 0) {
		goto flag1;
	}
	//判断列		
	t = Checkslash(board);
	if (t == 0) {
		goto flag1;
	}
	//判断斜线 		
	t = Checkequal(board);
flag1:
	return t;
}//检查电脑

int checkplayer(char board[3][3]) {
	int t = 1;
	//判断行
	t = Checkrow(board);
	if (t == 0) {
		goto flag2;
	}
	t = Checkcol(board);
	if (t == 0) {
		goto flag2;
	}
	//判断列		
	t = Checkslash(board);
	if (t == 0) {
		goto flag2;
	}
	//判断斜线 		
	t = Checkequal(board);
flag2:
	return t;
}//检查玩家

int Checkcol2(char board[3][3], int i) {
	int j = 0;
	int numnull = 0;
	int n1 = 0, n2 = 0;
	for (j; j < 3; j++) {
		if (board[j][i] == 'X') {
			n1++;
		}
		else if (board[j][i] == ' ') {
			numnull++;
		}
		else {
			n2++;
		}
	}
	if (n1 == 2 && n2 == 0) {
		return 1;//玩家一列有两个了
	}
	else if (n2 == 2 && n1 == 0) {
		return 2;//电脑一列有两个了
	}
	else {
		return 0;
	}
}//检查一列有两个

int Checkrow2(char board[3][3], int i) {
	int j = 0;
	int numnull = 0;
	int n1 = 0, n2 = 0;
	for (j; j < 3; j++) {
		if (board[i][j] == 'X') {
			n1++;
		}
		else if (board[i][j] == ' ') {
			numnull++;
		}
		else {
			n2++;
		}
	}
	if (n1 == 2 && n2 == 0) {
		return 1;//玩家一行有两个了
	}
	else if (n2 == 2 && n1 == 0) {
		return 2;//电脑一行有两个了
	}
	else {
		return 0;
	}
}//检查一行有两个

int Checkslash2(char board[3][3]) {
	int j = 0;
	int numnull = 0;
	int n1 = 0, n2 = 0;
	for (j; j < 3; j++) {
		if (board[j][j] == 'X') {
			n1++;
		}
		else if (board[j][j] == ' ') {
			numnull++;
		}
		else {
			n2++;
		}
	}
	if (n1 == 2 && n2 == 0) {
		return 1;//玩家正斜线有两个了
	}
	else if (n2 == 2 && n1 == 0) {
		return 2;//电脑正斜线有两个了
	}
	else {
		return 0;
	}
}//检查正斜线 有两个

int Checkslash3(char board[3][3]) {
	int j = 0;
	int numnull = 0;
	int n1 = 0, n2 = 0;
	for (j; j < 3; j++) {
		if (board[2 - j][j] == 'X') {
			n1++;
		}
		else if (board[2 - j][j] == ' ') {
			numnull++;
		}
		else {
			n2++;
		}
	}
	if (n1 == 2 && n2 == 0) {
		return 1;//玩家反斜线有两个了
	}
	else if (n2 == 2 && n1 == 0) {
		return 2;//电脑反斜线有两个了
	}
	else {
		return 0;
	}
}//检查反斜线 有两个

void Initboard(char board[3][3]) {
	int i = 0, j = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
}//初始化棋盘 
void Printform(char board[3][3]) {
	int i = 0, j = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf(" %c ", board[i][j]);
			if (j < 2) {
				printf("|");
			}
			else {
				printf("\n");

			}
		}
		if (i < 2) {
			for (j = 0; j < 3; j++) {
				if (j < 3) { printf("---"); }
				if (j < 2) {
					printf("|");
				}
				else {
					printf("\n");
				}
			}
		}
	}
}//打印表格 

void menu() {
	printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
	printf("X          XX井字棋XX          X\n");
	printf("X  1.play  XXXXXXXXXX  0.exit  X\n");
	printf("X          XXXXXXXXXX          X\n");
	printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
	//开始菜单 
}
void game() {
	char board[3][3];
	Initboard(board);//初始化表格
	cout << endl << "\n随机数生成：";
	double x = rand() % 10;
	cout << x << "，[5,10]为电脑先下。" << endl << endl;
	if (x >= 5) {
		cout << "电脑先下\n" << endl;
		AI1(board);
		Playermove(board);
		AI2(board);
	}
	else {
		cout << "玩家先下\n" << endl;
		Printform(board);//打印表格 
		Playermove(board);
		if (board[1][1] == ' ') {
			printf("\n电脑下棋:>\n");
			board[1][1] = 'O';
			Printform(board);//打印表格 
			Playermove(board);
		}
		while (1) {
			int w = 0, q = 0, v = 0;
			w = AI3(board);
			if (w == 1) {
				goto over;
			}
			q = AI4(board);
			if (q == 1) {
				goto over;
			}
			v = AI5(board);
			if (v != 0) {
				goto over;
			}
			Computermove(board);
		over:
			int u = checkcomputer(board);
			if (u == 0) {
				break;
			}
			Playermove(board);
			u = checkplayer(board);
			if (u == 0) {
				break;
			}
		}
	}
	/*do {
		int t = 1;
		t = checkcomputer(board);
		if (t == 0) {
			break;
		}
		Computermove(board); //电脑下棋
		t = checkplayer(board);
		if (t == 0) {
			break;
		}
	} while (1);
	*/
}
int main() {
	char input = '0';
	do {
		srand((int)time(0));
		menu();
		printf("请选择:>");
		cin >> input;
		switch (input) {
		case '0':printf("退出游戏\n");
			break;
		case '1':printf("开始游戏（O为电脑下棋，X为玩家下棋）\n"); times++;
			game();
			break;
		default:
			printf("选择错误，请重新选择\n\n");
		}

	} while (input-'0');
	if (times == 0) {
		cout << "一共下了0局\n\n";
	}
	else {
		double totalrate = 100 * playerwin / times;
		cout << endl << "一共下了" << times << "局" << endl << "胜率为" << setiosflags(ios::fixed) << setprecision(2) << totalrate << "%\n\n";
	}
	system("pause");
	return 0;
}

