#include<iostream>
#include <string>
using namespace std;

void diagonalmatrix(int n){
    cout<<"DIAGONAL"<<endl;
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                cout<<"enter value: ";cin>>arr[i][j];
            }
            else{
                arr[i][j]=0;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void tridiagonal(int n){
    cout<<"TRIDIAGONAL"<<endl;
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            //for |i-j|>1
            if((i-j==0) || (i-j==1) || (i-j==-1)){
                cout<<"enter value: ";cin>>arr[i][j];
            }
            else{
                arr[i][j]=0;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void lowtriangle(int n){
    int newlen=(n*(n+1))/2;
    int B[newlen];
    cout<<"LOWTRIANGLE"<<endl;
    for(int i=0;i<newlen;i++){
        cout<<"enter value: ";
        cin>>B[i];
    }
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i>=j){  
                arr[i][j]=B[i*(i+1)/2+j];
            }
            else{
                arr[i][j]=0;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}
void symmetricmatrix(int n){
    //if diagonal elements to be 0 then: 
    int newlen=((n*(n+1))/2); //(n*(n-1))/2)
    int B[newlen];

    cout<<"SYMMETRIC"<<endl;
    for(int i=0;i<newlen;i++){
        cout<<"enter value: ";
        cin>>B[i];
    }
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i>=j){  //i>j strict 
                arr[i][j]=B[i*(i+1)/2+j]; //alt lower triangle: [i*(i-1)/2+j
            }
            /*else if(i==j){
                arr[i][j]=0;
            }*/
            else{
                arr[i][j]=B[j*(j+1)/2+i]; //alt upper triangle : j*(j-1)/2+i]
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}


int main(){
    //diagonalmatrix(3);
    //tridiagonal(4);
    //lowtriangle(3);
    symmetricmatrix(4);

    
}