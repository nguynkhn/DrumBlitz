#include "app.hpp"

#include <memory>

int main(int argc, char *argv[]) {
    try {
        std::make_unique<App>()->run();
    } catch (const std::string &error) {
        SDL_Log("%s\n", error.c_str());
    }
    return 0;
}
