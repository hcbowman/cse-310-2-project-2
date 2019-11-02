#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include"defn.h"
#include"file_handler.hpp"

class hash_table{

    private:

    hash_table_entry** hash_table_s; //hash table, array of pointers to struc hach_table_entry

    public:

    hash_table();
    hash_table(int size);
    ~hash_table();

    //int hash_func();
    void set_ht();



};


#endif