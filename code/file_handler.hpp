#ifndef FILE_HANDLER_HPP
#define FILE_HANDLER_HPP

#include<iostream>
#include<fstream>
#include<vector>
#include<math.h>

class file_handler {


    private:

    struct event_file_count{
        std::string file_name;
        int number_of_events;
    };

    int argc;
    char** argv;
    int total_events;

    std::ifstream csv_in;
    std::vector<event_file_count> efcv;
    int count_events();
    void set_event_counts_helper();
    bool test_for_prime( int val );


    public:

    file_handler();
    file_handler(int arg_count, char** arg_var);
    ~file_handler();

    void set_files(int arg_count, char** arg_var);
    event_file_count get_files();
    void set_event_counts();
    int get_event_counts();
    int get_individual_ec(std::string fn);
    int get_ht_size(int count);


};


#endif