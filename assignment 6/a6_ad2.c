#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node* prev;
    int data;
    struct node* next;
}Node;

Node* push(Node*head, int val){
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->data=val;
    newnode->prev=0;
    newnode->next=0;

    if(head==0){
        return newnode;
    }
    //finding tail i.e last node
    Node *tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next=newnode;
    newnode->prev=tail;

    return head;
}

int hasevenparity(int x){ //parity is number of 1 bits in binary repr of number 
    int par=0;
    while(x!=0){
        if(x&1){ 
            /*checks if LSB is 1 since 
            101<   1100<
            &001   &0001
            =001   =0000
            ^lsb    ^lsb
            */               
            par++;
        }
        x=x>>1; //right shift operator, eg: 1101>>1=0110 and 1010>>1=0101 (shift all bits to the right & add 0 as MSB if +ve)
    }
    if(par%2==0){
        return 1;
    }
    else
        return 0;
}

Node* deletenode(Node *head, int pos){
    Node *temp=head;
    int i=0;
    while(temp!=NULL && i<pos){
        temp=temp->next;
        i++;
    }
    //if deleting head node
    if(temp==head){
        head=temp->next;
        head->prev=NULL;
        free(temp);
        return head;
    }

    //if deleting middle node
    if(temp->next!=NULL){
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }else{
        //if deleting last node
        temp->prev->next=NULL;
    }
    free(temp);
    return head;
}

Node *delevenparity(Node*head){
    Node *temp=head;
    int pos=0;
    while(temp!=NULL){
        Node*next=temp->next; //saving the next node in case this gets deleted
        if(hasevenparity(temp->data)){
            head=deletenode(head,pos);
            //since we deleted node, dont inc pos
        }else{
            pos++;
        }
        temp=next;
    }
    return head;
}
void display(Node*head){
    Node* temp=head;
    printf("\nThe DLL: \nhead");
    while(temp!=0){
        printf(" <-> %d",temp->data);
        temp=temp->next; //now temp stores address of next node 
    }
}

int main(){
    Node *list = NULL; // Initialize head

    list = push(list, 18);
    list = push(list, 15);
    list = push(list, 8);
    list = push(list, 9);
    list = push(list, 14);
    display(list);
    list=delevenparity(list);
    display(list);
}