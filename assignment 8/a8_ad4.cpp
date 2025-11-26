#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int val){
            this->data=val;
            this->left=NULL;
            this->right=NULL;
        }
};

void rsvfunc(Node*root,int level,vector<int>&res){
    if(root==nullptr) return; //recursion base condition
    //res is a stack that stores the rightmost nodes of every level 
    if(level==res.size()) res.push_back(root->data); //if level=size of stack, can add another 

    rsvfunc(root->right,level+1,res); //follows NRL (reverse preorder)
    rsvfunc(root->left,level+1,res); 
    //if right node existed, then its added to stack and level is increased. 
    //now the same level wont be traversed again, so the left node is left alone 
}
void rightsideview(Node* root){
    vector <int> st; 
    rsvfunc(root,0,st);
    for(int a:st){
        cout<<a<<" ";
    }
}


int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);

    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->right=new Node(7);

    root->left->right->left=new Node(6); 
    //binary tree created
            /*          1
                    2       3
                4      5        7
                     6
            */

    rightsideview(root);
    
}