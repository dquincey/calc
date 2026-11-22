#include <iostream>
#include <string>
#include <utility>
namespace maths {
bool is_between(int low, int high, int val) {
    if (low > high) {
        std::swap(low, high);
    }
    return (val >= low && val <= high);
}
} // namespace maths
