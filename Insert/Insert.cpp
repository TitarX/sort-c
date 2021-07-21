/*
Сортировка вставкой
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 50

int main()
{
        srand(time(NULL));
        clrscr();
        int mas[SIZE];

        for(int i=1;i<=SIZE;i++)
        {
                mas[i-1]=rand()%10;
                printf("%d ",mas[i-1]);
                if(!(i%10))
                {
                        printf("\n\n");
                }
        }
        printf("\n");

        int temp;
        for(int i=1;i<SIZE;i++)
        {
                temp=mas[SIZE-1];
                for(int j=SIZE-1;j>i;j--)
                {
                        mas[j]=mas[j-1];
                }
                for(int j=i;j>0;j--)
                {
                        if(mas[j-1]>temp)
                        {
                                mas[j]=mas[j-1];
                                if(!(j-1))mas[j-1]=temp;
                        }
                        else
                        {
                                mas[j]=temp;
                                break;
                        }
                }
        }

        for(int i=1;i<=SIZE;i++)
        {
                printf("%d ",mas[i-1]);
                if(!(i%10))
                {
                        printf("\n\n");
                }
        }

        getchar();
        return 0;
}

