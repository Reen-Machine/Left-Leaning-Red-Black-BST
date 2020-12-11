//Ryan Benvenuti, Max Mueller, Peter Saakov

#include "bst.h"

/*
 * Node Class Functions
*/

BSTNode::BSTNode(std::string data){

    this->count = 1;
    this->data = data;

    this->left = NULL;
    this->right = NULL;

    this->red = true;

}

BSTNode::BSTNode(){

    this->count = 0;
    this->data = "";

    this->left = NULL;
    this->right = NULL;

    this->red = false;

}

BSTNode::~BSTNode(){

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

       root->count++; //This is where you would input code to look at when a repeated word has been entered. //I believe, that if there is a repeated word, then it would come down the tree the same way so it should reach here

    }

    if (isRed(root->right)) {

	    root = rotateLeft(root);

	}

	if (isRed(root->left) && isRed(root->left->left)) {

	    root = rotateRight(root);

	}

	if (isRed(root->right) && isRed(root->left)) {

	    root->right->red = false;
	    root->left->red = false;

	    root->red = true;

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

    os << root->data << ":" << root->red << ", ";

}

void BSTree::inorder(BSTNode* root, std::ostream& os){

    if (root = NULL) {

        return;

    }

    preorder(root->left, os);

    os << root->data << ":" << root->red << ", ";

    preorder(root->right, os);

}

void BSTree::postorder(BSTNode* root, std::ostream& os){

    if (root = NULL) {

        return;

    }

    os << root->data << ":" << root->red << ", ";

    preorder(root->left, os);

    preorder(root->right, os);

}

void BSTree::destroy(BSTNode* root){

    if(!root){
        
        return;
        
    }

    this->destroy(root->left);
    
    this->destroy(root->right);
    
    delete root->left;
    
    delete root->right;

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

int BSTree::count_helper(std::string data, BSTNode* root){          //function definition

    if (root == NULL) {

        return 0;

    }

    int x = data.compare(root->data);

    if (x == 0) {

        return root->count;

    }

    if (x < 0) {

        return count_helper(data, root->left);

    } else if (x > 0) {

        return count_helper(data, root->right);

    }

}

BSTNode* BSTree::rotateLeft(BSTNode* root){

    BSTNode* p = root->right;
    root->right = root->right->left;
    p->left = root;

    p->red = p->left->red;
    p->left->red = true;

    return p;

}

BSTNode* BSTree::rotateRight(BSTNode* root){

    BSTNode* p = root->left;
    root->left = p->right;
    p->right = root;

    p->red = p->right->red;
    p->right->red = true;

    return p;

}

bool BSTree::isRed(BSTNode* root){
    if(!root){
        return false;
    }

    return root->red;
}

void BSTree::DOT(std::ofstream& of, BSTNode* root) {

    if (root->left != NULL) {

        if(root->left->red == true) {

            of << "\t" << "\"" << root->data << "\" -> \"" << root->left->data << "\"[label=\"L\"][color=\"red\"];" << std::endl;

        } else {
            of << "\t" << "\"" << root->data << "\" -> \"" << root->left->data << "\"[label=\"L\"][color=\"black\"];" << std::endl;

        }

        DOT(of, root->left);

    }

    if (root->right != NULL) {

        if(root->right->red == true) {

            of << "\t" << "\"" << root->data << "\" -> \"" << root->right->data << "\"[label=\"R\"][color=\"red\"];" << std::endl;

        } else {

            of << "\t" << "\"" << root->data << "\" -> \"" << root->right->data << "\"[label=\"R\"][color=\"black\"];" << std::endl;

        }

        DOT(of, root->right);

    }

    return;

}


/*
 * Public Functions
*/

BSTree::BSTree(){
    
    this->root = NULL;
    
}

BSTree::~BSTree(){
    
    this->destroy(this->root);
    
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


int BSTree::count_helper(std::string data){             //function definition

    return count_helper(data, this->root);

}

void BSTree::DOT(std::string fname) {

    std::ofstream of(fname);

    of << "digraph G {\n" << std::endl;

    of << std::endl;

    DOT(of, this->root);

    of << std::endl;

    of << "\n}";
    
}