#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 50

void heap(int[],int,int);
void heapSort(int[],int);

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

        heapSort(mas,SIZE-1);

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

void heap(int mas[],int k,int n)
{
        int newElt,child;
        newElt=mas[k];
        while(k<=n/2)
        {
                child=2*k;
                if(child<n&&mas[child]<mas[child+1])
                {
                        child++;
                }
                if(newElt>=mas[child])
                {
                        break;
                }
                mas[k]=mas[child];
                k=child;
        }
        mas[k]=newElt;
}

void heapSort(int mas[],int n)
{
        int i,temp;
        for(i=n/2;i>=0;i--)
        {
                heap(mas,i,n);
        }
        for(i=n;i>1;i--)
        {
                temp=mas[i];
                mas[i]=mas[0];
                mas[0]=temp;
                heap(mas,0,i-1);
        }
}

