#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const & src) {
    *this = src;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs) {
    if (this == &rhs)
        return *this;
    this->stackA = rhs.stackA;
    this->stackB = rhs.stackB;
    return *this;
}

void    PmergeMe::isDuplicate(int next) {

    return;

    for (std::vector<int>::iterator it = this->stackA.begin(); it != this->stackA.end(); it++) {
        if (*it == next)
            throw PmergeMe::DuplicateInputException();
    }
}

void    PmergeMe::parse(int ac, char **av) {
    int     next = 0;
    for (int i = 1; i < ac; i++) {
        try {
            next = std::stoi(av[i]);
        }
        catch (std::exception & e) {
            std::cout << av[i] << std::endl;
            throw PmergeMe::InvalidInputException();
        }
        if (next < 0)
            throw PmergeMe::InvalidInputException();
        this->isDuplicate(next);
        this->stackA.push_back(next);
        this->stackB.push_back(next);
    }
}

void    PmergeMe::print() {
    for (std::vector<int>::iterator it = this->stackA.begin(); it != this->stackA.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::vectorInsertionSort(int left, int right) {
    for (int i = left; i <= right; i++) {
        int tmp = this->stackA.at(i);

        int j = i;
        for (; j > left && this->stackA.at(j - 1) > tmp; j--)
             this->stackA.at(j) = this->stackA.at(j - 1);

        this->stackA.at(j) = tmp;
    }
}

void PmergeMe::vectorMerge(std::vector<int> & temp, int left, int mid, int right) {
    int l = left;
    int m = mid + 1;
    int i = left;

    for (; l <= mid && m <= right; i++) {
        if (this->stackA.at(l) < this->stackA.at(m))    { temp.at(i) = this->stackA.at(l); l++; }
        else                                            { temp.at(i) = this->stackA.at(m); m++; }
    }

    for (; m <= right; m++, i++)                        { temp.at(i) = this->stackA.at(m); }
    for (; l <= mid; l++, i++)                          { temp.at(i) = this->stackA.at(l); }

    for (i = left; i <= right; i++)                     { this->stackA.at(i) = temp.at(i); }
}

void PmergeMe::vectorMergeSort(std::vector<int> & temp, int left, int right, int threshold) {
    if (right <= left)
        return;

    if (right - left <= threshold) {
        this->vectorInsertionSort(left, right);
        return;
    }

    int mid = (left + right) / 2;

    this->vectorMergeSort(temp, left, mid, threshold);
    this->vectorMergeSort(temp, mid + 1, right, threshold);

    this->vectorMerge(temp, left, mid, right);
}

void PmergeMe::vectorSort() {
    std::vector<int>         temp = this->stackA;
    this->vectorMergeSort(temp, 0, this->stackA.size() - 1, 10);
}



void PmergeMe::dequeInsertionSort(int left, int right) {
    for (int i = left; i <= right; i++) {
        int tmp = this->stackB.at(i);

        int j = i;
        for (; j > left && this->stackB.at(j - 1) > tmp; j--)
             this->stackB.at(j) = this->stackB.at(j - 1);

        this->stackB.at(j) = tmp;
    }
}

void PmergeMe::dequeMerge(std::deque<int> & temp, int left, int mid, int right) {
    int l = left;
    int m = mid + 1;
    int i = left;

    for (; l <= mid && m <= right; i++) {
        if (this->stackB.at(l) < this->stackB.at(m))    { temp.at(i) = this->stackB.at(l); l++; }
        else                                            { temp.at(i) = this->stackB.at(m); m++; }
    }

    for (; m <= right; m++, i++)                        { temp.at(i) = this->stackB.at(m); }
    for (; l <= mid; l++, i++)                          { temp.at(i) = this->stackB.at(l); }

    for (i = left; i <= right; i++)                     { this->stackB.at(i) = temp.at(i); }
}

void PmergeMe::dequeMergeSort(std::deque<int> & temp, int left, int right, int threshold) {
    if (right <= left)
        return;

    if (right - left <= threshold) {
        this->dequeInsertionSort(left, right);
        return;
    }

    int mid = (left + right) / 2;

    this->dequeMergeSort(temp, left, mid, threshold);
    this->dequeMergeSort(temp, mid + 1, right, threshold);

    this->dequeMerge(temp, left, mid, right);
}

void PmergeMe::dequeSort() {
    std::deque<int>         temp = this->stackB;
    this->dequeMergeSort(temp, 0, this->stackB.size() - 1, 10);
}
