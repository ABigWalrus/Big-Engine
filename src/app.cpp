#include "app.hpp"
#include "render.hpp"

void NonameApplication::run(){
    renderer.init();
    mainLoop();
    cleanup();
}

void NonameApplication::mainLoop(){
    while (!glfwWindowShouldClose(renderer.window)) {
        glfwPollEvents();
        renderer.render();
    }
}

void NonameApplication::cleanup(){
    renderer.cleanup();
}