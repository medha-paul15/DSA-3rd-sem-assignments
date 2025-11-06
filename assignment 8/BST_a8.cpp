#include <iostream>
#include <climits>
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

treenode*searchinBST(treenode* root,int key);
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

void inorder(treenode *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(treenode *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(treenode *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

bool searchitemrecur(treenode*root,int key){
    if(root==NULL){
        return false;
    }
    if(root->data==key){
        return true;
    }
    if(root->data>key){
        return searchitemrecur(root->left,key);
    }else{
        return searchitemrecur(root->right,key);
    }       
}

treenode* searchinBST(treenode*root,int key){
    if(root==NULL){
        return NULL;
    }
    treenode*temp=root;
    while(temp!=NULL){
        if(temp->data==key){
            return temp;
        }
        else if(temp->data>key){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    return NULL;
}

int maxInBST(treenode*root){
    //to find right most element
    treenode*temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp->data;
}

int minInBST(treenode*root){
    //to find left most element
    treenode*temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->data;
}

treenode *inorder_successor(treenode*root, int key){
    //smallest node in right subtree 
    cout<<endl;
    treenode*p=searchinBST(root,key);
    treenode* successor=NULL;
    while(root!=NULL){
        if(p->data>=root->data){
            root=root->right;
        }else{
            successor=root;
            root=root->left;
        }
    }
    return successor;
}
treenode *inorder_predecessor(treenode*root, int key){
    //smallest node in right subtree 
    cout<<endl;
    treenode*p=searchinBST(root,key);
    treenode* predecessor=NULL;
    while(root!=NULL){
        if(p->data<=root->data){
            root=root->left;
        }else{
            predecessor=root;
            root=root->right;
        }
    }
    return predecessor;
}

treenode* deletefromBST(treenode*root,int val){
    if(root==NULL) return root;

    if(root->data==val){ //check all 3 cases
        //0 children
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;;
        }

        //1 child
        if(root->left!=NULL && root->right==NULL){ //only left child exists
            treenode *temp=root->left; //pointer pointing to left child 
            delete root;
            return temp; 
        }else if(root->left==NULL && root->right!=NULL){
            treenode *temp=root->right; //pointer pointing to left child 
            delete root;
            return temp; //replaces parent
        }

        //2 children
        if(root->left!=NULL && root->right!=NULL){
            int mini=minInBST(root->right);
            root->data=mini;
            root->right=deletefromBST(root->right,mini);
            return root;
        }
    }
    else if(root->data>val){
        root->left=deletefromBST(root->left, val);
        return root;
    }
    else{
        root->right=deletefromBST(root->right, val);
        return root;
    }
    return root;
}

int maxdepth(treenode*root){
    if(root==NULL) return 0;
    int lh=maxdepth(root->left);
    int rh=maxdepth(root->right);

    return 1+max(lh,rh);
}
int mindepth(treenode*root){
    if(root==NULL) return 0;
    int lh=mindepth(root->left);
    int rh=mindepth(root->right);
    //if one child is null, take depth of other
    if(root->left==NULL){
        return 1+rh;
    }
    if(root->right==NULL){
        return 1+lh;
    }
    //both children exist
    return 1+min(lh,rh);
}

void BSTfuncs(treenode* root){
    cout<<
    "1.insert an element"<<endl<<
    "2.delete an element"<<endl<<
    "3.find maximum depth"<<endl<<
    "4.find minimum depth"<<endl;
    int ans=1;
    while(ans){
        int choice;
        cout<<"choose: ";cin>>choice;
        switch(choice){
            case 1:
                int v;
                cout<<"enter value to insert: ";cin>>v;
                root=insertIntoBST(root,v);
                preorder(root);
                break;
            case 2:
                int a;
                cout<<"enter value to delete: ";cin>>a;   
                root=deletefromBST(root,a);
                preorder(root);
                break;
            case 3:
                cout<<"the maximum depth of the BST is: "<<maxdepth(root);
                break;
            case 4:
                cout<<"the minimum depth of the BST is: "<<mindepth(root);
                break;
        }




        cout<<endl<<"do u wanna continue? (0 to exit): ";cin>>ans;
    }

}


bool isValidBST_helper(treenode* root,long long minval,long long maxval){
    if(root==NULL) return true;
    if(root->data>=maxval || root->data<=minval) return false; 
    return isValidBST_helper(root->left,minval,root->data) && isValidBST_helper(root->right,root->data,maxval);
}
bool isValidBST(treenode* root){
    return isValidBST_helper(root,LLONG_MIN, LLONG_MAX);
}

int main(){
    treenode *root= takeInput(); //10 8 21 7 27 5 4 3 -1
   /*
   //Q1] 
    cout<<"Inorder traversal"<<endl;
    inorder(root);
    cout<<endl<<"Preorder traversal"<<endl;
    preorder(root);
    cout<<endl<<"Postorder traversal"<<endl;
    postorder(root);
    
    //Q2] (a) search item
    int key;
    cout<<"enter item to search: ";cin>>key;
    if(searchinBST(root,key)){
        cout<<"item found"<<endl;
    }else{
        cout<<"item not found"<<endl;
    }
    
   //Q2 (b) max element in BST 
   cout<<"max element in BST is: "<<maxInBST(root)<<endl;
   //Q2 (c) min element in BST
   cout<<"min element in BST is: "<<minInBST(root)<<endl;


   //Q2 (d) in order successor AND (e)inorder predecessor
   int k;
   cout<<"inorder traversal: ";
   inorder(root);
   cout<<"enter key:";cin>>k;
   treenode *suc=inorder_successor(root,k);
   cout<<"inorder successor is: "<<suc->data;
   treenode *pre=inorder_predecessor(root,k);
   cout<<"inorder predecessor is: "<<pre->data;

    //Q3] 
    BSTfuncs(root);
*/
    //Q4] validity of BST 
    (isValidBST(root))?cout<<"valid BST":cout<<"invalid BST";




}