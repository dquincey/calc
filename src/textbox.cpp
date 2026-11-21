#include "textbox.hpp"
#include "draw.hpp"
#include "termbox2.h"
#include <iostream>
#include <string>
namespace textbox {
void Textbox::render() {
    draw::make_square(x1, y1, x2, y2);
    tb_print(string_pos_x, string_pos_y, TB_DEFAULT, TB_DEFAULT, text.c_str());
    tb_set_cursor(string_pos_x + text.size(), string_pos_y);
}
void Textbox::push_char(const char &character) { text += character; }
Textbox::Textbox() : x1(9), y1(9), x2(18), y2(19), string_pos_x(x1 + 1), string_pos_y(y1 + 1) { render(); }

Textbox::Textbox(int X1, int Y1, int X2, int Y2)
    : x1(X1), x2(X2), y1(Y1), y2(Y2), string_pos_x(x1 + 1), string_pos_y(y1 + 1) {
    render();
}
Textbox::Textbox(int X1, int Y1, int X2, int Y2, std::string newtext)
    : x1(X1), x2(X2), y1(Y1), y2(Y2), string_pos_x(x1 + 1), string_pos_y(y1 + 1), text(newtext) {
    render();
}
void Textbox::clear() { text = ""; }
void Textbox::backspace() {
    if (!text.empty()) {
        text.pop_back();
    }
}
std::string *Textbox::get_text() { return &text; }
} // namespace textbox
