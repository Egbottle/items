#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#include<stdlib.h>
#include<time.h>
#define MODERN 10

void Initboard(char unshow[ROWS][COLS],char show[ROWS][COLS]);
void Displayboard(char unshow[ROWS][COLS],char show[ROWS][COLS]);
void Stickmine(char unshow[ROWS][COLS]);
int  Checkmine(char unshow[ROWS][COLS],char show[ROWS][COLS]);
void Spreadcheck(char unshow[ROWS][COLS],char show[ROWS][COLS],int a,int b);
