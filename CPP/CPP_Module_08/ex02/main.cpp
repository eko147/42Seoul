#include "MutantStack.hpp"
#include <list>

int main()
{
    // 첫 번째 테스트: MutantStack 사용
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << std::endl;
    std::stack<int> s(mstack);
    std::cout << s.top() << std::endl;
    std::cout << mstack.top() << std::endl;
    std::cout << std::endl;

    // 두 번째 테스트: MutantStack의 reverse_iterator 사용
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    ++rit;
    --rit;
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }

    std::cout << std::endl;

    // 세 번째 테스트: std::list 사용
    std::list<int> lst;
    lst.push_back(5); 
    lst.push_back(17);
    std::cout << lst.back() << std::endl;
    lst.pop_back();
    std::cout << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();
    ++lit;
    --lit;
    std::cout << std::endl;

    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }
    std::cout << std::endl;


    // 네 번째 테스트: std::list의 reverse_iterator 사용
    std::list<int>::reverse_iterator lrit = lst.rbegin();
    std::list<int>::reverse_iterator lrite = lst.rend();
    ++lrit;
    --lrit;
    while (lrit != lrite)
    {
        std::cout << *lrit << std::endl;
        ++lrit;
    }

    return 0;
}
