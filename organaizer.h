#include <stdio.h>

#ifndef ORGANAIZER_H
#define ORGANAIZER_H

#define SIZE 256
#define MAXMEET 6
#define MAXDAY 31

int i,j,find_date,del_meet;

struct MEET
{
    int date;
	char descr[SIZE];
	int t_hour_begin;
	int t_hour_end;
};

struct DAY
{
	int date;
	struct MEET meets[MAXMEET];
	int top;
};

struct ORGANAIZER
{
	struct DAY days[MAXDAY];
};

void CreateMeet(struct MEET *m,int date,char *descr,int t_hour_begin,int t_hour_end);

void PrintMeet(struct MEET *m);

void CreateDay(struct DAY *d,int number);

void AddMeet2Day(struct DAY *d,struct MEET *m);

int noneDay(struct MEET *m);

void PrintDay(struct DAY *d);

void CreateOrganaizer();

void AddMeet(struct MEET *m);

void PrintOrganaizer();

void LoadFile(FILE *fp);

void SaveFile(FILE *fp);

void SaveDay(FILE *fp,struct DAY *d);

void SaveMeet(FILE *fp,struct MEET *m);

int menu();

void AddMeet2();

void FindMeet(int find);

void DeleteMeet(int del_date,int del_date_meet);

void DeleteDay(struct DAY *d,int d_d_m);

void DelnoneDay(struct MEET *m);

#endif
