#include <iostream>

#define MAX 50
using namespace std;

class Queue{
        //int arr[MAX];
        char arr[MAX];
        int st,en;
    public:
        Queue(){
            st=en=-1;
        }

        bool isEmpty(){
            return ((st==en)&&(en==-1));
        }

        bool isFull(){
            return(st==(en+1)%MAX);
        }

        int size(){
            if (isEmpty()) return 0;
            if (en >= st) return en - st + 1;
            else return MAX - (st - en) + 1;
            //return(en-st+1)%MAX + 1;
        }

        void display(){
            if(!isEmpty()){
                cout<<"elements in circular queue: "<<endl;
                if(en>=st){
                    for(int i=st;i<=en;i++){
                        cout<<arr[i]<<" ";
                    }
                }else{
                    for(int i=st;i<MAX;i++){
                        cout<<arr[i]<<" ";
                    }
                    for(int i=0;i<=en;i++){
                        cout<<arr[i]<<" ";
                    }
                }
                cout<<endl;
            }
            else{
                cout<<"queue empty"<<endl;
            }
        }

        int peek(){ //top elem is like start element
            if(isEmpty()){
                cout<<"queue empty"<<endl;
            }
            else{
                //cout<<"front: "<<arr[st]<<endl;
                return arr[st];
            }
        }

        void enqueue(char val){
            if(isFull()){
                cout<<"queue overflow"<<endl;
            }
            else{
                en=(en+1)%MAX;
                arr[en]=val;
                if(st==-1){
                    st=0;
                }
            }
        }

        void dequeue(){
            if(isEmpty()){
                cout<<"underflow"<<endl;
            }
            else{
                int item=arr[st];
                if(st==en){
                    st=en=-1;
                }
                else{
                    st=(st+1)%MAX;
                }
            }
            
        }
        friend Queue interleavefunc(Queue &A);
};

void firstnonrepeating(char str[])
{
    Queue q;
    int charCount[26] = { 0 };

    for (int i = 0; str[i]; i++) {
        q.enqueue(str[i]);
        charCount[str[i] - 'a']++;
        //non repeating character
        while (!q.isEmpty()) {
            if (charCount[q.peek() - 'a'] > 1)
                q.dequeue(); //if not distinct, then remove from queue
            else {
                cout << (char)q.peek() << " ";
                break;
            }
        }

        if (q.isEmpty())
            cout << -1 << " ";
    }
    cout << endl;
}


Queue interleavefunc(Queue &A){
    Queue temp1,temp2,res;
    A.display();
    cout<<endl<<"size: "<<A.size()<<endl;
    for(int i=0;i<(A.size()/2);i++){
        int val=A.peek();
        A.dequeue();
        temp1.enqueue(val);
    }
    while (!A.isEmpty()) {
        temp2.enqueue(A.peek());
        A.dequeue();
    }
    while(!temp1.isEmpty()&&!temp2.isEmpty()){
        
        res.enqueue(temp1.peek());
        temp1.dequeue();
        
        res.enqueue(temp2.peek());
        temp2.dequeue();
        
    }
    //something wrong as it only prints first 4 numbers
    cout<<endl<<"res size: "<<res.size()<<endl;
    return res;
}

class mystack{
        //two queues 
    Queue q1,q2;
    public:
        void push(int x){
            q2.enqueue(x); //first push new val in-> new val is st val(front value)
            while(!q1.isEmpty()){
                q2.enqueue(q1.peek());//push remaining elems
                q1.dequeue();
            }
            //swap names:
            Queue temp=q1;
            q1=q2;
            q2=temp;
        }

        void pop(){
            if (q1.isEmpty())
            return;
            q1.dequeue();
        }

        int top(){
            if (q1.isEmpty()){
                return -1;
            }
            return q1.peek();
        }
};

class yourstack{
    Queue qu;

    public:
        
        void push(int x){ //x=4
            qu.enqueue(x); // 1 2 3 [4]
            for(int i=0;i<qu.size()-1;i++){ 
                qu.enqueue(qu.peek()); //rotates
                qu.dequeue(); // [4] 1 2 3
            }
        }

        void pop(){
            if(!qu.isEmpty()){
                qu.dequeue();
            }
        }

        int top(){
            if (qu.isEmpty()) return -1;
            return qu.peek();
        }

        };



int main(){
/*
//Q2.
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
        cout<<endl<<"do u wanna continue?(y/n): ";
        cin>>ans;
    }

//Q3.
    Queue Q;
    for(int i=0;i<6;i++){
        int el;
        cout<<"el "<<i+1<<": "; cin>>el;
        Q.enqueue(el);

    }
    Queue ans=interleavefunc(Q);
    while (!ans.isEmpty()) {
        cout << ans.peek() << " ";
        ans.dequeue();
    }
   

//Q4.
    char str[] = "aabc";
    firstnonrepeating(str); 


//Q5. 1. class mystack implements stack using 2 queues, and class yourstack implements it using one queue

    //mystack st; -->part 1
    //yourstack st; --> part 2
    st.push(5);
    st.push(6);
    st.push(8);

    cout << st.top() << endl; //should print top of stack i.e 8
    st.pop();
    cout << st.top() << endl;//6
    st.pop();
    cout << st.top() << endl; //5
*/ 



    

   



    return 0;
}
