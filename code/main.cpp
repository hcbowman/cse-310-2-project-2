#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include<bits/stdc++.h>
#include<algorithm>
#include<iterator>

#include"defn.h"
#include"file_handler.hpp"
#include"hash_table.hpp"


int main (int argc, char** argv) {

    //Global Variables
    int num_years = std::atoi(argv[1]);
    int events_perfile = 0;
    //int events_total = 0;
    int ht_size = 0; //size of the hash table based on the next prime number after double the number of total events
    int hash_function_result = 0;
    int event_cnt_total = 0;


    //Global Objects
    //std::vector<std::string> dates_vector; //Holds the range of years inputed via command line
    std::ifstream csv_in;                                                //File object
    //typedef storm_event* storm_event_ptr;                       
    //storm_event *storm_events = new storm_event[1024];        //pointer to an array of storm_event
    annual_storms annual_storms_array[num_years];          //array of annual_storms
    storm_event* sep;
    file_handler fh;



    //Disable synchronization between the C and C++ standard streams
	std::ios::sync_with_stdio(false);


    //Get command line args
    //TODO: change to get dates and add to struct?
    if (argc != 1) {

        fh.set_files(argc, argv);
        event_cnt_total = fh.get_event_counts();

        ht_size = fh.get_ht_size(event_cnt_total);

        std::cout << "hash_table_size:" << ht_size << "\n";

        //Initialize the hash table
        hash_table ht(ht_size);


        //Each loop opens one particular file, gets and stores it's contents
        for (int i = 2; i < argc; i++) {

            //Opens a file based on the command line
            std::string st = argv[i];
            csv_in.open("details-" + st + ".csv", std::ios::in);

            events_perfile = fh.get_individual_ec("details-" + st + ".csv");
            std::cout << events_perfile << "\n";

            storm_event* storm_event_array = new storm_event[events_perfile];     
            

            //Add the years of the storm events into the annual storms array; index suposedly contains the year
            annual_storms_array[i-2].year = std::stoi(argv[i]);

            //int storm_events_size = 50; //The number of sapces left in the array storm events, decrements evry loop
            int event_cnt = 0; //Count of the number of events in one file 
            std::string line; //stores a line of the details.csv files
            std::getline(csv_in, line); //Skips first line

            //std::cout << "before while" << "\n";
            //Gets each row of the file and puts it into a struct storm_event, where each struct is stored into an array of storm event
            while(std::getline(csv_in, line)) {

                //std::cout << "the while loop 1" << "\n";


                sep = &storm_event_array[event_cnt];

                //storm_events_size--;

                std::string line_words; //Temp string to store each word before it is pased into eah index of a vector, from "line"
                std::vector<std::string> words_vect; //Stores the line_words strings


                std::stringstream word_stream(line);

                while (getline(word_stream, line_words, ',')){
                    words_vect.push_back(line_words);
                    //std::cout << line_words << ",";
                }
                //std::cout << "\n";

                sep->event_id = std::stoi(words_vect.at(0));
                sep->state = words_vect.at(1);
                sep->year = std::stoi(words_vect.at(2));
                sep->month_name = words_vect.at(3);
                sep->event_type = words_vect.at(4);
                sep->cz_type = words_vect.at(5);
                sep->cz_name = words_vect.at(6);
                sep->injuries_direct = std::stoi(words_vect.at(7));
                sep->injuries_indirect = std::stoi(words_vect.at(8));
                sep->deaths_direct = std::stoi(words_vect.at(9));
                sep->deaths_indirect = std::stoi(words_vect.at(10));
                sep->damage_property = std::stoi(words_vect.at(11));
                sep->damage_crops = std::stoi(words_vect.at(12));
                sep->tor_f_scale = words_vect.at(13);

                //storm_events[event_cnt] = storm_event_array;

                //Hash Entries
                hash_function_result = ht_size % std::stoi(words_vect.at(0));

                if (hash_table_s[hash_function_result] == nullptr) {

                    hash_table_s[hash_function_result] = new hash_table_entry();
                    hash_table_s[hash_function_result]->event_id = std::stoi(words_vect.at(0));
                    hash_table_s[hash_function_result]->year = std::stoi(words_vect.at(2));
                    hash_table_s[hash_function_result]->event_index = event_cnt;
                    hash_table_s[hash_function_result]->next = nullptr;



                }
                else {

                    hash_table_entry *entry = hash_table_s[hash_function_result];
                    while (entry->next != nullptr && entry->event_id != std::stoi(words_vect.at(0)))
                    {
                        entry = entry->next;
                    }
                    if (entry->event_id == std::stoi(words_vect.at(0))) {

                        hash_table_s[hash_function_result]->year = std::stoi(words_vect.at(2));
                        hash_table_s[hash_function_result]->event_index = event_cnt;
                        
                    }
                    else {

                        hash_table_s[hash_function_result] = new hash_table_entry();
                        hash_table_s[hash_function_result]->event_id = std::stoi(words_vect.at(0));
                        hash_table_s[hash_function_result]->year = std::stoi(words_vect.at(2));
                        hash_table_s[hash_function_result]->event_index = event_cnt;
                        hash_table_s[hash_function_result]->next = nullptr; 

                    }

                }
                
                //hash_entry->event_id = std::stoi(words_vect.at(0)); //Event id -- key used to hash on
                //hash_entry->year = std::stoi(words_vect.at(2)); //Year of storm event

                //hash_entry->event_index = (*storm_events)->year;

                event_cnt++;
                event_cnt_total++;
            }

            annual_storms_array[i-2].events = storm_event_array;

            

        }

    }
    else {
        return -1;
    }


    for (int i = 0; i < num_years; i++) {

        std::cout << annual_storms_array[i].year << "\n";

        for (int j = 0; j < events_perfile; j++) {

            std::cout << annual_storms_array[i].events[j].event_id << ",";
            std::cout << annual_storms_array[i].events[j].state << ",";
            std::cout << annual_storms_array[i].events[j].year << ",";
            std::cout << annual_storms_array[i].events[j].month_name << ",";
            std::cout << annual_storms_array[i].events[j].event_type << ",";
            std::cout << annual_storms_array[i].events[j].cz_type << ",";
            std::cout << annual_storms_array[i].events[j].cz_name << ",";
            std::cout << annual_storms_array[i].events[j].injuries_direct << ",";
            std::cout << annual_storms_array[i].events[j].injuries_indirect << ",";
            std::cout << annual_storms_array[i].events[j].deaths_direct << ",";
            std::cout << annual_storms_array[i].events[j].deaths_indirect << ",";
            std::cout << annual_storms_array[i].events[j].damage_property << ",";
            std::cout << annual_storms_array[i].events[j].damage_crops << ",";
            std::cout << annual_storms_array[i].events[j].tor_f_scale << "\n";

        }
        


    }
    




    std::cout << "DEBUG: end Project2" << "\n";

}