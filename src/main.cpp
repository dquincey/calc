#include <cctype>
#define TB_IMPL
#include "draw.hpp"
#include "stack.hpp"
#include "termbox2.h"
#include "textbox.hpp"
#include <iostream>
#include <string>

int main() {
    tb_init();
    tb_event ev;
    tb_clear();

    std::string display_string = "";
    stack::Stack number_stack{0, 0, tb_width() - 1, tb_height() - 4};
    textbox::Textbox text_box{0, tb_height() - 3, tb_width() - 1, tb_height() - 1, display_string};
    tb_present();

    while (true) {
        tb_poll_event(&ev);
        if (ev.ch == 'q' || ev.key == TB_KEY_ESC) {
            break;
        }
        if (ev.ch != 0) {
            if (ev.ch == '-' || ev.ch == '.' || std::isdigit(ev.ch))
                text_box.push_char(ev.ch);
        }
        if (ev.key == TB_KEY_ENTER) {
            if (*text_box.get_text() != "")
                number_stack.push_stack(text_box.get_text());
        }
        if (ev.key == TB_KEY_BACKSPACE || ev.key == TB_KEY_BACKSPACE2) {
            text_box.backspace();
        }
        if (ev.ch == 'j') {
            number_stack.change_focus(1);
        }
        if (ev.ch == 'k') {
            number_stack.change_focus(-1);
        }
        if (ev.ch == 'v') {
            number_stack.toggle_select_mode();
        }
        tb_clear();
        text_box.render();
        number_stack.render();
        tb_present();
    }

    tb_shutdown();
}
