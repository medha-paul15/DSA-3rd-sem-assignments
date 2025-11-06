#include <iostream>
#include <vector>
using namespace std;
class node{
    public:
        int data;
        node* left;
        node* right;
        node* up;
        node* down;
        node(int x): data(x),left(NULL),right(NULL),up(NULL),down(NULL){};
};

void display(node*head){
    //use rightptr and downptr to traverse the DLL of 2d matrix
    node* downptr = head;
    node* rightptr;
    while (downptr) { //traverses rows
        rightptr = downptr;
        while (rightptr) {
            cout << (rightptr->data);
            if(rightptr->right) cout<< "<->"; //traverses elems in each row until rightptr reaches NULL
            rightptr = rightptr->right;
        }
        
        cout <<endl;
        downptr = downptr->down;
    }
}

node *construct_matrixLL(const vector<vector<int>> &mat){
    int rows = mat.size(); 
    int cols=mat[0].size();

    node*head_main=NULL;
    node* prev, *upper = new node(-1);

    for(int i=0;i<rows;i++){
        node* head_row;
        node* prev=new node(-1);

        for(int j=0;j<cols;j++){
            node* temp=new node(mat[i][j]);

            //define the heads
            if(i==0 && j==0) head_main=temp; //mat[0][0]-> first elem aka head of DLL
            if(j==0) head_row=temp; //mat[i][0]-> first elem of each row i

            temp->left=prev;
            prev->right=temp;
            if(i==rows-1) temp->down=NULL; //if last row, then down ptr points to NULL

            if(!upper->right) upper->right =new node(-1); //only first row
            upper=upper->right; //shift element above temp to right, for new upper to new temp
            temp->up=upper;
            upper->down=temp;
            prev=temp;

            if (j == cols - 1) prev->right = NULL; //last column points right to NULL

        }
        upper=head_row->left; //for the next rows traversal, we want to traverse the row above it along w it. so we bring upper back to old row's head('s prev) 
    }
    return head_main;
}

int main() {
    vector<vector<int>>matrix = {
         { 1, 2, 3 },
        { 4, 69, 6 },
        { 7, 8, 9 }
    };
    node* matLL=construct_matrixLL(matrix);
    display(matLL);
    return 0;
}



