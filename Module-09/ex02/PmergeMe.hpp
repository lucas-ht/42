#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <string>
#include <iostream>
#include <chrono>

#include <forward_list>
#include <list>
#include <deque>
#include <vector>

class PmergeMe {
private:
    std::vector<int>        stackA;
    std::deque<int>         stackB;

    void    isDuplicate(int next);

    void    vectorInsertionSort(int left, int right);
    void    vectorMerge(std::vector<int> & temp, int left, int mid, int right);
    void    vectorMergeSort(std::vector<int> & temp, int left, int right, int threshold);

    void    dequeInsertionSort(int left, int right);
    void    dequeMerge(std::deque<int> & temp, int left, int mid, int right);
    void    dequeMergeSort(std::deque<int> & temp, int left, int right, int threshold);

public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(PmergeMe const & src);
    PmergeMe & operator=(PmergeMe const & rhs);

    void    parse(int ac, char **av);
    void    print();
    void    vectorSort();
    void    dequeSort();

    class InvalidInputException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Invalid input";
        }
    };

    class DuplicateInputException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Duplicate input";
        }
    };

};

#endif
