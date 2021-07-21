#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 50
#define MAXSTACK 2048

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

void fastSort(int mas[],int size)
{
        int i, j;
        int lb, ub;
        int lbstack[MAXSTACK], ubstack[MAXSTACK];
        int stackpos = 1;
        int ppos;
        int pivot;
        int temp;

        lbstack[1] = 0;
        ubstack[1] = size;

        do
        {
                lb = lbstack[ stackpos ];
                ub = ubstack[ stackpos ];
                stackpos--;

                do
                {
                        ppos = ( lb + ub ) >> 1;
                        i = lb; j = ub; pivot = mas[ppos];

                        do
                        {
                                while ( mas[i] < pivot ) i++;
                                while ( pivot < mas[j] ) j--;

                                if ( i <= j )
                                {
                                        temp = mas[i]; mas[i] = mas[j]; mas[j] = temp;
                                        i++; j--;
                                }
                        }while ( i <= j );

                        if ( i < ppos )
                        {
                                if ( i < ub )
                                {
                                        stackpos++;
                                        lbstack[ stackpos ] = i;
                                        ubstack[ stackpos ] = ub;
                                }
                                ub = j;

                        }
                        else
                        {
                                if ( j > lb )
                                {
                                        stackpos++;
                                        lbstack[ stackpos ] = lb;
                                        ubstack[ stackpos ] = j;
                                }
                                lb = i;
                        }

                }while ( lb < ub );

        }while ( stackpos != 0 );
}

