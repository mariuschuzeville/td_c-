#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include "SearchingAlgorithm.h"

int SearchingAlgorithm::totalComparisons = 0;
int SearchingAlgorithm::totalSearch = 0;
int SearchingAlgorithm::averageComparisons = 0;

SearchingAlgorithm::SearchingAlgorithm() : numberComparisons(0) {
}

int SearchingAlgorithm::displaySearchResults(std::ostream& a, int results, int target) {
    ++totalSearch;
    totalComparisons += numberComparisons;
    averageComparisons = totalSearch > 0 ? totalComparisons / totalSearch : 0;

    return numberComparisons/results;
}

int LinearSearch::Search(std::vector<int> elem, int target) {
    numberComparisons = 0;
    for (std::size_t i = 0; i < elem.size(); ++i) {
        ++numberComparisons;
        if (elem[i] == target) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

int JumpSearch::Search(std::vector<int> elem, int target) {
    numberComparisons = 0;
    if (elem.empty()) {
        return -1;
    }
    const std::size_t blockSize =
        static_cast<std::size_t>(std::sqrt(static_cast<double>(elem.size())));
    std::size_t blockStart = 0;
    std::size_t blockEnd = blockSize;

    while (blockStart < elem.size()) {
        const std::size_t lastIndex = std::min(blockEnd, elem.size()) - 1;
        ++numberComparisons;
        if (elem[lastIndex] >= target) {
            for (std::size_t i = blockStart; i <= lastIndex; ++i) {
                ++numberComparisons;
                if (elem[i] == target) {
                    return static_cast<int>(i);
                }
                if (elem[i] > target) {
                    return -1;
                }
            }
            return -1;
        }
        blockStart = blockEnd;
        blockEnd += blockSize;
    }
    return -1;
}

int BinarySearch::Search(std::vector<int> elem, int target) {
    numberComparisons = 0;
    std::size_t left = 0;
    std::size_t right = elem.size();
    while (left < right) {
        const std::size_t middle = left + (right - left) / 2;
        ++numberComparisons;
        if (elem[middle] == target) {
            return static_cast<int>(middle);
        }
        ++numberComparisons;
        if (elem[middle] < target) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }
    return -1;
}
