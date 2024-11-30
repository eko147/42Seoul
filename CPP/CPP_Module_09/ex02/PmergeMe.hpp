#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <deque>
#include <vector>

class PmergeMe
{
private:
	std::deque<int> _deque;
    std::deque<int> _dequeResult;
    std::vector<int> _vector;
    std::vector<int> _vectorResult;


    /*deque*/
    std::deque<int>::iterator dequeBinarySearch(std::deque<int>::iterator first, std::deque<int>::iterator last, int value);
    void dequeMergeSortByFirst(std::deque<std::pair<int, int> >& pairDeque);
    void dequeMergePairsByFirst(const std::deque<std::pair<int, int> >& left, const std::deque<std::pair<int, int> >& right, std::deque<std::pair<int, int> >& result);
    void dequeInsertSort(std::deque<std::pair<int, int> > &pairDeque, std::deque<int> &mainChain);
    void dequeAdvance(std::deque<int>::iterator &it, size_t add);
    void dequePairAdvance(std::deque<std::pair<int, int> >::iterator &it, size_t add);

    /*vector*/
    std::vector<int>::iterator vectorBinarySearch(std::vector<int>::iterator first, std::vector<int>::iterator last, int value);
    void vectorMergeSortByFirst(std::vector<std::pair<int, int> >& pairvector);
    void vectorMergePairsByFirst(const std::vector<std::pair<int, int> >& left, const std::vector<std::pair<int, int> >& right, std::vector<std::pair<int, int> >& result);
    void vectorInsertSort(std::vector<std::pair<int, int> > &pairvector, std::vector<int> &mainChain);
    void vectorAdvance(std::vector<int>::iterator &it, size_t add);
    void vectorPairAdvance(std::vector<std::pair<int, int> >::iterator &it, size_t add);



    void checkPrintdequePair(std::deque<std::pair<int, int> > arr);
    void checkPrintdeque(std::deque<int> arr);
    void checkPrintvectorPair(std::vector<std::pair<int, int> > arr);
    void checkPrintvector(std::vector<int> arr);
    void checkvectorSorted(std::vector<int> arr, std::vector<int> original);
    void checkdequeSorted(std::deque<int> arr, std::deque<int> original);


public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(int argc, char** argv);
    PmergeMe(const PmergeMe &obj);
    PmergeMe &operator=(const PmergeMe &obj);

    void getElement(int argc, char** argv);
    bool isPositiveInteger(const std::string& str);

    void dequeMergeInsertSort();
    void vectorMergeInsertSort();

    void printDequeResult();
    void printVectorResult();

};

#endif
