#include <iostream>
using namespace std;

typedef struct node{
	int data;
	struct node *next;
    node(int x) {
        data = x; //parameterised constructor defined to accept vals using 'new'
        next = nullptr;
    }	
}node;



node* createLL(){
	node *head,*temp,*newnode;
	head=0;
	int choice=1;
	while(choice){
		newnode= (node*)malloc(sizeof(node));
		cout<<"enter data: "; cin>>newnode->data;
		newnode->next=0;
		if(head==0){
			head=temp=newnode;
		}
		else{
			temp->next=newnode;
			temp=newnode;
		}
		cout<<"press 0 to exit, any other to continue: ";
		cin>>choice;
	}
	return head;	
}

void displayLL(node*head){
	node*temp=head;
	while(temp!=nullptr){
		cout<<"->"<<temp->data;
		temp=temp->next;
	}	
}

int getcount(node*head){
	int count=0;
	node*temp=head;
	while(temp!=nullptr){
		count++;
		temp=temp->next;
	}
	cout<<"\nlength of LL: "<<count;
	return count;	
}

node *getintersection(node*l1,node*l2){
	node *temp1=l1;
	node *temp2=l2;
	int c1=getcount(l1);
	int c2=getcount(l2);
	
	int diff;
	c1>c2? diff=c1-c2: diff=c2-c1;

	if(c1>c2){
		for(int i=0;i<diff;i++){
            if(temp1==0){
                return 0;
            }
		    temp1=temp1->next;
	    }
    }
	else{
		for(int i=0;i<diff;i++){
            if(temp2==0){
                return 0;
            }
            temp2=temp2->next;
	    }
    }
	while(temp1!=0 && temp2!=0){
		if(temp1==temp2){
			return temp1;
		}
		temp1=temp1->next;
		temp2=temp2->next;
	}
	return 0;
}

int detectloop(node* head){
	node* fastptr=head;
	node* slowptr=head;
	while((fastptr!=nullptr) && fastptr->next!=nullptr){
		slowptr=slowptr->next;
		fastptr=fastptr->next->next;

		if(slowptr==fastptr){ //i.e loop detected
			return 1;
		}
	}
	return 0;
}
node* detectremoveloop(node* head){
	node* fastptr=head;
	node* slowptr=head;
	bool iscycle=false;
	while((fastptr!=nullptr) && fastptr->next!=nullptr){
		slowptr=slowptr->next;
		fastptr=fastptr->next->next;

		if(slowptr==fastptr){ //i.e loop detected
			iscycle=true;
		}
		if(!iscycle){
			return nullptr;
		}
		
		node *prev;
		slowptr=head;
		while(slowptr!=fastptr){
			slowptr=slowptr->next;
			prev=fastptr;
			fastptr=fastptr->next;
		}
		prev->next=NULL;
		return slowptr;
	}
}



int main(){

/*
	//Q1. intersection of linked lists
	node *list1,*list2;
	cout<<"first LL:"<<endl;
	list1=new node(4);
    list1->next=new node(8);
    list1->next->next=new node(5);
	displayLL(list1); //list1: 4->1->(8->5

	cout<<endl<<"second LL:"<<endl;
	list2=new node(5);
    list2->next=new node(6);
    list2->next->next=new node(1);
    //intersection at 8
    list2->next->next->next=list1->next; //list2 4th elem onwards it merges w list1 3rd elem
	displayLL(list2); //list2: 5->6->1->(8->5
	
    node *interpt=getintersection(list2,list1); 
    if (interpt == 0)
        cout << "-1";
    else
        cout << "\n\nthus, intersected at: "<<interpt->data << endl;

*/

	// Q3. find loop in linked list (using slow and fast pointers)

	node* h1=new node(1);
	h1->next=new node(7);
	h1->next->next=new node(3);
	h1->next->next->next=new node(6);
	h1->next->next->next->next=h1->next;

	h1=detectremoveloop(h1);
	int res=detectloop(h1);
	if(res==1)
		cout<<"loop present"<<endl;
	else
		cout<<"loop absent"<<endl;	

	
	return 0;

}