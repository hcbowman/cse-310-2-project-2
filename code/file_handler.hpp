#ifndef FILE_HANDLER_HPP
#define FILE_HANDLER_HPP

#include<iostream>
#include<fstream>
#include<vector>
#include<math.h>
#include<sstream>
#include<memory>

class file_handler {


    private:

    struct event_file_count{
        int year;
        std::string file_name;
        int number_of_events;
    };

    int argc;
    char** argv;
    int total_events; //Number of events from all files
    int file_count; //The number files passed into the original program
    std::vector<event_file_count> efcv; //Vector that stores structs with year, file name and num of events in that file. (1951, details-1951.csv, 221)

    int count_events();
    void set_event_counts_helper();
    void set_total_ecs();
    bool test_for_prime( int val );

    protected:
    unsigned int ht_size; //size of the hash table based on the next prime number after double the number of total events

    public:

    //std::shared_ptr<std::vector<event_file_count>> efcv;
    // = std::make_shared<std::vector<event_file_count>>;
    // = std::make_shared<std::vector<event_file_count>>;
    std::ifstream csv_in;

    file_handler();
    file_handler(int arg_count, char** arg_var);
  
    void set_files(int arg_count, char** arg_var);
    std::string get_file_name(int index);
    int get_file_year(int index); //TODO: change this
    int get_file_count();
    int get_total_events(); //returns the total count of events from all files
    int get_individual_ec(std::string fn); //Returns the events by file name
    void set_ht_size();
    int get_ht_size();


};


#endif