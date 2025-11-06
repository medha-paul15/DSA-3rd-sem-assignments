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
    temp=temp->next;
    printf("(->%d)",temp->data); //->prints first elem again, showing that list is circular
    cout<<endl;
}
pair<node*,node*> splitlist(node*head){
    node *slow=head; //move by 1
    node *fast=head; //move by 2
    if(head==nullptr){
        cout<<"no nodes existing"<<endl;
    }

    // For odd nodes, fast->next is head and 
    // for even nodes, fast->next->next is head
    while(fast->next!=head && fast->next->next!=head){
        fast=fast->next->next; //reaches end
        slow=slow->next;
     } //reaches middle of linked list
        //in case of even nodes to reach end 
    if(fast->next->next == head) 
        fast = fast->next; 
        
        //set new heads for both halves of CL    
    node *head1=head; //first half
    node *head2=slow->next; //second half

    fast->next=slow->next; //make second half circular
    slow->next=head1; //make first half circular
    
    return {head1,head2};
}

int main(){
    node *head = new node(1); 
    node *head1 = nullptr; 
    node *head2 = nullptr; 

    // Created linked list will be 1->2->3->4->5
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    head->next->next->next->next->next=head;
    
    pair<node*, node*> result = splitlist(head); 
    head1 = result.first;
    head2 = result.second;
    display(head1);
    display(head2);
}