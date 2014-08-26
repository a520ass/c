#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define M 50
typedef struct
{
	char number[20];
	char title[20];
	char press[20];
	char author[20];
	char ISBN[20];
	char loantime[20];
	char returntime[20];
	char enteringtime[20];
	int status;
	int price;
}BOOKS;
//以下为函数原形
int enter (BOOKS b[]);
int del(BOOKS b[],int n); 
int find_title(BOOKS b[],int n,char *s);
void modify(BOOKS b[],int n);
void search(BOOKS b[],int n);
void save(BOOKS b[],int n);
int load(BOOKS b[]);
void statistics(BOOKS b[],int n);
