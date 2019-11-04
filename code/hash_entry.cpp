#include"hash_entry.hpp"


hash_entry::hash_entry() {

    ht_entry.event_id = 0;
    ht_entry.year = 0;
    ht_entry.event_index = 0;
    ht_entry.next = nullptr;

}

hash_entry::hash_entry(int event_id, int year, int event_index) {

    this->ht_entry.event_id = event_id;
    this->ht_entry.year = year;
    this->ht_entry.event_index = event_index;
    this->ht_entry.next = nullptr;

}

int hash_entry::get_key() {
    return ht_entry.event_id;
}

void hash_entry::set_key(int key) {
    ht_entry.event_id = key;
}

int hash_entry::get_year() {
    return ht_entry.year;
}

void hash_entry::set_year(int year) {
    ht_entry.year = year;
}

int hash_entry::get_event_index() {
    return ht_entry.event_index;
}

void hash_entry::set_event_index(int evnt_indx) {
    ht_entry.event_index = evnt_indx;
}

hash_entry* hash_entry::get_next() {
    return ht_entry.next;
}

void hash_entry::set_next(hash_entry *next) {
    ht_entry.next = next;
}