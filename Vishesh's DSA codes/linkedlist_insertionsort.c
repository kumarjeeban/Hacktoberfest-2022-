#include <stdio.h>

#include <stdlib.h>
struct Node
{

    int elem;

    struct Node *Next;
};

struct Node *Create_Node(int Data);

void InsertSort(struct Node **href, struct Node *new_Node);

void show(struct Node *);

int main(int argc, char const *argv[])

{

    int m, Data;

    struct Node *p, *h;

    h = NULL;

    printf("enter the number of Nodes to be inserted\n");

    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {

        printf("enter the Data of Node %d \n", i + 1);

        scanf("%d", &Data);

        p = Create_Node(Data);

        InsertSort(&h, p);
    }
    printf("the list in sorted order after insertion\n");

    show(h);

    return 0;
}

struct Node *
Create_Node(int Data)
{

    struct Node *new_Node;

    new_Node = (struct Node *)malloc(sizeof(struct Node));

    new_Node->elem = Data;

    new_Node->Next = NULL;

    return new_Node;
}

// function to add new Node in original list in sorted way
void InsertSort(struct Node **href, struct Node *new_Node)
{

    struct Node *Curr;

    if (*href == NULL || (*href)->elem >= new_Node->elem)
    {

        new_Node->Next = *href;

        *href = new_Node;
    }

    else
    {

        Curr = *href;

        while (Curr->Next != NULL && Curr->Next->elem < new_Node->elem)
        {

            Curr = Curr->Next;
        }

        new_Node->Next = Curr->Next;

        Curr->Next = new_Node;
    }
}

// function to show the list
void show(struct Node *h)
{

    struct Node *Curr = h;

    while (Curr != NULL)
    {

        printf("%d  ", Curr->elem);

        Curr = Curr->Next;
    }

    printf("\n");
}
