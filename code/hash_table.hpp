#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include<iostream>
#include<string>
#include"hash_entry.hpp"

class hash_table{

    private:

    hash_entry** the_table; //hash table, array of pointers to struc hach_table_entry

    public:

    hash_table();
    hash_table(int size);
    ~hash_table();

    // int hash_func();
    // void insert_nodes(annual_storms as_array[], int index, int ht_size);
    // int get_node();
    // void delete_node();
    // int ht_size();
    // void print_ht();




};


#endif