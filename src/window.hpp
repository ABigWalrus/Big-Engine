#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

class BigWindow{
public:
    BigWindow(std::string windowName, uint32_t width, uint32_t heigth);
    ~BigWindow();
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