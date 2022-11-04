#include <vector>
#include <iostream>
#include <string>
#include "dice.h"
#include <unordered_map>

#include "PDiceConfig.h"

void pdice_usage(){
    std:: cout << "Usage\n" << std::endl;
    std:: cout << "\t./PDice [options]\n" << std:: endl;
    std:: cout << "Check the instream and process the dice.\n" << std:: endl;
    std:: cout << "Options" << std::endl;
    std:: cout << "\t-v|--version\t= Print the version about PDice." << std:: endl;
    std:: cout << "\t-h|--help\t= Print help about PDice." << std:: endl;
    std:: cout << "\t-s|--start\t= Start to use PDice." << std:: endl;
    std:: cout << "\tUsage -s\n" << std::endl;
    std:: cout << "\t\tadd [name] [possible]\t= add item with possible." << std::endl;
    std:: cout << "\t\tdelete [name]\t= delete item by name." << std::endl;
    std:: cout << "\t\tprint \t= print current items." << std::endl;
    std:: cout << "\t\tselect \t= select one item by possibility." << std::endl;
    std:: cout << "\t\texit \t= exit." << std::endl;
}

std::vector<std::string> str_split(const std:: string str) {
    std::vector<std::string> res;
    int len = str.length();
    int index = 0;
    for (int i = 0; i < len; ++i) {
        if (str[i] == ' ') {
            if (i != index)
                res.push_back(str.substr(index, i-index));
            index = i+1;
        }
    }
    res.push_back(str.substr(index, len-index));
    return res;
}

int str2int(std::string str) {
    int res = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] < '0' || str[i] > '9') return -1;
        res *= 10;
        res += (str[i] - '0');
    }
    return res;
}
void read_orders() {

    std:: string str;
    Dice* pdice = new Dice();
    std::unordered_map<std::string, int> order2int{{"add", 0}, {"delte", 1}, {"print", 2}, {"select", 3}, {"exit", 4}};

    while(std::getline(std::cin, str)) {
        std::vector<std::string> splited = str_split(str);
        bool flag = false;
        if (!splited.size()) continue;
        switch (order2int[splited[0]]) {
            case 0:
            {
                if (splited.size() < 3) {
                    std::cout << "Usage: add [name] [possible]" << std:: endl;
                    std::cout << "example: add fruit 100" << std:: endl;
                    break;
                }
                std::string& name = splited[1];
                int poss = str2int(splited[2]);
                if (poss == -1) {
                    std:: cout << "possible must be positive number" << std:: endl;
                    break;
                }
                pdice->push(name, poss);
                break;
            }
            case 1:
            {
                if (splited.size() < 2) {
                    std:: cout << "Usage: delete [name]" << std:: endl;
                    std:: cout << "example: delete fruit" << std:: endl;
                    break;
                }
                pdice->pop(splited[1]);
                break;
            }
            case 2:
            {
                pdice->print();
                break;
            }
            case 3:
            {
                std:: cout <<"Select: " << pdice->select() << std:: endl;
                break;
            }
            case 4:
            {
                flag = true;
                break;
            }
            default:
                break;
        }
        if (flag) break;
    }
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
            else if (param == "-h" || param == "--help") {
                pdice_usage(); 
            }
            else if (param == "-s" || param == "--start") {
                read_orders();
            }
            else {
                std:: cout << "Use `./PDice -h` for help" << std:: endl;
            }
            break;
        }

        default:
            std:: cout << "ERROR! Please use: './PDice -h|--help' for more infomation." << std:: endl;
            break;
    }

    return 0;
}