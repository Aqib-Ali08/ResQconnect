#include<stdio.h>
#include<stdlib.h>
struct list
{
   int data;
   struct list *next;
   struct list *prev;
};
struct list *creation(struct list *head)
{
    int item;
    struct list *new,*temp;
    new=malloc(sizeof(struct list));
    printf("Enter The Data=");
    scanf("%d",&item);
    new->data=item;
    new->next=NULL;
    new->prev=NULL;
    if(head==NULL)
    {
        head=new;
    }
    else{
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new;
        new->prev=temp;
    }
    return head;

}
void printLinkedlist(struct list *head) 
{
  while (head != NULL) 
  {
    printf("%d ", head->data);
    head= head->next;
  }
}

// INSERTION OPERATION



struct list *insert_at_begining(struct list *head)
{
    struct list *temp;
    temp=malloc(sizeof(struct list));
    printf("Enter the new element=");
    scanf("%d",&temp->data);
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL)
    {
        head=temp;
        head->next=NULL;
        head->prev=NULL;

    }
    else{
        temp->next=head;
        head=temp;
    }
    return head;
}
struct list *insert_at_end(struct list *head)
{
    struct list *temp,*cur;
    temp=malloc(sizeof(struct list));
    printf("Enter the new element=");
    scanf("%d",&temp->data);
    temp->next=NULL;
    cur=head;
    if(cur==NULL)
    {
        head=temp;
    }
    else{
        while(cur->next != NULL)
        {
            cur=cur->next;
        }
        cur->next=temp;
        temp->prev=cur;
    }
    return head;
}
struct list *insert_at_any_position(struct list *head)
{
     struct list *new,*temp,*prev;
     int p;
     printf("enter the position =");
     scanf("%d",&p);
    new=malloc(sizeof(struct list));
    printf("Enter the new element=");
    scanf("%d",&new->data);
    new->next=NULL;
    new->prev=NULL;
    temp=head;
    int count=1;
    while(count<p)
    {
        prev=temp;
        temp=temp->next;
        count++;
    }    
    prev->next=new;
    new->next=temp;
    return head;
}



//DELETATION OPERATION 


struct list *delete_at_begining(struct list *head)
{
    struct list *temp;
    temp=head;
    if(head==NULL)
    {
        printf("no list are created");
    }
    head=head->next;
    head->prev=NULL;
    free(temp);
    return head;   
}
struct list *delete_at_ending(struct list *head)
{
    struct list *tail_node,*prev_tail_node;
    if(head==NULL)
    {
        printf("no list are created");
    }
    else{
        tail_node=head;
        prev_tail_node=NULL;
        while(tail_node->next!=NULL)
        {
            prev_tail_node=tail_node;
            tail_node=tail_node->next;

        }
        prev_tail_node->next=NULL;
        tail_node->next=NULL;
        free(tail_node);
        return head;
    }

}
struct list *delete_at_any_position(struct list *head)
{
    struct list *prev_node,*temp=head;
     int p;
     printf("enter the position =");
     scanf("%d",&p);
     int k=1;
     while(k<p && (temp->next!=NULL))
     {
        k++;
        prev_node=temp;
        temp=temp->next;
     }
     prev_node->next=temp->next;
     temp->next->prev=prev_node;
     free(temp);
     return head;
}
int main()
{
    struct list *head=NULL;
    int ch;
    int n=1;
    while(n)
    {
    printf("\nPress 1-Want to Create a Linked List\nPress 2-Want to Print the Linked List\nPress 3-Want to add an element at begining\nPress 4-Want to add an element at end of list\nPress 5-Want to add an element at any position\nPress E for Exit\nENTER YOUR CHOICE=");
    scanf("%d",&ch);
    switch (ch)
    
    {
        case 1:
        {
            head=creation(head);
            break;
        }
        case 2:
        {
           printLinkedlist(head); 
           break;
        }
        case 3:
        {
            head=delete_at_begining(head);
            break;
        }
        case 4:
        {
            head=delete_at_ending(head);
            break; 
        }
        case 5:
        {
            head=delete_at_any_position(head);
            break;
        }
        default:
        {
            n--;
            break;
        }
       

    }
    }
}
