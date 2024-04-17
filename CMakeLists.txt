cmake_minimum_required (VERSION 3.5)
project (VulkanTutorial)

find_package(Vulkan REQUIRED)
# set(ENV{VULKAN_SDK} "C:/VulkanSDK/1.3.280.0")
# set(CMAKE_CXX_STANDARD 17)
# add_subdirectory(libs)
include_directories(
	libs/glfw-3.4.bin.WIN64/include/
	libs/glm/
)
add_executable(VulkanTutorial src/main.cpp)
target_link_libraries(VulkanTutorial Vulkan::Vulkan ${CMAKE_CURRENT_SOURCE_DIR}/libs/glfw-3.4.bin.WIN64/lib-static-ucrt/glfw3.dll)