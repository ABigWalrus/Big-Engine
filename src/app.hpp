#pragma once

#include "render.hpp"

class NonameApplication{
public:
    void run();
    void cleanup();
    void mainLoop();
private:
    VulkanRenderer renderer;
};