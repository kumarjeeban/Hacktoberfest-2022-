#include <stdio.h>

#include <stdlib.h>
int k = 1;

struct Node
{

    int Coeff;

    int power;

    struct Node *Next;
};

struct Node *Create_List();

void show(struct Node *h);

void showp(struct Node *h);

struct Node *Add_poly(struct Node *h1, struct Node *h2);

int main(int argc, char const *argv[])
{

    struct Node *h1, *h2, *h3;

    h1 = Create_List();

    show(h1);

    h2 = Create_List();

    show(h2);

    printf("showing of two polynomial\n");

    show(h1);

    show(h2);

    printf("addition of two polynomial\n");

    h3 = Add_poly(h1, h2);

    showp(h3);

    return 0;
}

struct Node *
Create_List()
{

    struct Node *h, *Temp;

    int m, coe, exp;

    printf("enter the number of terms in polynomial %d\n", k);

    k++;

    scanf("%d", &m);

    for (int i = 1; i <= m; i++)

    {

        printf("enter the Coeff and power\n");

        scanf("%d%d", &coe, &exp);

        if (i == 1)

        {

            h = (struct Node *)malloc(sizeof(struct Node));

            Temp = h;
        }

        else

        {

            Temp->Next = (struct Node *)malloc(sizeof(struct Node));

            Temp = Temp->Next;
        }

        Temp->Coeff = coe;

        Temp->power = exp;
    }
    Temp->Next = NULL;

    return h;
}

void show(struct Node *h)
{

    struct Node *p;

    if (h == NULL)

    {

        printf("empty list\n\n");
    }

    else

    {

        for (p = h; p != NULL; p = p->Next)

        {

            if (p->Next != NULL)

            {

                printf("%d*x^%d + ", p->Coeff, p->power);
            }

            else

            {

                printf("%d*x^%d\n\n\n", p->Coeff, p->power);
            }
        }
    }
}

struct Node *
Add_poly(struct Node *h1, struct Node *h2)
{

    int c, e;

    struct Node *h3, *Temp, *p, *q, *New;

    h3 = (struct Node *)malloc(sizeof(struct Node));

    h3->Next = NULL;

    Temp = h3;

    p = h1;

    q = h2;

    while (p != NULL && q != NULL)

    {

        if (p->power > q->power)

        {

            c = p->Coeff;

            e = p->power;

            p = p->Next;
        }

        else if (p->power < q->power)

        {

            c = q->Coeff;

            e = q->power;

            q = q->Next;
        }

        else if (p->power == q->power)

        {

            c = p->Coeff + q->Coeff;

            e = p->power;

            p = p->Next;

            q = q->Next;
        }

        New = (struct Node *)malloc(sizeof(struct Node));

        New->Coeff = c;

        New->power = e;

        New->Next = NULL;

        Temp->Next = New;

        Temp = New;
    }

    while (p != NULL)
    {

        New = (struct Node *)malloc(sizeof(struct Node));

        New->Coeff = p->Coeff;

        New->power = p->power;

        New->Next = NULL;

        Temp->Next = New;

        Temp = New;

        p = p->Next;
    }
    while (q != NULL)

    {

        New = (struct Node *)malloc(sizeof(struct Node));

        New->Coeff = q->Coeff;

        New->power = q->power;

        New->Next = NULL;

        Temp->Next = New;

        Temp = New;

        q = q->Next;
    }
    return h3;
}

void showp(struct Node *h)
{

    struct Node *p;

    if (h->Next == NULL)
    {

        printf("empty list\n\n");
    }

    else
    {

        for (p = h->Next; p != NULL; p = p->Next)
        {

            if (p->Next != NULL)

            {

                printf("%d*x^%d + ", p->Coeff, p->power);
            }

            else

            {

                printf("%d*x^%d\n\n\n", p->Coeff, p->power);
            }
        }
    }
}
