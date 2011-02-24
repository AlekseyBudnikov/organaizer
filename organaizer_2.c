#include "organaizer_2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ORGANAIZER_2 org;

void CreateMeet_2(struct MEET_2 *m,int date,char *descr,int t_hour_begin,int t_hour_end)
{
    m->date=date;
	strcpy(m->descr,descr);
	m->t_hour_begin=t_hour_begin;
	m->t_hour_end=t_hour_end;
}

void PrintMeet_2(struct MEET_2 *m)
{
	printf("Meet\n time: %d-%d\n theme: %s\n",m->t_hour_begin,m->t_hour_end,m->descr);
}

void CreateDay_2(struct DAY_2 *d,int number)
{
    d->date=number;
    d->top=0;
}

void AddMeet2Day_2(struct DAY_2 *d,struct MEET_2 *m)
{
    if(d->top>0)
        for(j=0;j<d->top;j++)
        {
            if((d->meets[j].t_hour_end>=m->t_hour_begin) && (d->meets[j].t_hour_begin<=m->t_hour_end))
            {
                printf("Time is busy %d-%d at %d\n\n",d->meets[j].t_hour_begin,d->meets[j].t_hour_end,d->date);
                return;
            }
        }
	d->meets[d->top++]=*m;
}

int noneDay_2(struct MEET_2 *m)
{
    if(m->date!=0)
        return m->date;
    else
        return -1;
}

void PrintDay_2(struct DAY_2 *d)
{
	if(noneDay_2(&d->meets[0])==(d->date))
    {
        printf("\nDay %d\n\n",d->date);
        for(j=0;j<d->top;j++)
            PrintMeet_2(&d->meets[j]);
        printf("----------------------\n");
    }
}

void CreateOrganaizer_2()
{
	for(i=0;i<MAXDAY;++i)
		CreateDay_2(&org.days[i],i);
}

void PrintOrganaizer_2()
{
	for(i=1;i<MAXDAY;++i)
		PrintDay_2(&org.days[i]);
}

void AddMeet_2(struct MEET_2 *m)
{
    AddMeet2Day_2(&org.days[m->date],m);
}

void LoadFile_2(FILE *fp)
{
	char buf[SIZE];
	char *delim="\t\n";
	char *res;
	while(fgets(buf,SIZE,fp))
	{
		char date[SIZE],descr[SIZE],t_hour_begin[SIZE],t_hour_end[SIZE];
		int dt,thb,the;
		res=strtok(buf,delim);
		strcpy(date,res);
		dt=atoi(date);
		res=strtok(0,delim);
		strcpy(descr,res);
		res=strtok(0,delim);
		strcpy(t_hour_begin,res);
		thb=atoi(t_hour_begin);
		res=strtok(0,delim);
		strcpy(t_hour_end,res);
		the=atoi(t_hour_end);
		struct MEET_2 m;
		CreateMeet_2(&m,dt,descr,thb,the);
		AddMeet_2(&m);
	}
}

void SaveFile_2(FILE *fp)
{
    for(i=1;i<MAXDAY;++i)
		SaveDay_2(fp,&org.days[i]);
}

void SaveDay_2(FILE *fp,struct DAY_2 *d)
{
	if(noneDay_2(&d->meets[0])==(d->date))
    {
        for(j=0;j<d->top;j++)
            SaveMeet_2(fp,&d->meets[j]);
    }
}

void SaveMeet_2(FILE *fp,struct MEET_2 *m)
{
	fprintf(fp,"%d\t%s\t%d\t%d",m->date,m->descr,m->t_hour_begin,m->t_hour_end);
}

int menu_2()
{
    int c;

    printf("1. Load\n");
    printf("2. Save\n");
    printf("3. Add\n");
    printf("4. Find\n");
    printf("5. Delete\n");
    printf("6. List\n");
    printf("7. Exit\n");

    do
    {
        printf("\nEnter number: ");
        scanf("%d",&c);
        printf("\n");
    }
    while(c<0 || c>7);

    return c;
}

void AddMeet2_2()
{
		char descr[SIZE];
		int date,thb,the;
		printf("Date: ");
		scanf("%d",&date);
		printf("Descr: ");
		scanf("%s",&descr);
		printf("Begin: ");
		scanf("%d",&thb);
		printf("End: ");
		scanf("%d",&the);
		printf("\n");
		struct MEET_2 m;
		CreateMeet_2(&m,date,descr,thb,the);
		AddMeet_2(&m);
}

void FindMeet_2(int find)
{
    PrintDay_2(&org.days[find]);
}

void DeleteMeet_2(int del_date,int del_date_meet)
{
    DeleteDay_2(&org.days[del_date],del_date_meet);

}

void DelnoneDay_2(struct MEET_2 *m)
{
    m->date=0;
}

void DeleteDay_2(struct DAY_2 *d,int d_d_m)
{
    DelnoneDay_2(&d->meets[d_d_m]);
}
