#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 50

typedef struct tree
{
        int a;
        struct tree *left;
        struct tree *right;
}TREE;

TREE*add_to_tree(TREE*,int);
void tree_to_array(TREE*,int[]);
void sort_tree(int[],int);

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

        sort_tree(mas,SIZE);

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

TREE*add_to_tree(TREE*root,int new_value)
{
        if (root==NULL)
        {
                root=(TREE*)malloc(sizeof(TREE));
                root->a=new_value;
                root->left=root->right=0;
                return root;
        }
        if (root->a<new_value)
        {
                root->right=add_to_tree(root->right,new_value);
        }
        else
        {
                root->left=add_to_tree(root->left,new_value);
        }
        return root;
}
void tree_to_array(TREE*root,int mas[])
{
        static max2=0;
        if(root==NULL)
        {
                return;
        }
        tree_to_array(root->left,mas);
        mas[max2++] = root->a;
        tree_to_array(root->right,mas);
        free(root);
}
void sort_tree(int mas[],int elem_total)
{
        TREE*root;
        int i;
        root=NULL;
        for (i=0;i<elem_total;i++)
        {
                root=add_to_tree(root,mas[i]);
        }
        tree_to_array(root,mas);
}

