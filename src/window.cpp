#include "window.hpp"

#include <string>

const char** Big::Window::getRequiredWindowsExtensions(uint32_t &extensionCount){
    return glfwGetRequiredInstanceExtensions(&extensionCount);
}

VkResult Big::Window::createWindowVkSurface(VkInstance instance, const VkAllocationCallbacks *allocator, VkSurfaceKHR &surface){
    return glfwCreateWindowSurface(instance, windowPointer, allocator, &surface);
}

BigWindow::BigWindow(std::string _windowName, uint32_t _width, uint32_t _heigth):windowName{_windowName}, width{_width}, heigth{_heigth}{
    initWindow();
}

BigWindow::~BigWindow(){
    cleanupWindow();
}

void BigWindow::initWindow(){
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    //glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    windowPointer = glfwCreateWindow(width, heigth, windowName.c_str(), nullptr, nullptr);
    glfwSetWindowUserPointer(windowPointer, this);
}
void BigWindow::cleanupWindow(){
    glfwDestroyWindow(windowPointer);
    glfwTerminate();
}

uint32_t BigWindow::getWidth() const{
    return width;
}

uint32_t BigWindow::getHeight() const{
    return heigth;
}

GLFWwindow* BigWindow::getWindow() const{
    return windowPointer;
}

bool BigWindow::isOpen(){
        return !glfwWindowShouldClose(windowPointer);
}