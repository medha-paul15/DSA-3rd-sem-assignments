#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

int c=0;
struct node* tail=0;
struct node* createdoublelist(struct node* head){

    head=0;
    struct node* newnode;
    //struct node* tail; //tail pointer is like temp ptr, points to the end
    int choice=1;
    while (choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nenter elem %d: ",c++);
        scanf("%d",&newnode->data);
        newnode->prev=0;
        newnode->next=0;
        if(head==0){
            head=tail=newnode;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail; //like swapping
            tail=newnode;
        }
        printf("do u wanna continue? (0->no): ");
        scanf("%d",&choice);
    }
    return head;
};

void display(struct node*head){
    struct node* temp=head;
    printf("\nThe DLL: \nhead");
    while(temp!=0){
        printf(" -> %d",temp->data);
        temp=temp->next; //now temp stores address of next node 
    }
    printf("\nthe number of nodes are: %d\n\n",c);
}

struct node* insert_at_beg(struct node*head){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter node data: ");
    scanf("%d",&newnode->data);
    head->prev=newnode; //previous head is now second elem
    newnode->next=head;
    newnode->prev=0;
    head=newnode;

    c++;
    return head;

}

struct node* insert_at_end(struct node*head){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter node data: ");
    scanf("%d",&newnode->data);
    tail->next=newnode;
    newnode->next=0;
    newnode->prev=tail;
    tail=newnode;
    c++;
    return head;
}

struct node* insert_at_pos(struct node*head){
    int pos;
    struct node*temp=head;
    printf("enter pos to insert at: ");
    scanf("%d",&pos);
    if(pos>c || pos<0){
        printf("invalid position.");
    }else if(pos==1){
        insert_at_beg(head);
    }else{
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter node data: ");
        scanf("%d",&newnode->data);
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        (newnode->next)->prev=newnode;
    }
    c++;
    return head;
}

void ispalindrome(struct node*head){
    struct node *temp1,*temp2;
    temp1=head; //moves toward right
    temp2=tail; //moves left
    while(temp1!=temp2 &&temp2->next!=temp1){
        if(temp1->data!=temp2->data){
            printf("not a palindrome.");
            return;
        }
        temp1=temp1->next;
        temp2=temp2->prev;
    }
    printf("the list is a palindrome.");
}



int main(){

    printf("DOUBLY LINKED LIST\n");
    struct node* head1=createdoublelist(head1);
    display(head1);
    /* 
    printf("\ninserting at beginning: ");
    head1=insert_at_beg(head1);
    display(head1);
    printf("\ninserting at the end: ");
    head1=insert_at_end(head1);
    display(head1);
    printf("\ninserting at position: ");
    head1=insert_at_pos(head1);
    display(head1);
    */
    printf("\nchecking if palindrome: ");
    ispalindrome(head1);
}