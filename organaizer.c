#include "organaizer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ORGANAIZER org;

void CreateMeet(struct MEET *m,int date,char *descr,int t_hour_begin,int t_hour_end)
{
    m->date=date;
	strcpy(m->descr,descr);
	m->t_hour_begin=t_hour_begin;
	m->t_hour_end=t_hour_end;
}

void PrintMeet(struct MEET *m)
{
	printf("Meet\n time: %d-%d\n theme: %s\n",m->t_hour_begin,m->t_hour_end,m->descr);
}

void CreateDay(struct DAY *d,int number)
{
    d->date=number;
    d->top=0;
}

void AddMeet2Day(struct DAY *d,struct MEET *m)
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

int noneDay(struct MEET *m)
{
    if(m->date!=0)
        return m->date;
    else
        return -1;
}

void PrintDay(struct DAY *d)
{
	if(noneDay(&d->meets[0])==(d->date))
    {
        printf("\nDay %d\n\n",d->date);
        for(j=0;j<d->top;j++)
            PrintMeet(&d->meets[j]);
        printf("----------------------\n");
    }
}

void CreateOrganaizer()
{
	for(i=0;i<MAXDAY;++i)
		CreateDay(&org.days[i],i);
}

void PrintOrganaizer()
{
	for(i=1;i<MAXDAY;++i)
		PrintDay(&org.days[i]);
}

void AddMeet(struct MEET *m)
{
    AddMeet2Day(&org.days[m->date],m);
}

void LoadFile(FILE *fp)
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
		struct MEET m;
		CreateMeet(&m,dt,descr,thb,the);
		AddMeet(&m);
	}
}

void SaveFile(FILE *fp)
{
    for(i=1;i<MAXDAY;++i)
		SaveDay(fp,&org.days[i]);
}

void SaveDay(FILE *fp,struct DAY *d)
{
	if(noneDay(&d->meets[0])==(d->date))
    {
        for(j=0;j<d->top;j++)
            SaveMeet(fp,&d->meets[j]);
    }
}

void SaveMeet(FILE *fp,struct MEET *m)
{
	fprintf(fp,"%d\t%s\t%d\t%d",m->date,m->descr,m->t_hour_begin,m->t_hour_end);
}

int menu()
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

void AddMeet2()
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
		struct MEET m;
		CreateMeet(&m,date,descr,thb,the);
		AddMeet(&m);
}

void FindMeet(int find)
{
    PrintDay(&org.days[find]);
}

void DeleteMeet(int del_date,int del_date_meet)
{
    DeleteDay(&org.days[del_date],del_date_meet);

}

void DelnoneDay(struct MEET *m)
{
    m->date=0;
}

void DeleteDay(struct DAY *d,int d_d_m)
{
    DelnoneDay(&d->meets[d_d_m]);
}
