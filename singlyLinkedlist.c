#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// create  structure 

struct Node
{
    int data;
    struct Node *next;
};


// Node Create

struct Node *head;
struct Node *createNode()
{
    struct Node *temp;
    head = (struct Node *)malloc(sizeof(struct Node));

    char ch;
    int data;
    printf("\nenter value : ");
    scanf("%d", &head->data);
    head->next = NULL;
    temp = head;

    printf("\nenter add more value y/n : ");
    ch = getche();

    while (ch == 'y')
    {
        struct Node *newNode;
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("\nenter value : ");
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        temp->next = newNode;
        temp = newNode;

        printf("\nenter add more value y/n : ");
        ch = getche();
    }
    return head;
}
// display value

void display_value(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%5d", ptr->data);
        ptr = ptr->next;
    }
}

// Insert At First

struct Node *insertAtfirst(struct Node *head)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    int data;

    printf("\nenter value you want to add : ");
    scanf("%d", &newNode->data);

    newNode->next = head;
    return newNode;
}

// Insert At middle

struct Node *insertAtmiddle(struct Node *head)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *z;
    z = head;

    int data, index, i = 0;

    printf("\n Enter index no where you want to insert data : ");
    scanf("%d", &index);

    printf("\nenter value you want to add : ");
    scanf("%d", &newNode->data);

    while (i != index - 1)
    {
        z = z->next;
    }
    newNode->next = z->next;
    z->next = newNode;

    return head;
}

// Insert At End

struct Node *insertAtend(struct Node *head)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    int data;
    struct Node *z;
    z = head;

    printf("\nenter value you want to add : ");
    scanf("%d", &newNode->data);

    while (z->next != NULL)
    {
        z = z->next;
    }
    z->next = newNode;
    newNode->next = NULL;

    return head;
}

// delete node

struct Node *deleteAtfirst(struct Node *head)
{
    struct Node *z;
    z = head;
    head = head->next;
    free(z);

    return head;
}

// delete middle node

struct Node *deleteAtmid(struct Node *head)
{
    struct Node *temp;
    struct Node *z = head;
    int index, i = 0;
    printf("\n Enter index no : ");
    scanf("%d",&index);
    while (i != index - 1)
    {
        z = z->next;
        i++;
    }
    temp = z->next;
    z->next = temp->next;
    free(temp);
    return head;
}

// Delete End Node

struct Node *deleteAtEnd(struct Node *head)
{
    struct Node *temp;
    struct Node *z = head;
    while (z->next->next != NULL)
    {
        z = z->next;
    }
    temp = z->next;
    z->next = NULL;
    free(temp);

    return head;
}

struct Node *reversNode(struct Node *head)
{
    struct Node *i;
    i = head;
    struct Node *j;
    int temp;

    for (i = head; i->next != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            temp = i->data;
            i->data = j->data;
            j->data = temp;
        }
    }
    return head;
}

struct Node *sortingNode(struct Node *head)
{
    struct Node *i;
    i = head;
    struct Node *j;
    int temp;

    for (i = head; i->next != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            // printf(" sorting in ascending order ");
            // int a;
            // if (a == 1)
            // {
                if (i->data > j->data)
                {
                    temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            //}
            // else
            // {
            //     if (i->data < j->data)
            //     {
            //         temp = i->data;
            //         i->data = j->data;
            //         j->data = temp;
            //     }
            // }
        }
    }
    return head;
}

// Concate In linked list /////
//Create Another node //

struct Node*createNode2(){
    struct Node*head;
    struct Node*temp;
    head=(struct Node*)malloc(sizeof(struct Node));
    int data;
    printf("\nenter value : ");
    scanf("%d",&head->data);
    head->next=NULL;
    temp=head;
    
