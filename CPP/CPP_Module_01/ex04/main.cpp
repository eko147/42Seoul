#include "Sed.hpp"

void exitFromError(std::string str)
{
    std::cout << str << std::endl;
    std::exit(EXIT_FAILURE);
}

int main(int ac, char **av)
{
    if (ac != 4)
        exitFromError("Invalid Argument Type");
    Sed sed(av[1], av[2], av[3]);
    sed.replaceFile(sed.openFile());
}
