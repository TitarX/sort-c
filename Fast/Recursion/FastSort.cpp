#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 50

void fastSort(int[],int);

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

        fastSort(mas,SIZE-1);

        for(int i=0;i<SIZE;i++)
        {
                printf("%d ",mas[i]);
                if(!((i+1)%10))
                {
                        printf("\n");
                }
        }
        printf("\n");

        getchar();
        return 0;
}

void fastSort(int mas[],int N)
{

        int i = 0, j = N;
        int temp, p;

        p = mas[ N>>1 ];

        do
        {
                while ( mas[i] < p ) i++;
                while ( mas[j] > p ) j--;

                if (i <= j)
                {
                        temp = mas[i]; mas[i] = mas[j]; mas[j] = temp;
                        i++; j--;
                }
        }while ( i<=j );

        if ( j > 0 ) fastSort(mas, j);
        if ( N > i ) fastSort(mas+i, N-i);

}

