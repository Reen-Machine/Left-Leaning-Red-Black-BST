//use include <string> in bst.h for std::string library



BSTree::count_helper(std::string data, BSTNode* root){          //function definition

    if (root == NULL) {

        return;

    }

    if (root->data == data) {

        count += 1;                                         //if match, add to count and continue
        return count_helper(data, root->left);
        return count_helper(data, root->right);

    }

//need to search every node regardless of match to get accurate count
    else {

        return count_helper(data, root->left);
        return count_helper(data, root->right);

    }

    return count;

}



BSTree::count_helper(std::string data){             //function definition

    return count_helper(data, this->root);

}