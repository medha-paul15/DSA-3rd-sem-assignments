#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>&arr,int st,int mid,int en){
    int i=st,j=mid+1,invCount=0;
    vector<int> temp;
    while(i<=mid && j<=en){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
            invCount+=(mid-i+1);
        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=en){
        temp.push_back(arr[j]);
        j++;
    }

    for(int idx=0;idx<temp.size();idx++){
        arr[idx+st]=temp[idx];
    }
    return invCount;
}

int mergesort(vector<int>&arr,int st,int en){
    if(st<en){
        int mid=st+(en-st)/2;
        int leftInvCount=mergesort(arr,st,mid);
        int rightInvCount=mergesort(arr,mid+1,en);

        int invCount=merge(arr,st,mid,en);

        return leftInvCount+rightInvCount+invCount;
    }
    return 0;
}


int main(){

    vector<int> arr={6,3,5,2,7};
    int ans=mergesort(arr,0,arr.size()-1);
    cout<<"number of inversions: "<<ans<<endl;

    return 0;
}