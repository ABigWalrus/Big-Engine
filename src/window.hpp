#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

class DeerWindow{
public:
    DeerWindow(std::string windowName, uint32_t width, uint32_t heigth);
    ~DeerWindow();
    uint32_t getWidth() const;
    uint32_t getHeight() const;
    GLFWwindow* getWindow() const;
    
    bool isOpen();
private:
    std::string windowName;
    
    const uint32_t width;
    const uint32_t heigth;

    GLFWwindow* windowPointer;

    void initWindow();
    void cleanupWindow();
};