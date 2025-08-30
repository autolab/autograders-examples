#include "sort.hpp"
#include <vector>
#include <algorithm>

std::vector<int> sort(std::vector<int> input) {
    std::vector<int> copy = input;
    std::sort(copy.begin(), copy.end());
    return copy;
}