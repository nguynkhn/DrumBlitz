#ifndef DRUM_BLITZ_APP_HPP
#define DRUM_BLITZ_APP_HPP

#include "lib.hpp"

#include <string_view>

constexpr std::string_view window_title = "DrumBlitz";
constexpr std::string_view texture_path = "assets/texture.png";
constexpr int screen_width = 1024;
constexpr int screen_height = 768;

class App {
public:
    App();
    ~App();
    void run();

private:
    Window window;
    Renderer renderer;
    Uint64 last_frame = 0;

    bool handle_event(const SDL_Event &event);
    void update();
    void render();
};

#endif // DRUM_BLITZ_APP_HPP
