#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void duplzeros(vector<int>&arr){
    int i=0;
    queue<int> q;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0){
            q.push(0);
            q.push(0);
        }
        else{
            q.push(arr[i]);
        }
        int temp=q.front();
        q.pop();
        arr[i]=temp;
    }
}

int main(){
    vector <int> ab={3,0,4,5,0};
    duplzeros(ab);
    for(int i: ab){ 
        cout<<i<<" ";
    }
}