    char ch;
    printf("\nyou want to add more value y/n : ");
    ch=getche();
    while (ch=='y')
    {
        struct Node*newNode;
        newNode=(struct Node*)malloc(sizeof(struct Node));

        printf("\nenter value : ");
        scanf("%d",&newNode->data);
        newNode->next=NULL;

        temp->next=newNode;
        temp=newNode;
        printf("\nyou want to add more value y/n : ");
        ch=getche();
    }
    return head;
}

// Concate Strcuture created //

struct Node*concateNode(struct Node*head,struct Node*head1){
    struct Node*temp;
    while (head->next!=NULL)
    {
        head=head->next;
    }
    head->next=head1;
    return head;
    
}

// Global variable
struct Node *z;
struct Node*z1;
int main()
{
    char ch;

    printf("\n 1. CreateNode And Traverse : ");
    printf("\n 2. Insert At First Node : ");
    printf("\n 3. Insert At Middle Node : ");
    printf("\n 4. Insert At End Node : ");
    printf("\n 5. Delete At First Node :");
    printf("\n 6. Delete At Midde Node :");
    printf("\n 7. Delete At End Node :");
    printf("\n 8. Reverse Node  :");
    printf("\n 9. Swapping Node :");
    printf("\n 10.Concate Node :");

    printf("\n 15. Exit ");

    printf("\n Enter inside  switch case y/n : ");

    ch = getche();
    while (ch == 'y')
    {
        int n;
        printf("\n If you want to perform any operation please choice No : ");
        scanf("%d", &n);
        switch (n)
        {

        case 1:
            // Node Created
            z = createNode();
            printf("\ndisplay value : ");
            display_value(z);
            break;

        case 2:
            // insertion At first perform
            z = createNode();
            printf("\ndisplay value : ");
            display_value(z);

            z = insertAtfirst(z);
            printf("\nAfter Insertion display value  : ");
            display_value(z);
            break;

        case 3:
            // insertion At Middle perform
            z = createNode();
            printf("\ndisplay value : ");
            display_value(z);

            z = insertAtmiddle(z);
            printf("\nAfter Insertion display value  : ");
            display_value(z);
            break;

        case 4:
            // insertion At End perform
            z = createNode();
            printf("\ndisplay value : ");
            display_value(z);

            z = insertAtend(z);
            printf("\nAfter Insertion display value  : ");
            display_value(z);
            break;
        case 5:
            // Delete  First Node value
            z = createNode();
            printf("\ndisplay value : ");
            display_value(z);

            z = deleteAtfirst(z);
            printf("\nAfter deleted display value  : ");
            display_value(z);

            break;
        case 6:
            // Delete  Middle Node value
            z = createNode();
            printf("\ndisplay value : ");
            display_value(z);

            z = deleteAtmid(z);
            printf("\nAfter deleted mid  display value  : ");
            display_value(z);
            break;
        case 7:
            // Delete  End Node value
            z = createNode();
            printf("\ndisplay value : ");
            display_value(z);

            z = deleteAtEnd(z);
            printf("\nAfter deleted End display value  : ");
            display_value(z);
            break;
        case 8:
            z = createNode();
            printf("\ndisplay value : ");
            display_value(z);

            z = reversNode(z);
            printf("\nAfter Reverse display value : ");
            display_value(z);
            break;
        case 9:
            z = createNode();
            printf("\ndisplay value : ");
            display_value(z);

            z = sortingNode(z);
            printf("\nAfter Sorting display value : ");
            display_value(z);
            break;
        case 10:
            z = createNode();
            printf("\ndisplay value : ");
            display_value(z);
            printf("\n");
            printf("\n First Node Created ....");
            printf("\n");

            z1= createNode2();
            printf("\ndisplay value : ");
            display_value(z1);
            printf("\n");
            printf("\n Second Node Created ....");
            printf("\n");
            concateNode(z,z1);
            printf("\nAfter Concate display value : ");
            display_value(z);

            break;
        default:
            break;
        }
        if (n == 15)
        {
            break;
        }
    }

    return 0;
}