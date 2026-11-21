#pragma once
#include <string>
namespace textbox {
class Textbox {

  private:
    int x1, x2, y1, y2;
    std::string text = "";
    int string_pos_x, string_pos_y;

  public:
    void render();
    void push_char(const char &character);
    void clear();
    void backspace();
    Textbox();
    Textbox(int X1, int Y1, int X2, int Y2);
    Textbox(int X1, int Y1, int X2, int Y2, std::string newtext);
    std::string *get_text();
};
} // namespace textbox
