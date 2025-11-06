#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

int hasevenparity(int x){ //parity is number of 1 bits in binary repr of number 
    int par=0;
    while(x!=0){
        if(x&1==1){ 
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

int count=0;
struct node* createcircularlist(){
    struct node *head=0;
    struct node *newnode;
    struct node *temp;

    int choice=1;
    while (choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nelem %d: ",++count);
        scanf("%d",&(newnode->data));
        newnode->next=0;//for now, next doesn't point to anything else 
        if(head==0){
            head=temp=newnode; //all 3 pointers point to same one node at the beginning
        }
        else{
            temp->next=newnode; 
            temp=newnode;
        }
        temp->next=head;
        printf("do u wanna continue? (0->no): ");
        scanf("%d",&choice);
    }
    return head;
}

void display(struct node* head){
    struct node* temp;
    if(head==0){
        printf("empty list");
    }
    else{
        temp=head;
        printf("head");
        while(temp->next!=head){
            printf(" -> %d",temp->data);
            temp=temp->next;
        }
        printf("-> %d",temp->data);
    }
   // temp=temp->next;
   // printf("(->%d)",temp->data); ->prints first elem again, showing that list is circular

}

void search(struct node* head){
    printf("\nSEARCH FUNCTION");
    int key,k=1;
    printf("\nenter val to search: ");
    scanf("%d", &key);
    struct node*temp=head;
    while(temp->next!=head && temp->data!=key){
        temp=temp->next;
        k++;
    }
    if(temp->data==key){
        printf("%d found at position %d",key,k);
    }
    else{
        printf("element not found");
    }
}

struct node* insertatbeg(struct node *head){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    struct node* temp;
    temp=head;
    printf("\nenter elem to insert in the beginning: "); 
    scanf("%d",&newnode->data);
    if(head==0){
        head=newnode;
    }
    else{
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
        head=newnode;
        count++;
    }
   

    return head;
}

struct node* insertatend(struct node* head){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    struct node*temp=head;

    printf("\nenter data: ");
    scanf("%d",&newnode->data);
    if(head==0){
        newnode->next=newnode; //first node points to itself
        return newnode;
    }
    while(temp->next!=head){
        temp=temp->next;
    }
    newnode->next=head;
    temp->next=newnode;

    return head;
}

struct node* deletenode(struct node *head){
    struct node*temp,*prevnode;
    temp=head;
    int val;
    printf("\nenter value to delete: ");
    scanf("%d",&val);
    if(head==0){
        printf("list is empty");
    }
    else if(head->data==val){ //if the data at head is the key
        struct node* next_to_head=temp->next;
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next=next_to_head;
        free(head);
        head=next_to_head;
    }
    else{
        while(temp->data!=val){
            prevnode=temp;
            temp=temp->next;
        }
        prevnode->next=temp->next;
        free(temp);
    }
    count--;
    return head;
}


int main(){
    struct node* circ=createcircularlist();
    display(circ);
    //search(circ);
    //circ=insertatend(circ);
    circ=deletenode(circ);
    display(circ);

}