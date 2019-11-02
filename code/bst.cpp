#include<string.h>
#include"bst.h"

bst::bst() {
    root = nullptr;
}

bst::~bst() {

}

bst_node* bst::create_leaf(char* str, int key) {

    bst_node* n = new bst_node();
    n->s = str;
    n->event_id = key;
    n->left = nullptr;
    n->right = nullptr;

    return n;

}

void bst::insert_leaf(char* str, int key) {

    bst::insert_leaf_private(str, key, root);

}

void bst::insert_leaf_private(char* str, int key, bst_node* ptr) {

    if(root == nullptr)
    {
        root = create_leaf(str, key);
    }
    else if (strcmp(str, ptr->s) < 0) //New node is less; go left
    {
        //Checks if left spot is available
        if (ptr->left != nullptr) //Not empty; goes down-left 1 node
        {
            insert_leaf_private(str, key, ptr);
        } else //is empty; create new node in the left spot
        {
            ptr->left = create_leaf(str, key);
        }
    }
    else if (strcmp(str, ptr->s) > 0) //New node is greater; go right
    {
        //Checks if right spot is available
        if (ptr->right != nullptr) //Not empty; goes down-right 1 node
        {
            insert_leaf_private(str, key, ptr);
        } else //Is empty; create new node in the right spot
        {
            ptr->right = create_leaf(str, key);
        }
    }
    else //Strings are equal
    {
        //If strings are equal, compares keys
        if (key < ptr->event_id) //Go left
        {
            //Checks if left spot is open
            if (ptr->left != nullptr) //Not empty
            {
                insert_leaf_private(str, key, ptr);
            } else //Empty
            {
                ptr->left = create_leaf(str, key);
            }

        } else if (key > ptr->event_id) //Go right
        {
            //Checks if right spot is open
            if (ptr->right != nullptr) //Not empty
            {
                insert_leaf_private(str, key, ptr);
            } else //Empty
            {
                ptr->right = create_leaf(str, key);
            }
        } else //Strings AND keys are equal; go right
        {
            //Checks if right spot is open
            if (ptr->right != nullptr) //Not empty
            {
                insert_leaf_private(str, key, ptr);
            } else //Empty
            {
                ptr->right = create_leaf(str, key);
            }

        }



    }
    

}

void bst::print_bst() {

}