#include<iostream>
#include <vector>
using namespace std;
vector<vector<int> > convertToTriplet(int mat[4][4], int rows, int cols);
vector<vector<int> > transposesparse(const vector<vector<int> >& sparse);
vector<vector<int>> tripletToMatrix(const vector<vector<int> >& triplet);
vector <vector<int> > additionmatrix(vector<vector<int> >& triplet1,vector<vector<int> >& triplet2);



vector<vector<int> > convertToTriplet(int mat[4][4], int rows, int cols) { //vector<vector<int>> -> 2d array
    vector<vector<int> >triplet;         
    int nonZero = 0;
    triplet.push_back({rows,cols,0}); //change value of non zero elems later
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                triplet.push_back({i, j, mat[i][j]});
               
                nonZero++;
            }
        }
    }

    triplet[0][2] = nonZero;
    return triplet;         

}

vector<vector<int>> tripletToMatrix(const vector<vector<int> >& triplet) {
    int rows = triplet[0][0];
    int cols = triplet[0][1];
    int nonZero = triplet[0][2];

    // Create rows × cols matrix initialized with 0
    vector<vector<int>> mat(rows, vector<int>(cols, 0));

    // Fill non-zero values
    for (int i = 1; i <= nonZero; i++) {
        int r = triplet[i][0];
        int c = triplet[i][1];
        int val = triplet[i][2];
        mat[r][c] = val;
    }

    return mat;
}

void printMatrix(const vector<vector <int> >& mat) {
    for (const auto& row : mat) {      // loop through rows
        for (int val : row) {          // loop through elements
            cout << val << " ";
        }
        cout << endl;
    }
}

vector<vector<int> > transposesparse(const vector<vector<int> >& triplet) {
    int rows = triplet[0][0];
    int cols = triplet[0][1];
    int nonzero=triplet[0][2];

    vector <vector<int> > transpose;
    transpose.push_back({cols,rows,nonzero});
    for(int j=0;j<cols;j++){
        for(int i=1;i<=nonzero;i++){
            if(triplet[i][1]==j){
                transpose.push_back(vector<int>({triplet[i][1], triplet[i][0], triplet[i][2]}));
            }
        }
    }
    return transpose;
}

vector <vector<int> > additionmatrix(vector<vector<int> >& triplet1,vector<vector<int> >& triplet2){
    int i=1,j=1;
    vector<vector<int> >sum;
    sum.push_back({triplet1[0][0], triplet1[0][1], 0});

    while(i<=triplet1[0][2] && j<=triplet2[0][2]){ //total elems in both
        if((triplet1[i][0]<triplet2[j][0])|| //t1.row<t2.row
        (triplet1[i][0]==triplet2[j][0] && triplet1[i][1]<triplet2[j][1])){
            sum.push_back(triplet1[i]);
            i++; //next row in triplet1
        } //comparing trip1{1,1,4} w trip2{1,2,3}->(1,1)comes first->store taht value
        else if((triplet2[j][0]<triplet1[i][0])||(triplet2[j][0]==triplet1[i][0] && triplet2[j][1]<triplet1[i][1])){
            sum.push_back(triplet2[j]);
            j++; //next row in triplet1
        }
        else{ //same row and col
            int res=triplet1[i][2]+triplet2[j][2];
            if(res!=0){
                sum.push_back({triplet1[i][0],triplet1[i][1],res});
            }
            i++;j++;
        }
    }
    while(i<=triplet1[0][2]){sum.push_back(triplet1[i++]);} //push remaining elems into triplet
    while(j<=triplet2[0][2]){sum.push_back(triplet2[j++]);}

    sum[0][0] = triplet1[0][0];  // rows same
    sum[0][1] = triplet1[0][1];  // cols same
    sum[0][2] = sum.size()-1; //update nonzero element

    return sum;
}



int main() {
    int mat1[4][4] = {
        {0, 0, 3, 0},
        {22, 0, 0, 0},
        {0, 0, 0, 7},
        {0, 5, 0, 0}
    };

    int mat2[4][4]={
        {0, 1, 3, 0},
        {12, 0, 0, 0},
        {1, 0, 5, 7},
        {0, 5, 0, 0}
    };

    int choice;
    cout<<"choose ur operation: \n1. Transpose \n2. Addition \n3. Multiplication \n4.Print triplet"<<endl;
    cout<<"choice: "; 
    cin>>choice;

    switch(choice){
        case 1:{

        
            vector<vector<int> >sparsetriplet=convertToTriplet(mat1, 4, 4);
            printMatrix(tripletToMatrix(sparsetriplet));
            vector<vector<int> >transpose=transposesparse(sparsetriplet);
            cout<<endl;
            printMatrix(tripletToMatrix(transpose));
            break;  
        }
        case 2:{
            vector<vector<int> >trip1=convertToTriplet(mat1,4,4);
            vector<vector<int> >trip2=convertToTriplet(mat2,4,4);
            vector<vector<int> > result=additionmatrix(trip1,trip2);
            printMatrix(tripletToMatrix(result));
            break;
        }
    }
   

    return 0;
}