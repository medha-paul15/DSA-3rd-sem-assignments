#include <iostream>
using namespace std;

void binarySearch();
void missingnumlinear();
void missingnumbinary();
void bubbleSort();
void stringprobs();
void countDistinct();


int main(){
    //q1. 
    binarySearch();

    //q2. 
    bubbleSort();

    //q3(a) 
    missingnumlinear();
    //q3(b) 
    missingnumbinary();
    
    //q4. 
    stringprobs();

    //q8. 
    countDistinct();

    return 0;
}


//FUNCTIONS:

void binarySearch() {
    int arr[]={3,4,7,9,12,15,19};
    int target;
    cout<<"enter target: ";
    cin>>target;
    int l = 0;
    int n=sizeof(arr)/sizeof(arr[0]);
    int u = n - 1;
    int found=0;
    
    while ((l <= u) && found==0) {
        int mid = l + (u - l) / 2;  
        
        if (arr[mid] == target) {
            cout<<endl<<"the position is: "<<mid;
            found=1;
            break;  // Found target, return index
        }
        else if (arr[mid] < target) {
            l = mid + 1;  // Search in right half
        }
        else {
            u = mid - 1;  // Search in left half
        }
    }
    if(found==0){
        cout<<endl<<"number not found";
    }
}
void bubbleSort() {
    int arr[] = {64,34,25,12,22,11,90};
    int n = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < n - 1; i++) {
        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; j++) {
            // Compare adjacent elements
            if (arr[j] > arr[j+1]) {
                // Swap if they are in the wrong order
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void missingnumlinear(){
    int arr[] = {1, 2, 4, 5, 6};
    int n = 6;
    int total = n * (n + 1) / 2;
    int sum = 0;
    for(int i = 0; i < n - 1; i++){
        sum += arr[i];
    } 
    cout << "Missing number: " << total - sum<<endl;
}

void missingnumbinary(){
    int arr[] = {1, 2, 3, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int l = 0, r = n - 1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(arr[mid] == mid + 1) l = mid + 1;
        else r = mid - 1;
    }
    cout << "Missing number: " << l+1;
}

void stringprobs(){
    //a. concatanate strings
    char str1[100] = "Hi ";
    char str2[] = "medha";
    strcat(str1, str2);
    cout << "Concatenated string: " << str1<<endl;

    //reverse string
    int n = strlen(str1);
    for(int i = 0; i < n / 2; i++){
        char temp = str1[i];
        str1[i] = str1[n - i - 1];
        str1[n - i - 1] = temp;
    }
    cout << "Reversed string: " << str1<<endl;

    //remove vowels
    for(int i=0; i<n; i++){
		if(str1[i]=='a'||str1[i]=='e'||str1[i]=='i'||str1[i]=='o'||str1[i]=='u'
		||str1[i]=='A'||str1[i]=='E'||str1[i]=='I'||str1[i]=='O'||str1[i]=='U')
		{
			for(int j=i; j<n; j++)
			{
				str1[j]=str1[j+1];
			}
		    i--;
		    n--;
        }
    } 
    cout << "After removing Vowels: " << str1<<endl;   

    //uppercase to lower
    char ch = 'M';
    cout << "Lowercase: " << char(tolower(ch))<<endl;
}

void countDistinct() {
    int arr[]={2,2,3,3,3,4,5,6,7,8,9,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int count = 0;
    for (int i = 0; i < n; i++) {
        bool found = false;
        // Check if arr[i] appeared before
        for (int j = 0; j < i; j++) {
            if (arr[j] == arr[i]) {
                found = true;
                break;
            }
        }
        if (!found)
            count++;
    }
    cout<<"the number of distinct elements is: "<< count;
}