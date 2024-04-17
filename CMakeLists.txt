cmake_minimum_required (VERSION 3.5)
project (VulkanTutorial)

set(ENV{VULKAN_SDK} "C:/VulkanSDK/1.3.280.0")
set(CMAKE_CXX_STANDARD 17)
find_package(Vulkan REQUIRED)
add_subdirectory(lib/glfw-3.4)
add_subdirectory(lib/glm)

add_executable(VulkanTutorial main.cpp)
target_link_libraries(VulkanTutorial glfw ${GLFW_LIBRARIES} Vulkan::Vulkan)