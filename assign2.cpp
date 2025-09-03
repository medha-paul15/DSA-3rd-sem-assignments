#include <iostream>
using namespace std;

void binarySearch();
void missingnumlinear();
void missingnumbinary();
void bubbleSort();
void stringprobs();
void countDistinct();

//Q5.
class Diagonal{
   int *arr,n;
   public:
   Diagonal(int size){
      n=size;
      arr=new int[n];
   }
   void set(int i,int j,int x){
      if(i==j) arr[i-1]=x;
   }
   int get(int i,int j){
      if(i==j) return arr[i-1];
      else return 0;
   }
   void display(){
      for(int i=1;i<=n;i++){
         for(int j=1;j<=n;j++){
            cout<<get(i,j)<<" ";
         }
         cout<<endl;}}};

class TriDiagonal{
   int *arr,n;
   public:
   TriDiagonal(int size){
      n=size;
      arr=new int[3*n-2];
   }
   void set(int i,int j,int x){
      if(i-j==0) arr[n-1+i-1]=x;
      else if(i-j==1) arr[i-2]=x;
      else if(i-j==-1) arr[2*n-1+i-1]=x;
   }
   int get(int i,int j){
      if(i-j==0) return arr[n-1+i-1];
      else if(i-j==1) return arr[i-2];
      else if(i-j==-1) return arr[2*n-1+i-1];
      else return 0;}};

class LowerTri{
   int *arr,n;
   public:
   LowerTri(int size){
      n=size;
      arr=new int[n*(n+1)/2];
   }
   void set(int i,int j,int x){
      if(i>=j) arr[i*(i-1)/2+j-1]=x;
   }
   int get(int i,int j){
      if(i>=j) return arr[i*(i-1)/2+j-1];
      else return 0;}};

class UpperTri{
   int *arr,n;
   public:
   UpperTri(int size){
      n=size;
      arr=new int[n*(n+1)/2];
   }
   void set(int i,int j,int x){
      if(i<=j) arr[j*(j-1)/2+i-1]=x;
   }
   int get(int i,int j){
      if(i<=j) return arr[j*(j-1)/2+i-1];
      else return 0;}};

class Symmetric{
   int *arr,n;
   public:
   Symmetric(int size){
      n=size;
      arr=new int[n*(n+1)/2];
   }
   void set(int i,int j,int x){
      if(i>=j) arr[i*(i-1)/2+j-1]=x;
      else arr[j*(j-1)/2+i-1]=x;
   }
   int get(int i,int j){
      if(i>=j) return arr[i*(i-1)/2+j-1];
      else return arr[j*(j-1)/2+i-1];}};

    struct Element {
    int r, c, val;
};

//Q6.
struct Sparse {
    int m, n, num;
    Element *ele;

    Sparse(int row, int col, int numE) {
        m = row;
        n = col;
        num = numE;
        ele = new Element[num];
    }

    ~Sparse() {
        delete[] ele; // Free allocated memory
    }

    void read() {
        for (int i = 0; i < num; i++) {
            cin >> ele[i].r >> ele[i].c >> ele[i].val;
        }
    }

    void display() {
        int k = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (k < num && ele[k].r == i && ele[k].c == j)
                    cout << ele[k++].val << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }

    Sparse transpose() {
        Sparse t(n, m, num);
        int k = 0;
        // For each column in original matrix
        for (int i = 0; i < n; i++) {
            // Check all elements
            for (int j = 0; j < num; j++) {
                if (ele[j].c == i) {
                    t.ele[k].r = ele[j].c; // column of original becomes row of transpose
                    t.ele[k].c = ele[j].r; // row of original becomes column of transpose
                    t.ele[k].val = ele[j].val;
                    k++;
                }
            }
        }
        return t;
    }
};

//Q7.
int merge(int arr[], int temp[], int l, int m, int r) {
    int i = l, j = m, k = l, inv = 0;
    while (i <= m - 1 && j <= r) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            inv += (m - i);
        }
    }
    while (i <= m - 1)
        temp[k++] = arr[i++];
    while (j <= r)
        temp[k++] = arr[j++];
    for (int p = l; p <= r; p++)
        arr[p] = temp[p];
    return inv;
}

int _mergeSort(int arr[], int temp[], int l, int r) {
    int inv = 0;
    if (l < r) {
        int m = (l + r) / 2;
        inv += _mergeSort(arr, temp, l, m);
        inv += _mergeSort(arr, temp, m + 1, r);
        inv += merge(arr, temp, l, m + 1, r);
    }
    return inv;
}

int countInv(int arr[], int n) {
    int *temp = new int[n];
    int result = _mergeSort(arr, temp, 0, n - 1);
    delete[] temp;
    return result;
}




int main(){
    //q1. binarySearch();

    //q2. bubbleSort();

    //q3(a) missingnumlinear();
    //q3(b) missingnumbinary();
    
    //q4. stringprobs();

    //q8. countDistinct();

    //q5. 
    /*Diagonal d(3);
    d.set(1,1,5);
    d.set(2,2,7);
    d.set(3,3,9);
    d.display();*/

    //q6.
    /*Sparse s(3, 3, 3);
    cout << "Enter non-zero elements (row, column, value):\n";
    s.read();

    cout << "Original matrix:\n";
    s.display();

    Sparse t = s.transpose();
    cout << "Transposed matrix:\n";
    t.display();
*/
    //q7
    /*int arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Inversions = " << countInv(arr, n) << endl;
*/




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
