#pragma once

#include "render.hpp"
#include "window.hpp"
#include <string>

class NNApplication{
public:
    // std::string name;
    // uint64_t renders = 0;
    static constexpr uint32_t WIDTH = 800;
    static constexpr uint32_t HEIGTH = 600;

    NNApplication();
    ~NNApplication();
 //std::string name, uint32_t width, uint32_t height);
    void run();
    // void init();
    // void cleanup();

private:
    NNWindow window{"TEST WINDOW", WIDTH, HEIGTH};
    VulkanRenderer renderer;

    // void initWindow();
    // void mainLoop();
    void init();
    void cleanup();

};