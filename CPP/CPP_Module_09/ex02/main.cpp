#include "PmergeMe.hpp"

int main (int argc, char** argv)
{
    if(argc == 1)
    {
        std::cout << "Error" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    PmergeMe pmergeMe(argc, argv);
    clock_t startDeque = clock();
    pmergeMe.dequeMergeInsertSort();
    clock_t endDeque = clock();
    double elapsedTimeDeque = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000;
    
    clock_t startVector = clock();
    pmergeMe.vectorMergeInsertSort();
    clock_t endVector = clock();
    double elapsedTimeVector = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000;
    pmergeMe.printVectorResult();
    std::cout << "Time for dequeMergeInsertSort: " << elapsedTimeDeque << " ms" << std::endl;
    std::cout << "Time for VectorMergeInsertSort: " << elapsedTimeVector << " ms" << std::endl;
    return 0;
}