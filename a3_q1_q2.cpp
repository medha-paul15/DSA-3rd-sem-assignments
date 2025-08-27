#include <iostream>
#include <string>
using namespace std;

#define maxsize 4
int stack[maxsize];
int aux[10];
int top=-1;

bool isFull(int top){
    if(top==maxsize-1){
        return true;
    }
    else{
        return false;
    }
}

bool isEmpty(int top){
    if(top==-1){
        return true;
    }
    else{
        return false;
    }
}

void push(){
    int x;
    cout<<"enter element to push: ";
    cin>>x;
    if(isFull(top)){
        cout<<"stack overflow"<<endl;
    }
    else{
        top++;
        stack[top]=x;
        if(top==0){
            aux[top]=x;
        }
        else{
            aux[top]=(aux[top-1]>x)? x:aux[top-1];
        }
    }
}

void pop(){
    if(isEmpty(top)){
        cout<<"stack underflow"<<endl;
    }
    else{
        cout<<"popped out elem: "<<stack[top]<<endl;
        top--;
    }
}

void display(){
    for(int i=top;i>=0;i--){
        cout<<stack[i]<<endl;
    }
}

void peek(){
    if(isEmpty(top)){
        cout<<"stack empty"<<endl;
    }
    else{
        cout<<"peeking at top elem: "<<stack[top]<<endl;
    }
}

void getmin(){
    cout<<"min elem: "<<aux[top]<<endl;
}

void reversestring(string s){
    char stack[50];
    int len=s.length();
    int top=-1;
    //pushing elements into stack
    for(int i=0;i<len;i++){
        top++;
        stack[top]=s[i];
    }
    //popping out elements from stack
    for (int i = 0; i < len; i++) {
        s[i] = stack[top];
        top--;
    }
    cout << "Reversed string: " << s<< endl;
}





int main(){
    
    char ans='y';
    cout<<"--- MENU---\n1.push\n2.pop\n3.display\n4.peek\n5.getmin\n";
    while(ans=='y'){
        int choice;
        cout<<"choose: ";
        cin>>choice;
        switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;  
            case 3:
                display();
                break;
            case 4:
                peek();
                break;  
            case 5:
                getmin();
                break;           
        }
        cout<<"do u wanna continue?(y/n): ";
        cin>>ans;
        
    

    reversestring("hello");

    return 0;
}