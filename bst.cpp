#include "bst.h"

/*
 * Node Class Functions
*/

BSTNode::BSTNode(int data){
    
    this->data = data;
    
    this->left = NULL;
    this->right = NULL;
    
}

BSTNode::~BSTNode(){

    delete this->left;
    delete this->right;

}

/*
 * Tree Class Functions
*/

/*
 * Private Functions
*/

BSTNode* BSTree::insert(int data, BSTNode* root){
    
    if(!root) {
        
        return new BSTNode(data);
        
    }
    
    if (data < root->data) {
        
        root->left = insert(data, root->left);
        
    } else {
        
        root->right = insert(data, root->right);
        
    }

    
    return root;
    
}

int BSTree::height(BSTNode* root){
    
    if (root == NULL) {
        
        return -1;
        
    }
    
    int lh = height(root->left);
    int rh = height(root->right);
    
    if (lh > rh) {
        
        return (lh+1);
        
    } else {
        
        return (rh+1);
        
    }

}

void BSTree::preorder(BSTNode* root, std::ostream& os){
    
    if (root = NULL) {
        
        return;
        
    }
    
    preorder(root->left, os);
    
    preorder(root->right, os);
    
    os << root->data << " ";

}

void BSTree::inorder(BSTNode* root, std::ostream& os){
    
    if (root = NULL) {
        
        return;
        
    }
    
    preorder(root->left, os);
    
    os << root->data << " ";
    
    preorder(root->right, os);

}

void BSTree::postorder(BSTNode* root, std::ostream& os){
    
    if (root = NULL) {
        
        return;
        
    }
    
    os << root->data << " ";
    
    preorder(root->left, os);
    
    preorder(root->right, os);
    
}

void BSTree::destroy(BSTNode* root){
    
    if (root->left != NULL) {
        
        destroy(root->left);
        
    }
    
    if (root->right != NULL) {
        
        destroy(root->left);
        
    }
    
    delete root;

}

bool BSTree::search(int data, BSTNode* root){
    
    if (root == NULL) {
        
        return false;
        
    }
    
    if (root->data == data) {
        
        return true;
        
    }
    
    if (data < root->data) {
        
        return search(data, root->left);
        
    } else if (data > root->data) {
        
        return search(data, root->right);
    
    }
    

}

/*
 * Public Functions
*/

BSTree::BSTree(){
    
    BSTNode* root;
    
}

BSTree::~BSTree(){
    
    delete root;

}

void BSTree::insert(int data){
    
    this->root = this->insert(data, this->root);

}

int BSTree::height(){
    
    return this->height(this->root);

}

void BSTree::preorder(std::ostream& os){
    
    preorder(this->root, os);

}

void BSTree::inorder(std::ostream& os){
    
    inorder(this->root, os);

}

void BSTree::postorder(std::ostream& os){
    
    postorder(this->root, os);

}

bool BSTree::search(int data){
    
    return search(data, this->root);

}