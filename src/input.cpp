#include "ui.hpp"
#include <cctype>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <iostream>

using namespace ftxui;
void ApplyInput(ScreenInteractive &screen, Component &renderer) {
    renderer |= CatchEvent([&screen](Event event) {
        unsigned char inputCharacter = static_cast<unsigned char>(event.character()[0]);
        if (event == Event::Character('q') || event == Event::Escape) {
            screen.Exit();
            return true;
        } else if (event.is_character() && std::isdigit(inputCharacter)) {
            inputString += inputCharacter;
            RefreshElements();
            return true;
        } else {
            return false;
        }
    });
}
