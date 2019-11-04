#ifndef HASH_ENTRY_HPP
#define HASH_ENTRY_HPP

#include"defn.h"


class hash_entry {
        
    private:

    hash_table_entry ht_entry;

    public:

    hash_entry();
    hash_entry(int event_id, int year, int event_index);
    
    int get_key();
    void set_key(int key);
    int get_year();
    void set_year(int year);
    int get_event_index();
    void set_event_index(int event_index);
    hash_entry *get_next();
    void set_next(hash_entry *next);

};

#endif