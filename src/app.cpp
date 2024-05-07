#include <string>
#include <chrono>
#include <iostream>

#include "app.hpp"
#include "render.hpp"
#include "window.hpp"

NNApplication::NNApplication(){
    init();
}

NNApplication::~NNApplication(){
    cleanup();
}

void NNApplication::run(){
    while (window.isOpen()) {
        glfwPollEvents();
        renderer.render();
    }
}

void NNApplication::init(){
    renderer.init(window.getWindow(), window.getWidth(), window.getWidth());   
}


void NNApplication::cleanup(){
    renderer.cleanup();
}