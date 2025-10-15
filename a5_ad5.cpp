#include <iostream>
using namespace std;


typedef struct polynode{
	float coeff;
	int expo;
	struct polynode *link;
}polynode;


polynode *createpolynomial(){
    int i=1;
    float coeff;
    int expo;

    polynode *head,*temp,*newnode;
	head=0;
	int choice=1;
	while(choice){
		newnode= (polynode*)malloc(sizeof(polynode));
		cout<<endl<<"enter coeff for term "<<i<<": ";
        cin>>newnode->coeff;
        cout<<"enter expo for term "<<i<<": ";
        cin>>newnode->expo;
        i++;

		newnode->link=0;
		if(head==0){
			head=temp=newnode;
		}
		else{
			temp->link=newnode;
			temp=newnode;
		}
		cout<<"press 0 to exit, any other to continue: ";
		cin>>choice;
	}
	return head;	

}

void displaypolynimial(polynode*head){
	polynode*temp=head;
	while(temp!=0){
		cout<<"-> ["<<temp->coeff<<","<<temp->expo<<"]";
		temp=temp->link;
	}	
    cout<<endl;
}

polynode* insert(polynode*head,int c,int e){
    polynode*newnode;
    newnode= (polynode*)malloc(sizeof(polynode));
    newnode->coeff=c;
    newnode->expo=e;
    newnode->link=0; //last node points to null

    if(head==NULL){
        head=newnode;
    }
    else{
        polynode* temp=head;
        while(temp->link!=0){
            temp=temp->link;
        }
        temp->link=newnode;
    }
    
    return head;
}

polynode* addpoly(polynode *head1,polynode *head2){
    polynode *temp1=head1;
    polynode *temp2=head2;
    polynode *head3=NULL;

    while(temp1!=NULL && temp2!=NULL){
    
        if(temp1->expo==temp2->expo){
            int newcoeff=temp1->coeff+temp2->coeff;
            int newexpo=temp1->expo;
            head3=insert(head3,newcoeff,newexpo);
            temp1=temp1->link;
            temp2=temp2->link;
        }
        else if(temp1->expo>temp2->expo){
            head3=insert(head3,temp1->coeff,temp1->expo);
            temp1=temp1->link;
        }
        else if(temp1->expo<temp2->expo){
            head3=insert(head3,temp2->coeff,temp2->expo);
            temp2=temp2->link;
        }
    }

    while(temp1!=NULL){
        head3=insert(head3,temp1->coeff,temp1->expo);
        temp1=temp1->link;
    }

    while(temp2!=NULL){
        head3=insert(head3,temp2->coeff,temp2->expo);
        temp2=temp2->link;
    }

    return head3;
}

int main(){
    polynode* p1=createpolynomial();
    displaypolynimial(p1);
    polynode* p2=createpolynomial();
    displaypolynimial(p2);

    cout<<"sum of polynomials: "<<endl;
    polynode* result= addpoly(p1,p2);
    displaypolynimial(result);
}