#include "organaizer.h"
#include "organaizer_2.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;

    CreateOrganaizer();
    CreateOrganaizer_2();

    int d;

menu:
    printf("1. First journalist\n");
    printf("2. Second journalist\n");
    printf("3. Add meet to both\n");
    printf("4. Exit\n");

    do
    {
        printf("\nEnter number: ");
        scanf("%d",&d);
        printf("\n");
    }
    while(d<0 || d>4);

    for(;;)
    {
        switch(d)
        {
            case 1:
                for(;;)
                {
                    switch(menu())
                    {
                        case 1:
                            fp=fopen("lib.txt","r");
                            LoadFile(fp);
                            fclose(fp);
                            break;
                        case 2:
                            fp=fopen("lib.txt","w");
                            SaveFile(fp);
                            fclose(fp);
                            break;
                        case 3:
                            AddMeet2();
                            break;
                        case 4:
                            printf("Enter date: ");
                            scanf("%d",&find_date);
                            FindMeet(find_date);
                            break;
                        case 5:
                            printf("Enter date: ");
                            scanf("%d",&find_date);
                            printf("Enter number of meet: ");
                            scanf("%d",&del_meet);
                            DeleteMeet(find_date,del_meet);
                            break;
                        case 6:
                            PrintOrganaizer();
                            break;
                        case 7:
                            goto menu;
                            break;
                    }
                }
                break;
            case 2:
                for(;;)
                {
                    switch(menu_2())
                    {
                        case 1:
                            fp=fopen("lib_2.txt","r");
                            LoadFile_2(fp);
                            fclose(fp);
                            break;
                        case 2:
                            fp=fopen("lib_2.txt","w");
                            SaveFile_2(fp);
                            fclose(fp);
                            break;
                        case 3:
                            AddMeet2();
                            break;
                        case 4:
                            printf("Enter date: ");
                            scanf("%d",&find_date);
                            FindMeet_2(find_date);
                            break;
                        case 5:
                            printf("Enter date: ");
                            scanf("%d",&find_date);
                            printf("Enter number of meet: ");
                            scanf("%d",&del_meet);
                            DeleteMeet_2(find_date,del_meet);
                            break;
                        case 6:
                            PrintOrganaizer_2();
                            break;
                        case 7:
                            goto menu;
                            break;
                    }
                }
                break;
            case 3:
            ////
                break;
            case 4:
                exit(0);
                break;
        }
    }

	return 0;
}

