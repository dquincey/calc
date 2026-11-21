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
    std::vector<int> selected;

  public:
    Stack(int x1, int y1, int x2, int y2);
    void push_stack(std::string *number);
    void change_focus(int change);
    void change_selected(int low, int high);
    void render();
};
} // namespace stack
