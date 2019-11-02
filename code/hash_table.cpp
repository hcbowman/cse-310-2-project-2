#include"hash_table.hpp"


hash_table::hash_table() {

}

hash_table::hash_table(int size) {

    hash_table_s = new hash_table_entry *[size];


    //Initialize the ht with nullptrs
    for (int i = 0; i < size; i++) {

        hash_table_s[i] = nullptr;

    }

}