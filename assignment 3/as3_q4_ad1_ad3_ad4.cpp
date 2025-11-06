#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//stack functions

#define MAX 50

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
    stack <char> st;
    while(i<n){
        if((s[i]>='A'&&s[i]<='Z') or (s[i]>='a'&&s[i]<='z') or (s[i]>='0'&&s[i]<='9')){
            ans+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop(); //pop out the '(' as well
        }
        else{ //operators
            while(!st.empty() && (priority(s[i])<=priority(st.top()))){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
   while(!st.empty()){
    ans+=st.top();
    st.pop();
   }
   return ans;
}

void nearestSmallerToleft(int A[],int n){
    stack <int> S;
    int G[n];
    for(int i=0;i<n;i++){
        while(!S.empty() && S.top()>=A[i]){
            S.pop();
        }
        if(S.empty()){
            G[i]=-1;
        }
        else{
            G[i]=S.top();
        }
        S.push(A[i]);
    }
    for(int i=0;i<n;i++){
        cout<<G[i]<<" ";
    }
}

void nextgreatestelement(int A[],int n){
    stack <int> D;
    int G[n];
    for(int i=n-1;i>=0;i--){
        while(!D.empty() && D.top()<=A[i]){
            D.pop();
        }
        if(D.empty()){
            G[i]=-1;
        }
        else{
            G[i]=D.top();
        }
        D.push(A[i]);
    }
    for(int i=0;i<n;i++){
        cout<<G[i]<<" ";
    }
    }


void dailytemps(int T[],int n){
    stack <int> D;
    vector <int> G(n,-1);
    for(int i=n-1;i>=0;i--){
        while(!D.empty() && T[D.top()]<=T[i]){
            D.pop();
        }
        if(!D.empty()){
            G[i]=D.top();
        }
        D.push(i);
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        if(G[i]==-1){ //compare to G[i], if G[i]=-1 it implies there are no more greater elems in future, thus print 0 
            cout<<"0 ";
        }
        else{
            cout<<G[i] - i<<" ";
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
int array[]={73,74,75,71,69,72,76,73};
//nearestSmallerToleft(array,10);
cout<<endl;
//nextgreatestelement(array,5);
dailytemps(array,8);



return 0;
}



