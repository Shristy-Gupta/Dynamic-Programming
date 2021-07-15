#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    int liss;
    node *left, *right;
};

int LISS(node *root)
{
     if(root==NULL){
         return 0;
     }
     if(root->liss!=0){return root->liss;}
     if(root->left==NULL && root->right==NULL){
         //leaf
         root->liss=1;
         return root->liss;
     }
     int liss_child=LISS(root->left)+LISS(root->right);
     int liss_grand_child=1;
     if(root->left!=NULL){
         liss_grand_child+=LISS(root->left->left)+LISS(root->left->right);
     }
     if(root->right!=NULL){
         liss_grand_child+=LISS(root->right->left)+LISS(root->right->right);
     }
     root->liss=max(liss_child,liss_grand_child);
     return root->liss;
    
}
node* newNode( int data )
{
    node* temp = new node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
int main() {
// Let us construct the tree
    // given in the above diagram
    node *root	 = newNode(20);
	root->left		 = newNode(8);
	root->left->left	 = newNode(4);
	root->left->right	 = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);
	root->right		 = newNode(22);
	root->right->right	 = newNode(25);
 
    cout << "Size of the Largest Independent Set is " << LISS(root);
 
    return 0;
}
