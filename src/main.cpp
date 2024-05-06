#include "render.hpp"

int main() {

    VulkanRenderer app1;
    try {
        app1.run();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}