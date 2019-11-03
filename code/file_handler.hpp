#ifndef FILE_HANDLER_HPP
#define FILE_HANDLER_HPP

#include<iostream>
#include<fstream>
#include<vector>
#include<math.h>
#include<sstream>

class file_handler {


    private:

    struct event_file_count{
        int year;
        std::string file_name;
        int number_of_events;
    };

    int argc;
    char** argv;
    int total_events;
    int file_count;

    std::vector<event_file_count> efcv;


    int count_events();
    void set_event_counts_helper();
    void set_total_ecs();
    bool test_for_prime( int val );


    public:

    std::ifstream csv_in;
    file_handler();
    file_handler(int arg_count, char** arg_var);
    ~file_handler();

    void set_files(int arg_count, char** arg_var);
    std::string get_file_name(int index);
    int get_file_year(int index);
    int get_file_count();
    int get_total_ecs();
    int get_individual_ec(std::string fn);
    int get_ht_size();


};


#endif