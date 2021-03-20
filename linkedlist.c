#include <stdio.h>
#include <stdlib.h>

//node struct
struct Node
{
    int val;
    struct Node *next;
};

struct Node *head = NULL; //head node
struct Node *curr = NULL; //curr node

//print the entire list (value and address)
void printList()
{
    printf("\n*************Printing all nodes*************\n");
    struct Node *ptr = head;
    if(ptr ==  NULL)
        printf("Linked list is empty\n");
    else
    {
        while(ptr != NULL)
        {
            printf("%d %p", ptr->val, ptr);
            printf(" -> ");
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

struct Node* addNode(int num)
{
    //if list is empty, create first node
    if (head == NULL)
    {
        struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    
        if(NULL == ptr)
        {
            printf("\nFail to create node");
            return NULL;
        }

        ptr->val = num;
        ptr->next = NULL;

        head = curr = ptr;
        return ptr;
    }

    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));

    ptr->val = num;
    ptr->next = NULL;
    curr->next = ptr;
    curr = ptr;

    return ptr;
}

//always delete the last node
void deleteNode()
{
    struct Node *del, *prev;
    //empty list
    if(head == NULL)
    {
        printf("\nYour list is empty\n");
    }
    else
    {
        del = head;
        prev = head;

        while(del->next != NULL)
        {
            prev = del;
            del = del->next;
        }
        if(del == head)
        {
            head = NULL;
        }
        else
        {
            prev->next = NULL;
        }
        free(del);
    }
}

void menu()
{
    int choice = 0, num = 0;
    printf("\n*************Linkedlist*************\n");
    printf("Choose your action: \n");
    printf("\n1\tAdd a new node\n2\tDelete the last node\n3\tPrint current list\n");
    printf("\nInsert your choice:");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("\nInsert a value:");
            scanf("%d", &num);
            addNode(num);
            printList();
            menu();
            break;
        case 2:
            if(curr != NULL)
            {
                printf("\n*************Deleting nodes*************\n");
                printf("\nValue: %d will be deleted\n", curr->val);
                deleteNode();
                printList();
            }
            else
                printf("\nThe list is empty");
            menu();
            break;
        case 3:
            printList();
            menu();
            break;
        default:
            printf("\nPlease enter a valid choice: 1-3");
            menu();
            break;       
    }
}

int main()
{
    menu();
}