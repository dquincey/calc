#include "ui.hpp"
#include <ftxui/component/component_base.hpp>
#include <memory>
using namespace ftxui;
std::vector<std::string> components = {};
int current = 0;
std::shared_ptr<ComponentBase> menu = ftxui::Menu(&components, &current);
std::string inputString = "";
std::shared_ptr<Node> elements = vbox(window(text("Stack"), menu->Render()) | flex, text(inputString) | border);
void RefreshElements() { elements = vbox(window(text("Stack"), menu->Render()) | flex, text(inputString) | border); }
