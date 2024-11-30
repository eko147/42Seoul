#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}
PmergeMe::PmergeMe(int argc, char** argv)
{
    getElement(argc, argv);
}

PmergeMe::PmergeMe(const PmergeMe &obj){
	*this = obj;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj){
	(void)obj;
	return *this;
}

bool PmergeMe::isPositiveInteger(const std::string& str) {
    int value = std::atoi(str.c_str());

    return (value > 0 && value <= INT_MAX);
}

// void PmergeMe::checkPrintdequePair(std::deque<std::pair<int, int> > arr)
// {
//     std::cout << "------merge sort 후 pair deque ------" << std::endl;
//     std::cout << "[";
//     for (size_t i = 0; i < arr.size(); i++){
//         std::cout << "(" << arr[i].first << "," << arr[i].second << "), ";
//     }
//     std::cout << "]" << std::endl;
//     std::cout << "----------" << std::endl;
// }

void PmergeMe::checkPrintdeque(std::deque<int> arr)
{
    std::cout << "------deque ------" << std::endl;
    std::cout << "[";
    for (size_t i = 0; i < arr.size(); i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << "----------" << std::endl;
}

void PmergeMe::checkdequeSorted(std::deque<int> arr, std::deque<int> original)
{
    sort(original.begin(), original.end());
    if (arr.size() != original.size()){
        std::cout << "deque is not sorted!" << std::endl;
        return;
    }
    for(size_t i = 0; i < original.size(); i++){
        if (arr[i] != original[i]){
            std::cout << "deque is not sorted!" << std::endl;
            return;
        }
    }
    std::cout << "deque is sorted!" << std::endl;
}

// void PmergeMe::checkPrintvectorPair(std::vector<std::pair<int, int> > arr)
// {
//     std::cout << "------merge sort 후 pair vector ------" << std::endl;
//     std::cout << "[";
//     for (size_t i = 0; i < arr.size(); i++){
//         std::cout << "(" << arr[i].first << "," << arr[i].second << "), ";
//     }
//     std::cout << "]" << std::endl;
//     std::cout << "----------" << std::endl;
// }

void PmergeMe::checkPrintvector(std::vector<int> arr)
{
    std::cout << "------vector ------" << std::endl;
    std::cout << "[";
    for (size_t i = 0; i < arr.size(); i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << "----------" << std::endl;
}

void PmergeMe::checkvectorSorted(std::vector<int> arr, std::vector<int> original)
{
    sort(original.begin(), original.end());
    if (arr.size() != original.size()){
        std::cout << "vector is not sorted!" << std::endl;
        return;
    }
    for(size_t i = 0; i < original.size(); i++){
        if (arr[i] != original[i]){
            std::cout << "vector is not sorted!" << std::endl;
            return;
        }
    }
    std::cout << "vector is sorted!" << std::endl;
}

void PmergeMe::getElement(int argc, char** argv)
{
    int value;
    for(int i = 1; i < argc; i++)
    {
        if(isPositiveInteger(std::string(argv[i]))){
            value = std::atoi(argv[i]);
            _deque.push_back(value);  
            _vector.push_back(value);  
        }          
        else{
            std::cout << "Error" << std::endl;
            std::exit(EXIT_FAILURE);
        }
    }
}

/*merge sort*/
void PmergeMe::dequeMergeSortByFirst(std::deque<std::pair<int, int> >& pairDeque) {
    if (pairDeque.size() <= 1)
        return;
    size_t mid = pairDeque.size() / 2;
    std::deque<std::pair<int, int> > left(pairDeque.begin(), pairDeque.begin() + mid);
    std::deque<std::pair<int, int> > right(pairDeque.begin() + mid, pairDeque.end());

    dequeMergeSortByFirst(left);
    dequeMergeSortByFirst(right);

    dequeMergePairsByFirst(left, right, pairDeque);
}

void PmergeMe::dequeMergePairsByFirst(const std::deque<std::pair<int, int> >& left, const std::deque<std::pair<int, int> >& right, std::deque<std::pair<int, int> >& result) {
    size_t i = 0, j = 0, k = 0;

    while (i < left.size() && j < right.size()) {
        if (left[i].first <= right[j].first) {
            result[k] = left[i];
            ++i;
        } else {
            result[k] = right[j];
            ++j;
        }
        ++k;
    }
    while (i < left.size()) {
        result[k] = left[i];
        ++i;
        ++k;
    }

    while (j < right.size()) {
        result[k] = right[j];
        ++j;
        ++k;
    }
}

/*  Binary Search */

std::deque<int>::iterator PmergeMe::dequeBinarySearch(std::deque<int>::iterator first, std::deque<int>::iterator last, int value)
{
    if (first == last)
        return last;

    std::deque<int>::iterator mid = first;
    dequeAdvance(mid, std::distance(first, last) / 2);

    if (*mid == value)
        return mid;
    else if (*mid < value)
    {
        dequeAdvance(mid, 1);
        return dequeBinarySearch(mid, last, value);
    }
    else
        return dequeBinarySearch(first, mid, value);
}

/*  Merge Insert Sort */

void PmergeMe::dequeMergeInsertSort()
{
    std::deque<std::pair<int, int> > pairDeque;

    if (_deque.size() == 1){
        _dequeResult = _deque;
        return;
    }
    for (size_t i = 0; i < _deque.size(); i += 2) {
        if (i + 1 < _deque.size()) {
            if(_deque[i] > _deque[i + 1])
                pairDeque.push_back(std::make_pair(_deque[i], _deque[i + 1]));
            else
                pairDeque.push_back(std::make_pair(_deque[i + 1], _deque[i]));
        }
        else 
            pairDeque.push_back(std::make_pair(-1, _deque[i]));
    }
    if(pairDeque.back().first == -1)
    {
        std::pair <int, int> tmp = pairDeque.back();
        pairDeque.pop_back();
        dequeMergeSortByFirst(pairDeque);
        pairDeque.push_back(tmp);
    }
    else
        dequeMergeSortByFirst(pairDeque);

    std::deque<int> mainChain;

    for (std::deque<std::pair<int, int> >::const_iterator it = pairDeque.begin(); it != pairDeque.end(); ++it) {
        const std::pair<int, int>& pair = *it; 
        if (pair.first != -1)
        {
            mainChain.push_back(pair.first);
        }
    }
    dequeInsertSort(pairDeque, mainChain);
}

/* InsertSort*/
void PmergeMe::dequeInsertSort(std::deque<std::pair<int, int> >& pairDeque, std::deque<int>& mainChain)
{
    size_t start = 1;
    size_t next = 1; 

    std::deque<std::pair<int, int> >::iterator it = pairDeque.begin();
    std::deque<std::pair<int, int> >::iterator cmp;
    std::deque<int>::iterator findIter;

    size_t pendingLen = _deque.size() % 2 == 0 ? pairDeque.size() : pairDeque.size() - 1;
    size_t count = pendingLen; 
    int j;

    mainChain.insert(mainChain.begin(), (*it).second);
    count--;
    int prev;
    while (count > 0)
    {
        size_t nextBlockSize = next + 2 * start; 
        prev = next;
        next = (nextBlockSize > pendingLen) ? pendingLen : nextBlockSize;
        start = prev;
        it = pairDeque.begin();
        dequePairAdvance(it, next - 1);
        cmp = pairDeque.begin();
        dequePairAdvance(cmp, start - 1);
        while (it != cmp)
        {
            j = (*it).first;
            findIter = dequeBinarySearch(mainChain.begin(), mainChain.end(), j); 
            findIter = dequeBinarySearch(mainChain.begin(), findIter, (*it).second);
            mainChain.insert(findIter, (*it).second); 
            count--; 
            --it; 
        }
    }

    if (_vector.size() % 2 == 1){
        it = pairDeque.begin();
        dequePairAdvance(it, pairDeque.size() - 1);
        findIter = dequeBinarySearch(mainChain.begin(), mainChain.end(), (*it).second);
        mainChain.insert(findIter, (*it).second);
    }
    _dequeResult = mainChain;
    // checkdequeSorted(_dequeResult, _deque);
}

void PmergeMe::printDequeResult(){
    std::cout << "Before : ";
    for (size_t i = 0; i < _deque.size(); i++){
        if (_deque.size() > 5 && i > 3){
            std::cout << "[...]";
            break;
        }
        std::cout << _deque[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "After  : ";
    for (size_t i = 0; i < _dequeResult.size(); i++){
        if (_dequeResult.size() > 5 && i > 3){
            std::cout << "[...]";
            break;
        }
        std::cout << _dequeResult[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::dequeAdvance(std::deque<int>::iterator &it, size_t add){
    for (size_t i = 0; i < add; i++){
        it++;
    }
}

void PmergeMe::dequePairAdvance(std::deque<std::pair<int, int> >::iterator &it, size_t add){
    for (size_t i = 0; i < add; i++){
        it++;
    }
}

/* ----------------------------------- vector -------------------------------------- */

/*merge sort*/
void PmergeMe::vectorMergeSortByFirst(std::vector<std::pair<int, int> >& pairVector) {
    if (pairVector.size() <= 1)
        return;
    size_t mid = pairVector.size() / 2;
    std::vector<std::pair<int, int> > left(pairVector.begin(), pairVector.begin() + mid);
    std::vector<std::pair<int, int> > right(pairVector.begin() + mid, pairVector.end());

    vectorMergeSortByFirst(left);
    vectorMergeSortByFirst(right);

    vectorMergePairsByFirst(left, right, pairVector);
}

void PmergeMe::vectorMergePairsByFirst(const std::vector<std::pair<int, int> >& left, const std::vector<std::pair<int, int> >& right, std::vector<std::pair<int, int> >& result) {
    size_t i = 0, j = 0, k = 0;

    
    while (i < left.size() && j < right.size()) {
        if (left[i].first <= right[j].first) {
            result[k] = left[i];
            ++i;
        } else {
            result[k] = right[j];
            ++j;
        }
        ++k;
    }
    while (i < left.size()) {
        result[k] = left[i];
        ++i;
        ++k;
    }

    while (j < right.size()) {
        result[k] = right[j];
        ++j;
        ++k;
    }
}

/*  Binary Search */
std::vector<int>::iterator PmergeMe::vectorBinarySearch(std::vector<int>::iterator first, std::vector<int>::iterator last, int value)
{
    if (first == last)
        return last;

    std::vector<int>::iterator mid = first;
    vectorAdvance(mid, std::distance(first, last) / 2);

    if (*mid == value)
        return mid;
    else if (*mid < value)
    {
        vectorAdvance(mid, 1);
        return vectorBinarySearch(mid, last, value);
    }
    else
        return vectorBinarySearch(first, mid, value);
}

/*  Merge Insert Sort */
void PmergeMe::vectorMergeInsertSort()
{
    std::vector<std::pair<int, int> > pairVector;

    if (_vector.size() == 1){
        _vectorResult = _vector;
        return;
    }
    for (size_t i = 0; i < _vector.size(); i += 2) {
        if (i + 1 < _vector.size()) {
            if(_vector[i] > _vector[i + 1])
                pairVector.push_back(std::make_pair(_vector[i], _vector[i + 1]));
            else
                pairVector.push_back(std::make_pair(_vector[i + 1], _vector[i]));
        }
        else 
            pairVector.push_back(std::make_pair(-1, _vector[i]));
    }
    if(pairVector.back().first == -1)
    {
        std::pair <int, int> tmp = pairVector.back();
        pairVector.pop_back();
        vectorMergeSortByFirst(pairVector);
        pairVector.push_back(tmp);
    }
    else
        vectorMergeSortByFirst(pairVector);

    std::vector<int> mainChain;

    for (std::vector<std::pair<int, int> >::const_iterator it = pairVector.begin(); it != pairVector.end(); ++it) {
        const std::pair<int, int>& pair = *it; 
        if (pair.first != -1)
        {
            mainChain.push_back(pair.first);
        }
    }
    vectorInsertSort(pairVector, mainChain);
}


/* InsertSort*/
void PmergeMe::vectorInsertSort(std::vector<std::pair<int, int> >& pairVector, std::vector<int>& mainChain)
{
    size_t start = 1; 
    size_t next = 1; 

    std::vector<std::pair<int, int> >::iterator it = pairVector.begin();
    std::vector<std::pair<int, int> >::iterator cmp;
    std::vector<int>::iterator findIter;

    size_t pendingLen = _vector.size() % 2 == 0 ? pairVector.size() : pairVector.size() - 1;
    size_t count = pendingLen; 
    int j;

    mainChain.insert(mainChain.begin(), (*it).second);
    count--;

    while (count > 0)
    {
        size_t nextBlockSize = next + 2 * start;
        next = (nextBlockSize > pendingLen) ? pendingLen : nextBlockSize;
        it = pairVector.begin();
        vectorPairAdvance(it, next - 1);
        cmp = pairVector.begin();
        vectorPairAdvance(cmp, start - 1);
        while (it != cmp)
        {
            j = (*it).first;
            findIter = vectorBinarySearch(mainChain.begin(), mainChain.end(), j); 
            findIter = vectorBinarySearch(mainChain.begin(), findIter, (*it).second); 
            mainChain.insert(findIter, (*it).second); 
            count--; 
            --it; 
        }
        start = next;
    }

    if (_vector.size() % 2 == 1){
        it = pairVector.begin();
        vectorPairAdvance(it, pairVector.size() - 1);
        findIter = vectorBinarySearch(mainChain.begin(), mainChain.end(), (*it).second);
        mainChain.insert(findIter, (*it).second);
    }

    _vectorResult = mainChain;
    // checkvectorSorted(_vectorResult, _vector);
}

void PmergeMe::printVectorResult(){
    std::cout << "Before : ";
    for (size_t i = 0; i < _vector.size(); i++){
        if (_vector.size() > 5 && i > 3){
            std::cout << "[...]";
            break;
        }
        std::cout << _vector[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "After  : ";
    for (size_t i = 0; i < _vectorResult.size(); i++){
        if (_vectorResult.size() > 5 && i > 3){
            std::cout << "[...]";
            break;
        }
        std::cout << _vectorResult[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::vectorAdvance(std::vector<int>::iterator &it, size_t add){
    for (size_t i = 0; i < add; i++){
        it++;
    }
}

void PmergeMe::vectorPairAdvance(std::vector<std::pair<int, int> >::iterator &it, size_t add){
    for (size_t i = 0; i < add; i++){
        it++;
    }
}