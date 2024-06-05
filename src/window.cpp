#include "window.hpp"

#include <string>

const char** Big::Window::getRequiredWindowsExtensions(uint32_t &extensionCount){
    return glfwGetRequiredInstanceExtensions(&extensionCount);
}

VkResult Big::Window::createWindowVkSurface(VkInstance instance, const VkAllocationCallbacks *allocator, VkSurfaceKHR &surface){
    return glfwCreateWindowSurface(instance, windowPointer, allocator, &surface);
}

Big::Window::Window(std::string _windowName, uint32_t _width, uint32_t _heigth):windowName{_windowName}, width{_width}, heigth{_heigth}{
    initWindow();
}

Big::Window::~Window(){
    cleanupWindow();
}

void Big::Window::initWindow(){
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    //glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    windowPointer = glfwCreateWindow(width, heigth, windowName.c_str(), nullptr, nullptr);
    glfwSetWindowUserPointer(windowPointer, this);
}
void Big::Window::cleanupWindow(){
    glfwDestroyWindow(windowPointer);
    glfwTerminate();
}

uint32_t Big::Window::getWidth() const{
    return width;
}

uint32_t Big::Window::getHeight() const{
    return heigth;
}

GLFWwindow* Big::Window::getWindow() const{
    return windowPointer;
}

bool Big::Window::isOpen(){
        return !glfwWindowShouldClose(windowPointer);
}