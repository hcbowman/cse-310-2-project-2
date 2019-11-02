#include"file_handler.hpp"

file_handler::file_handler() {

}

file_handler::file_handler(int arg_count, char** arg_var) {

    argc = arg_count;
    argv = arg_var;


}

file_handler::~file_handler() {

}

void file_handler::set_files(int arg_count, char** arg_var) {

    argc = arg_count;
    argv = arg_var;

}

int file_handler::count_events() {

    int count;

	std::string line_temp;

	while ( std::getline(csv_in, line_temp)){
		count++;
	}

    //subtract 1 for the header in the event file
	return count--;
}

void file_handler::set_event_counts_helper() {

    for(int i = 2; i < argc; i++) {

        std::string st = argv[i];
        

        event_file_count efc;

        efc.file_name = "details-" + st + ".csv";

		csv_in.open(efc.file_name, std::ios::in);

        efc.number_of_events += count_events();

		csv_in.close();

        efcv.push_back(efc);

    }


}

void file_handler::set_event_counts() {

    set_event_counts();

    for (auto efc : efcv) {

        total_events += efc.number_of_events;

    }

}

int file_handler::get_event_counts() {

    //DEBUG:
    std::cout << "events_total:" << total_events << "\n";

    return total_events;

}

int file_handler::get_individual_ec(std::string fn) {

    bool found = false;
    int index = 0;

    while(!found) {

        if (efcv.at(index).file_name == fn) {
            found = true;
        }
        else
        {
            index++;
        }
        
    }
    

    return efcv.at(index).number_of_events;



}

bool file_handler::test_for_prime( int val ) {
    int limit, factor = 2;

    limit = (long)( sqrtf( (float) val ) + 0.5f );
    while( (factor <= limit) && (val % factor) )
        factor++;

    return( factor > limit );
}

int file_handler::get_ht_size(int count) {
    
	int ht_size;

	for(int i = count*2; ; i++ ){

        if( test_for_prime( i ) ) {
            ht_size = i;
            break;
        }

    }

    return ht_size;

}


