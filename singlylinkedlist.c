#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

struct node* getNode()
{
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    printf("\nNew node created.\n");
    return newNode;
}

void insertAtBeg(int data)
{
    struct node *new_node = getNode();
    new_node->data = data;
    new_node->next = start;
    start = new_node;
    printf("\nThe data %d has been inserted in the beginning of the list.\n", data);
    return;
}

void insertAtPos(int pos, int data)
{
    struct node *new_node = getNode();
    new_node->data = data;
    
    if(pos <= 0)
    {
        printf("\nThis operation can not be performed as the given position is invalid.\n");
        return;
    }
    if(start == NULL && pos == 1)
    {
        new_node->next = start;
        start = new_node;
        printf("\nThe data %d has been added to the list at position %d.\n", data, pos);
        return;
    }
    else if(start == NULL && pos != 1)
    {
        new_node->next = start;
        start = new_node;
        printf("\nThe list is empty! Therefore, the data %d has been added to the list at position 0.\n", data);
        return;
    }
    else
    {
        int count=0;
        struct node *temp = start;
        
        while(count < pos-2)
        {
            temp = temp->next;
            count++;
        }
        
        new_node->next = temp->next;
        temp->next = new_node;
        
        printf("\nThe data %d has been added to the list at position %d.\n", data, pos);
        return;
    }
}

void insertAtEnd(int data)
{
    struct node *new_node = getNode();
    new_node->data = data;
    new_node->next = NULL;
    
    if(start == NULL)
    {
        start = new_node;
        printf("\nThe data %d has been added to the end of the list.\n", data);
        return;
    }
    else
    {
        struct node *temp = start;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    
        printf("\nThe data %d has been added to the end of the list.\n", data);
        return;    
    }
}

void deleteAtBeg()
{
    if(start == NULL)
    {
        printf("\nThe list is empty!\n");
        return;
    }
    else
    {
        struct node *temp = start;
        start = temp->next;
        temp->next = NULL;
        printf("\nThe data %d has been removed from the list.\n", temp->data);
        return;
    }
}

void deleteAtPos(int pos)
{
    if(start == NULL)
    {
        printf("\nThe list is empty!\n");
        return;
    }
    else
    {
        struct node *temp1 = start;
        
        if(pos == 1)
        {
            start = temp1->next;
            printf("\nThe data %d has been deleted from the list at position %d.\n", temp1->data, pos);
            return;
        }
        else
        {
            struct node *temp2;
            int count = 0;
            
            while(count<pos-1)
            {
                temp2 = temp1;
                temp1 = temp1->next;
                count++;
            } 
            
            temp2->next = temp1->next;
            printf("\nThe data %d has been deleted from the list at position %d.\n", temp1->data, pos);
            return;
        }
    }
}

void deleteAtEnd()
{
    if(start == NULL)
    {
        printf("\nThe list is empty!\n");
        return;
    }
    else if(start->next == NULL)
    {
        printf("\nThe data %d has been removed from the end of the list.\n", start->data);
        start = NULL;
        return;
    }
    else
    {
        struct node *temp1, *temp2;
        temp1 = start;
        
        while(temp1->next != NULL)
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        
        temp2->next = NULL;
        printf("\nThe data %d has been removed from the end of the list.\n", temp1->data);
        return;
    }
}

void traversal()
{
    if(start == NULL)
    {
        printf("\nThe list is empty.\n");
        return;
    }
    else
    {
        struct node *temp = start;
        int pos = 1;
        
        while(temp != NULL)
        {
            printf("\nThe data in position %d is %d.\n", pos, temp->data);
            pos++;
            temp = temp->next;
        }
        
        printf("\nTraversal Completed.\n");
        return;
    }
}

void main()
{
    insertAtBeg(16);
    insertAtEnd(24);
    insertAtPos(2,20);
    traversal();
    deleteAtPos(2);
    deleteAtEnd();
    deleteAtEnd();
    deleteAtEnd();
}


