#ifndef SEARCHINGALGORITHM_H
#define SEARCHINGALGORITHM_H
#include <vector>
#include <iostream>

class SearchingAlgorithm{
    protected :
    int numberComparisons;

    private :
    int static totalComparisons;
    int static totalSearch;
    int static averageComparisons;

    public :
    SearchingAlgorithm();
    virtual int Search(std::vector<int> elem, int a) = 0;
    int displaySearchResults(std::ostream& a, int results, int target);

};

class LinearSearch : public SearchingAlgorithm {
    public:
    int Search(std::vector<int> elem, int target) override;
};

class JumpSearch : public SearchingAlgorithm {
    public:
    int Search(std::vector<int> elem, int target) override;
};

class BinarySearch : public SearchingAlgorithm {
    public:
    int Search(std::vector<int> elem, int target) override;
};

#endif