#pragma once
#include <ftxui/component/component_base.hpp>
#include <ftxui/ftxui.hpp>
#include <memory>
#include <string>
#include <vector>
using namespace ftxui;
extern std::vector<std::string> components;
extern int current;
extern std::shared_ptr<ComponentBase> menu;
extern std::shared_ptr<Node> elements;
extern std::string inputString;
void RefreshElements();
