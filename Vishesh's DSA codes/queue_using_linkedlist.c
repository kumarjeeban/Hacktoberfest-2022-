#include <stdio.h>

#include <stdlib.h>
struct Node
{

    int elem;

    struct Node *Next;
};

struct Node *Create_Node(int Data);

struct Node *Insert_q(struct Node **h, struct Node *new_Node);

void show(struct Node *h);

struct Node *Delete_q(struct Node **h);

int main(int argc, char const *argv[])
{
    int m, Data;

    struct Node *h = NULL, *p, *l;

    printf("enter the number of Node to be inserted in list\n");

    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {

        printf("enter the elem to be inserted in Node\n");

        scanf("%d", &Data);

        p = Create_Node(Data);

        Insert_q(&h, p);

        show(h);
    }
    printf("all the inserted elems\n");

    show(h);

    printf("the deletion from the end\n");

    for (int i = 0; i < m; i++)

    {

        Delete_q(&h);

        show(h);
    }
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

struct Node *
Insert_q(struct Node **h, struct Node *new_Node)
{
    struct Node *Curr;

    if (*h == NULL)
    {

        *h = new_Node;
    }

    else
    {
        Curr = *h;

        while (Curr->Next != NULL)
        {

            Curr = Curr->Next;
        }

        Curr->Next = new_Node;
    }
}

struct Node *
Delete_q(struct Node **h)
{

    struct Node *Curr;

    if (*h == NULL)
    {

        return NULL;
    }

    Curr = *h;

    if (Curr->Next == NULL)
    {

        printf("the deleted Node is=%d\n", Curr->elem);

        Curr = NULL;

        free(Curr);
    }

    else
    {

        while (Curr->Next->Next != NULL)
        {

            Curr = Curr->Next;
        }

        printf("the deleted Node is=%d\n", Curr->Next->elem);

        Curr->Next = NULL;

        free(Curr->Next);
    }

    return *h;
}

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
