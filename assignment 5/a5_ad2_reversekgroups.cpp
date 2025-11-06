#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node *next;
        node(int val){
            data=val;
            next=nullptr;
        }
};

void display( node* head){
    node* temp;
    if(head==0){
        cout<<"empty list";
    }
    else{
        temp=head;
        printf("head");
        while(temp->next!=NULL){
            printf(" -> %d",temp->data);
            temp=temp->next;
        }
        printf("-> %d",temp->data);
    }
    cout<<endl;
}

node *reverseKGroups(node *head, int k){

    //step1] check if K nodes exist
    node *temp=head;
    int cnt=0;

    while(cnt<k){
        if(temp==NULL){
            return head;
        }
        temp=temp->next;
        cnt++;
    }

    //recursive call for the rest of the LL
    node* newNext=reverseKGroups(temp,k);

    //reverse the current group

    temp=head;cnt=0;
    while(cnt<k){
        //4 steps
        node* next=temp->next;
        temp->next=newNext;
        newNext=temp;
        temp=next;

        cnt++;
    }
    return newNext;
}

int main(){
    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    head->next->next->next->next->next=new node(6);
    head->next->next->next->next->next->next=new node(7);
     head->next->next->next->next->next->next->next=NULL;
    head=reverseKGroups(head,4);

    display(head);
}