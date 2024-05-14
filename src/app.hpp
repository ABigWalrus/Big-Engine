#pragma once

#include "render.hpp"
#include "window.hpp"
#include <string>

class Application{
public:
    // std::string name;
    // uint64_t renders = 0;
    static constexpr uint32_t WIDTH = 800;
    static constexpr uint32_t HEIGTH = 600;

    Application();
    ~Application();
 //std::string name, uint32_t width, uint32_t height);
    void run();
    // void init();
    // void cleanup();

private:
    DeerWindow window{"TEST WINDOW", WIDTH, HEIGTH};
    DeerRenderer renderer;

    // void initWindow();
    // void mainLoop();
    void init();
    void cleanup();

};