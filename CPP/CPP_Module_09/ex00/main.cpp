#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
    if(argc != 2){
        std::cout << "Invalid Argument." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    BitcoinExchange bitcoinExchange;
    bitcoinExchange.getDatabase();
    bitcoinExchange.readFile(argv[1]);
	return 0;
}