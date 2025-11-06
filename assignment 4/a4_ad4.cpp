#include <iostream>
#include <vector>
using namespace std;

int hungrystudents(vector<int>students,vector<int>sandwiches){
    int res=students.size();
    vector<int>count={0,0};
    for(int i:students){
        count[i]++; //count of preference of students 
    }
    for(int i=0;i<count.size();i++){
        cout<<i<<":"<<count[i]<<endl;
    }
    for(int s:sandwiches){
        if(count[s]>0){
            res--;
            count[s]--;
        }
        else{
            return res;
        }
    }
    return res;
}

int main(){
    vector <int> stu={1,1,1,1};
    vector <int> san={1,1,1,0};
    int ans=hungrystudents(stu,san);
    cout<<endl<<ans<<endl;
}