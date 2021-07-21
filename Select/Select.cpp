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

        for(int i=0;i<SIZE;i++)
        {
                mas[i]=rand()%10;
                printf("%d ",mas[i]);
                if(!((i+1)%10))
                {
                        printf("\n");
                }
        }
        printf("\n");

        for(int i=0;i<SIZE-1;i++)
        {
                for(int j=i+1;j<SIZE;j++)
                {
                        if(mas[i]>mas[j])
                        {
                                mas[i]+=mas[j];
                                mas[j]=mas[i]-mas[j];
                                mas[i]-=mas[j];
                        }
                }
        }

        for(int i=0;i<SIZE;i++)
        {
                printf("%d ",mas[i]);
                if(!((i+1)%10))
                {
                        printf("\n");
                }
        }

        getchar();
        return 0;
}

