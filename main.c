#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node * next;
};
void traversal_list(struct Node *head)
{
    struct Node *ptr;
    ptr=head;
    do
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}
struct Node * delete_at_beg(struct Node *head)
{
    struct Node *ptr,*p;
    ptr=head;
    while(ptr->next!=head)
    {
        ptr=ptr->next;
    }
    ptr->next=head->next;
    free(head);
    head=ptr->next;
    return head;
}
struct Node * delete_at_end(struct Node * head)
{
    struct Node * ptr,*pre;
    ptr=head;
    while(ptr->next!=head)
    {
        pre=ptr;
        ptr=ptr->next;
    }
    pre->next=head;
    free(ptr);
    return head;
};
struct Node * delete_at_value(struct Node *head,int value)
{
    struct Node *ptr,*pre;
    ptr=head;
    pre=ptr;
    if(value==ptr->data)
    {
        head=delete_at_beg(head);
    }
    else
    {
        while(ptr->data!=value)
        {
            pre=ptr;
            ptr=ptr->next;
        }
        pre->next=ptr->next;
        free(ptr);
    }
    return head;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *thrid;
    struct Node * last;
    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    thrid=(struct Node *)malloc(sizeof(struct Node));
    last=(struct Node *)malloc(sizeof(struct Node));
    head->data=7;
    head->next=second;
    second->data=11;
    second->next=thrid;
    thrid->data=66;
    thrid->next=last;
    last->data=33;
    last->next=head;
    traversal_list(head);
    printf("\nAfter Deletion\n");
    //head=delete_at_beg(head);
    //head=delete_at_end(head);
    head=delete_at_value(head,33);
    traversal_list(head);
    return 0;
}
