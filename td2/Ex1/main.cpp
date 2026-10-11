#include <iostream>
#include <vector>
#include "SearchingAlgorithm.h"

int main() {
    const std::vector<int> values = {1, 3, 5, 7, 9, 11};
    LinearSearch linear;
    JumpSearch jump;
    BinarySearch binary;
    SearchingAlgorithm* algorithms[] = {&linear, &jump, &binary};
    const char* names[] = {"LinearSearch", "JumpSearch", "BinarySearch"};
    int failures = 0;
    for (int i = 0; i < 3; ++i) {
        const int found = algorithms[i]->Search(values, 7);
        const int missing = algorithms[i]->Search(values, 8);
        const bool passed = found == 3 && missing == -1;
        std::cout << names[i] << ": "
                  << (passed ? "OK" : "ECHEC")
                  << " (7 -> " << found << ", 8 -> " << missing << ")\n";
        if (!passed) {
            ++failures;
        }
    }
    return failures == 0 ? 0 : 1;
}