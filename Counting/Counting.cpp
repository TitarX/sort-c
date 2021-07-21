#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

#define SIZE 50

void countingSort(int[],int,int,int);

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

        countingSort(mas,SIZE,0,9);

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

void countingSort (int mas[], int n, int min, int max)
{
        int i, j, c;
        int *b;
        assert(n > 0);
        assert(min <= max);
        b = (int *)calloc(max - min + 1, sizeof(int));
        assert(b != NULL);
        for (i = 0; i <= n - 1; ++i)
        {
                ++b[mas[i] - min];
        }
        for (j = min; j <= max; ++j)
        {
                c = b[j - min];
                while (c > 0)
                {
                        *mas = j; ++mas; --c;
                }
        }
        free(b);
}

