#include"hash_table.hpp"


hash_table::hash_table() {
    the_table = nullptr;
}

hash_table::hash_table(int arg_count, char** arg_var): file_handler(arg_count, arg_var) {

    the_table = new hash_entry*[ht_size];


    //Initialize the ht with nullptrs
    for (unsigned int i = 0; i < ht_size; i++) {

        the_table[i] = nullptr;

    }

}

hash_table::~hash_table() {

    for (unsigned int i = 0; i < ht_size; i++) {

        if (the_table[i] != nullptr) {

            hash_entry *prevEntry = nullptr;

            hash_entry *entry = the_table[i];

            while (entry != nullptr) {

                    prevEntry = entry;

                    entry = entry->get_next();

                    delete prevEntry;

            }

        }
    }
    delete[] the_table;

}

/* hash_table::hash_table(int size) {

    the_table = new hash_entry*[size];


    //Initialize the ht with nullptrs
    for (int i = 0; i < size; i++) {

        the_table[i] = nullptr;

    }

} */

/* int hash_table::hash_func() {

    return 0;
}


void hash_table::insert_nodes(annual_storms annual_storms_a[], int index, int ht_size) {

    int hash_key;

    std::string file_name = file_handler::get_file_name(index);
    int events = file_handler::get_individual_ec(file_name);
    storm_event* sep; //Storm event pointer


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
    annual_storms_a[index].year = file_handler::get_file_year(index);

    //int storm_events_size = 50; //The number of sapces left in the array storm events, decrements evry loop
    int event_cnt = 0; //Count of the number of events in one file 
    std::string line; //stores a line of the details.csv files
    std::getline(file_handler::csv_in, line); //Skips first line

    //std::cout << "before while" << "\n";
    //Gets each row of the file and puts it into a struct storm_event, where each struct is stored into an array of storm event
    while(std::getline(file_handler::csv_in, line)) {

        //std::cout << "the while loop 1" << "\n";


        sep = &storm_event_array[event_cnt];

        //storm_events_size--;

        std::string line_words; //Temp string to store each word before it is pased into eah index of a vector, from "line"
        std::vector<std::string> words_vect; //Stores the line_words strings


        std::stringstream word_stream(line);

        while (std::getline(word_stream, line_words, ',')){
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
        hash_key = ht_size % std::stoi(words_vect.at(0));

        if (the_table[hash_key] == nullptr) {

            the_table[hash_key] = new hash_table_entry();
            the_table[hash_key]->event_id = std::stoi(words_vect.at(0));
            the_table[hash_key]->year = std::stoi(words_vect.at(2));
            the_table[hash_key]->event_index = event_cnt;
            the_table[hash_key]->next = nullptr;



        }
        else {

            hash_table_entry *entry = the_table[hash_key];
            while (entry->next != nullptr && entry->event_id != std::stoi(words_vect.at(0)))
            {
                entry = entry->next;
            }
            if (entry->event_id == std::stoi(words_vect.at(0))) {

                the_table[hash_key]->year = std::stoi(words_vect.at(2));
                the_table[hash_key]->event_index = event_cnt;
                    
            }
            else {

                the_table[hash_key] = new hash_table_entry();
                the_table[hash_key]->event_id = std::stoi(words_vect.at(0));
                the_table[hash_key]->year = std::stoi(words_vect.at(2));
                the_table[hash_key]->event_index = event_cnt;
                the_table[hash_key]->next = nullptr; 

            }

        }
            
        //hash_entry->event_id = std::stoi(words_vect.at(0)); //Event id -- key used to hash on
        //hash_entry->year = std::stoi(words_vect.at(2)); //Year of storm event

        //hash_entry->event_index = (*storm_events)->year;

        event_cnt++;
        //event_cnt_total++;
        //}

        annual_storms_a[index].events = storm_event_array;

        

    }

}

int hash_table::get_node() {
    return 0;
}
void hash_table::delete_node() {

}
int hash_table::ht_size() {
    return 0;
}
void hash_table::print_ht() {

} */

