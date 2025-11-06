#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int canSplit(string &s){ 
    vector <int> freq(26,0);
    for(char ch:s){
        freq[ch-'a']++;
    }
    for(int a:freq){ //if any character in string appears at least thrice, then it can be split like that
        if(a>=3) return 1;
    }
    return 0;
}

int main(){
    string str="aabaab";
    int ans=canSplit(str);
    ans? cout<<"YES": cout<<"NO";
}