#include "Harl.hpp"

int main (int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Usage : " << av[0] << "<log level >" << std::endl ;
        return 1;
    }
    std::string lvl  = av[1];
    Harl harl ;
    harl.complain(lvl) ;
    return 0;
} 