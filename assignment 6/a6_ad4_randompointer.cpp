#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *prev;
        Node(int val){
            data=val;
            next=nullptr;
            prev=nullptr;
        }
};

void display(Node*head){
    Node* temp=head;
    while(temp!=0){
        cout<<"->"<<temp->data;
        temp=temp->next; //now temp stores address of next node 
    }
    cout<<endl;
}

void revdisplay(Node*head){
    Node* temp=head;
    while(temp->next!=0){
        temp=temp->next;
    }
    while(temp!=nullptr){
        cout<<"->"<<temp->data;
        temp=temp->prev;
    }
    cout<<endl;
}

Node* correctpointer(Node *head){
    if(head==nullptr){
        return head;
    }
    Node *temp=head;
    while(temp!=nullptr){
        if(temp->next && temp->next->prev!=temp){
            temp->next->prev=temp;
        }
        temp=temp->next;
    }
    return head;
}


int main() 
{ 
  
    // Creating a DLL 
    cout<<"backward link fault: "<<endl;
    Node* ll= new Node(1);
    ll->next = new Node(2); 
    ll->next->prev = ll; 
    ll->next->next = new Node(3); 
    ll->next->next->prev =ll; 
    ll->next->next->next = new Node(4); 
    ll->next->next->next->prev = ll->next->next;
    
    display(ll);
    revdisplay(ll);
    correctpointer(ll);
    revdisplay(ll);
}

