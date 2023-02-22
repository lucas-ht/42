#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << std::endl;

    std::list<int> s;
    s.push_back(5);
    s.push_back(17);
    std::cout << s.back() << std::endl;
    s.pop_back();
    std::cout << s.size() << std::endl;
    s.push_back(3);
    s.push_back(5);
    s.push_back(737);
    s.push_back(0);
    std::list<int>::iterator its = s.begin();
    std::list<int>::iterator ites = s.end();

    ++its;
    --its;
    while (its != ites)
    {
        std::cout << *its << std::endl;
        ++its;
    }

    return 0;
}