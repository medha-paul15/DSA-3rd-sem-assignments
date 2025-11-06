#include <iostream>
using namespace std;

//declaring global vars
int arr[50];
int len=0;


void question1();
void create();
void insert();
void display();
void del();
void linsearch();
void reverse();
void matrixmul();
void remdupl();
void transpose();
void rowcolsum();


int main(){

    //q1
    //question1();

    //q2
    //remdupl();

    //q4
    //reverse();
    //matrixmul();
    //transpose();

    //q5
    //rowcolsum();

    


    return 0;
}

//functions

void create(){
    cout<<"enter no. of elements: ";
    cin>>len;
    cout<<endl<<"enter elements: "<<endl;
    for(int i=0;i<len;i++){
        cin>>arr[i];
    }
}

void display(){
    cout<<"printing the array: "<<endl;
    for(int i=0;i<len;i++){
        cout<<" "<<arr[i];
    }
}

void insert(){
    int elem,pos;
    cout<<"enter element and position: ";
    cin>>elem>>pos;
    len++;
    for(int i=len;i>=pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos-1]=elem;
}

void del(){
    int pos;
    len--;
    cout<<"enter position of elem to delete: ";
    cin>>pos;
    for(int i=pos-1;i<len;i++){
        arr[i]=arr[i+1];
    }
}

void linsearch(){
    int elem;
    cout<<"enter elem to search for: ";
    cin>>elem;
    for(int i=0;i<len;i++){
        if(arr[i]==elem){
            cout<<endl<<"element found at position: "<<i+1;
        }
    }
}

void question1(){
    int choice;
    cout<<"——MENU——-\n1.CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT\n";

    do{
        cout<<"\nchoose an option: ";
        cin>>choice;
        switch(choice){
        case 1:
            create(); break;
        case 2:
            display();break;
        case 3:
            insert();break;
        case 4:
            del();break;
        case 5:
            linsearch(); break;
        case 6:
            cout<<"exiting."; break;    
        }
    }while(choice!=6);
}    

void reverse(){
    int arr2[]={1,2,3,4,5,98,4,56};
    int n=sizeof(arr2)/sizeof(arr2[0]);
    for(int i=0,j=n-1;i<=j;i++,j--){
        int temp=arr2[i];
        arr2[i]=arr2[j];
        arr2[j]=temp;
    }
    cout<<"printing the array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<" "<<arr2[i];
    }
}

void matrixmul(){

    int arrfin[2][2];
    int arr1[2][3]={
        {1,2,4},
        {3,4,5}
    };
    int arr2[3][2]={
        {6,7},
        {8,9},
        {1,2}
    };
        
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            arrfin[i][j]=0;
            for(int k=0;k<3;k++){
                arrfin[i][j]+=arr1[i][k]*arr2[k][j];
            }
    
        }
    }
    cout<<endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout<<arrfin[i][j]<<" ";
        }
        cout<<endl;
    } 
}

void remdupl(){
    int n;
    cout<<"enter no. of elements: ";
    cin>>n;
    int a[n];
    cout<<endl<<"enter elements: "<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i=0;i<n;i++){
        for(int j=i+1;j<n;){
            if(a[i]==a[j]){
                for(int k=j;k<n-1;k++){
                    a[k]=a[k+1];
                }
                n--;
            }
            else{
                j++;
            }
        }
    }

    cout<<"printing the array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<" "<<a[i];
    }
}

void transpose(){
    int x[3][2]={{1,2},{3,4},{5,6}};
    int y[2][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            y[j][i] = x[i][j];
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            cout<<y[i][j]<<" ";
        }
        cout<<endl;
    }
}

void rowcolsum(){
    int x[3][2]={{1,2},{3,4},{5,6}};
    for(int i=0;i<3;i++){
        int sum_row=0;
        for(int j=0;j<2;j++){
            sum_row+=x[i][j];
        }
        cout<<"sum of elems in row "<<i<<": "<<sum_row<<endl;
    }
    cout<<endl;
    for(int j=0;j<2;j++){
        int sum_col=0;
        for(int i=0;i<3;i++){
            sum_col+=x[i][j];
        }
        cout<<"sum of elems in col "<<j<<": "<<sum_col<<endl;
    }
}
