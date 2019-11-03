#ifndef UTIL_HPP
#define UTIL_HPP

#include"file_handler.hpp"
#include"hash_table.hpp"

class util: public file_handler, public hash_table {

    private:

    public:

    void insert_node();

};

#endif