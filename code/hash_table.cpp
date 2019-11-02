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

int hash_table::hash_func() {

}


void hash_table::insert_nodes(annual_storms as_array, int index) {


    std::string file_name = file_handler::get_file_name(index);
    int events = file_handler::get_individual_ec(file_name);


    //Each loop opens one particular file, gets and stores it's contents
    //for (int i = 0; i < file_cnt; i++) {

        //Opens a file based on the command line
        //std::string st = argv[i];

        //std::string csv_file_name = fh.get_file_name(i);

        file_handler::csv_in.open(file_name, std::ios::in);

        //events_perfile = fh.get_individual_ec("details-" + st + ".csv");
        //std::cout << evnts << "\n";

        storm_event* storm_event_array = new storm_event[events];     

        
            

        //Add the years of the storm events into the annual storms array; index suposedly contains the year
        annual_storms_array[index].year = file_handler::get_file_year(index);

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
            //event_cnt_total++;
        //}

        annual_storms_array[i-2].events = storm_event_array;

            

    }

}
int hash_table::get_node() {

}
void hash_table::delete_node() {

}
int hash_table::ht_size() {

}
void hash_table::print_ht() {

}