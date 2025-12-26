#include "app.hpp"

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

    update();
    render();
    goto next_frame;
}

bool App::handle_event(const SDL_Event &event) {
    if (event.type == SDL_EVENT_QUIT)
        return false;

    return true;
}

void App::update() {
    Uint64 current_frame = SDL_GetPerformanceCounter();

    if (last_frame != 0) {
        Uint64 frequency = SDL_GetPerformanceFrequency();
        double dt = (double)(current_frame - last_frame) / frequency;
        // TODO: give dt an use
    }

    last_frame = current_frame;
}

void App::render() {
    SDL_RenderClear(renderer.get());
    SDL_RenderPresent(renderer.get());
}
