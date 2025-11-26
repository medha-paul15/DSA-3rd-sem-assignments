#include <iostream>
#include <algorithm>
using namespace std;

void display(int arr[],int n);

void maxheapify(int arr[],int n, int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;

    if(left<=n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<=n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        maxheapify(arr,n,largest);
    }
}

void minheapify(int arr[],int n, int i){
    int smallest=i;
    int left=2*i;
    int right=2*i+1;

    if(left<n && arr[left]<arr[smallest]){
        smallest=left;
    }
    if(right<n && arr[right]<arr[smallest]){
        smallest=right;
    }
    if(smallest!=i){
        swap(arr[i],arr[smallest]);
        minheapify(arr,n,smallest);
    }
}


void display(int arr[],int n){
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void buildHeap(int arr[],int n){
    cout<<"Heap created: "<<endl;
    for(int i=n/2; i>0;i--){
        maxheapify(arr,n,i);
    }
    display(arr,n);
}

void insert(int arr[],int *size, int val){
    int idx=++(*size);
    arr[idx]=val;

    while(idx>1){
        int p_idx=idx/2;
        if(arr[p_idx]<arr[idx]){
            swap(arr[idx],arr[p_idx]);
            idx=p_idx;
        }
        else{
            return;
        }
    }
    cout<<endl<<"after inserting "<<val<<":"<<endl;
    display(arr,*size);
}

//HEAPSORT-> O(nlogn)
void inc_heapsort(int arr[],int n){ //sort elems of a heap into ascending order
    int size=n;
    while(size>1){
        //step1: swap first and last elem as first elem is the largest, so itll be at the end 
        swap(arr[1],arr[size]);
        size--; //as the last part is sorted 
        //step2: use heapify to take the new first elem to correct position
        maxheapify(arr,size,1); 
    }
    cout<<endl<<"sorted array using heapsort: "<<endl;
    display(arr,n);
}

void dec_heapsort(int arr[],int n){ //sort elems of a heap into ascending order
    cout<<endl<<"sorted array using heapsort: "<<endl;
    for (int i = n / 2; i >= 1; i--)
        minheapify(arr, n, i);
    for (int i = n; i >=2; i--) {
        // Move current root (min element) to end
        swap(arr[1], arr[i]);
        minheapify(arr, i, 1);
    }
    display(arr,n);
    
}


int main(){

    int arr[100] = { - 1,25,30,40,10,20,35,38}; //55 53 54 52 50 
    int n = 7;
    buildHeap(arr,n);
    //insert(arr,&n,56);
    //inc_heapsort(arr,n);
    dec_heapsort(arr,n);
    

}
