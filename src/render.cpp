#include "render.hpp"
#include "input.hpp"
#include "ui.hpp"
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <memory>
using namespace ftxui;
int main() {
    // create screen
    ScreenInteractive screen = ScreenInteractive::Fullscreen();
    // make the ui componenets renderable
    Component renderer = Renderer(menu, [&] { return elements; });
    // Give input
    ApplyInput(screen, renderer);

    // Start loop
    screen.Loop(renderer);
    return 0;
}
