#include "lib.hpp"

#include <string_view>

constexpr std::string_view window_title = "DrumBlitz";
constexpr std::string_view texture_path = "assets/texture.png";
constexpr int screen_width = 1024;
constexpr int screen_height = 768;

class App {
    Window window;
    Renderer renderer;
    Texture texture;

    bool handle_event(SDL_Event &event);

public:
    App();
    void run();
};

App::App() {
        SDL_CreateWindowAndRenderer(
            window_title.data(), screen_width, screen_height, 0,
            std::out_ptr(window), std::out_ptr(renderer)
        );

        /* Surface texture_surface(SDL_LoadSurface(texture_path.data()));
        texture.reset(
            SDL_CreateTextureFromSurface(renderer.get(), texture_surface.get())
        );*/
}

void App::run() {
next_frame:
    SDL_Event event;
    while (SDL_PollEvent(&event))
        if (!handle_event(event))
            return;

    SDL_RenderClear(renderer.get());
    // SDL_RenderTexture(renderer.get(), texture.get(), nullptr, nullptr);
    SDL_RenderPresent(renderer.get());
    goto next_frame;
}

bool App::handle_event(SDL_Event &event) {
    if (event.type == SDL_EVENT_QUIT)
        return false;

    return true;
}

int main(int argc, char *argv[]) {
    App app;
    try { app.run(); } catch (...) {}
    return 0;
}
