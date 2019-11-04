#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
#include<algorithm>
#include<iterator>

//#include"file_handler.hpp"
//#include"hash_table.hpp"
#include"util.hpp"


int main (int argc, char** argv) {

    //Global Variables 
    int num_years = std::atoi(argv[1]);
    //int events_perfile = 0;
    //int events_total = 0;
    int ht_size = 0; //size of the hash table based on the next prime number after double the number of total events
    //int hash_function_result = 0;


    //Global Objects
    //std::vector<std::string> dates_vector; //Holds the range of years inputed via command line
    //std::ifstream csv_in;                                                //File object
    //typedef storm_event* storm_event_ptr;                       
    //storm_event *storm_events = new storm_event[1024];        //pointer to an array of storm_event
    util ut(argc, argv);
    annual_storms annual_storms_a[ut.get_total_events()];          //array of annual_storms 



    //Disable synchronization between the C and C++ standard streams daisea
	std::ios::sync_with_stdio(false);


    //Get command line args
    if (argc != 1) { 
        return -1;
    }

    //Pass inputed files to file handler
    //fh.set_files(argc, argv);

    //Get the ht size/next prime
    ht_size = fh.get_ht_size();

    //DEBUG:
    std::cout << "hash_table_size:" << ht_size << "\n";

    //Initialize the hash table
    //hash_table ht(ht_size);

    //For each file, fill the hash table 
    for (int i = 0; i <fh.get_file_count(); i++) {

        ht.insert_nodes(annual_storms_a, i, ht_size);

    }




    for (int i = 0; i < num_years; i++) {

        std::string s = fh.get_file_name(i);

        std::cout << annual_storms_a[i].year << "\n";

        for (int j = 0; j < fh.get_individual_ec(s); j++) {

            std::cout << annual_storms_a[i].events[j].event_id << ",";
            std::cout << annual_storms_a[i].events[j].state << ",";
            std::cout << annual_storms_a[i].events[j].year << ",";
            std::cout << annual_storms_a[i].events[j].month_name << ",";
            std::cout << annual_storms_a[i].events[j].event_type << ",";
            std::cout << annual_storms_a[i].events[j].cz_type << ",";
            std::cout << annual_storms_a[i].events[j].cz_name << ",";
            std::cout << annual_storms_a[i].events[j].injuries_direct << ",";
            std::cout << annual_storms_a[i].events[j].injuries_indirect << ",";
            std::cout << annual_storms_a[i].events[j].deaths_direct << ",";
            std::cout << annual_storms_a[i].events[j].deaths_indirect << ",";
            std::cout << annual_storms_a[i].events[j].damage_property << ",";
            std::cout << annual_storms_a[i].events[j].damage_crops << ",";
            std::cout << annual_storms_a[i].events[j].tor_f_scale << "\n";

        }
        


    }
    

    std::cout << "DEBUG: end Project2" << "\n";

}