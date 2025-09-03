#include <iostream>

#define MAX 10
using namespace std;

class Queue{
        int arr[MAX];
        int st,en;
    public:
        Queue(){
            st=en=-1;
        }

        bool isEmpty(){
            return ((st==-1)||(st>en));
        }

        bool isFull(){
            return((en==MAX-1));
        }

        int size(){
            return(en-st+1);
        }

        void display(){
            if(!isEmpty()){
                cout<<"queue elements: "<<endl;
                for(int i=st;i<=en;i++){
                    cout<<arr[i]<<" ";
                }
            }
            else{
                cout<<"queue empty";
            }
        }

        int peek(){ //top elem is like start element
            if(isEmpty()){
                cout<<"queue empty"<<endl;
                return -1;
            }
            else{
                cout<<arr[st];
                return arr[st];
            }
        }

        void enqueue(int val){
            if(isFull()){
                cout<<"queue overflow"<<endl;
            }
            else{
                if((st==-1) &&(en==-1)){
                    st=0;
                    en=0;
                }
                else{
                    en++;
                }
                arr[en]=val;
            }
        }

        void dequeue(){
            if(isEmpty()){
                cout<<"underflow"<<endl;
            }
            else{
                int item=arr[st];
                st++;
            }
            
        }
        friend void interleavefunc(Queue &A);
};





int main(){

    Queue Q;
    char ans='y';
    cout<<"--- MENU---\n1.enqueue\n2.dequeue\n3.display\n4.peek\n";
    while(ans=='y'){
        int choice;
        cout<<"choose: ";
        cin>>choice;
        switch(choice){
            case 1:
                int val;
                cout<<"enter elem to push: ";cin>>val;
                Q.enqueue(val);
                break;
            case 2:
                Q.dequeue();
                break;  
            case 3:
                Q.display();
                break;
            case 4:
                Q.peek();
                break;            
        }
        cout<<"do u wanna continue?(y/n): ";
        cin>>ans;
    }

    



    return 0;
}