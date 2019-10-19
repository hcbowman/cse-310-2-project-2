#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include"defn.h"

int main (int argc, char** argv) {

    //Variables


    //Objects
    std::vector<std::string> dates_vector; //Holds the range of years inputed via command line
    std::fstream csv_in;


    //Disable synchronization between the C and C++ standard streams
	std::ios::sync_with_stdio(false);

    //Get command line args
    //TODO: change to get dates and add to struct?
    if (argc != 1) {

        for (int i = 2; i < argc; i++) {
            //dates_vector.push_back( std::stoi(argv[i]) );
            dates_vector.push_back(argv[i]);
        }                

    }
    else {
        return -1;
    }

    for (int i = 0; i < dates_vector.size(); i++) {

        std::string det_str = "details-";
        csv_in.open(det_str << dates_vector[i] << ".csv" ,std::ios::in);

    }

    



    std::cout << "DEBUG: end Project2" << "\n";

}