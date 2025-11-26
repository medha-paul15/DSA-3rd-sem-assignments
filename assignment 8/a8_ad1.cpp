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

int leftleafsum(Node* root,int &sum){
    if(!root) return 0;
    if(root->left && !root->left->left && !root->left->right){
        sum+= root->left->data;
    }
    leftleafsum(root->left,sum);
    leftleafsum(root->right,sum);

    return sum;
}



int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);

    root->left->left=new Node(4);
    root->left->left->left=new Node(11);
    root->left->right=new Node(5);
    root->right->right=new Node(7);

    root->left->right->left=new Node(6); 
    //binary tree created
            /*          1
                    2       3
                4      5        7
             11      6
            */

    int sum=0;
    cout<<"sum of left leaf nodes is : "<<leftleafsum(root,sum);


    return 0;
 }