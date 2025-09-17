#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;


//q1.two pointer technique 

int countPairs(vector<int> &arr, int k) {
    int n = arr.size();
    int cnt = 0;

    sort(arr.begin(), arr.end()); 
    int i = 0, j = 0; //i=left ptr, j=right pointer

    while(j < n) {
        if(arr[j] - arr[i] < k) //if difference less than k, then expand from right
            j++;
        else if(arr[j] - arr[i] > k) //else shrink from left
            i++;
        else {
            int ele1 = arr[i], ele2 = arr[j];
            int cnt1 = 0, cnt2 = 0;

            while(j < n && arr[j] == ele2) {
                j++;
                cnt2++;
            }
            while(i < n && arr[i] == ele1) {
                i++;
                cnt1++;
            }

            if(ele1 == ele2) 
                cnt += (cnt1 * (cnt1 - 1))/2; // nC2->combinationof two(since pair) from same grp of integer
            else 
                cnt += (cnt1 * cnt2); //when elenms are diff, total number of pairs that an be formed are c1xc2
        }
    }
    return cnt;
}

//q3. anagrams
bool areAnagrams(const string& str1, const string& str2) {
    if (str1.size() != str2.size()) {
        return false;
    }

    int count[26] = {0};  // Fixed-size array for 'a' to 'z'

    for (char ch : str1) {
        count[ch - 'a']++;
    }

    for (char ch : str2) {
        count[ch - 'a']--; //count increased at index of each alphabet in frequency array
    }

    for (int i = 0; i < 26; ++i) {
        if (count[i] != 0) {
            return false;
        }
    }

    return true;
}

//q4. dutch sort
void sort012(vector<int> &arr) {
    int n = arr.size();
    int lo = 0, mid = 0, hi = n - 1; 

    while (mid <= hi) { //while mid hasnt reached end of array 
        if (arr[mid] == 0) {
            swap(arr[lo], arr[mid]); //if elem=0, push behind
            lo++; //update both lo and mid to move forward
            mid++;
        } else if (arr[mid] == 1) {
            mid++; //elem=1, no swapping reqd. just update mid 
        } else { //if elem=2, replace w elem at end, then move end ptr backwards
            swap(arr[mid], arr[hi--]);
        }
    }
}


//q5. duplicate every 2 in array, dont change array length
void duplicateTwos(std::vector<int>& arr) {
    int n = arr.size();
    
    // Count the number of 2's
    int countTwos = 0;
    for (int num : arr) {
        if (num == 2) {
            countTwos++;
        }
    }
    
    int newLength = n + countTwos;
    int i = n - 1;        // original array pointer
    int j = newLength - 1; // pointer for new arry including duplicates
    
    // traverse from the end , duplicating 2's and shifting others
    while (i < j) {
        if (j < n) {
            arr[j] = arr[i];  // write element if normal, but shifted to right
        }
        
        if (arr[i] == 2) {//already wrote 2 in the prev step, now write again
            j--;
            if (j < n) {
                arr[j] = 2;  // duplicate the 2
            }
        }
        i--;
        j--; //shift both backwards
    }
}




int main() {
    //q1
   /* int temp[] = {1, 4, 1, 4, 5};
    vector<int> arr(temp, temp + 5);

    int k = 3;
    cout << countPairs(arr, k);

    //q3.
    string str1, str2;
    cout << "Enter two strings: ";
    cin >> str1 >> str2;

    if (areAnagrams(str1, str2)) {
        cout << "Yes, the strings are anagrams.\n";
    } else {
        cout << "No, the strings are not anagrams.\n";
    }

    //q4.
    vector<int> arr = { 0, 1, 2, 0, 1, 2 };
    int n = arr.size();
    
    sort012(arr); 

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

*/
   vector<int> arr = {1, 2, 3, 2, 4, 5};
    
    duplicateTwos(arr);
    
    for (int num : arr) {
        cout << num << " ";
    }
    // Expected output: 1 2 2 3 2 2


    return 0;
}


