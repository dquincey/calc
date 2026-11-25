#include "stack.hpp"
#include "draw.hpp"
#include "maths.hpp"
#include "termbox2.h"
#include <algorithm>
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
    if (number_stack.size() > 0) {
        number_stack.insert(number_stack.begin() + focus + 1, std::stod(*number));
    } else {
        number_stack.emplace_back(std::stod(*number));
    }
    change_focus(1);
}

void Stack::render() {
    draw::make_square(Stack::x1, Stack::y1, Stack::x2, Stack::y2);
    int index = 0;
    for (double i : Stack::number_stack) {
        if (index == focus) {
            tb_print(Stack::x1 + 1, Stack::y1 + index + 1, TB_RED | TB_BOLD, TB_DEFAULT, "> ");
            if (select_mode && maths::is_between(select_origin, focus, index)) {
                tb_print(Stack::x1 + 3, Stack::y1 + index + 1, TB_DEFAULT | TB_REVERSE, TB_DEFAULT,
                         std::string(maths::format_double(i)).c_str());
            } else {
                tb_print(Stack::x1 + 3, Stack::y1 + index + 1, TB_DEFAULT | TB_BOLD, TB_DEFAULT,
                         std::string(maths::format_double(i)).c_str());
            }
        } else {
            tb_print(Stack::x1 + 1, Stack::y1 + index + 1, TB_DEFAULT, TB_DEFAULT, "  ");
            if (select_mode && maths::is_between(select_origin, focus, index)) {
                tb_print(Stack::x1 + 3, Stack::y1 + index + 1, TB_DEFAULT | TB_REVERSE, TB_DEFAULT,
                         std::string(maths::format_double(i)).c_str());
            } else {
                tb_print(Stack::x1 + 3, Stack::y1 + index + 1, TB_DEFAULT | TB_DIM, TB_DEFAULT,
                         std::string(maths::format_double(i)).c_str());
            }
        }
        index++;
    }
}

void Stack::change_focus(int change) {
    if (!number_stack.empty()) {
        focus = std::clamp(change + focus, 0, static_cast<int>(number_stack.size() - 1));
    }
}
void Stack::toggle_select_mode() {
    select_mode = !select_mode;
    if (select_mode == true) {
        select_origin = focus;
    }
}
const bool Stack::get_select_mode() const { return select_mode; }
void Stack::move(int change) {
    int direction = change / std::abs(change);
    if (select_mode == false) {
        for (int i = 0; i < std::abs(change); i++) {
            int current = focus + (i * direction);
            int proposed = current + direction;
            if (proposed < number_stack.size() && proposed >= 0) {
                std::swap(number_stack[current], number_stack[proposed]);
            }
        }
    } else {
        auto [lower, higher] = std::minmax(focus, select_origin);
        if (direction == -1) {
            // start from the lowest
            for (int i = 0; i < std::abs(change); i++) {
                for (int j = lower; j <= higher; j++) {
                    int current = j + (i * direction);
                    int proposed = current + direction;
                    if (proposed < number_stack.size() && proposed >= 0) {
                        std::swap(number_stack[current], number_stack[proposed]);
                        std::cerr << "works!" << std::endl;
                    } else {
                        std::cerr << "broken!" << std::endl;
                        break;
                    }
                }
            }
        } else if (direction == 1) {
            for (int i = 0; i < std::abs(change); i++) {
                for (int j = direction == 1 ? higher : lower; j >= lower; j--) {
                    int current = j + (i * direction);
                    int proposed = current + direction;
                    if (proposed < number_stack.size() && proposed >= 0) {
                        std::swap(number_stack[current], number_stack[proposed]);
                        std::cerr << "works!" << std::endl;
                    } else {
                        std::cerr << "broken!" << std::endl;
                        break;
                    }
                }
            }
        }
        select_origin += change;
    }
    change_focus(change);
}
} // namespace stack
