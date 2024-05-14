#include "window.hpp"

#include <string>

DeerWindow::DeerWindow(std::string _windowName, uint32_t _width, uint32_t _heigth):windowName{_windowName}, width{_width}, heigth{_heigth}{
    initWindow();
}

DeerWindow::~DeerWindow(){
    cleanupWindow();
}

void DeerWindow::initWindow(){
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    //glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    windowPointer = glfwCreateWindow(width, heigth, windowName.c_str(), nullptr, nullptr);
    glfwSetWindowUserPointer(windowPointer, this);
}
void DeerWindow::cleanupWindow(){
    glfwDestroyWindow(windowPointer);
    glfwTerminate();
}

uint32_t DeerWindow::getWidth() const{
    return width;
}

uint32_t DeerWindow::getHeight() const{
    return heigth;
}

GLFWwindow* DeerWindow::getWindow() const{
    return windowPointer;
}

bool DeerWindow::isOpen(){
        return !glfwWindowShouldClose(windowPointer);
}