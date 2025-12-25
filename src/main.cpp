#include "lib.hpp"

#include <iostream>
#include <string_view>

constexpr std::string_view window_title = "DrumBlitz";
constexpr std::string_view texture_path = "assets/texture.png";
constexpr int screen_width = 1024;
constexpr int screen_height = 768;

class App {
    Window window;
    Renderer renderer;

public:
    App();
    ~App();
    void run();

private:
    bool handle_event(SDL_Event &event);
};

App::App() {
    SDL_Init(SDL_INIT_VIDEO);
    check_sdl_error("Failed to initialize SDL");

    SDL_CreateWindowAndRenderer(
        window_title.data(), screen_width, screen_height, 0,
        std::out_ptr(window), std::out_ptr(renderer)
    );
    check_sdl_error("Failed to create window");
}

App::~App() {
    SDL_Quit();
}

void App::run() {
next_frame:
    SDL_Event event;
    while (SDL_PollEvent(&event))
        if (!handle_event(event))
            return;

    SDL_RenderClear(renderer.get());
    SDL_RenderPresent(renderer.get());
    goto next_frame;
}

bool App::handle_event(SDL_Event &event) {
    if (event.type == SDL_EVENT_QUIT)
        return false;

    return true;
}

int main(int argc, char *argv[]) {
    try {
        App app;
        app.run();
    } catch (const std::string &error) {
        SDL_Log("%s\n", error.c_str());
    }
    return 0;
}
