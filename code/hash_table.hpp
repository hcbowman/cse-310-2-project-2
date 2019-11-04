#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include<iostream>
#include<string>
#include"hash_entry.hpp"
#include"file_handler.hpp"

class hash_table: public file_handler {

    private:

    hash_entry** the_table; //hash table, array of pointers to struc hach_table_entry

    public:

    hash_table();
    hash_table(int arg_count, char** arg_var);
    ~hash_table();



    // int hash_func();
    void insert_nodes(annual_storms as_array[], int index);
    // int get_node();
    // void delete_node();
    // int ht_size();
    // void print_ht();




};


#endif