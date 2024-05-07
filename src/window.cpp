#include "window.hpp"

#include <string>

NNWindow::NNWindow(std::string _windowName, uint32_t _width, uint32_t _heigth):windowName{_windowName}, width{_width}, heigth{_heigth}{
    initWindow();
}

NNWindow::~NNWindow(){
    cleanupWindow();
}

void NNWindow::initWindow(){
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    //glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    windowPointer = glfwCreateWindow(width, heigth, windowName.c_str(), nullptr, nullptr);
    glfwSetWindowUserPointer(windowPointer, this);
}
void NNWindow::cleanupWindow(){
    glfwDestroyWindow(windowPointer);
    glfwTerminate();
}

uint32_t NNWindow::getWidth() const{
    return width;
}

uint32_t NNWindow::getHeight() const{
    return heigth;
}

GLFWwindow* NNWindow::getWindow() const{
    return windowPointer;
}

bool NNWindow::isOpen(){
        return !glfwWindowShouldClose(windowPointer);
}