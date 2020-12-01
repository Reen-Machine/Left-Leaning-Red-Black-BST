//Ryan Benvenuti, Max Mueller, Peter Saakov

#include "bst.h"

/*
 * Node Class Functions
*/

BSTNode::BSTNode(std::string data){
    
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

BSTNode* BSTree::insert(std::string data, BSTNode* root){
    
    if(!root) {
        
        return new BSTNode(data);
        
    }
    
    int x = data.compare(root->data); /// with compare, if data.compare(root->data) < 0 then data is < root->data, if it's > 0, then data > root->data, and if it = 0 then the two are the same
    
    if (x < 0) { 
        
        root->left = insert(data, root->left);
        
    } else if (x > 0) {
        
        root->right = insert(data, root->right);
        
    } else {
        
        //This is where you would input code to look at when a repeated word has been entered
        //I belive, that if there is a repeated word, then it would come down the tree the same way so it should reach here
        
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

bool BSTree::search(std::string data, BSTNode* root){
    
    if (root == NULL) {
        
        return false;
        
    }
    
    int x = data.compare(root->data);
    
    if (x == 0) {
        
        return true;
        
    }
    
    if (x < 0) {
        
        return search(data, root->left);
        
    } else if (x > 0) {
        
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

void BSTree::insert(std::string data){
    
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

bool BSTree::search(std::string data){
    
    return search(data, this->root);

}