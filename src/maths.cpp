#include <string>
namespace maths {
double calculate_string(std::string &string) {
    char first_non_space = '0';
    for (int i; i < static_cast<int>(string.size()); i++) {
        if (string[i] != ' ') {
            first_non_space = string[i];
            break;
        }
    }
    return 0;
}
} // namespace maths
