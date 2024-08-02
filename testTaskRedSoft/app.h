#pragma once
#include <string>

class App {
public:
    App() = delete;
    App(App &other) = delete;
    void operator= (const App& other) = delete;
    ~App() = default;

    static App* getInstance(int argc, char* argv[]);
    static void run();

private:
    enum class Mode {
        STRING,
        FILE
    };

    App(char* argv[]);
    static App* instancePtr;

    Mode mode;
    std::string source;
};
