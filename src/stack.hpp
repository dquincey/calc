#pragma once
#include <string>
#include <vector>
namespace stack {
extern std::vector<int> number_stack;
class Stack {
  private:
    int x1, y1, x2, y2;
    std::vector<double> number_stack = {};
    int focus;
    int select_origin;
    bool select_mode = false;

  public:
    const bool get_select_mode() const;
    void to_selected(double (*func)(double a, double b));
    void do_operation(double (*func)(double a, double b));
    Stack(int x1, int y1, int x2, int y2);
    void push_stack(std::string *number);
    void change_focus(int change);
    void toggle_select_mode();
    void render();
    void move(int change);
};
} // namespace stack
