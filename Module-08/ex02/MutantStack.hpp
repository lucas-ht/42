#ifndef __MUTANT_STACK_HPP__
#define __MUTANT_STACK_HPP__

#include <iostream>
#include <iterator>
#include <algorithm>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack<T>();
    MutantStack<T>(const MutantStack<T>& m);
    ~MutantStack<T>();
    MutantStack<T>  &operator=(const MutantStack<T>& m);

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator    begin();
    iterator    end();
};

#include "MutantStack.tpp"

#endif