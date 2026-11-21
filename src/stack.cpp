#include "stack.hpp"
#include "draw.hpp"
#include "termbox2.h"
#include <iostream>
#include <string>
#include <type_traits>
namespace stack {

Stack::Stack(int X1, int Y1, int X2, int Y2) {
    Stack::x1 = X1;
    Stack::y1 = Y1;
    Stack::x2 = X2;
    Stack::y2 = Y2;
    Stack::render();
}

void Stack::push_stack(std::string *number) {
    number_stack.emplace_back(std::stod(*number));
    *number = "";
}

void Stack::render() {
    draw::make_square(Stack::x1, Stack::y1, Stack::x2, Stack::y2);
    int index = 1;
    for (double i : Stack::number_stack) {
        tb_print(Stack::x1 + 1, Stack::y1 + index, TB_DEFAULT, TB_DEFAULT, std::string(std::to_string(i)).c_str());
        index++;
    }
}
} // namespace stack
