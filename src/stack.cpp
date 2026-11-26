#include "stack.hpp"
#include "draw.hpp"
#include "maths.hpp"
#include "termbox2.h"
#include <algorithm>
#include <cstdlib>
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
    bool can_move = true;
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
        for (int i = 0; i < std::abs(change); i++) {
            for (int j = direction == 1 ? higher : lower; direction == 1 ? j >= lower : j <= higher; j -= direction) {
                int current = j + (i * direction);
                int proposed = current + direction;
                if (proposed < number_stack.size() && proposed >= 0) {
                    std::swap(number_stack[current], number_stack[proposed]);
                } else {
                    change = 0;
                    break;
                }
            }
        }
        select_origin += change;
    }
    change_focus(change);
}
void Stack::to_selected(double (*func)(double a, double b)) {
    std::cerr << std::endl;
    if (number_stack.empty() || !select_mode) {
        return;
    }
    int direction = (focus - select_origin) / std::abs(focus - select_origin);
    double current = number_stack[select_origin];
    auto [lower, higher] = std::minmax(focus, select_origin);
    int prev_focus = focus;
    for (int i = select_origin + direction; direction == 1 ? i <= prev_focus : i >= prev_focus; i += direction) {
        current = func(number_stack[i], current);
    }
    for (int i = higher; i > lower; i--) {
        number_stack.erase(number_stack.begin() + i);
    }
    focus = lower;
    number_stack[focus] = current;
    toggle_select_mode();
}
void Stack::do_operation(double (*func)(double a, double b)) {
    if (number_stack.empty()) {
        return;
    }
    if (select_mode) {
        std::cout << "select_mode";
        to_selected(func);
        return;
    }
    if (focus - 1 >= 0) {
        number_stack[focus] = func(number_stack[focus], number_stack[focus - 1]);
        number_stack.erase(number_stack.begin() + (focus - 1));
        change_focus(-1);
    }
}
} // namespace stack
