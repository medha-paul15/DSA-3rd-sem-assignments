#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

int count=0;
struct node* createlinklist(){
    struct node *head=0;
    struct node *newnode;
    struct node *temp;

    int choice=1;
    while (choice){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nelem %d: ",count++);
        scanf("%d",&(newnode->data));
        newnode->next=0;//for now, next doesn't point to anything else 
        if(head==0){
            head=temp=newnode; //all 3 pointers point to same one node at the beginning
        }
        else{
            temp->next=newnode; 
            temp=newnode;
        }
        printf("do u wanna continue? (0->no): ");
        scanf("%d",&choice);
    }
    return head;
}

void traverselist(struct node*head){
    struct node* temp=head;
    //int ind=0;
    printf("The SLL: \nhead");
    while(temp!=0){
        //ind++;
        printf(" -> %d",temp->data);
        temp=temp->next; //now temp stores address of next node 
    }
    printf("\nthe number of nodes are: %d\n\n",count);
}


struct node* insert_at_beg(struct node*head){
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter elem to insert in the beginning: "); 
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
    count++;

    return head;
}

struct node* insert_at_end(struct node*head){
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter elem to insert at end: "); 
    scanf("%d",&newnode->data);
    newnode->next=0; //last node points to null

    //to link to linked list, traverse from head to last node via temp ptr
    struct node* temp=head;
    while(temp->next!=0){
        temp=temp->next;
    }
    temp->next=newnode;
    count++;

    return head;
}

struct node* insert_at_pos(struct node*head){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    int pos, i=1;
    struct node* temp=head;

    printf("enter position: ");scanf("%d",&pos);
    if(pos>count){
        printf("\nposition out of bound\n");
        return head;
    }
    else{
        while(i<pos){
            temp=temp->next; 
            i++;
        }
        printf("enter elem to insert at end: "); 
        scanf("%d",&newnode->data);
        newnode->next=temp->next;
        temp->next=newnode;
    }
    count++;
    return head;

}

struct node* del_from_beg(struct node*head){
    struct node*temp=head;
    head=head->next;
    free(temp);
    count--;
    return head;
}

struct node* del_from_end(struct node*head){
    struct node*temp=head;
    struct node* prevnode;
    while(temp->next!=0){
        prevnode=temp;
        temp=temp->next;
    }
    if(temp==head){
        head=0;
    }
    else{
        prevnode->next=0;
    }
    free(temp); 
    count--;
    return head;
}

struct node* del_at_pos(struct node* head){
    struct node* temp=head;
    struct node* prevnode;
    int pos;
    printf("enter position: "); 
    scanf("%d",&pos);
    int i=0;
    while(i<pos){
        prevnode=temp;
        temp=temp->next;
        i++;
    }
    prevnode->next=temp->next;
    free(temp);
    count--;
    return head;
}

struct node* del_by_val(struct node* head){
    struct node* temp=head;
    struct node* prevnode;
    int val;
    printf("enter node value to delete: ");
    scanf("%d",&val);
    while(temp->data!=val){
        prevnode=temp;
        temp=temp->next;
    }
    prevnode->next=temp->next;
    free(temp);
    count--;
    return head;
}

struct node* count_and_del(struct node* head){
    struct node*temp=head;
    struct node*prevnode=0;
    int key;
    printf("enter key: "); 
    scanf("%d",&key);
    int k=0; //will count number of occurences of key
    while(temp!=0){
        if(temp->data==key){
            k++;
            if (prevnode == NULL) { 
                // deleting head as head data=key
                struct node* toDelete = temp;
                head = temp->next;//head is the next value after previous head 
                temp = temp->next;
                free(toDelete);
            } else {
                struct node* toDelete = temp;
                prevnode->next = temp->next;
                temp = temp->next;
                free(toDelete); //so we can free memory space w/o hanging temp pointer
            }  
            count--;
        }
        else {
            prevnode = temp;
            temp = temp->next;
        }
    }    
    
    printf("the number of times %d appeared is: %d\n",key,k);
    return head;
};



struct node* reverselist(struct node* head){
    struct node*temp=head;
    struct node* prevnode,*currnode,*nextnode; //declare node pointers
    prevnode=0;
    currnode=nextnode=head;
    while(nextnode!=0){
        nextnode=nextnode->next; 
        currnode->next=prevnode;
        prevnode=currnode;
        currnode=nextnode;
    }
    head=prevnode;
    return head;
}

void findmiddle(struct node* head){
    struct node*temp=head;
    struct node*prev;
    
    if(count%2==0)
    {
        int pos1=count/2;
        int pos2=pos1+1;
        int a=0;
        while(a<pos1){
            prev=temp;
            temp=temp->next;
            a++;
        }
        printf("middle elements: p: %d %d",prev->data,temp->data);
    
        temp=temp->next;
    }
    else{
        int a=0;
        int pos=(count+1)/2;
        while(a<pos){
            prev=temp;
            temp=temp->next;
            a++;
        }
        printf("middle element: %d",prev->data);
        temp=temp->next;
    }


}










int main(){ 
    
    struct node* head1=createlinklist();
    traverselist(head1);
    /*
    printf("insert:\n 1.at beginning\n 2.at end\n 3.at position\n");
    printf("delete:\n 4.at beginning\n 5.at end\n 6.at position\n");
    printf(" 7.delete by val\n 8.insert by val\n 9.show position");
    int ans=1;
    while(ans==1){
        int choice;
        printf("\nenter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                head1=insert_at_beg(head1);
                traverselist(head1);
                break;
            case 2:
                head1=insert_at_end(head1);
                traverselist(head1);
                break;
            case 3:
                head1=insert_at_pos(head1);
                traverselist(head1);
                break;
            case 4:
                head1=del_from_beg(head1);
                traverselist(head1);
                break;
            case 5:
                head1=del_from_end(head1);
                traverselist(head1);
                break;
            case 6:
                head1=del_at_pos(head1);
                traverselist(head1);
                break; 
            case 7:
                head1=del_by_val(head1);
                traverselist(head1);
                break;   

        }
        printf("continue?(0->no): "); 
        scanf("%d",&ans);
    }
       

    printf("\ncount and delete func:\n");
    head1=count_and_del(head1);
    traverselist(head1);
    printf("\nprinting reversed list: ");
    head1= reverselist(head1);
    traverselist(head1);
 */
    findmiddle(head1);


    

    return 0;
}