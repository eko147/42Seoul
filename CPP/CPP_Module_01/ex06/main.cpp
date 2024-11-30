#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;

    if (ac != 2)
    {
        std::cout << "Wrong Type" << std::endl;
        exit(EXIT_FAILURE);
    }
    harl.complain(av[1]);
    return (0);
}