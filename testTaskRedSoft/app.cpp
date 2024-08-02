#include <stdexcept>
#include <cstring>
#include <stdlib.h>
#include "app.h"

App* App::instancePtr = nullptr;
static const char* invalidInputMsg = "Invalid Input";

App *App::getInstance(int argc, char *argv[]) {
    if (instancePtr != nullptr) {
        return instancePtr;
    }

    if (argc != 3) {
        throw std::runtime_error(invalidInputMsg);
    }

    if (! std::strcmp(argv[1], "-f") && ! std::strcmp(argv[1], "-s")) {
        throw std::runtime_error(invalidInputMsg);
    }

    instancePtr = new App(argv);
    return instancePtr;
}

void App::run() {
    system("xclip -sel clip -i test_string");
}

App::App(char *argv[]) :
    mode(std::strcmp(argv[1], "-f") ? Mode::FILE : Mode::STRING),
    source(std::string(argv[2]))
{}
