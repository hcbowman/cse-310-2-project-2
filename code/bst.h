#ifndef BST_H
#define BST_H

#include "defn.h"


class bst{

    private:

    bst_node* root;
    void insert_leaf_private(char* str, int key, bst_node* ptr);

    public:

    bst();
    ~bst();
    bst_node* create_leaf(char* str, int key);
    void insert_leaf(char* str, int key);
    void print_bst();



};

#endif