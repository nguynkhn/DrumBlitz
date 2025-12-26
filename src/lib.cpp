#include "lib.hpp"

#include <format>

void check_sdl_error(const std::string_view error_msg) {
    const std::string_view error_desc{SDL_GetError()};
    if (error_desc.empty())
        return;

    SDL_ClearError();
    throw std::format("{}: {}", error_msg, error_desc);
}
