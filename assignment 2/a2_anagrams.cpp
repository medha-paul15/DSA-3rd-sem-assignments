#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool areAnagrams(string &s1,string &s2){
    if(s1.length()!=s2.length()) return false;

    vector <int> freq(26,0);

    for(char c1:s1){
        freq[c1-'a']++;
    }
    for(char c2:s2){
        freq[c2-'a']--;
    }

    for(int i:freq){
        if(i!=0) return false;
    }
    return true;
}

int main() {
    
    string s1 = "hot";
    string s2 = "otp";
    
    if (areAnagrams(s1, s2))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}