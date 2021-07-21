#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 50

void mergeSort(int[],int,int);

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

void mergeSort(int mas[],int begin,int end)
{
        int key=(end-begin)/2+begin;
        int i=begin;
        int j=end;
        int l;

        if(key>begin)
        {
                mergeSort(mas,begin,key);
        }
        if(key<(end-1))
        {
                mergeSort(mas,key+1,end);
        }

        int *temp;
        temp=(int*)calloc(SIZE,sizeof(int));

        int k=key+1;

        for(l=0;(i<=key)&&(k<=j);l++)
        {
                if(mas[i]<mas[k])
                {
                        temp[l]=mas[i];
                        i++;
                }
                else
                {
                        temp[l]=mas[k];
                        k++;
                }
        }

        if(i>key)
        {
                while(k<=j)
                {
                        temp[l]=mas[k];
                        l++;
                        k++;
                }
        }
        else
        {
                while(i<=key)
                {
                        temp[l]=mas[i];
                        l++;
                        i++;
                }
        }

        for(int m=begin,n=0;m<=end;m++,n++)
        {
                mas[m]=temp[n];
        }

        free(temp);
}

