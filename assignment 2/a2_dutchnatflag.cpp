#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countdistinct(vector<int>&arr){
    sort(arr.begin(),arr.end());
    int i=1,c=1; //start counting from second elem as first is already distinct
    while(i<arr.size()){
        if(arr[i]!=arr[i-1]){
            c++;
        }
        i++;
    }
    cout<<endl<<"number of dictinct elems is: "<<c<<endl;
}


void sortdnf(vector<int>&arr){
    int l=0;
    int m=0;
    int h=arr.size()-1;

    while(m<=h){
        if(arr[m]==0){
            swap(arr[l],arr[m]);
            l++;
            m++;
        }
        else if(arr[m]==1){
            m++;
        }
        else{
            swap(arr[h],arr[m]);
            h--;
        }
    }
}

int main(){
    vector <int> ab={2,0,2,1,1,0,1,2,0,0};
    sortdnf(ab);
    for(int i: ab){
        cout<<i<<" ";
    }
    countdistinct(ab);
    

}
