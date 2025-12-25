#ifndef DRUM_BLITZ_LIB_HPP
#define DRUM_BLITZ_LIB_HPP

#include <SDL3/SDL.h>

#include <memory>
#include <format>
#include <string_view>

template <auto Deleter>
struct static_deleter {
    template <typename T>
    void operator()(T* ptr) const noexcept { Deleter(ptr); }
};

template <typename T, auto F>
using static_ptr = std::unique_ptr<T, static_deleter<F>>;

using Window = static_ptr<SDL_Window, SDL_DestroyWindow>;
using Renderer = static_ptr<SDL_Renderer, SDL_DestroyRenderer>;
using Surface = static_ptr<SDL_Surface, SDL_DestroySurface>;
using Texture = static_ptr<SDL_Texture, SDL_DestroyTexture>;

void check_sdl_error(const std::string_view error_msg) {
    const std::string_view error_desc{SDL_GetError()};
    if (error_desc.empty())
        return;

    SDL_ClearError();
    throw std::format("{}: {}", error_msg, error_desc);
}

#endif // DRUM_BLITZ_LIB_HPP
