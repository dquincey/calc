#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <utility>
namespace maths {
bool is_between(int low, int high, int val) {
    if (low > high) {
        std::swap(low, high);
    }
    return (val >= low && val <= high);
}
std::string format_double(double num) {
    std::string str = std::to_string(num);
    str.erase(str.find_last_not_of('0') + 1, std::string::npos);
    str.erase(str.find_last_not_of('.') + 1, std::string::npos);
    int to;
    if (str.find(".") != std::string::npos) {
        to = str.find(".");
    } else {
        to = static_cast<int>(str.size());
    }

    for (int i = 0; i < to; i++) {

        if (i % 3 == 0 && i > 1 && str[to - 1 - i] != '-') {
            str.insert((to - i), ",");
        }
    }
    return str;
}
int move_towards(int a, int b) {
    int direction = (b - a) / std::abs(b - a);
    auto [low, high] = std::minmax(a, b);
    return std::clamp(a + direction, low, high);
}

double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) { return a / b; }
} // namespace maths
