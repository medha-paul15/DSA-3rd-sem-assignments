#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int countpairs(vector<int>&arr,int k){
    sort(arr.begin(),arr.end());
    int l=0,r=1;
    int c=0;
    while(r<arr.size()){
        if(arr[r]-arr[l]>k){
            l++;
        }
        else if(arr[r]-arr[l]<k){
            r++;
        }
        else{
            int ele1=arr[l];
            int ele2=arr[r];
            int c1=0;
            int c2=0;

            //count duplicates of ele2 starting r 
            while(r<arr.size() && arr[r]==ele2){
                c2++;
                r++;
            }
            //count duplicates of ele1 starting i
            while(l<arr.size() && arr[l]==ele1){
                c1++;
                l++;
            }
            if(ele1==ele2){
                //all elems same, k=0->[2,2,2,2]
                c+=(c1*(c1-1))/2;
            }
            else{
                //ele1=1 and ele2=4 so different like [1,1,4,4], k=3-> (1,4),(1,4),(1,4),(1,4)
                c+=c1*c2;
            }

        }
    }
    return c;
}


int main(){
    vector <int> array={8, 16, 12, 16, 4, 0};
    int k=4;
    int ans=countpairs(array,k);
    cout<<endl<<"number of pairs w abs difference "<<k<<" is : "<<ans<<endl;
    return 0;
}