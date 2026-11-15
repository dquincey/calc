#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/ftxui.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/screen.hpp>
#include <string>
#include <vector>
using namespace ftxui;
int main() {
    auto screen = ScreenInteractive::Fullscreen();
    std::vector<std::string> components = {};
    int current = 0;
    auto menu = Menu(&components, &current);

    auto elements = vbox(window(text("Stack"), menu->Render()) | flex, text("hello") | border);
    auto renderer = Renderer(menu, [&] { return elements; });

    renderer |= CatchEvent([&](Event event) {
        if (event == Event::Character('q') || event == Event::Escape) {
            screen.Exit();
            return true;
        } else {
            return false;
        }
    });

    screen.Loop(renderer);
    return 0;
}
