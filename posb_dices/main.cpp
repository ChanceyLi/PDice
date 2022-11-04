#include <vector>
#include <iostream>
#include <string>
#include "dice.h"

#include "PDiceConfig.h"

void pdice_usage(){
    std:: cout << "Usage\n" << std::endl;
    std:: cout << "\t./PDice [options]\n" << std:: endl;
    std:: cout << "Check the instream and process the dice.\n" << std:: endl;
    std:: cout << "Options" << std::endl;
    std:: cout << "\t-v|--version\t= Print the version about PDice." << std:: endl;
    std:: cout << "\t-h|--help\t= Print help about PDice." << std:: endl;
    std:: cout << "\t-s|--start\t= Start to use PDice." << std:: endl;
}
void read_orders() {
    std:: string str;
    //todo
}
int main(int argc, char* argv[])
{
    switch (argc) {
        case 1:
        {
            pdice_usage();
            break;
        }

        case 2:
        {
            std::string param = argv[1];
            /*
            * check some other parameters if neccessary.
            */
            if (param == "-v" || param == "--version") {
                std:: cout << "VERSION: " << PDice_VERSION_MAJOR << "." << PDice_VERSION_MINOR << std:: endl;
            }
            if (param == "-h" || param == "--help") {
                pdice_usage(); 
            }
            if (param == "-s" || param == "--start") {
                read_orders();
            }
            break;
        }

        default:
            std:: cout << "ERROR! Please use: './PDice -h|--help' for more infomation." << std:: endl;
            break;
    }

    return 0;
}