#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void insert_begin();
void insert_pos();
void insert_end();
void delete_begin();
void delete_end();
void delete_pos();

struct node *head = NULL;
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

int main()
{
    // #ifndef ONLINE_JUDGE
    //     // for getting input from input.txt
    //     freopen("input.txt", "r", stdin);
    //     // for writing output to output.txt
    //     freopen("output.txt", "w", stdout);
    // #endif
    int choice;
    while (1)
    {
        printf("\n***************\n");
        printf("0. Create\n");
        printf("1. display\n");
        printf("2. Insert Node at beginning\n");
        printf("3. Insert Node at specific position\n");
        printf("4. Insert Node at end\n");
        printf("5. Delete Node at beginning\n");
        printf("6. Delete Node at end\n");
        printf("7. Delete Node at position\n");
        printf("8. Exit\n");

        printf("\nEnter your choise\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            create();
            break;
        case 1:
            display();
            break;
        case 2:
            insert_begin();
            break;
        case 3:
            insert_pos();
            break;
        case 4:
            insert_end();
            break;
        case 5:
            delete_begin();
            break;
        case 6:
            delete_end();
            break;
        case 7:
            delete_pos();
            break;
        case 8:
            exit(0);
        default:
            printf("\nInvalid Choice");
            break;

        }
    }
}

void create()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter data :- ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->prev = ptr;
    }
}

void display()
{
    if (head == NULL)
    {
        printf("\nList is empty");
        return;
    }
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void insert_begin()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data :- ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insert_pos()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data :- ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    else
    {
        struct node *prev_ptr;
        struct node *ptr = head;
        int posi;
        printf("Enter the position :- ");
        scanf("%d", &posi);

        for (int i = 0; i < posi - 1; i++)
        {
            prev_ptr = ptr;
            ptr = ptr->next;
        }

        prev_ptr -> next = temp;
        temp->next = ptr;
        ptr->prev = temp;
        temp->prev = prev_ptr;
    }
}

void insert_end()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data :- ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    else
    {
        struct node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->prev = ptr;
    }
}

void delete_begin()
{
    if (head == NULL)
    {
        printf("LinkedList is Empty :(");
        return;
    }
    else
    {
        struct node *ptr = head;
        head = ptr->next;
        head->prev = NULL;
        free(ptr);
        printf("Deleted\n");
    }
}


void delete_end()
{
    if (head == NULL)
    {
        printf("LinkedList is Empty :(");
        return;
    }
    else if (head->next == NULL)
    {
        struct node *ptr = head;
        head = ptr->next;
        free(ptr);
    }
    else
    {
        struct node *ptr = head;
        struct node *prev_ptr = NULL;
        while (ptr->next != NULL)
        {
            prev_ptr = ptr;
            ptr = ptr->next;
        }
        prev_ptr->next = NULL;
        free(ptr);
    }
}

void delete_pos()
{
    int posi;
    printf("Enter position :- ");
    scanf("%d", &posi);
    struct node *ptr = head;
    if (head == NULL)
    {
        printf("LinkedList is Empty :(");
        return;
    }
    else if (posi == 0)
    {
        ptr = head;
        head = ptr->next;
        head->prev = NULL;
        free(ptr);
    }
    else
    {
        struct node *prev_ptr;
        for (int i = 0; i < posi - 1; i++)
        {
            prev_ptr = ptr;
            ptr = ptr->next;
        }
        prev_ptr->next = ptr->next;
        ptr->next->prev = prev_ptr;
        free(ptr);
    }
}