void hash_table::insert_nodes(annual_storms as_array[], int index) {

    int hash_key;
    int event_index = 0; // For the given year, the index into array of storm events

    //TODO: change this
    std::string file_name = get_file_name(index);
    int events = get_individual_ec(file_name);

    std::string line; //stores a line of the details.csv files, for the std::getline
    storm_event* sep; //Storm event pointer
    storm_event* storm_event_array = new storm_event[events];

    //Add the year of the storm events into the annual storms array
    as_array[index].year = get_file_year(index);


    //Each loop opens one particular file, gets and stores it's contents
    //for (int i = 0; i < file_cnt; i++) {

    //Opens a file based on the command line
    //std::string st = argv[i];

    //std::string csv_file_name = fh.get_file_name(i);

    csv_in.open(file_name, std::ios::in);

    //events_perfile = fh.get_individual_ec("details-" + st + ".csv");
    //std::cout << evnts << "\n";

    //Add the year of the storm events into the annual storms array
    as_array[index].year = get_file_year(index);

    //int storm_events_size = 50; //The number of sapces left in the array storm events, decrements evry loop

    std::getline(file_handler::csv_in, line); //Skips first line
    //Gets each row of the file and puts it into a struct storm_event, where each struct is stored into an array of storm event
    while(std::getline(file_handler::csv_in, line)) {

        sep = &storm_event_array[event_index];

        //storm_events_size--;

        std::string line_words; //Temp string to store each word before it is pased into eah index of a vector, from "line"
        std::vector<std::string> words_vect; //Stores the line_words strings


        std::stringstream word_stream(line);

        while (std::getline(word_stream, line_words, ',')){
            words_vect.push_back(line_words);
            //std::cout << line_words << ",";
        }
        //std::cout << "\n";

        int event_id = std::stoi(words_vect.at(0));
        std::string state = words_vect.at(1);
        int year = std::stoi(words_vect.at(2));
        std::string month_name = words_vect.at(3);
        std::string event_type = words_vect.at(4);
        std::string cz_type = words_vect.at(5);
        std::string cz_name = words_vect.at(6);
        int injuries_direct = std::stoi(words_vect.at(7));
        int injuries_indirect = std::stoi(words_vect.at(8));
        int deaths_direct = std::stoi(words_vect.at(9));
        int deaths_indirect = std::stoi(words_vect.at(10));
        int damage_property = std::stoi(words_vect.at(11));
        int damage_crops = std::stoi(words_vect.at(12));
        std::string tor_f_scale = words_vect.at(13);


        sep->event_id = event_id;
        sep->state = state;
        sep->year = year;
        sep->month_name = month_name;
        sep->event_type = event_type;
        sep->cz_type = cz_type;
        sep->cz_name = cz_name;
        sep->injuries_direct = injuries_direct;
        sep->injuries_indirect = injuries_indirect;
        sep->deaths_direct = deaths_direct;
        sep->deaths_indirect = deaths_indirect;
        sep->damage_property = damage_property;
        sep->damage_crops = damage_crops;
        sep->tor_f_scale = tor_f_scale;

        //storm_events[event_cnt] = storm_event_array;

        //Hash Entries
        hash_key = ht_size % event_id;

        if (the_table[hash_key] == nullptr) {

            the_table[hash_key] = new hash_entry(event_id, year, event_index);
            /* the_table[hash_key]->event_id = std::stoi(words_vect.at(0));
            the_table[hash_key]->year = std::stoi(words_vect.at(2));
            the_table[hash_key]->event_index = event_cnt;
            the_table[hash_key]->next = nullptr; */



        }
        else {

            hash_entry *entry = the_table[hash_key];
            while (entry->get_next() != nullptr && entry->get_key() != event_id)
            {
                entry = entry->get_next();
            }
            if (entry->get_key() == event_id) {

                the_table[hash_key]->set_year(year);
                the_table[hash_key]->set_event_index(event_index);
                    
            }
            else {

                the_table[hash_key] = new hash_entry(event_id, year, event_index);

            }

        }
            
        //hash_entry->event_id = std::stoi(words_vect.at(0)); //Event id -- key used to hash on
        //hash_entry->year = std::stoi(words_vect.at(2)); //Year of storm event

        //hash_entry->event_index = (*storm_events)->year;

        event_index++;
        //event_cnt_total++;
        //}

        as_array[index].events = storm_event_array;
    }

}