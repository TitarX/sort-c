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

        for(int i=1;i<SIZE;i++)
        {
                for(int j=SIZE-1;j>=i;j--)
                {
                        if(mas[j]<mas[j-1])
                        {
                                mas[j]+=mas[j-1];
                                mas[j-1]=mas[j]-mas[j-1];
                                mas[j]-=mas[j-1];
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
