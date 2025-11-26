#include <iostream>
#include <vector>
using namespace std;

class treenode{
    public:
        int data;
        treenode *left;
        treenode *right;

        treenode(int val){
            this->data=val;
            this->left=NULL;
            this->right=NULL;
        }
};

treenode* insertIntoBST(treenode* root, int val){
    if(root==NULL){
        root=new treenode(val);
        return root;
    }
    //no condition for val=root->data which means duplicates arent allowed only
    else if(val>root->data){
        root->right=insertIntoBST(root->right,val);
    }else{
        root->left=insertIntoBST(root->left,val);
    }
    return root;
}

treenode *takeInput(){
    cout<<"enter data to create BST:"<<endl;
    int data;
    cin>>data;
    treenode *root=NULL;
    while(data!=-1){
        root=insertIntoBST(root,data);
        cin>>data;
    }
    return root;
}

int maxdepth(treenode*root){
    if(root==NULL) return 0;
    int lh=maxdepth(root->left);
    int rh=maxdepth(root->right);

    return 1+max(lh,rh);
}


int main(){
    treenode *root= takeInput(); //10 8 21 7 27 5 4 3 -1
    cout<<"the maximum depth of the BT is: "<<maxdepth(root);
}