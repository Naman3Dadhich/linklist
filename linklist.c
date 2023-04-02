#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};

void link_list_traversal(struct node *);
struct node *add_at_end(struct node * ,int);
struct node *add_at_first(struct node *, int);
struct node *add_at_place(struct node * ,int);
struct node *del_at_first(struct node *);
struct node *del_at_end(struct node *);
struct node *del_at_place(struct node *);

struct node *add_at_place(struct node *head , int temp)
{
    int pos;
    printf("what position you wanna add(Index - 1 list) : ");
    scanf(" %d", &pos);
    pos--;

    struct node *par = head;
    struct node *ptr = head;
    while (pos > 0 && ptr != NULL)
    {
        par = ptr;
        ptr = ptr->next;
        pos--;
    }

    if (pos == 0 && ptr != NULL)
    {
        struct node *P = (struct node *)malloc(sizeof(struct node));
        P->data = temp;
        par->next = P;
        P->next = ptr;
    }
    else if (ptr == NULL)
    {
        head = add_at_end(head , temp);
        return head;
    }

    return head;
}

void link_list_traversal(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf(" %d", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node *add_at_first(struct node *head, int temp)
{
    struct node *P;

    if (head->next == NULL && head->data == INT_MAX)
    {
        head->data = temp;
        return head;
    }

    {
        P = (struct node *)malloc(sizeof(struct node));
        P->data = temp;
        P->next = head;
    }
    return P;
}

struct node *add_at_end(struct node *head , int temp)
{

    if (head->next == NULL && head->data == INT_MAX)
    {
        head->data = temp;
        return head;
    }

    struct node *P = (struct node *)malloc(sizeof(struct node));
    P->data = temp;

    struct node *ptr = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = P;
    P->next = NULL;

    return head;
}

struct node *del_at_first(struct node *head)
{
    struct node *P = head;
    head = head->next;
    free(P);
    return head;
}

struct node *del_at_end(struct node *head)
{
    struct node *ptr = head;
    struct node *par = head;
    while (ptr->next != NULL)
    {
        par = ptr;
        ptr = ptr->next;
    }

    par->next = NULL;
    free(ptr);
    return head;
}

struct node *del_at_place(struct node *head)
{
    int pos;
    printf("what position you wanna del(Index - 1 list) : ");
    scanf(" %d", &pos);
    pos--;

    struct node *par = head;
    struct node *ptr = head;
    while (pos > 0 && ptr != NULL)
    {
        par = ptr;
        ptr = ptr->next;
        pos--;
    }

    par->next = ptr->next;
    free(ptr);
    return head;
}

int main()
{
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));

    head->data = INT_MAX;
    head->next = NULL;

    int val;

    char ope[3][10] = {"insert", "delete", "display"};

    char ans[10];

    char choice = 'Y';

    while (choice == 'Y' || choice == 'y')
    {
        printf("what action you wanna perform 'insert'/'delete'/'display' : ");
        scanf(" %s", &ans);

        if (strcmp(ans, ope[0]) == 0)
        {
            printf("where would you like to add your no -at start-> 0, -at end-> 1 , -at some position-> 2 : ");
            scanf(" %d", &val);
            switch (val)
            {
            case 0:
            {
                int more;
                printf("new no : ");
                scanf(" %d", &more);
                while (more != -333)
                {
                    head = add_at_first(head, more);
                    printf("new no (else -333): ");
                    scanf(" %d", &more);
                }
                break;
            }

            case 1:
            {
                int more;
                printf("new no : ");
                scanf(" %d", &more);
                while (more != -333)
                {
                    head = add_at_end(head ,more);
                    printf("new no (else -333): ");
                    scanf(" %d", &more);
                }
                
                break;
            }

            case 2:
            {
                int more;
                printf("new no : ");
                scanf(" %d", &more);
                while (more != -333)
                {
                    head = add_at_place(head, more);
                    printf("new no else(-333) : ");
                    scanf(" %d", &more);
                }
                
                break;
            }
            }
        }

        else if (strcmp(ans, ope[1]) == 0)
        {
            printf("from where would you like to del your no -at start-> 0, -at end-> 1 , -at some position-> 2 : ");
            scanf(" %d", &val);
            switch (val)
            {
            case 0:
            {
                head = del_at_first(head);
                break;
            }

            case 1:
            {
                head = del_at_end(head);
                break;
            }

            case 2:
            {
                head = del_at_place(head);
                break;
            }
            }
        }

        else if (strcmp(ans, ope[2]) == 0)
        {
            link_list_traversal(head);
        }

        printf("whoul you like to perform any operation ('Y'/'n') : ");
        scanf(" %c", &choice);
        printf("\n");
    }

    return 0;
}
