#include <stdio.h>

#ifndef ORGANAIZER_2_H
#define ORGANAIZER_2_H

#define SIZE 256
#define MAXMEET 6
#define MAXDAY 31

int i,j,find_date,del_meet;

struct MEET_2
{
    int date;
	char descr[SIZE];
	int t_hour_begin;
	int t_hour_end;
};

struct DAY_2
{
	int date;
	struct MEET_2 meets[MAXMEET];
	int top;
};

struct ORGANAIZER_2
{
	struct DAY_2 days[MAXDAY];
};

void CreateMeet_2(struct MEET_2 *m,int date,char *descr,int t_hour_begin,int t_hour_end);

void PrintMeet_2(struct MEET_2 *m);

void CreateDay_2(struct DAY_2 *d,int number);

void AddMeet2Day_2(struct DAY_2 *d,struct MEET_2 *m);

int noneDay_2(struct MEET_2 *m);

void PrintDay_2(struct DAY_2 *d);

void CreateOrganaizer_2();

void AddMeet_2(struct MEET_2 *m);

void PrintOrganaizer_2();

void LoadFile_2(FILE *fp);

void SaveFile_2(FILE *fp);

void SaveDay_2(FILE *fp,struct DAY_2 *d);

void SaveMeet_2(FILE *fp,struct MEET_2 *m);

int menu_2();

void AddMeet2_2();

void FindMeet_2(int find);

void DeleteMeet_2(int del_date,int del_date_meet);

void DeleteDay_2(struct DAY_2 *d,int d_d_m);

void DelnoneDay_2(struct MEET_2 *m);

#endif
