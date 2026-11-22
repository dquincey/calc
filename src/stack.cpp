#include "stack.hpp"
#include "draw.hpp"
#include "maths.hpp"
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
    Stack::focus = 0;
    Stack::render();
}

void Stack::push_stack(std::string *number) {
    number_stack.emplace_back(std::stod(*number));
    *number = "";
}

void Stack::render() {
    draw::make_square(Stack::x1, Stack::y1, Stack::x2, Stack::y2);
    int index = 0;
    for (double i : Stack::number_stack) {
        if (index == focus) {

            tb_print(Stack::x1 + 1, Stack::y1 + index + 1, TB_RED | TB_BOLD, TB_DEFAULT, "> ");
            if (select_mode && maths::is_between(select_origin, focus, index)) {
                tb_print(Stack::x1 + 3, Stack::y1 + index + 1, TB_DEFAULT | TB_BOLD | TB_REVERSE, TB_DEFAULT,
                         std::string(std::to_string(i)).c_str());
            } else {
                tb_print(Stack::x1 + 3, Stack::y1 + index + 1, TB_DEFAULT | TB_BOLD, TB_DEFAULT,
                         std::string(std::to_string(i)).c_str());
            }
        } else {
            tb_print(Stack::x1 + 1, Stack::y1 + index + 1, TB_DEFAULT, TB_DEFAULT, "  ");
            if (select_mode && maths::is_between(select_origin, focus, index)) {
                tb_print(Stack::x1 + 3, Stack::y1 + index + 1, TB_DEFAULT | TB_REVERSE, TB_DEFAULT,
                         std::string(std::to_string(i)).c_str());
            } else {
                tb_print(Stack::x1 + 3, Stack::y1 + index + 1, TB_DEFAULT, TB_DEFAULT,
                         std::string(std::to_string(i)).c_str());
            }
        }
        index++;
    }
}

void Stack::change_focus(int change) {
    if ((focus + change >= 0 && focus + change < number_stack.size())) {
        focus += change;
    }
}
void Stack::toggle_select_mode() {
    select_mode = !select_mode;
    if (select_mode == true) {
        select_origin = focus;
    }
}
} // namespace stack
