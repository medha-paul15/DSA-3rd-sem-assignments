#include <iostream>
using namespace std;

//stack functions

#define MAX 50

class Stack{
        int arr[MAX];
        //char arr[MAX];
        int top;
    public:

        Stack(){
            top=-1; //using constructor to give val to top
        };

        bool isFull(){
            return top>=MAX-1; //returns True if statement true, else False
        }

        bool isEmpty() {
            return top == -1;
        }
        void push(/*char*/  int value) {
            if (isFull()) {
                cout << "Stack Overflow\n";
                return;
            }

            arr[++top] = value;
            //cout << value << " pushed into stack\n";
        }

        void pop() {
            if (isEmpty()) {
                cout << "Stack Underflow\n";
                return;
            }
            //cout << arr[top--] << " popped from stack\n";
            top--;

        }

        void peek() {
            if (isEmpty()) {
                cout << "Stack is Empty\n";
            }
            cout<< arr[top]<<endl;
        }

        void display() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        }
        
        int topval(){
            if(isEmpty()){
                return '\0';
            }
            else{
                return arr[top];
            }
        }

    friend int priority(char op);
    friend string infixtopostfix(string expr);
    friend void nearestSmallerToLeft(int A[]);
    friend void nextgreatestelement(int A[],int n);
    friend void dailytemps(int T[],int n);
};

int priority(char op){
    if(op=='^'){
        return 3;
    }
    else if(op=='*' or op=='/'){
        return 2;
    }
    else if(op=='+' or op=='-'){
        return 1;
    }
    else{
        return -1;
    }

}
string infixtopostfix(string s){
    int n=s.length();
    int i=0;
    string ans="";
    Stack st;
    while(i<n){
        if((s[i]>='A'&&s[i]<='Z') or (s[i]>='a'&&s[i]<='z') or (s[i]>='0'&&s[i]<='9')){
            ans+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.isEmpty() && st.topval()!='('){
                ans+=st.topval();
                st.pop();
            }
            st.pop(); //pop out the '(' as well
        }
        else{ //operators
            while(!st.isEmpty() && (priority(s[i])<=priority(st.topval()))){
                ans+=st.topval();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
   while(!st.isEmpty()){
    ans+=st.topval();
    st.pop();
   }
   return ans;
}

void nearestSmallerToleft(int A[],int n){
    Stack S;
    int G[n];
    for(int i=0;i<n;i++){
        while(!S.isEmpty() && S.topval()>=A[i]){
            S.pop();
        }
        if(S.isEmpty()){
            G[i]=-1;
        }
        else{
            G[i]=S.topval();
        }
        S.push(A[i]);
    }
    for(int i=0;i<n;i++){
        cout<<G[i]<<" ";
    }
}

void nextgreatestelement(int A[],int n){
    Stack D;
    int G[n];
    for(int i=n-1;i>=0;i--){
        while(!D.isEmpty() && D.topval()<=A[i]){
            D.pop();
        }
        if(D.isEmpty()){
            G[i]=-1;
        }
        else{
            G[i]=D.topval();
        }
        D.push(A[i]);
    }
    for(int i=0;i<n;i++){
        cout<<G[i]<<" ";
    }
    }


void dailytemps(int T[],int n){
    Stack D;
    int G[n];
    for(int i=n;i>=0;i--){
        while(!D.isEmpty() && D.topval()<=T[i]){
            D.pop();
        }
        if(D.isEmpty()){
            G[i]=-1;
        }
        else{
            G[i]=D.topval();
        }
        D.push(T[i]);
    }
    for(int i=0;i<n;i++){
        cout<<G[i]<<" "; //prints next greatest temperature 
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        if(G[i]==-1){ //compare to G[i], if G[i]=-1 it implies there are no more greater elems in future, thus print 0 
            cout<<"0 ";
        }
        else{
            for(int j=0;j<n;j++){ //otherwise, search for index of next greatest elem in original array. print the difference in index i.e diff in days
                if(T[j]==G[i]){
                    cout<<(j-i)<<" ";
                }
            }
        }
    }
            
    } 
  





int main(){
/*
    Stack array;
    char ans='y';
    cout<<"--- MENU---\n1.push\n2.pop\n3.display\n4.peek\n";
    while(ans=='y'){
        int choice;
        cout<<"choose: ";
        cin>>choice;
        switch(choice){
            case 1:
                int val;
                cout<<"enter elem to push: ";cin>>val;
                array.push(val);
                break;
            case 2:
                array.pop();
                break;  
            case 3:
                array.display();
                break;
            case 4:
                array.peek();
                break;            
        }
        cout<<"do u wanna continue?(y/n): ";
        cin>>ans;
    }
*/
  /* Q4. INFIX TO POSTFIX
   string expr;
   cout<<"enter expression: ";cin>>expr;

   //infix to postfix
   string postfix=infixtopostfix(expr); 
   cout<<postfix<<endl;
*/

//int array[]={1, 4, 1, 4, 5};
int array[]={30,40,50,60};
//nearestSmallerToleft(array,5);
cout<<endl;
//nextgreatestelement(array,8);
//dailytemps(array,4);



return 0;
}



