#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 50

void mergeSort(int[],int,int);
void merge(int[],int,int,int);

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

        mergeSort(mas,0,SIZE-1);

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

void mergeSort(int mas[],int lb,int ub)
{
        int split;

        if (lb < ub)
        {
                split = (lb + ub)/2;
                mergeSort(mas, lb, split);
                mergeSort(mas, split+1, ub);
                merge(mas, lb, split, ub);
        }
}
void merge(int mas[], int lb, int split, int ub)
{
        int pos1=lb;
        int pos2=split+1;
        int pos3=0;
        int *temp;
        temp=(int*)calloc(SIZE,sizeof(int));

        while (pos1 <= split && pos2 <= ub)
        {
                if (mas[pos1] < mas[pos2])
                        temp[pos3++] = mas[pos1++];
                else
                        temp[pos3++] = mas[pos2++];
        }

        while (pos2 <= ub)
                temp[pos3++] = mas[pos2++];
        while (pos1 <= split)
                temp[pos3++] = mas[pos1++];

        for (pos3 = 0; pos3 < ub-lb+1; pos3++)
                mas[lb+pos3] = temp[pos3];

        free(temp);
}

